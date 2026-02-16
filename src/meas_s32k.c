/*******************************************************************************
*   Project      : FRDM_A_S32K312_MC_PMSM_FOC_2Sh
*   Version      : 1.0
*   RTD Version  : 7.0.0
*   Brief description  :
*   File contains definition of functions related to analog quantities capturing.
*
*   Copyright 2022, 2023 NXP
*
*   NXP Proprietary. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
*******************************************************************************/
/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "meas_s32k.h"

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
extern volatile Bctu_Ip_FifoResultType measuredValues[16];

/*==================================================================================================
*                                    FUNCTIONS DEFINITION
==================================================================================================*/

/*FUNCTION**********************************************************************
 *
 * Function Name : MEAS_Clear
 * Description   : Clears variables needed for both calibration as well as run time measurement.
 *                 It is not intended to be executed when application is in run mode.
 *
 *END**************************************************************************/
tBool MEAS_Clear(measModule_t *ptr)
{
    ptr->measured.fltPhA.filt   = 0.0F;
    ptr->measured.fltPhA.raw    = 0.0F;
    ptr->measured.fltPhB.filt   = 0.0F;
    ptr->measured.fltPhB.raw    = 0.0F;
    ptr->measured.fltPhC.filt   = 0.0F;
    ptr->measured.fltPhC.raw    = 0.0F;
    ptr->measured.fltUdcb.filt  = 0.0F;
    ptr->measured.fltUdcb.raw   = 0.0F;
    ptr->measured.fltTemp.filt  = 0.0F;
    ptr->measured.fltTemp.raw   = 0.0F;
    ptr->offset.fltPhA.fltOffset  = I_MAX;
    ptr->offset.fltPhB.fltOffset  = I_MAX;
    ptr->offset.fltPhC.fltOffset  = I_MAX;
    ptr->flag.R                 = 0;
    ptr->flag.B.calibInitDone   = 0;
    ptr->flag.B.calibDone       = 0;

    return (TRUE);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : MEAS_CalibCurrentSense
 * Description   : This function performs offset calibration for 3 phase current measurement
 *				   during the calibration phase of the application. It is not intended to be
 *				   executed when application is in run mode.
 *
 *
 *END**************************************************************************/
tBool MEAS_CalibCurrentSense(measModule_t *ptr, tU16 svmSector)
{
    if (!(ptr->flag.B.calibInitDone))
    {
        ptr->calibCntr = 1 << (ptr->param.u16CalibSamples + 4); /* +4 in order to accommodate settling time of the filter */
        ptr->measured.fltPhA.filt   = 0x0;
        ptr->measured.fltPhB.filt   = 0x0;
        ptr->measured.fltPhC.filt   = 0x0;
        ptr->offset.fltPhA.filtParam.fltAcc = I_MAX;
        ptr->offset.fltPhB.filtParam.fltAcc = I_MAX;
        ptr->offset.fltPhC.filtParam.fltAcc = I_MAX;
        ptr->flag.B.calibDone       = 0;
        ptr->flag.B.calibInitDone   = 1;
    }

    if (!(ptr->flag.B.calibDone))
    {
        /* --------------------------------------------------------------
         * Phase A - DC offset data filtering using MA recursive filter
         * ------------------------------------------------------------ */
        ptr->offset.fltPhA.fltOffset  = GDFLIB_FilterMA(ptr->measured.fltPhA.raw, &ptr->offset.fltPhA.filtParam);
        /* --------------------------------------------------------------
         * Phase B - DC offset data filtering using MA recursive filter
         * ------------------------------------------------------------ */
        ptr->offset.fltPhB.fltOffset  = GDFLIB_FilterMA(ptr->measured.fltPhB.raw, &ptr->offset.fltPhB.filtParam);
        /* --------------------------------------------------------------
         * Phase C - DC offset data filtering using MA recursive filter
         * ------------------------------------------------------------ */
        ptr->offset.fltPhC.fltOffset  = GDFLIB_FilterMA(ptr->measured.fltPhC.raw, &ptr->offset.fltPhC.filtParam);

        if ((--ptr->calibCntr) <= 0)
        {
            ptr->flag.B.calibDone = 1;    /* end of DC offset calibration */
        }
    }
    return (ptr->flag.B.calibDone);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : MEAS_Get3PhCurrent
 * Description   : This function performs measurement of three phase currents from
            	   two shunt resistors. Because a non-zero length PWM pulse width
            	   is required for successful current sample, this approach can not
            	   be utilized up to full PWM dutycycle.
 *
 *
 *END**************************************************************************/
tBool MEAS_Get3PhCurrent(measModule_t *ptr, SWLIBS_3Syst_FLT *i,  tU16 svmSector)
{
    uint16_t PhaseA_Current = 0;
    uint16_t PhaseB_Current = 0;

    PhaseA_Current = measuredValues[1].AdcData;
    PhaseB_Current = measuredValues[0].AdcData;
    ptr->measured.fltPhA.raw = MLIB_Mul(((tFloat)MLIB_Div((tFloat)(PhaseA_Current & 0x00003FFF), (tFloat)0x00003FFF)), I_MAX * 2.0F);
    ptr->measured.fltPhB.raw = MLIB_Mul(((tFloat)MLIB_Div((tFloat)(PhaseB_Current & 0x00003FFF), (tFloat)0x00003FFF)), I_MAX * 2.0F);
    i->fltArg1 = MLIB_Sub(ptr->offset.fltPhA.fltOffset,ptr->measured.fltPhA.raw);
    i->fltArg2 = MLIB_Sub(ptr->offset.fltPhB.fltOffset,ptr->measured.fltPhB.raw);
    i->fltArg3 = MLIB_Neg(MLIB_Add(i->fltArg1,i->fltArg2));

    return (TRUE);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : MEAS_GetUdcVoltage
 * Description   : his function performs measurement of DCBus Voltage.
 *
 *END**************************************************************************/
tBool MEAS_GetUdcVoltage(measModule_t *ptr, GDFLIB_FILTER_MA_T *uDcbFilter)
{
    uint16_t DCBus_Voltage= 0;
    DCBus_Voltage = measuredValues[2].AdcData;
    ptr->measured.fltUdcb.raw = MLIB_Mul(((tFloat)MLIB_Div((tFloat)(DCBus_Voltage & 0x00003FFF), (tFloat)0x00003FFF)), U_DCB_MAX);
    ptr->measured.fltUdcb.filt  = GDFLIB_FilterMA(ptr->measured.fltUdcb.raw, uDcbFilter);

    return (TRUE);
}
