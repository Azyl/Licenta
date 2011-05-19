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
#define  PANEL_AC_F_CONF                  2       /* callback function: ac_f_conf */
#define  PANEL_NR_F                       3       /* callback function: NR_F */
#define  PANEL_DEF_F_10                   4       /* callback function: def_f_10 */
#define  PANEL_DEF_F_9                    5       /* callback function: def_f_9 */
#define  PANEL_GRAPH_F_D_10               6
#define  PANEL_GRAPH_F_D_9                7
#define  PANEL_GRAPH_F_D_8                8
#define  PANEL_GRAPH_F_D_7                9
#define  PANEL_GRAPH_F_D_6                10
#define  PANEL_GRAPH_F_D_5                11
#define  PANEL_GRAPH_F_D_4                12
#define  PANEL_GRAPH_F_D_3                13
#define  PANEL_GRAPH_F_D_2                14
#define  PANEL_GRAPH_F_D_1                15
#define  PANEL_DEF_F_8                    16      /* callback function: def_f_8 */
#define  PANEL_DEF_F_7                    17      /* callback function: def_f_7 */
#define  PANEL_DEF_F_6                    18      /* callback function: def_f_6 */
#define  PANEL_DEF_F_5                    19      /* callback function: def_f_5 */
#define  PANEL_DEF_F_4                    20      /* callback function: def_f_4 */
#define  PANEL_DEF_F_3                    21      /* callback function: def_f_3 */
#define  PANEL_DEF_F_2                    22      /* callback function: def_f_2 */
#define  PANEL_DEF_F_1                    23      /* callback function: def_f_1 */
#define  PANEL_REVENIRE_CONF_F            24


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */ 

int  CVICALLBACK ac_f_conf(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK def_f_1(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK def_f_10(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK def_f_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK def_f_3(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK def_f_4(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK def_f_5(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK def_f_6(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK def_f_7(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK def_f_8(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK def_f_9(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK NR_F(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
