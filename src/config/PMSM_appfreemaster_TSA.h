/*******************************************************************************
*   Project      : FRDM_A_S32K312_MC_PMSM_FOC_2Sh
*   Version      : 1.0
*   RTD Version  : 7.0.1
*   Brief description  :
*   File contains Freemaster TSA table definition.
*
*   Copyright 2022, 2026 NXP
*
*   NXP Proprietary. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
*******************************************************************************/

#ifndef TSA_TABLE_H_
#define TSA_TABLE_H_
/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "motor_structure.h"
#include "pospe_sensor.h"
/*==================================================================================================
*                                     IMPORTED GLOBAL VARIABLES
==================================================================================================*/
/* Structure type information will be available in the FreeMASTER application
  (TSA) by: */

extern         pmsmDrive_t                     drvFOC;
extern         encoderPospe_t                  encoderPospe;
extern         fm_scale_t                      fmScale;
extern         driveStates_t                   cntrState;
extern         gd3000Status_t                  gd3000Status;
extern         tpp_drv_config_t                tppDrvConfig;
extern         appFaultStatus_t                tempfaults;
extern         appFaultStatus_t                permFaults;
extern         measModule_t                    meas;
extern         tPos_mode                       pos_mode;
extern         switchSensor_t                  switchSensor;
extern         volatile tFloat                 OL_SpeedRampInc, CL_SpeedRampInc, CL_SpeedRampDec;
extern         tBool                           fieldWeakOnOff;
extern         volatile tFloat                 UDQVectorSum;
extern         volatile tFloat                 FW_PropGainControl;
extern         volatile tFloat                 FW_IntegGainControl;

/*==================================================================================================
*                                     TSA TABLE
==================================================================================================*/
/*    *************** begin TSA table - S32K_PMSM   ************* */
FMSTR_TSA_TABLE_BEGIN(S32K_PMSM)
    FMSTR_TSA_RW_VAR(encoderPospe,              FMSTR_TSA_USERTYPE(encoderPospe_t))
    FMSTR_TSA_RW_VAR(drvFOC,                    FMSTR_TSA_USERTYPE(pmsmDrive_t))
    FMSTR_TSA_RW_VAR(fmScale,                   FMSTR_TSA_USERTYPE(fm_scale_t))
    FMSTR_TSA_RW_VAR(cntrState,                 FMSTR_TSA_USERTYPE(driveStates_t))
    FMSTR_TSA_RW_VAR(gd3000Status,              FMSTR_TSA_USERTYPE(gd3000Status_t))
    FMSTR_TSA_RW_VAR(tppDrvConfig,              FMSTR_TSA_USERTYPE(tpp_drv_config_t))
    FMSTR_TSA_RW_VAR(tempfaults,                FMSTR_TSA_USERTYPE(appFaultStatus_t))
    FMSTR_TSA_RW_VAR(permFaults,                FMSTR_TSA_USERTYPE(appFaultStatus_t))
    FMSTR_TSA_RW_VAR(meas,                      FMSTR_TSA_USERTYPE(measModule_t))
    FMSTR_TSA_RW_VAR(pos_mode,                  FMSTR_TSA_USERTYPE(tPos_mode))
    FMSTR_TSA_RW_VAR(switchSensor,              FMSTR_TSA_USERTYPE(switchSensor_t))

/*  ***************                VARIABLES                 ******************* */
    FMSTR_TSA_RW_VAR(CL_SpeedRampDec,           FMSTR_TSA_FLOAT)
    FMSTR_TSA_RW_VAR(CL_SpeedRampInc,           FMSTR_TSA_FLOAT)
    FMSTR_TSA_RW_VAR(OL_SpeedRampInc,           FMSTR_TSA_FLOAT)
    FMSTR_TSA_RW_VAR(fieldWeakOnOff,            FMSTR_TSA_UINT8)
    FMSTR_TSA_RW_VAR(UDQVectorSum,              FMSTR_TSA_FLOAT)
    FMSTR_TSA_RW_VAR(FW_PropGainControl,        FMSTR_TSA_FLOAT)
    FMSTR_TSA_RW_VAR(FW_IntegGainControl,       FMSTR_TSA_FLOAT)

/*    ***************             STRUCTURES              ******************* */
    FMSTR_TSA_STRUCT(pospeControl_t)
        FMSTR_TSA_MEMBER(pospeControl_t,                     thRotEl,                FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(pospeControl_t,                     thRotElEnc,             FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(pospeControl_t,                     thRotElEnck1,           FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(pospeControl_t,                     thRotElEncErr,          FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(pospeControl_t,                     wRotEl,                 FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(pospeControl_t,                     wRotElEnc,              FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(pospeControl_t,                     wRotElFilt,             FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(pospeControl_t,                     wRotElReq,              FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(pospeControl_t,                     wRotElErr,              FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(pospeControl_t,                     speedLoopCntr,          FMSTR_TSA_SINT16)

    FMSTR_TSA_STRUCT(openLoopPospe_t)
        FMSTR_TSA_MEMBER(openLoopPospe_t,                    thRotEl,                FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(openLoopPospe_t,                    wRotEl,                 FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(openLoopPospe_t,                    iQUpperLimit,           FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(openLoopPospe_t,                    iQLowerLimit,           FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(openLoopPospe_t,                    thDifOpenLEstim,        FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(openLoopPospe_t,                    integ,                  FMSTR_TSA_USERTYPE(GFLIB_INTEGRATOR_TR_T_F32))

    FMSTR_TSA_STRUCT(GFLIB_INTEGRATOR_TR_T_F32)
        FMSTR_TSA_MEMBER(GFLIB_INTEGRATOR_TR_T_F32,         f32State,                 FMSTR_TSA_FRAC32)
        FMSTR_TSA_MEMBER(GFLIB_INTEGRATOR_TR_T_F32,         f32InK1,                 FMSTR_TSA_FRAC32)
        FMSTR_TSA_MEMBER(GFLIB_INTEGRATOR_TR_T_F32,         f32C1,                     FMSTR_TSA_FRAC32)
        FMSTR_TSA_MEMBER(GFLIB_INTEGRATOR_TR_T_F32,         u16NShift,                 FMSTR_TSA_UINT16)



    FMSTR_TSA_STRUCT(encoderPospe_t)
        FMSTR_TSA_MEMBER(encoderPospe_t,                    thRotMec,                FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(encoderPospe_t,                    wRotMec,                 FMSTR_TSA_USERTYPE(pospeValue_t))
        FMSTR_TSA_MEMBER(encoderPospe_t,                    thRotEl,                 FMSTR_TSA_USERTYPE(pospeValue_t))
        FMSTR_TSA_MEMBER(encoderPospe_t,                    thRotElk1,               FMSTR_TSA_USERTYPE(pospeValue_t))
        FMSTR_TSA_MEMBER(encoderPospe_t,                    wRotEl,                  FMSTR_TSA_USERTYPE(pospeValue_t))
        FMSTR_TSA_MEMBER(encoderPospe_t,                    thRoErr,                 FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(encoderPospe_t,                    thRotMecSin,             FMSTR_TSA_USERTYPE(pospeValue_t))
        FMSTR_TSA_MEMBER(encoderPospe_t,                    thRotMecCos,             FMSTR_TSA_USERTYPE(pospeValue_t))
        FMSTR_TSA_MEMBER(encoderPospe_t,                    thRotElSin,              FMSTR_TSA_USERTYPE(pospeValue_t))
        FMSTR_TSA_MEMBER(encoderPospe_t,                    thRotElCos,              FMSTR_TSA_USERTYPE(pospeValue_t))
        FMSTR_TSA_MEMBER(encoderPospe_t,                    TrackObsrv,              FMSTR_TSA_USERTYPE(AMCLIB_TRACK_OBSRV_T_FLT))
        FMSTR_TSA_MEMBER(encoderPospe_t,                    s32MotorPpScale,         FMSTR_TSA_FRAC32)
        FMSTR_TSA_MEMBER(encoderPospe_t,                    s16MotorPpScaleShift,    FMSTR_TSA_FRAC16)
        FMSTR_TSA_MEMBER(encoderPospe_t,                    fltMotorPP,              FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(encoderPospe_t,                    counterOffset,           FMSTR_TSA_UINT16)
        FMSTR_TSA_MEMBER(encoderPospe_t,                    positionAccumulator,     FMSTR_TSA_SINT32)
        FMSTR_TSA_MEMBER(encoderPospe_t,                    positionGain,            FMSTR_TSA_FLOAT)

	    FMSTR_TSA_STRUCT(pospeValue_t)
			FMSTR_TSA_MEMBER(pospeValue_t,                  raw,                     FMSTR_TSA_FLOAT)
			FMSTR_TSA_MEMBER(pospeValue_t,                  filt,                    FMSTR_TSA_FLOAT)

    FMSTR_TSA_STRUCT(sensorLessPospe_t)
        FMSTR_TSA_MEMBER(sensorLessPospe_t,                 thRotEl,                 FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(sensorLessPospe_t,                 wRotEl,                  FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(sensorLessPospe_t,                 wRotElMatch_1,           FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(sensorLessPospe_t,                 wRotElMatch_2,           FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(sensorLessPospe_t,                 DQtoGaDeError,           FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(sensorLessPospe_t,                 iQUpperLimit,            FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(sensorLessPospe_t,                 iQLowerLimit,            FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(sensorLessPospe_t,                 sensorlessCnt,           FMSTR_TSA_UINT16)
        FMSTR_TSA_MEMBER(sensorLessPospe_t,                 TrackObsrv,              FMSTR_TSA_USERTYPE(AMCLIB_TRACK_OBSRV_T_FLT))
        FMSTR_TSA_MEMBER(sensorLessPospe_t,                 bEMFObs,                 FMSTR_TSA_USERTYPE(AMCLIB_BEMF_OBSRV_DQ_T_FLT))

    FMSTR_TSA_STRUCT(AMCLIB_TRACK_OBSRV_T_FLT)
        FMSTR_TSA_MEMBER(AMCLIB_TRACK_OBSRV_T_FLT,          pParamPI,                FMSTR_TSA_USERTYPE(GFLIB_CONTROLLER_PIAW_R_T_FLT))
        FMSTR_TSA_MEMBER(AMCLIB_TRACK_OBSRV_T_FLT,          pParamInteg,             FMSTR_TSA_USERTYPE(GFLIB_INTEGRATOR_TR_T_FLT))

    FMSTR_TSA_STRUCT(GFLIB_CONTROLLER_PIAW_R_T_FLT)
        FMSTR_TSA_MEMBER(GFLIB_CONTROLLER_PIAW_R_T_FLT,     fltCC1sc,                FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(GFLIB_CONTROLLER_PIAW_R_T_FLT,     fltCC2sc,                FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(GFLIB_CONTROLLER_PIAW_R_T_FLT,     fltUpperLimit,           FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(GFLIB_CONTROLLER_PIAW_R_T_FLT,     fltLowerLimit,           FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(GFLIB_CONTROLLER_PIAW_R_T_FLT,     fltAcc,                  FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(GFLIB_CONTROLLER_PIAW_R_T_FLT,     fltInErrK1,              FMSTR_TSA_FLOAT)

    FMSTR_TSA_STRUCT(GFLIB_INTEGRATOR_TR_T_FLT)
        FMSTR_TSA_MEMBER(GFLIB_INTEGRATOR_TR_T_FLT,         fltC1,                   FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(GFLIB_INTEGRATOR_TR_T_FLT,         fltInK1,                 FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(GFLIB_INTEGRATOR_TR_T_FLT,         fltState,                FMSTR_TSA_FLOAT)

    FMSTR_TSA_STRUCT(GDFLIB_FILTER_MA_T_FLT)
        FMSTR_TSA_MEMBER(GDFLIB_FILTER_MA_T_FLT,            fltAcc,                 FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(GDFLIB_FILTER_MA_T_FLT,            fltLambda,              FMSTR_TSA_FLOAT)

    FMSTR_TSA_STRUCT(AMCLIB_BEMF_OBSRV_DQ_T_FLT)
        FMSTR_TSA_MEMBER(AMCLIB_BEMF_OBSRV_DQ_T_FLT,        fltIGain,               FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(AMCLIB_BEMF_OBSRV_DQ_T_FLT,        fltUGain,               FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(AMCLIB_BEMF_OBSRV_DQ_T_FLT,        fltWIGain,              FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(AMCLIB_BEMF_OBSRV_DQ_T_FLT,        fltEGain,               FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(AMCLIB_BEMF_OBSRV_DQ_T_FLT,        pEObsrv,                FMSTR_TSA_USERTYPE(SWLIBS_2Syst_FLT))
        FMSTR_TSA_MEMBER(AMCLIB_BEMF_OBSRV_DQ_T_FLT,        pIObsrv,                FMSTR_TSA_USERTYPE(SWLIBS_2Syst_FLT))
        FMSTR_TSA_MEMBER(AMCLIB_BEMF_OBSRV_DQ_T_FLT,        pParamD,                FMSTR_TSA_USERTYPE(GFLIB_CONTROLLER_PIAW_R_T_FLT))
        FMSTR_TSA_MEMBER(AMCLIB_BEMF_OBSRV_DQ_T_FLT,        pParamQ,                FMSTR_TSA_USERTYPE(GFLIB_CONTROLLER_PIAW_R_T_FLT))
        FMSTR_TSA_MEMBER(AMCLIB_BEMF_OBSRV_DQ_T_FLT,        pIObsrvIn_1,            FMSTR_TSA_USERTYPE(SWLIBS_2Syst_FLT))

    FMSTR_TSA_STRUCT(SWLIBS_2Syst_FLT)
        FMSTR_TSA_MEMBER(SWLIBS_2Syst_FLT,                  fltArg1,                 FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(SWLIBS_2Syst_FLT,                  fltArg2,                 FMSTR_TSA_FLOAT)

    FMSTR_TSA_STRUCT(scalarControl_t)
        FMSTR_TSA_MEMBER(scalarControl_t,                   UmReq,                   FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(scalarControl_t,                   VHzRatioReq,             FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(scalarControl_t,                   VHzRatioReq_Shift,       FMSTR_TSA_SINT16)


    FMSTR_TSA_STRUCT(pmsmDrive_t)
        FMSTR_TSA_MEMBER(pmsmDrive_t,                       alignCntr,               FMSTR_TSA_UINT16)
		FMSTR_TSA_MEMBER(pmsmDrive_t,                       alignCntrInitValue,      FMSTR_TSA_UINT16)
        FMSTR_TSA_MEMBER(pmsmDrive_t,                       alignVoltage,            FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(pmsmDrive_t,                       svmSector,               FMSTR_TSA_UINT16)
        FMSTR_TSA_MEMBER(pmsmDrive_t,                       iDQFbck,                 FMSTR_TSA_USERTYPE(SWLIBS_2Syst_FLT))
        FMSTR_TSA_MEMBER(pmsmDrive_t,                       iAlBeFbck,               FMSTR_TSA_USERTYPE(SWLIBS_2Syst_FLT))
        FMSTR_TSA_MEMBER(pmsmDrive_t,                       iDQReqInLoop,            FMSTR_TSA_USERTYPE(SWLIBS_2Syst_FLT))
        FMSTR_TSA_MEMBER(pmsmDrive_t,                       iDQReqOutLoop,           FMSTR_TSA_USERTYPE(SWLIBS_2Syst_FLT))
        FMSTR_TSA_MEMBER(pmsmDrive_t,                       uDQReq,                  FMSTR_TSA_USERTYPE(SWLIBS_2Syst_FLT))
        FMSTR_TSA_MEMBER(pmsmDrive_t,                       uAlBeReq,                FMSTR_TSA_USERTYPE(SWLIBS_2Syst_FLT))
        FMSTR_TSA_MEMBER(pmsmDrive_t,                       uAlBeReqDCB,             FMSTR_TSA_USERTYPE(SWLIBS_2Syst_FLT))
        FMSTR_TSA_MEMBER(pmsmDrive_t,                       uAlBeReqDCBLim,          FMSTR_TSA_USERTYPE(SWLIBS_2Syst_FLT))
        FMSTR_TSA_MEMBER(pmsmDrive_t,                       uAlBEReqDCBTest,         FMSTR_TSA_USERTYPE(SWLIBS_2Syst_FLT))
        FMSTR_TSA_MEMBER(pmsmDrive_t,                       thTransform,             FMSTR_TSA_USERTYPE(SWLIBS_2Syst_FLT))
        FMSTR_TSA_MEMBER(pmsmDrive_t,                       iAbcFbck,                FMSTR_TSA_USERTYPE(SWLIBS_3Syst_FLT))
        FMSTR_TSA_MEMBER(pmsmDrive_t,                       pwmflt,                  FMSTR_TSA_USERTYPE(SWLIBS_3Syst_FLT))
        FMSTR_TSA_MEMBER(pmsmDrive_t,                       elimDcbRip,              FMSTR_TSA_USERTYPE(GMCLIB_ELIMDCBUSRIP_T_FLT))
        FMSTR_TSA_MEMBER(pmsmDrive_t,                       uDcbFilter,              FMSTR_TSA_USERTYPE(GDFLIB_FILTER_MA_T_FLT))
        FMSTR_TSA_MEMBER(pmsmDrive_t,                       fltUdcb,                 FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(pmsmDrive_t,                       pospeOpenLoop,           FMSTR_TSA_USERTYPE(openLoopPospe_t))
        FMSTR_TSA_MEMBER(pmsmDrive_t,                       pospeControl,            FMSTR_TSA_USERTYPE(pospeControl_t))
        FMSTR_TSA_MEMBER(pmsmDrive_t,                       pospeSensorless,         FMSTR_TSA_USERTYPE(sensorLessPospe_t))
        FMSTR_TSA_MEMBER(pmsmDrive_t,                       scalarControl,           FMSTR_TSA_USERTYPE(scalarControl_t))
        FMSTR_TSA_MEMBER(pmsmDrive_t,                       CurrentLoop,             FMSTR_TSA_USERTYPE(AMCLIB_CURRENT_LOOP_T_FLT))
        FMSTR_TSA_MEMBER(pmsmDrive_t,                       FwSpeedLoop,             FMSTR_TSA_USERTYPE(AMCLIB_FW_SPEED_LOOP_T_FLT))
        FMSTR_TSA_MEMBER(pmsmDrive_t,                       AlBeReqDCBLim,           FMSTR_TSA_USERTYPE(GFLIB_VECTORLIMIT_T_FLT))

    FMSTR_TSA_STRUCT(GDFLIB_FILTER_MA_T_FLT)
        FMSTR_TSA_MEMBER(GDFLIB_FILTER_MA_T_FLT,            fltAcc,                  FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(GDFLIB_FILTER_MA_T_FLT,            fltLambda,               FMSTR_TSA_FLOAT)

    FMSTR_TSA_STRUCT(SWLIBS_3Syst_FLT)
        FMSTR_TSA_MEMBER(SWLIBS_3Syst_FLT,                  fltArg1,                 FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(SWLIBS_3Syst_FLT,                  fltArg2,                 FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(SWLIBS_3Syst_FLT,                  fltArg3,                 FMSTR_TSA_FLOAT)

    FMSTR_TSA_STRUCT(GMCLIB_ELIMDCBUSRIP_T_FLT)
        FMSTR_TSA_MEMBER(GMCLIB_ELIMDCBUSRIP_T_FLT,         fltArgDcBusMsr,          FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(GMCLIB_ELIMDCBUSRIP_T_FLT,         fltModIndex,             FMSTR_TSA_FLOAT)

    FMSTR_TSA_STRUCT(AMCLIB_CURRENT_LOOP_T_FLT)
        FMSTR_TSA_MEMBER(AMCLIB_CURRENT_LOOP_T_FLT,         pPIrAWD,                 FMSTR_TSA_USERTYPE(GFLIB_CONTROLLER_PIAW_R_T_FLT))
        FMSTR_TSA_MEMBER(AMCLIB_CURRENT_LOOP_T_FLT,         pPIrAWQ,                 FMSTR_TSA_USERTYPE(GFLIB_CONTROLLER_PIAW_R_T_FLT))
        FMSTR_TSA_MEMBER(AMCLIB_CURRENT_LOOP_T_FLT,         pIDQReq,                 FMSTR_TSA_USERTYPE(FMSTR_TSA_POINTER))
        FMSTR_TSA_MEMBER(AMCLIB_CURRENT_LOOP_T_FLT,         pIDQFbck,                FMSTR_TSA_USERTYPE(FMSTR_TSA_POINTER))

    FMSTR_TSA_STRUCT(AMCLIB_FW_SPEED_LOOP_T_FLT)
        FMSTR_TSA_MEMBER(AMCLIB_FW_SPEED_LOOP_T_FLT,        pFilterW,                FMSTR_TSA_USERTYPE(GDFLIB_FILTER_MA_T_FLT))
        FMSTR_TSA_MEMBER(AMCLIB_FW_SPEED_LOOP_T_FLT,        pFilterFW,               FMSTR_TSA_USERTYPE(GDFLIB_FILTER_MA_T_FLT))
        FMSTR_TSA_MEMBER(AMCLIB_FW_SPEED_LOOP_T_FLT,        pPIpAWQ,                 FMSTR_TSA_USERTYPE(GFLIB_CONTROLLER_PIAW_P_T_FLT))
        FMSTR_TSA_MEMBER(AMCLIB_FW_SPEED_LOOP_T_FLT,        pPIpAWFW,                FMSTR_TSA_USERTYPE(GFLIB_CONTROLLER_PIAW_P_T_FLT))
        FMSTR_TSA_MEMBER(AMCLIB_FW_SPEED_LOOP_T_FLT,        pRamp,                   FMSTR_TSA_USERTYPE(GFLIB_RAMP_T_FLT))
        FMSTR_TSA_MEMBER(AMCLIB_FW_SPEED_LOOP_T_FLT,        pIQFbck,                 FMSTR_TSA_USERTYPE(FMSTR_TSA_POINTER))
        FMSTR_TSA_MEMBER(AMCLIB_FW_SPEED_LOOP_T_FLT,        pUQReq,                  FMSTR_TSA_USERTYPE(FMSTR_TSA_POINTER))
        FMSTR_TSA_MEMBER(AMCLIB_FW_SPEED_LOOP_T_FLT,        pUQLim,                  FMSTR_TSA_USERTYPE(FMSTR_TSA_POINTER))
        FMSTR_TSA_MEMBER(AMCLIB_FW_SPEED_LOOP_T_FLT,        fltUmaxDivImax,          FMSTR_TSA_USERTYPE(FMSTR_TSA_FLOAT))



    FMSTR_TSA_STRUCT(GFLIB_CONTROLLER_PIAW_P_T_FLT)
        FMSTR_TSA_MEMBER(GFLIB_CONTROLLER_PIAW_P_T_FLT,     fltPropGain,             FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(GFLIB_CONTROLLER_PIAW_P_T_FLT,     fltIntegGain,            FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(GFLIB_CONTROLLER_PIAW_P_T_FLT,     fltLowerLimit,           FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(GFLIB_CONTROLLER_PIAW_P_T_FLT,     fltUpperLimit,           FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(GFLIB_CONTROLLER_PIAW_P_T_FLT,     fltIntegPartK_1,         FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(GFLIB_CONTROLLER_PIAW_P_T_FLT,     fltInK_1,                FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(GFLIB_CONTROLLER_PIAW_P_T_FLT,     u16LimitFlag,            FMSTR_TSA_UINT16)

    FMSTR_TSA_STRUCT(GFLIB_RAMP_T_FLT)
        FMSTR_TSA_MEMBER(GFLIB_RAMP_T_FLT,                  fltState,                FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(GFLIB_RAMP_T_FLT,                  fltRampUp,               FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(GFLIB_RAMP_T_FLT,                  fltRampDown,             FMSTR_TSA_FLOAT)

    FMSTR_TSA_STRUCT(userControl_t)
        FMSTR_TSA_MEMBER(userControl_t,                     ledCounter,             FMSTR_TSA_UINT32)
        FMSTR_TSA_MEMBER(userControl_t,                     ledFlashing,            FMSTR_TSA_UINT32)
        FMSTR_TSA_MEMBER(userControl_t,                     cntSpeedUp,             FMSTR_TSA_UINT32)
        FMSTR_TSA_MEMBER(userControl_t,                     cntSpeedDown,           FMSTR_TSA_UINT32)
        FMSTR_TSA_MEMBER(userControl_t,                     cntAppOff,              FMSTR_TSA_UINT32)
        FMSTR_TSA_MEMBER(userControl_t,                     btSpeedUp,              FMSTR_TSA_UINT8)
        FMSTR_TSA_MEMBER(userControl_t,                     btSpeedDown,            FMSTR_TSA_UINT8)
        FMSTR_TSA_MEMBER(userControl_t,                     btFlipFlop,             FMSTR_TSA_UINT8)
        FMSTR_TSA_MEMBER(userControl_t,                     btFlipFlopTemp,         FMSTR_TSA_UINT8)
        FMSTR_TSA_MEMBER(userControl_t,                     controlMode,            FMSTR_TSA_USERTYPE(controlMode_t))
        FMSTR_TSA_MEMBER(userControl_t,                     FOCcontrolMode,         FMSTR_TSA_USERTYPE(controlStructMode_t))
        FMSTR_TSA_MEMBER(userControl_t,                     switchAppOnOff,         FMSTR_TSA_UINT8)
        FMSTR_TSA_MEMBER(userControl_t,                     switchAppOnOffState,    FMSTR_TSA_UINT8)
        FMSTR_TSA_MEMBER(userControl_t,                     switchFaultClear,       FMSTR_TSA_UINT8)
        FMSTR_TSA_MEMBER(userControl_t,                     switchAppReset,         FMSTR_TSA_UINT8)
        FMSTR_TSA_MEMBER(userControl_t,                     readFault,              FMSTR_TSA_UINT8)

    FMSTR_TSA_STRUCT(driveStates_t)
        FMSTR_TSA_MEMBER(driveStates_t,                     state,                  FMSTR_TSA_USERTYPE(AppStates))
        FMSTR_TSA_MEMBER(driveStates_t,                     event,                  FMSTR_TSA_USERTYPE(AppEvents))
        FMSTR_TSA_MEMBER(driveStates_t,                     usrControl,             FMSTR_TSA_USERTYPE(userControl_t))
        FMSTR_TSA_MEMBER(driveStates_t,                     loadDefSetting,         FMSTR_TSA_UINT8)

    FMSTR_TSA_STRUCT(gd3000Status_t)
        FMSTR_TSA_MEMBER(gd3000Status_t,                    R,                      FMSTR_TSA_UINT16)

    FMSTR_TSA_STRUCT(mcuFaultStatus_t)
        FMSTR_TSA_MEMBER(mcuFaultStatus_t,                  R,                      FMSTR_TSA_UINT16)

    FMSTR_TSA_STRUCT(stMachineFaultStatus_t)
        FMSTR_TSA_MEMBER(stMachineFaultStatus_t,            R,                      FMSTR_TSA_UINT16)

    FMSTR_TSA_STRUCT(motorFaultStatus_t)
        FMSTR_TSA_MEMBER(motorFaultStatus_t,                R,                      FMSTR_TSA_UINT16)

    FMSTR_TSA_STRUCT(fm_scale_t)
        FMSTR_TSA_MEMBER(fm_scale_t,                        speed_w_e,              FMSTR_TSA_UINT32)
        FMSTR_TSA_MEMBER(fm_scale_t,                        speed_n_m,              FMSTR_TSA_UINT32)
        FMSTR_TSA_MEMBER(fm_scale_t,                        speed_ramp,             FMSTR_TSA_UINT32)
        FMSTR_TSA_MEMBER(fm_scale_t,                        position,               FMSTR_TSA_UINT32)

    FMSTR_TSA_STRUCT(appFaultStatus_t)
        FMSTR_TSA_MEMBER(appFaultStatus_t,                  mcu,                    FMSTR_TSA_USERTYPE(mcuFaultStatus_t))
        FMSTR_TSA_MEMBER(appFaultStatus_t,                  gd3000,                 FMSTR_TSA_UINT8)
        FMSTR_TSA_MEMBER(appFaultStatus_t,                  stateMachine,           FMSTR_TSA_USERTYPE(stMachineFaultStatus_t))
        FMSTR_TSA_MEMBER(appFaultStatus_t,                  motor,                  FMSTR_TSA_USERTYPE(motorFaultStatus_t))

    FMSTR_TSA_STRUCT(tpp_drv_config_t)
        FMSTR_TSA_MEMBER(tpp_drv_config_t,                  en1PinInstance,         FMSTR_TSA_USERTYPE(aml_instance_t))
        FMSTR_TSA_MEMBER(tpp_drv_config_t,                  en1PinIndex,            FMSTR_TSA_UINT8)
        FMSTR_TSA_MEMBER(tpp_drv_config_t,                  en2PinInstance,         FMSTR_TSA_USERTYPE(aml_instance_t))
        FMSTR_TSA_MEMBER(tpp_drv_config_t,                  en2PinIndex,            FMSTR_TSA_UINT8)
        FMSTR_TSA_MEMBER(tpp_drv_config_t,                  rstPinInstance,         FMSTR_TSA_USERTYPE(aml_instance_t))
        FMSTR_TSA_MEMBER(tpp_drv_config_t,                  rstPinIndex,            FMSTR_TSA_UINT8)
        FMSTR_TSA_MEMBER(tpp_drv_config_t,                  spiInstance,            FMSTR_TSA_USERTYPE(aml_instance_t))
        FMSTR_TSA_MEMBER(tpp_drv_config_t,                  spiTppConfig,           FMSTR_TSA_USERTYPE(spi_tpp_config_t))
        FMSTR_TSA_MEMBER(tpp_drv_config_t,                  csPinInstance,          FMSTR_TSA_USERTYPE(aml_instance_t))
        FMSTR_TSA_MEMBER(tpp_drv_config_t,                  csPinIndex,             FMSTR_TSA_UINT8)
        FMSTR_TSA_MEMBER(tpp_drv_config_t,                  deviceConfig,           FMSTR_TSA_USERTYPE(tpp_device_data_t))

    FMSTR_TSA_STRUCT(measModule_t)
        FMSTR_TSA_MEMBER(measModule_t,                      measured,               FMSTR_TSA_USERTYPE(measResult_t))
        FMSTR_TSA_MEMBER(measModule_t,                      offset,                 FMSTR_TSA_USERTYPE(offset_t))
        FMSTR_TSA_MEMBER(measModule_t,                      param,                  FMSTR_TSA_USERTYPE(calibParam_t))
        FMSTR_TSA_MEMBER(measModule_t,                      flag,                   FMSTR_TSA_USERTYPE(calibFlags_t))
        FMSTR_TSA_MEMBER(measModule_t,                      calibCntr,              FMSTR_TSA_UINT16)

    FMSTR_TSA_STRUCT(meas_t)
        FMSTR_TSA_MEMBER(meas_t,                            raw,                    FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(meas_t,                            filt,                   FMSTR_TSA_FLOAT)

    FMSTR_TSA_STRUCT(measResult_t)
        FMSTR_TSA_MEMBER(measResult_t,                      fltPhA,                 FMSTR_TSA_USERTYPE(meas_t))
        FMSTR_TSA_MEMBER(measResult_t,                      fltPhB,                 FMSTR_TSA_USERTYPE(meas_t))
        FMSTR_TSA_MEMBER(measResult_t,                      fltPhC,                 FMSTR_TSA_USERTYPE(meas_t))
        FMSTR_TSA_MEMBER(measResult_t,                      fltUdcb,                FMSTR_TSA_USERTYPE(meas_t))
        FMSTR_TSA_MEMBER(measResult_t,                      fltTemp,                FMSTR_TSA_USERTYPE(meas_t))

    FMSTR_TSA_STRUCT(offsetBasic_t)
        FMSTR_TSA_MEMBER(offsetBasic_t,                     fltOffset,              FMSTR_TSA_FLOAT)
        FMSTR_TSA_MEMBER(offsetBasic_t,                     filtParam,              FMSTR_TSA_USERTYPE(GDFLIB_FILTER_MA_T_FLT))

    FMSTR_TSA_STRUCT(offset_t)
        FMSTR_TSA_MEMBER(offset_t,                          fltPhA,                 FMSTR_TSA_USERTYPE(offsetBasic_t))
        FMSTR_TSA_MEMBER(offset_t,                          fltPhB,                 FMSTR_TSA_USERTYPE(offsetBasic_t))
        FMSTR_TSA_MEMBER(offset_t,                          fltPhC,                 FMSTR_TSA_USERTYPE(offsetBasic_t))
        FMSTR_TSA_MEMBER(offset_t,                          fltUdcb,                FMSTR_TSA_USERTYPE(offsetBasic_t))
        FMSTR_TSA_MEMBER(offset_t,                          fltTemp,                FMSTR_TSA_USERTYPE(offsetBasic_t))

    FMSTR_TSA_STRUCT(calibParam_t)
        FMSTR_TSA_MEMBER(calibParam_t,                      u16CalibSamples,        FMSTR_TSA_UINT16)

    FMSTR_TSA_STRUCT(calibFlags_t)
        FMSTR_TSA_MEMBER(calibFlags_t,                      R,                      FMSTR_TSA_UINT16)

    FMSTR_TSA_STRUCT(tpp_drv_config_t)
        FMSTR_TSA_MEMBER(tpp_drv_config_t,                  en1PinInstance,         FMSTR_TSA_USERTYPE(aml_instance_t))
        FMSTR_TSA_MEMBER(tpp_drv_config_t,                  en1PinIndex,            FMSTR_TSA_UINT8)
        FMSTR_TSA_MEMBER(tpp_drv_config_t,                  en2PinInstance,         FMSTR_TSA_USERTYPE(aml_instance_t))
        FMSTR_TSA_MEMBER(tpp_drv_config_t,                  en2PinIndex,            FMSTR_TSA_UINT8)
        FMSTR_TSA_MEMBER(tpp_drv_config_t,                  rstPinInstance,         FMSTR_TSA_USERTYPE(aml_instance_t))
        FMSTR_TSA_MEMBER(tpp_drv_config_t,                  rstPinIndex,            FMSTR_TSA_UINT8)
        FMSTR_TSA_MEMBER(tpp_drv_config_t,                  spiInstance,            FMSTR_TSA_USERTYPE(aml_instance_t))
        FMSTR_TSA_MEMBER(tpp_drv_config_t,                  spiTppConfig,           FMSTR_TSA_USERTYPE(spi_tpp_config_t))
        FMSTR_TSA_MEMBER(tpp_drv_config_t,                  csPinInstance,          FMSTR_TSA_USERTYPE(aml_instance_t))
        FMSTR_TSA_MEMBER(tpp_drv_config_t,                  csPinIndex,             FMSTR_TSA_UINT8)
        FMSTR_TSA_MEMBER(tpp_drv_config_t,                  deviceConfig,           FMSTR_TSA_USERTYPE(tpp_device_data_t))

    FMSTR_TSA_STRUCT(tpp_device_data_t)
        FMSTR_TSA_MEMBER(tpp_device_data_t,                 opMode,                 FMSTR_TSA_USERTYPE(tpp_device_mode_t))
        FMSTR_TSA_MEMBER(tpp_device_data_t,                 statusRegister,         FMSTR_TSA_UINT8)
        FMSTR_TSA_MEMBER(tpp_device_data_t,                 intMask0,               FMSTR_TSA_UINT8)
        FMSTR_TSA_MEMBER(tpp_device_data_t,                 intMask1,               FMSTR_TSA_UINT8)
        FMSTR_TSA_MEMBER(tpp_device_data_t,                 modeMask,               FMSTR_TSA_UINT8)
        FMSTR_TSA_MEMBER(tpp_device_data_t,                 deadtime,               FMSTR_TSA_UINT16)

    FMSTR_TSA_STRUCT(GFLIB_INTEGRATOR_TR_T_F32)
        FMSTR_TSA_MEMBER(GFLIB_INTEGRATOR_TR_T_F32,         f32State,               FMSTR_TSA_FRAC32)
        FMSTR_TSA_MEMBER(GFLIB_INTEGRATOR_TR_T_F32,         f32InK1,                FMSTR_TSA_FRAC32)
        FMSTR_TSA_MEMBER(GFLIB_INTEGRATOR_TR_T_F32,         f32C1,                  FMSTR_TSA_FRAC32)
        FMSTR_TSA_MEMBER(GFLIB_INTEGRATOR_TR_T_F32,         u16NShift,              FMSTR_TSA_UINT16)

FMSTR_TSA_TABLE_END()

/* TSA table list */
FMSTR_TSA_TABLE_LIST_BEGIN()
    FMSTR_TSA_TABLE(S32K_PMSM)
FMSTR_TSA_TABLE_LIST_END()

#endif /* TSA_TABLE_H_ */
