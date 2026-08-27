/*******************************************************************************
*   Project      : FRDM_A_S32K312_MC_PMSM_FOC_2Sh
*   Version      : 1.0
*   RTD Version  : 7.0.1
*   Brief description  :
*   File contains declaration of structures and functions needed
*   for application state machine.
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
#ifndef _STATE_MACHINE_FRAME_H
#define _STATE_MACHINE_FRAME_H

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define TURNED_ON    0x1
#define TURNED_OFF   0x0

#ifndef true
#define true  ((tBool)1)
#endif

#ifndef false
#define false ((tBool)0)
#endif

/*==================================================================================================
*                              STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef enum {
    init            = 0,
    fault           = 1,
    ready           = 2,
    calib           = 3,
    align           = 4,
    run             = 5
}AppStates;         /* Application state identification user type*/

typedef enum {
    e_fault         = 0,
    e_fault_clear   = 1,
    e_init          = 2,
    e_init_done     = 3,
    e_ready         = 4,
    e_app_on        = 5,
    e_calib         = 6,
    e_calib_done    = 7,
    e_align         = 8,
    e_align_done    = 9,
    e_run           = 10,
    e_app_off       = 11
}AppEvents;         /* Application event identification user type*/

typedef void (*PFCN_VOID_STATES)(void); /* pointer to function */
typedef void (*PFCN_VOID_LED)(void); /* pointer to function*/
extern PFCN_VOID_STATES StateTable[12][6];
extern PFCN_VOID_LED StateLED[6];

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
/* Application control*/
extern void StateFault(void);
extern void StateInit(void);
extern void StateReady(void);
extern void StateCalib(void);
extern void StateAlign(void);
extern void StateRun(void);

/* LED control*/
extern void StateRGBLedOFF(void);
extern void StateRGBLedBlueON(void);
extern void StateRGBLedRedON(void);
extern void StateRGBLedGreenON(void);
extern void StateRGBLedGreenFlashing(void);

#endif //_STATE_MACHINE_FRAME_H
