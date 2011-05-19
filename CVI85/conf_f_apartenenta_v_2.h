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
#define  PANEL_GRAPH_M_F                  2
#define  PANEL_REV_D_M_F                  3       /* callback function: rev_d_m_f */
#define  PANEL_TEXTMSG_DF_T               4
#define  PANEL_TEXTMSG_DF_P               5
#define  PANEL_TIP_F                      6
#define  PANEL_PARAM_P_F                  7


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */ 

int  CVICALLBACK rev_d_m_f(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
