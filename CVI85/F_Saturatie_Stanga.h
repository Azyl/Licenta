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
#define  PANEL_OK_PARAM_F_SAT_S           2       /* callback function: ok_param_f_sat_s */
#define  PANEL_F_Saturatie_Stanga_A       3
#define  PANEL_F_Saturatie_Stanga_B       4
#define  PANEL_REV_S_S                    5       /* callback function: rev_s_s */
#define  PANEL_PICTURE_F_SAT_S            6


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */ 

int  CVICALLBACK ok_param_f_sat_s(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK rev_s_s(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
