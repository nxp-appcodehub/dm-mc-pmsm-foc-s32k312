/*******************************************************************************
*   Project      : FRDM_A_S32K312_MC_PMSM_FOC_2Sh
*   Version      : 1.0
*   RTD Version  : 7.0.0
*   Brief description  :
*   File contains declaration of structures and functions needed
*   for encoder sensor processing.
*
*   Copyright 2023, 2026 NXP
*
*   NXP Proprietary. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
*******************************************************************************/
#ifndef POSPE_SENSOR_H_
#define POSPE_SENSOR_H_

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "gflib.h"
#include "amclib.h"
#include "config\PMSM_appconfig.h"
#include "Emios_Icu_Ip.h"

/*==================================================================================================
*                                       ENCODER DEFINES
==================================================================================================*/
/* Encoder calculated values (for quadrature mode: 4 edges per pulse)
 * These are derived from ENC_PULSES defined in PMSM_appconfig.h */
#define ENC_COUNTS_PER_REV              (ENC_PULSES * 4)
#define ENC_POSITION_DIVISOR            ((ENC_COUNTS_PER_REV / 2) - 1)

/*==================================================================================================
*                              STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef struct
{
    tFloat    raw;   /*! raw value */
    tFloat    filt;  /*! filtered value */
}pospeValue_t;

typedef struct
{
    tFloat                              thRotMec;
    pospeValue_t                        wRotMec;
    pospeValue_t                        thRotEl;
    pospeValue_t                        thRotElk1;
    pospeValue_t                        wRotEl;
    tFloat                              thRoErr;
    pospeValue_t                        thRotMecSin;
    pospeValue_t                        thRotMecCos;
    pospeValue_t                        thRotElSin;
    pospeValue_t                        thRotElCos;
    AMCLIB_TRACK_OBSRV_T_FLT            TrackObsrv;
    tFrac32                             s32MotorPpScale;
    tFrac16                             s16MotorPpScaleShift;
    tFloat                              fltMotorPP;
    uint16_t                            counterOffset;      /* Encoder offset (CW-CCW at alignment) */
    int32_t                             positionAccumulator;/* Position accumulator (prevents overflow) */
    tFloat                              positionGain;       /* Position scaling gain */
}encoderPospe_t;

/*==================================================================================================
                                    FUNCTION PROTOTYPES
==================================================================================================*/
extern tBool POSPE_GetPospeElEnc(encoderPospe_t *ptr);
extern tBool POSPE_ClearPospeElEnc(encoderPospe_t *ptr);

#endif /* POSPE_SENSOR_H_ */
