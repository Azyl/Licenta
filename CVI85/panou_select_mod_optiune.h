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
#define  PANEL_OPT_DEFINITA               2       /* callback function: opt_definita */
#define  PANEL_OPT_PRESTABILIT            3       /* callback function: opt_prestabilit */
#define  PANEL_NR_D_F_X                   4
#define  PANEL_NR_D_F_dX                  5
#define  PANEL_NR_D_F_Y                   6
#define  PANEL_TEXTMSG_V_X_P              7
#define  PANEL_TEXTMSG_V_dX_P             8
#define  PANEL_TEXTMSG_V_Y_P_NR           9
#define  PANEL_TEXTMSG_V_dX_P_NR          10
#define  PANEL_TEXTMSG_V_X_P_NR           11
#define  PANEL_TEXTMSG_V_Y_P              12
#define  PANEL_TEXTMSG_V_X_P_NR_F         13
#define  PANEL_TEXTMSG_V_dX_P_NR_F        14
#define  PANEL_TEXTMSG_V_Y_P_NR_F         15
#define  PANEL_TEXTMSG_V_X_T_P            16
#define  PANEL_TEXTMSG_V_dX_T_P           17
#define  PANEL_TEXTMSG_V_Y_P_T            18
#define  PANEL_BACK_M                     19      /* callback function: back_m */
#define  PANEL_RULARE_PRESTABILITA_U      20      /* callback function: rulare_d_u */
#define  PANEL_RULARE_PRESTABILITA        21
#define  PANEL_REG_BRF_D                  22      /* callback function: reg_brf_d */
#define  PANEL_SELECT_M_D                 23      /* callback function: select_m_d */
#define  PANEL_TEXTMSG_F_A                24
#define  PANEL_TEXTMSG_BRF                25
#define  PANEL_TEXTBOX1                   26
#define  PANEL_TEXTMSG_M_DEF              27


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */ 

int  CVICALLBACK back_m(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK opt_definita(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK opt_prestabilit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK reg_brf_d(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK rulare_d_u(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK select_m_d(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
