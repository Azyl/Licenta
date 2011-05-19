/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/* Copyright (c) National Instruments 2011. All Rights Reserved.          */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL                            1
#define  PANEL_REVENIRE_S_M               2       /* callback function: revenire_s_m */
#define  PANEL_ACC_S_M                    3
#define  PANEL_RING_S_MET_D               4       /* callback function: ring_s_met_d */
#define  PANEL_NUMERIC_NR_INT             5       /* callback function: numeric_nr_int */
#define  PANEL_PICTURE_M_D                6


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */ 

int  CVICALLBACK numeric_nr_int(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK revenire_s_m(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ring_s_met_d(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
