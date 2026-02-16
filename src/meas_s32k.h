/*******************************************************************************
*   Project      : FRDM_A_S32K312_MC_PMSM_FOC_2Sh
*   Version      : 1.0
*   RTD Version  : 7.0.0
*   Brief description  :
*   File contains declaration of functions and structures related to
*   analog quantities capturing.
*
*   Copyright 2022, 2023, 2026 NXP
*
*   NXP Proprietary. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
*******************************************************************************/
#ifndef _MEAS_S32K_H_
#define _MEAS_S32K_H_

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Adc_Sar_Ip.h"
#include "Bctu_Ip.h"
#include "config\PMSM_appconfig.h"
#include "gdflib.h"
#include "gflib.h"
#include "gmclib.h"

/*==================================================================================================
*                              STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

typedef struct
{
    tFloat    raw;   /*! raw value */
    tFloat    filt;  /*! filtered value */
}meas_t;

/*------------------------------------------------------------------------*//*!
@brief  Structure containing measured raw values
*//*-------------------------------------------------------------------------*/
typedef struct
{
    meas_t    fltPhA;     /* Measured phase A current */
    meas_t    fltPhB;     /* Measured phase B current */
    meas_t    fltPhC;     /* Measured phase C current */
    meas_t    fltUdcb;    /* Measured DC bus voltage */
    meas_t    fltTemp;    /* Measured temperature */
}measResult_t;

typedef struct
{
    tFloat                    fltOffset;   /* raw value */
    GDFLIB_FILTER_MA_T_FLT    filtParam;   /* filter parameters */
}offsetBasic_t;


/*------------------------------------------------------------------------*//*!
@brief  Structure containing variables for software DC offset calibration.
*//*-------------------------------------------------------------------------*/
typedef struct
{
    offsetBasic_t    fltPhA;         /* DC offset measured on phase A current */
    offsetBasic_t    fltPhB;         /* DC offset measured on phase B current */
    offsetBasic_t    fltPhC;         /* DC offset measured on phase C current */
    offsetBasic_t    fltUdcb;        /* DC offset measured on DC bus voltage */
    offsetBasic_t    fltTemp;        /* DC offset measured on temperature */
}offset_t;


/*------------------------------------------------------------------------*//*!
@brief  Structure containing variables to configure Calibration on the application
        level.
*//*-------------------------------------------------------------------------*/
typedef struct
{
    tU16     u16CalibSamples; /* Number of samples taken for calibration */
}calibParam_t;

/*------------------------------------------------------------------------*//*!
@brief  Union containing module operation flags.
*//*-------------------------------------------------------------------------*/
typedef union
{
    tU16 R;
    struct {
        tU16               :14; /* RESERVED */
        tU16 calibDone     :1;  /* DC offset calibration done */
        tU16 calibInitDone :1;  /* initial setup for DC offset calibration done */
    } B;
}calibFlags_t;

/*------------------------------------------------------------------------*//*!
@brief  Module structure containing measurement related variables.
*//*-------------------------------------------------------------------------*/
typedef struct
{
    measResult_t        measured;
    offset_t            offset;
    calibParam_t        param;
    calibFlags_t        flag;
    tU16                calibCntr;
}measModule_t;

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
extern tBool MEAS_Clear(measModule_t *ptr);
extern tBool MEAS_CalibCurrentSense(measModule_t *ptr, tU16 svmSector);
extern tBool MEAS_Get3PhCurrent(measModule_t *ptr, SWLIBS_3Syst_FLT *i, tU16 svmSector);
extern tBool MEAS_GetUdcVoltage(measModule_t *ptr, GDFLIB_FILTER_MA_T *uDcbFilter);

#endif /* _MEAS_S32K_H_ */
