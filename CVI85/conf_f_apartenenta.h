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
#define  PANEL_CONF_F_Y                   2       /* callback function: conf_f_y */
#define  PANEL_CONF_F_DX                  3       /* callback function: conf_f_dx */
#define  PANEL_CONF_F_X                   4       /* callback function: conf_fa_x */
#define  PANEL_TERMINARE_CONF_FA          5       /* callback function: terminare_conf_fa */
#define  PANEL_GRAPH_F_D_X                6
#define  PANEL_GRAPH_F_D_dX               7
#define  PANEL_GRAPH_F_D_Y                8
#define  PANEL_REVENIRE_A_MOD_S           9       /* callback function: revenire_a_mod_s */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */ 

int  CVICALLBACK conf_f_dx(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK conf_f_y(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK conf_fa_x(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK revenire_a_mod_s(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK terminare_conf_fa(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
