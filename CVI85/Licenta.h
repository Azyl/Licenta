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
#define  PANEL_CONFIG_COM                 2       /* callback function: config_com */
#define  PANEL_CLOSE                      3       /* callback function: close */
#define  PANEL_LED_SERIALA                4
#define  PANEL_GRAPH                      5
#define  PANEL_TESTB                      6       /* callback function: testb */
#define  PANEL_SELECT_MOD_SIM             7       /* callback function: select_mod_sim */
#define  PANEL_TEXTBOX_2                  8
#define  PANEL_TEXTBOX                    9
#define  PANEL_RESCRIERE                  10      /* callback function: rescriere */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */ 

int  CVICALLBACK close(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK config_com(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK rescriere(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK select_mod_sim(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK testb(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
