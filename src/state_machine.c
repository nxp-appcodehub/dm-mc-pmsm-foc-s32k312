/*******************************************************************************
*   Project      : FRDM_A_S32K312_MC_PMSM_FOC_2Sh
*   Version      : 1.0
*   RTD Version  : 7.0.0
*   Brief description  :
*   File contains definition of the application state machine.
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
/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "state_machine.h"

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

PFCN_VOID_STATES StateTable[12][6]={
    /* Actual State ->         'Init'           'Fault'         'Ready'         'Calib'         'Align'         'Run'*/
    /* e_fault          */ { StateFault,     StateFault,     StateFault,     StateFault,     StateFault,     StateFault},
    /* e_fault_clear    */ { StateFault,     StateInit,      StateFault,     StateFault,     StateFault,     StateFault},
    /* e_init           */ { StateInit,      StateFault,     StateFault,     StateFault,     StateFault,     StateFault},
    /* e_init_done      */ { StateReady,     StateFault,     StateFault,     StateFault,     StateFault,     StateFault},
    /* e_ready          */ { StateFault,     StateFault,     StateReady,     StateFault,     StateFault,     StateFault},
    /* e_app_on         */ { StateFault,     StateFault,     StateCalib,     StateFault,     StateFault,     StateFault},
    /* e_calib          */ { StateFault,     StateFault,     StateFault,     StateCalib,     StateFault,     StateFault},
    /* e_calib_done     */ { StateFault,     StateFault,     StateFault,     StateAlign,     StateFault,     StateFault},
    /* e_align          */ { StateFault,     StateFault,     StateFault,     StateFault,     StateAlign,     StateFault},
    /* e_align_done     */ { StateFault,     StateFault,     StateFault,     StateFault,     StateRun,       StateFault},
    /* e_run            */ { StateFault,     StateFault,     StateFault,     StateFault,     StateFault,     StateRun},
    /* e_app_off        */ { StateFault,     StateFault,     StateReady,     StateInit,      StateInit,      StateInit}
};

/* Actual State ->                'Init'           'Fault'             'Ready'                   'Calib'                    'Align'            'Run'*/
PFCN_VOID_LED StateLED[6] = {StateRGBLedOFF, StateRGBLedRedON, StateRGBLedGreenON, StateRGBLedGreenFlashing, StateRGBLedGreenFlashing, StateRGBLedBlueON};
