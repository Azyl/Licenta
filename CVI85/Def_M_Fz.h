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
#define  PANEL_DEF_F_FZ                   2       /* callback function: def_f_fz */
#define  PANEL_DEF_T_M                    3       /* callback function: def_t_m */
#define  PANEL_DEF_M_FZ                   4       /* callback function: def_m_fz */
#define  PANEL_GRAPH_F_Y                  5
#define  PANEL_GRAPH_F_dX                 6
#define  PANEL_GRAPH_F_X                  7
#define  PANEL_GRAPH_F                    8
#define  PANEL_REV_D_M                    9       /* callback function: rev_d_m */
#define  PANEL_ETICHETA_M                 10      /* callback function: eticheta_m */
#define  PANEL_TEXTMSG_2                  11
#define  PANEL_NR_M_F                     12      /* callback function: nr_m_f */
#define  PANEL_RADIOBUTTON_F_F            13      /* callback function: radiobutton_f_f */
#define  PANEL_RADIOBUTTON_M_F            14      /* callback function: radiobutton_m_f */
#define  PANEL_PARAM_D                    15      /* callback function: param_a */
#define  PANEL_PARAM_C                    16      /* callback function: param_a */
#define  PANEL_PARAM_B                    17      /* callback function: param_a */
#define  PANEL_PARAM_A                    18      /* callback function: param_a */
#define  PANEL_PICTURE_M                  19


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */ 

int  CVICALLBACK def_f_fz(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK def_m_fz(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK def_t_m(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK eticheta_m(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK nr_m_f(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK param_a(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK radiobutton_f_f(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK radiobutton_m_f(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK rev_d_m(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
