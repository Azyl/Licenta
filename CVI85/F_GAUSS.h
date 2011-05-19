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
#define  PANEL_OK_PARAM_F_GAUSS           2       /* callback function: ok_param_f_sat_gauss */
#define  PANEL_F_GAUSS_S                  3
#define  PANEL_F_GAUSS_C                  4


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */ 

int  CVICALLBACK ok_param_f_sat_gauss(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
