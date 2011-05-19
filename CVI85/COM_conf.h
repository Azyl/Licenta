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

#define  P_COM_CONF                       1
#define  P_COM_CONF_PORT_NAME             2
#define  P_COM_CONF_ERROR                 3       /* callback function: ErrorCallBack */
#define  P_COM_CONF_COMSTATUS             4       /* callback function: ComStatusCallBack */
#define  P_COM_CONF_VITEZA                5
#define  P_COM_CONF_PARITATE              6
#define  P_COM_CONF_NR_BITI               7
#define  P_COM_CONF_NR_B_STOP             8
#define  P_COM_CONF_INCHIDE               9       /* callback function: inchide */
#define  P_COM_CONF_PROGRAMEAZA           10      /* callback function: programeaza */
#define  P_COM_CONF_REV_COM_CONF          11      /* callback function: rev_com_conf */
#define  P_COM_CONF_TEXTBOX_I_H           12
#define  P_COM_CONF_TEXTBOX_O_H           13
#define  P_COM_CONF_TEXTBOX_I             14
#define  P_COM_CONF_SPLITTER_2            15
#define  P_COM_CONF_SPLITTER              16
#define  P_COM_CONF_GET_S_O               17      /* callback function: get_s_o */
#define  P_COM_CONF_GET_S_I               18      /* callback function: get_s_i */
#define  P_COM_CONF_WRITE_S               19      /* callback function: write_s */
#define  P_COM_CONF_READ_S                20      /* callback function: read_s */
#define  P_COM_CONF_TEXTBOX_O             21
#define  P_COM_CONF_COMMANDBUTTON_2       22      /* callback function: to_delete_me */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */ 

int  CVICALLBACK ComStatusCallBack(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ErrorCallBack(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK get_s_i(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK get_s_o(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK inchide(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK programeaza(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK read_s(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK rev_com_conf(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK to_delete_me(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK write_s(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
