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
#define  PANEL_F_Z_SHAPE                  2       /* callback function: f_z_shape */
#define  PANEL_F_S_SHAPE                  3       /* callback function: f_s_shape */
#define  PANEL_F_GAUSIANA                 4       /* callback function: f_gausiana */
#define  PANEL_F_SATURATIE_DREAPTA        5       /* callback function: f_saturatie_dreapta */
#define  PANEL_F_SATURATIE_STANGA         6       /* callback function: f_saturatie_stanga */
#define  PANEL_F_TRAPEZOIDALA             7       /* callback function: f_trapezoidala */
#define  PANEL_F_TRIUNGHIULARA            8       /* callback function: f_triunghiulara */
#define  PANEL_PIC_TRIUNGHIULARA          9
#define  PANEL_PICT_TRAPEZOIDALA          10
#define  PANEL_PICT_SATURATIE             11


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */ 

int  CVICALLBACK f_gausiana(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK f_s_shape(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK f_saturatie_dreapta(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK f_saturatie_stanga(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK f_trapezoidala(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK f_triunghiulara(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK f_z_shape(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
