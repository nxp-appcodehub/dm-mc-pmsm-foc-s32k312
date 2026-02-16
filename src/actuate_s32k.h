/*******************************************************************************
*   Project      : FRDM_A_S32K312_MC_PMSM_FOC_2Sh
*   Version      : 1.0
*   RTD Version  : 7.0.0
*   Brief description  :
*   File contains declaration of functions needed for inverter voltage control.
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
#ifndef _ACTUATE_S32K_H_
#define _ACTUATE_S32K_H_

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Emios_Pwm_Ip.h"
#include "gflib.h"
#include "gdflib.h"
#include "gmclib.h"
#include "Lcu_Ip.h"
#include "Emios_Mcl_Ip.h"

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define APP_START_SEC_CODE_ITCM
#include "App_MemMap.h"

extern tBool    ACTUATE_EnableOutput(void);
extern tBool    ACTUATE_DisableOutput(void);
extern tBool    ACTUATE_SetDutycycle(SWLIBS_3Syst_FLT *fltpwm);
#define APP_STOP_SEC_CODE_ITCM
#include "App_MemMap.h"
#endif /* _ACTUATES_S32K_H_ */
