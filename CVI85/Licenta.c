#include "conf_f_apartenenta_v_2.h"
#include "Def_M_Fz.h"
#include <formatio.h>
#include "F_Z_Shape.h"
#include "F_S_Shape.h"
#include "F_GAUSS.h"
#include "Tabela_BRF.h"
#include "Selectare_Metode_Defuzificare.h"
#include "Functie_Saturatie_Dreapta.h"
#include "F_Trapezoidala.h"
#include "F_Saturatie_Stanga.h"
#include "panou_select_mod_optiune.h"
#include "conf_f_apartenenta.h"
#include <ansi_c.h>
#include "F_Triunghiulara.h"
#include "Tip_F.h"
#include "Conf_F_X.h"
#include <utility.h>
#include <rs232.h>
#include "COM_conf.h"
#include <cvirte.h>		
#include <userint.h>
#include "Licenta.h"
#include <string.h>
#include "crc.h"


static char gEventChar[2];
static int panelHandle,panelH_COM_CONF,panelH_F_CONF,panelH_F_TRI,panelH_F_Z_SHAPE,panelH_F_BRF_D,panelH_F_S_SHAPE,panelH_F_GAUSS ,panelH_S_MD,panelH_F_SAT_D,panelH_F_TIP,panelH_FA_CONF,panelH_F_TRA,panelH_FA_CONF_X,panelH_S_MS, panelH_F_SAT_S;
int COM_Port_Nr,Viteza,Paritate, Nr_Biti_Date, Nr_Biti_Stop,index,index_e,index_e_v,index_t,index_t_v,strLen=0,flag_S,nr=0;
int i,j,k,l,m,TIP_M_D,NR_INT,nr_biti=0,nr_biti_w=0,read;
int NR_F_X=3, NR_F_dX=3, NR_F_Y=3, NR_FUNCTI,TIP_M=1;
float TIP_F_X[10][5], TIP_F_dX[10][5],TIP_F_Y[10][5];
int *TIP_F[10][10];
int plotH_dX[11],plotH_X[11],plotH_Y[11],plotH_Def[11],f_def[11],v_met_defu[8];
int num,conf,def,tip=1,choise,index_s_md,index_s_md_v;
char buf1[2000],buf2[20],buf3[20],buffer[10000],buffer_1[128],buffer_2[128],bufTemp[30],buf4[30];
double testx[100],testy[100];
double u,a3,b3,c3,a,b,c,d,a1,b1,c1,d1,a2,b2,c2;
int def_f[4];
char mult_f_e_X[10][20]={"Multime Fuzzy X 1","Multime Fuzzy X 2","Multime Fuzzy X 3","Multime Fuzzy X 4","Multime Fuzzy X 5","Multime Fuzzy X 6","Multime Fuzzy X 7","Multime Fuzzy X 8","Multime Fuzzy X 9","Multime Fuzzy X 10"};
 char mult_f_e_dX[10][20]={"Multime Fuzzy dX 1","Multime Fuzzy dX 2","Multime Fuzzy dX 3","Multime Fuzzy dX 4","Multime Fuzzy dX 5","Multime Fuzzy dX 6","Multime Fuzzy dX 7","Multime Fuzzy dX 8","Multime Fuzzy dX 9","Multime Fuzzy dX 10"};
 char mult_f_e_Y[10][20]={"Multime Fuzzy Y 1","Multime Fuzzy Y 2","Multime Fuzzy Y 3","Multime Fuzzy Y 4","Multime Fuzzy Y 5","Multime Fuzzy Y 6","Multime Fuzzy Y 7","Multime Fuzzy Y 8","Multime Fuzzy Y 9","Multime Fuzzy Y 10"};
int m_or_f,COM_ERROR,RS232Error, com_status,nr_send=0;
 double I;
char BRF_E[10][10][20],buf2[20],readBuf[100000],writeBuf[4096],reafBuf_H[100000],writeBuf_H[100000];
char  com_msg[500],msg[100],devicename[30],CurrentFolder[MAX_PATHNAME_LEN];
char itemp[2],dtemp[4],separator[2]={'#','\0'}; // vai doamne nu sunt array-uri de la 0


int comport,
    baudrate,
    portindex,
    parity,
    databits,
    stopbits,
    inputq,         /* Sets input queue length in OpenComConfig */
    outputq,        /* Sets output queue length in OpenComConfig */
    xmode,
    ctsmode,
    stringsize,
    bytes_sent,
    bytes_read,
    RS232Error,
    config_flag,
    breakstatus,
    port_open,
    com_status,
    send_mode,
    send_byte,
    send_term_index,
    read_term_index,
    read_term,
    inqlen,         /* Stores result from GetInQLen */
    outqlen;        /* Stores result from GetOutQLen */


/* 
 VAL_RED 0xFF0000L 
VAL_GREEN 0x00FF00L 
VAL_BLUE 0x0000FFL 
VAL_CYAN 0x00FFFFL 
VAL_MAGENTA 0xFF00FFL 
VAL_YELLOW 0xFFFF00L 
VAL_DK_RED 0x800000L 
VAL_DK_BLUE 0x000080L 
VAL_DK_GREEN 0x008000L 
VAL_DK_CYAN 0x008080L 
VAL_DK_MAGENTA 0x800080L 
VAL_DK_YELLOW 0x808000L 
VAL_LT_GRAY 0xC0C0C0L 
VAL_DK_GRAY 0x808080L 
VAL_BLACK 0x000000L 
VAL_WHITE 0xFFFFFFL 
VAL_PANEL_GRAY 0xC0C0C0L 
VAL_GRAY 0xA0A0A0L 
VAL_OFFWHITE 0xE0E0E0L 
VAL_TRANSPARENT 0x1000000L 
  */

 
 
 
 int color[10]={0xFF0000L,0x0000FFL,0x00FF00L,0x00FFFFL,0xFF00FFL,0x808000L,0x000000L,0x000080L,0x800000L,0x008000L};
 
const char temp[20];
double v_y_X[10][100],v_x_X[10][100],v_y_dX[10][100],v_y_Y[10][100],v_x_dX[10][100],v_x_Y[10][100];

	


char val;   
int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "Licenta.uir", PANEL)) < 0)
		return -1;
	
	

	//crcInit();		
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	
	CloseCVIRTE ();
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////
 int retintfrst(char Buffer[],int indexB)
{
  if (indexB>=sizeof(Buffer))
    return 0;
   else
   {
  itemp[0]=Buffer[indexB];
  itemp[1]=Buffer[indexB+1];
  return (atoi(itemp));
   }
}

double retfloatfrst(char Buffer[],int indexB)
{
  if (indexB>=sizeof(Buffer))
    return 0;
   else
   {
  dtemp[0]=Buffer[indexB];
  dtemp[1]=Buffer[indexB+1];
  dtemp[2]=Buffer[indexB+2];
  dtemp[3]=Buffer[indexB+3];
  return (atof(dtemp));
   }
}



 
 
/*---------------------------------------------------------------------------*/
/* Set the port configuration parameters.                                    */
/*---------------------------------------------------------------------------*/
void SetConfigParms (void)
{
	SetCtrlVal (panelH_COM_CONF, P_COM_CONF_PORT_NAME, comport);
	SetCtrlVal (panelH_COM_CONF, P_COM_CONF_VITEZA, baudrate);
	SetCtrlVal (panelH_COM_CONF, P_COM_CONF_PARITATE, parity);
	SetCtrlVal (panelH_COM_CONF, P_COM_CONF_NR_BITI, databits);
	SetCtrlVal (panelH_COM_CONF, P_COM_CONF_NR_B_STOP, stopbits);
    //SetCtrlVal (panelH_COM_CONF, CONFIG_INPUTQ, inputq);
    //SetCtrlVal (panelH_COM_CONF, CONFIG_OUTPUTQ, outputq);
    //SetCtrlVal (panelH_COM_CONF, CONFIG_CTSMODE, ctsmode);
    //SetCtrlVal (panelH_COM_CONF, CONFIG_XMODE, xmode);
    //SetCtrlVal (panelH_COM_CONF, CONFIG_TIMEOUT, timeout);
	SetCtrlIndex (panelH_COM_CONF, P_COM_CONF_PORT_NAME, portindex);
}

/*---------------------------------------------------------------------------*/
/* Get the port configuration parameters.                                    */
/*---------------------------------------------------------------------------*/
void GetConfigParms (void)
{
	//GetCtrlVal (panelH_COM_CONF, P_COM_CONF_PORT_NAME, &comport);
	GetCtrlVal (panelH_COM_CONF, P_COM_CONF_VITEZA, &baudrate);
	GetCtrlVal (panelH_COM_CONF, P_COM_CONF_PARITATE, &parity);
	GetCtrlVal (panelH_COM_CONF, P_COM_CONF_NR_BITI, &databits);
	GetCtrlVal (panelH_COM_CONF, P_COM_CONF_NR_B_STOP, &stopbits);
    //GetCtrlVal (panelH_COM_CONF, CONFIG_INPUTQ, &inputq);
    //GetCtrlVal (panelH_COM_CONF, CONFIG_OUTPUTQ, &outputq);
    //GetCtrlVal (panelH_COM_CONF, CONFIG_CTSMODE, &ctsmode);
    //GetCtrlVal (panelH_COM_CONF, CONFIG_XMODE, &xmode);
    //GetCtrlVal (panelH_COM_CONF, CONFIG_TIMEOUT, &timeout);
	GetCtrlIndex (panelH_COM_CONF, P_COM_CONF_PORT_NAME, &portindex);
	GetValueFromIndex (panelH_COM_CONF, P_COM_CONF_PORT_NAME, portindex, &comport);
    //#ifdef _NI_unix_
      //  devicename[0]=0;
   // #else
		GetLabelFromIndex (panelH_COM_CONF, P_COM_CONF_PORT_NAME, portindex, devicename);
    //#endif                   
}
/*---------------------------------------------------------------------------*/      
void DisplayRS232Error (void)
{
    char ErrorMessage[200];
    switch (RS232Error)
        {
        default :
            if (RS232Error < 0)
                {  
                Fmt (ErrorMessage, "%s<RS232 error number %i", RS232Error);
                MessagePopup ("RS232 Message", ErrorMessage);
                }
            break;
        case 0  :
            MessagePopup ("RS232 Message", "No errors.");
            break;
        case -2 :
            Fmt (ErrorMessage, "%s", "Invalid port number (must be in the "
                                     "range 1 to 8).");
            MessagePopup ("RS232 Message", ErrorMessage);
            break;
        case -3 :
            Fmt (ErrorMessage, "%s", "No port is open.\n"
                 "Check COM Port setting in Configure. ");
            MessagePopup ("RS232 Message", ErrorMessage);
            break;
		case -6 :
				  Fmt (ErrorMessage, "%s", "No serial port found.\n"
                 "Check COM Port setting in Configure.and check that the device is conected to the computer");
            MessagePopup ("RS232 Message", ErrorMessage);
			break;
        case -99 :
            Fmt (ErrorMessage, "%s", "Timeout error.\n\n"
                 "Either increase timeout value,\n"
                 "       check COM Port setting, or\n"
                 "       check device.");
            MessagePopup ("RS232 Message", ErrorMessage);
            break;
        }
}


void DisplayComStatus ()
{
    com_msg[0] = '\0';
    if (com_status & 0x0001)
        strcat (com_msg, "Input lost: Input queue"
                " filled and characters were lost.\n");
    if (com_status & 0x0002)
        strcat (com_msg, "Asynch error: Problem "
                "determining number of characters in input queue.\n");
    if (com_status & 0x0010)
        strcat (com_msg, "Parity error.\n");
    if (com_status & 0x0020)
        strcat (com_msg, "Overrun error: Received"
                " characters were lost.\n");
    if (com_status & 0x0040)
        strcat (com_msg, "Framing error: Stop bits were not received"
                " as expected.\n");
    if (com_status & 0x0080)
        strcat (com_msg, "Break: A break signal was detected.\n");
    if (com_status & 0x1000)
        strcat (com_msg, "Remote XOFF: An XOFF character was received."
                "\nIf XON/XOFF was enabled, no characters are removed"
                " from the output queue and sent to another device "
                "until that device sends an XON character.\n");
    if (com_status & 0x2000)
        strcat (com_msg, "Remote XON: An XON character was received."
                "\nTransmisson can resume.\n");
    if (com_status & 0x4000)
        strcat (com_msg, "Local XOFF: An XOFF character was sent to\n"
                " the other device.  If XON/XOFF was enabled, XOFF is\n"
                " transmitted when the input queue is 50%, 75%, and 90%\n"
                " full.\n");
    if (com_status & 0x8000)
        strcat (com_msg, "Local XON: An XON character was sent to\n"
                " the other device.  If XON/XOFF was enabled, XON is\n"
                " transmitted when the input queue empties after XOFF\n"
                " was sent.  XON tells the other device that it can \n"
                " resume sending data.\n");
    if (strlen (com_msg) == 0)
        strcat (com_msg, "No status bits are set.");
    MessagePopup ("RS232 Message", com_msg);
}


double satl(double u, double a, double b)
{
        if (u<a)
                return 1;
        if ( u>=a && u<=b)
                return (b-u)/(b-a);
        if (u>b)
                return 0;
}

double pi(double u, double a1, double c1, double d1, double b1)
{
        if (u<a1)
                return 0;
        if ( u>=a1 && u<=c1)
                return (u-a1)/(c1-a1);
        if (u>c1 && u<=d1)
                return 1;
        if (u>d1 && u<=b1)
                return (b1-u)/(b1-d1);
        if(u>b1)
                return 0;
}

double gama (double u, double a, double b)
{
        if (u<a)
                return 0;
        if ( u>=a && u<=b)
                return (u-a)/(b-a);
        if (u>b)
                return 1;
}

double delta (double u, double a3, double c3, double b3)
{
        if (u<a3)
                return 0;
        if ( u>=a3 && u<=c3)
                return (u-a3)/(c3-a3);
        if (u>c3 && u<=b3)
                return (b3-u)/(b3-c3);
        if(u>b3)
                return 0;
}

double gauss(double u, double c, double s)
{
	return (exp ((-(u-c)*(u-c))/(2*(s*s))));
		
}

double sshape(double u,double a, double b)
{
	if (u<=a)
		return(0);
	else
		if (u<=((a+b)/2))
			return (2*(((u-a)/(b-a))*((u-a)/(b-a))));
		else
			if ((u>=((a+b)/2))&(u<=b))
				return (1-(2*(((u-b)/(b-a))*((u-b)/(b-a)))));
			else
				if (u>=b)
					return(1);
					
}
double zshape(double u,double a, double b)
{
	
	if (u<=a)
		return(1);
	else
		if ((u<=((a+b)/2))&(u>=a))
				return (1-(2*(((u-a)/(b-a))*((u-a)/(b-a)))));
			else
				if ((u>=((a+b)/2))&(u<=b))
					return (2*(((u-b)/(b-a))*((u-b)/(b-a))));
				else
					if (u>=b)
						return(0);
}

double sigmoidala(double u, double a, double b)
{
	return(1/(1+exp(-a*(u-b))));
}
double sigmoidala2(double u,double a1, double b1,double a2, double b2)
{
	return(1/((1+exp(-a1*(u-b1)))*(1+exp(-a2*(u-b2)))));	
}

//Generalized bell-shaped built-in membership function
double gbell(double u, double a,double b, double c)
{
	return (1/(1+((u-c)/a)*(pow(abs(((u-c)/a)),(2*b)))));
}


void genBuffer()
	{
		nr=0;
	//	nr_biti=0;
		NR_F_X=3;
		buffer[0]='\0';
		buf1[0]='\0';
		sprintf (buf1, "%i", NR_F_X);
		strcat (buffer,buf1);
		strcat (buffer,separator);
		nr++;
		
		 //MessagePopup ("NR_F_X= ", buf1);
		
		buf1[0]='\0';
		sprintf (buf1, "%i", NR_F_dX);
		strcat (buffer,buf1);
		strcat (buffer,separator);
		nr++;
		
		buf1[0]='\0';
		sprintf (buf1, "%i", NR_F_Y);
		strcat (buffer,buf1);
		strcat (buffer,separator);
		nr++;
		
		
		for (i=0;i<10;i++)
		{
			for (j=0;j<5;j++)
			{
				sprintf (buf1, "%f", TIP_F_X[i][j]);
				strcat (buffer,buf1);
				strcat (buffer,separator);
				nr++;
			}
		}
		
		
		for (i=0;i<10;i++)
		{
			for (j=0;j<5;j++)
			{
				sprintf (buf1, "%f", TIP_F_dX[i][j]);
				strcat (buffer,buf1);
				strcat (buffer,separator);
				nr++; 
			}
		}
		
		for (i=0;i<10;i++)
		{
			for (j=0;j<5;j++)
			{
				sprintf (buf1, "%f", TIP_F_Y[i][j]);
				
				strcat (buffer,buf1);
				strcat (buffer,separator);
				nr++; 
			}
		}
		//buffer[strlen(buffer)+1]='\0'; 
	/*	
		for (i=0;i<10;i++)
		{
			strcat (buffer,mult_f_e_X[i]);
			strcat (buffer,separator);
		
		}
		
		for (i=0;i<10;i++)
		{
			strcat (buffer,mult_f_e_dX[i]);
			strcat (buffer,separator);
			
		}
		
		for (i=0;i<10;i++)
		{
			strcat (buffer,mult_f_e_Y[i]);
			strcat (buffer,separator);
		
		}
		
		
		for (i=0;i<10;i++)
		{
			for (j=0;j<10;j++)
			{
				
				strcat (buffer,BRF_E[i][j]);
				strcat (buffer,separator);
				
				
			}
		}
		
	
		sprintf (buf1, "%i", &TIP_M_D);
		strcat (buffer,buf1);
		strcat (buffer,separator);
	
		
		sprintf (buf1, "%i", &NR_INT);
		strcat (buffer,buf1);
		strcat (buffer,separator);
		
		 	*/
		sprintf (buf1, "%i", nr);
		buf1[strlen(buffer)+1]='\0';
			
		MessagePopup ("nr :::: ", buf1);
		MessagePopup ("buffer", buffer);
		
		
	}
//////////////////////////////////////////////////////////////////////
 void CVICALLBACK ReceptieS(int COMPort, int eventMask, void *CallbackData)
 {
	 		 if (eventMask & LWRS_RXCHAR & (nr_send<=strlen(buffer)))
			 {
			  nr_send=ComWrtByte (comport, buffer[nr_send]);
			  FlushInQ (comport);
			 
			 }
			 if (eventMask & LWRS_RXFLAG)
			 {
				 ComRdTerm (comport, &readBuf[strlen(readBuf)+1], GetInQLen (comport), 13);
			 }
			 if (eventMask & LWRS_RXCHAR & (nr_send>strlen(buffer)))
			 {
				 ComRdTerm (comport, &readBuf[strlen(readBuf)+1], GetInQLen (comport), 13);				 
			 }


		}
 
 



int CVICALLBACK config_com (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					  panelH_COM_CONF = LoadPanel (panelHandle, "c:\\Users\\azyl\\Desktop\\Licentza\\CVI85\\COM_conf.uir", 1);
					  //panelH_COM_CONF = LoadPanel (panelHandle, "c:\\CVI85\\serial.uir", 1);
					  InstallPopup (panelH_COM_CONF);
					  
					  if (flag_S==1)
					  {
					  //DisableBreakOnLibraryErrors ();
					  //strLen = GetInQLen (comport);
            		  //ComRd (comport, readBuf, strLen);
					  //strcat (readBuf,"Numar de bytes ce asteapta sa fie cititi : ");
					  //strcpy (&readBuf[0],"Numar de bytes ce asteapta sa fie cititi : ");
					  //sprintf (bufTemp, "%i", &strLen);
				      //strcat (readBuf,bufTemp);
					  // strcpy (, );
					  //SetCtrlVal (panelH_COM_CONF, P_COM_CONF_TEXTBOX_I, readBuf);
					  //SetCtrlVal (panelH_COM_CONF, P_COM_CONF_TEXTBOX_O, writeBuf);
					  
					  //SetCtrlVal (panelH_COM_CONF, P_COM_CONF_TEXTBOX_I_H, "");
					  //SetCtrlVal (panelH_COM_CONF, P_COM_CONF_TEXTBOX_O_H, "");
					  //EnableBreakOnLibraryErrors ();
						SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_INCHIDE, ATTR_VISIBLE, 1);
						SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_PROGRAMEAZA, ATTR_VISIBLE, 0);
						SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_READ_S, ATTR_DIMMED, 0);
						SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_WRITE_S, ATTR_DIMMED, 0);
						SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_GET_S_I, ATTR_DIMMED, 0);
						SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_GET_S_O, ATTR_DIMMED, 0);
						SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_ERROR, ATTR_DIMMED, 0);
						SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_COMSTATUS, ATTR_DIMMED, 0);
						
						SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_PORT_NAME, ATTR_DIMMED, 1);
						SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_VITEZA, ATTR_DIMMED, 1);
						SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_PARITATE, ATTR_DIMMED, 1);
						SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_NR_BITI, ATTR_DIMMED, 1);
						SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_NR_B_STOP, ATTR_DIMMED, 1);
						
						ResetTextBox (panelH_COM_CONF, P_COM_CONF_TEXTBOX_O, "");
				   		SetCtrlVal (panelH_COM_CONF, P_COM_CONF_TEXTBOX_O, buffer);
				   		SetCtrlVal (panelH_COM_CONF, P_COM_CONF_TEXTBOX_O_H, buffer);
						
						
					  }
			break;
	}
	return 0;
}

int CVICALLBACK programeaza (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					  /*
					  GetCtrlVal (panelH_COM_CONF, P_COM_CONF_PORT_NAME, &COM_Port_Nr);
					  
					  //Device_Name=
					  
					  GetCtrlVal (panelH_COM_CONF, P_COM_CONF_VITEZA, &Viteza);
					  GetCtrlVal (panelH_COM_CONF, P_COM_CONF_PARITATE, &Paritate);
					  GetCtrlVal (panelH_COM_CONF, P_COM_CONF_NR_BITI, &Nr_Biti_Date);
					  GetCtrlVal (panelH_COM_CONF, P_COM_CONF_NR_B_STOP, &Nr_Biti_Stop);
					  
					  
					  DisableBreakOnLibraryErrors (); 
					  COM_ERROR = OpenComConfig (COM_Port_Nr, "", Viteza, Paritate, Nr_Biti_Date, Nr_Biti_Stop, 4096, 4096);
					  EnableBreakOnLibraryErrors ();
					  SetCtrlAttribute (panelHandle, PANEL_LED_SERIALA, ATTR_CTRL_VAL, 1);
					  */
			
					  port_open = 0;  /* initialize flag to 0 - unopened */
            		  GetConfigParms ();
            		  DisableBreakOnLibraryErrors ();		 //devicename
            		  RS232Error = OpenComConfig (comport, "", baudrate, parity,
                                        databits, stopbits, inputq, outputq);
            		  EnableBreakOnLibraryErrors ();
					  
            if (RS232Error) DisplayRS232Error ();
            if (RS232Error == 0)
                {
					
					  SetCtrlAttribute (panelHandle, PANEL_LED_SERIALA, ATTR_CTRL_VAL, 1);
					  SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_ERROR, ATTR_DIMMED, 0);
					  SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_COMSTATUS, ATTR_DIMMED, 0);
						  
						  FlushInQ (comport);
						  FlushOutQ (comport);
					  SetCtrlVal (panelH_COM_CONF, P_COM_CONF_TEXTBOX_I, "");
					  SetCtrlVal (panelH_COM_CONF, P_COM_CONF_TEXTBOX_O, "");
					  
					  SetCtrlVal (panelH_COM_CONF, P_COM_CONF_TEXTBOX_I_H, "");
					  SetCtrlVal (panelH_COM_CONF, P_COM_CONF_TEXTBOX_O_H, "");
					  flag_S=1;
					  SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_PROGRAMEAZA, ATTR_VISIBLE, 0);
					  SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_INCHIDE, ATTR_VISIBLE, 1);
					  SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_READ_S, ATTR_DIMMED, 0);
					  SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_WRITE_S, ATTR_DIMMED, 0);
					  SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_GET_S_I, ATTR_DIMMED, 0);
					  SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_GET_S_O, ATTR_DIMMED, 0);
					  
					  SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_PORT_NAME, ATTR_DIMMED, 1);
				      SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_VITEZA, ATTR_DIMMED, 1);
					  SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_PARITATE, ATTR_DIMMED, 1);
					  SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_NR_BITI, ATTR_DIMMED, 1);
					  SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_NR_B_STOP, ATTR_DIMMED, 1);
					  
					
             //  port_open = 1;
                //GetCtrlVal (config_handle, CONFIG_XMODE, &xmode);
                //SetXMode (comport, xmode);
                //GetCtrlVal (config_handle, CONFIG_CTSMODE, &ctsmode);
                //SetCTSMode (comport, ctsmode);
                //GetCtrlVal (config_handle, CONFIG_TIMEOUT, &timeout);
                //SetComTime (comport, timeout);
             //   EnablePanelControls (0); /* Enable: no errors */
                }
			else
				flag_S=0;
          //  else
           //     EnablePanelControls (1); /* Disable: errors found */
           // DiscardPanel (config_handle);
			
			
			
			
			
					  //DiscardPanel (panelH_COM_CONF);
			break;
	}
	return 0;
}

int CVICALLBACK close (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					 DisableBreakOnLibraryErrors ();
				CloseCom (comport);
				EnableBreakOnLibraryErrors ();
				flag_S=0;
					 QuitUserInterface (0);  
			break;
	}
	return 0;
}


int CVICALLBACK conf_f_x (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				   
				  //SetPanelAttribute (panelH_FA_CONF, ATTR_BACKCOLOR, VAL_DK_MAGENTA);
				   
			break;
	}
	return 0;
}

int CVICALLBACK ac_f_conf (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:				 
					def_f[conf]=1;
					   DiscardPanel (panelH_FA_CONF_X); 
			break;
	}
	return 0;
}

int CVICALLBACK NR_F (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
		case EVENT_VAL_CHANGED:
				GetCtrlVal (panelH_FA_CONF_X, PANEL_NR_F, &NR_FUNCTI);
				if (conf==1)
					NR_F_X=NR_FUNCTI;
				if (conf==2)
					NR_F_dX=NR_FUNCTI;
				if (conf==3)
					NR_F_Y=NR_FUNCTI;
					
				for(i=NR_FUNCTI;i<11;i++)
				{
					  
					
						for (j=0;j<10;j++)
						{
						   if(conf==1)
							   TIP_F_X[i][j]=0;
						   if(conf==2)
								TIP_F_dX[i][j]=0;							   
						   if(conf==2)
								TIP_F_Y[i][j]=0;							   
							}
				
				}	
				
				
				
				SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_1, ATTR_DIMMED, 1);
				SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_2, ATTR_DIMMED, 1);
				SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_3, ATTR_DIMMED, 1);
				SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_4, ATTR_DIMMED, 1);
				SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_5, ATTR_DIMMED, 1);
				SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_6, ATTR_DIMMED, 1);
				SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_7, ATTR_DIMMED, 1);
				SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_8, ATTR_DIMMED, 1);
				SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_9, ATTR_DIMMED, 1);
				SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_10, ATTR_DIMMED, 1);
				
				SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_1, ATTR_DIMMED, 1);
				SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_2, ATTR_DIMMED, 1);
				SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_3, ATTR_DIMMED, 1);
				SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_4, ATTR_DIMMED, 1);
				SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_5, ATTR_DIMMED, 1);
				SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_6, ATTR_DIMMED, 1);
				SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_7, ATTR_DIMMED, 1);
				SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_8, ATTR_DIMMED, 1);
				SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_9, ATTR_DIMMED, 1);
				SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_10, ATTR_DIMMED, 1);
				
				
				
				
				
				if (NR_FUNCTI==3)
				 {
				 	SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_1, ATTR_DIMMED, 0);
				 	SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_2, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_3, ATTR_DIMMED, 0);
					
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_1, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_2, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_3, ATTR_DIMMED, 0);
					
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_4, -1, VAL_IMMEDIATE_DRAW);
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_5, -1, VAL_IMMEDIATE_DRAW);
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_6, -1, VAL_IMMEDIATE_DRAW);
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_7, -1, VAL_IMMEDIATE_DRAW);
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_8, -1, VAL_IMMEDIATE_DRAW);
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_9, -1, VAL_IMMEDIATE_DRAW);
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_10, -1, VAL_IMMEDIATE_DRAW);
					
					if (conf==1)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[4], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[5], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[6], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[7], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[8], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[9], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[10], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==2)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[4], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[5], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[6], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[7], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[8], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[9], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[10], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==3)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[4], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[5], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[6], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[7], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[8], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[9], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[10], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					
				 }
				if (NR_FUNCTI==4)
				 {
				 	SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_1, ATTR_DIMMED, 0);
				 	SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_2, ATTR_DIMMED, 0);	
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_3, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_4, ATTR_DIMMED, 0);
					
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_1, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_2, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_3, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_4, ATTR_DIMMED, 0);
					
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_5, -1, VAL_IMMEDIATE_DRAW);
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_6, -1, VAL_IMMEDIATE_DRAW);
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_7, -1, VAL_IMMEDIATE_DRAW);
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_8, -1, VAL_IMMEDIATE_DRAW);
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_9, -1, VAL_IMMEDIATE_DRAW);
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_10, -1, VAL_IMMEDIATE_DRAW);
					
					if (conf==1)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[5], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[6], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[7], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[8], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[9], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[10], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==2)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[5], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[6], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[7], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[8], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[9], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[10], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==3)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[5], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[6], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[7], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[8], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[9], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[10], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					
				 }
				if (NR_FUNCTI==5)
				 {
				 	SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_1, ATTR_DIMMED, 0);
				 	SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_2, ATTR_DIMMED, 0);	
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_3, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_4, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_5, ATTR_DIMMED, 0);
					
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_1, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_2, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_3, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_4, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_5, ATTR_DIMMED, 0);
					
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_6, -1, VAL_IMMEDIATE_DRAW);
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_7, -1, VAL_IMMEDIATE_DRAW);
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_8, -1, VAL_IMMEDIATE_DRAW);
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_9, -1, VAL_IMMEDIATE_DRAW);
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_10, -1, VAL_IMMEDIATE_DRAW);
					
					 if (conf==1)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[6], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[7], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[8], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[9], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[10], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==2)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[6], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[7], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[8], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[9], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[10], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==3)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[6], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[7], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[8], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[9], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[10], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					
				 }
				if (NR_FUNCTI==6)
				 {
				 	SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_1, ATTR_DIMMED, 0);
				 	SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_2, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_3, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_4, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_5, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_6, ATTR_DIMMED, 0);
					
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_1, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_2, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_3, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_4, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_5, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_6, ATTR_DIMMED, 0);
					
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_7, -1, VAL_IMMEDIATE_DRAW);
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_8, -1, VAL_IMMEDIATE_DRAW);
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_9, -1, VAL_IMMEDIATE_DRAW);
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_10, -1, VAL_IMMEDIATE_DRAW);
					
					if (conf==1)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[7], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[8], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[9], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[10], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==2)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[7], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[8], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[9], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[10], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==3)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[7], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[8], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[9], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[10], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					
				 }
				if (NR_FUNCTI==7)
				 {
				 	SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_1, ATTR_DIMMED, 0);
				 	SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_2, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_3, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_4, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_5, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_6, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_7, ATTR_DIMMED, 0);
					
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_1, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_2, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_3, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_4, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_5, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_6, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_7, ATTR_DIMMED, 0);
					
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_8, -1, VAL_IMMEDIATE_DRAW);
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_9, -1, VAL_IMMEDIATE_DRAW);
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_10, -1, VAL_IMMEDIATE_DRAW);
					
					if (conf==1)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[8], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[9], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[10], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==2)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[8], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[9], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[10], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==3)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[8], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[9], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[10], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					
				 }
				if (NR_FUNCTI==8)
				 {
				 	SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_1, ATTR_DIMMED, 0);
				 	SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_2, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_3, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_4, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_5, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_6, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_7, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_8, ATTR_DIMMED, 0);
					
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_1, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_2, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_3, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_4, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_5, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_6, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_7, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_8, ATTR_DIMMED, 0);
					
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_9, -1, VAL_IMMEDIATE_DRAW);
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_10, -1, VAL_IMMEDIATE_DRAW);
					
					if (conf==1)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[9], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[10], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==2)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[9], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[10], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==3)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[9], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[10], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					
				 }
				if (NR_FUNCTI==9)
				 {
				 	SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_1, ATTR_DIMMED, 0);
				 	SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_2, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_3, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_4, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_5, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_6, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_7, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_8, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_9, ATTR_DIMMED, 0);
					
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_1, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_2, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_3, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_4, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_5, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_6, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_7, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_8, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_9, ATTR_DIMMED, 0);
					
					DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_10, -1, VAL_IMMEDIATE_DRAW);
					
					if (conf==1)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[10], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==2)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[10], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==3)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[10], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					
				 }
				if (NR_FUNCTI==10)
				 {
				 	SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_1, ATTR_DIMMED, 0);
				 	SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_2, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_3, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_4, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_5, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_6, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_7, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_8, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_9, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_DEF_F_10, ATTR_DIMMED, 0);
					
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_1, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_2, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_3, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_4, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_5, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_6, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_7, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_8, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_9, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_FA_CONF_X, PANEL_GRAPH_F_D_10, ATTR_DIMMED, 0);
					
				 }
				
				 				
			break;

	}
	return 0;
}

int CVICALLBACK def_f_1 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				   def=1;
				   if (f_def[def]!=1)
				   {
				   panelH_F_TIP = LoadPanel (panelHandle, "c:\\CVI85\\Tip_F.uir", 1);
				   InstallPopup (panelH_F_TIP);
				   }
				   else 
				   {
					choise = ConfirmPopup ("Redefinire Functie de Apartenenta", "Sigur doriti sa redefiniti aceasta Functie de Apartenenta ?");
					 if (choise==1)
					 { 
					 DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_1, -1, VAL_IMMEDIATE_DRAW);
					 f_def[def]=0;
					
					if (conf==1)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==2)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==3)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}  
					   
					panelH_F_TIP = LoadPanel (panelHandle, "c:\\CVI85\\Tip_F.uir", 1);
				   InstallPopup (panelH_F_TIP);
				   	}
					 
				   } 
				   
			break;
	}
	return 0;
}

int CVICALLBACK f_triunghiulara (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					tip=1;
				   panelH_F_TRI = LoadPanel (panelHandle, "c:\\CVI85\\F_Triunghiulara.uir", 1);
				   InstallPopup (panelH_F_TRI);
			break;
	}
	return 0;
}

int CVICALLBACK f_trapezoidala (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			   tip=2;
			   panelH_F_TRA = LoadPanel (panelHandle, "c:\\CVI85\\F_Trapezoidala.uir", 1);
			   InstallPopup (panelH_F_TRA);
			break;
	}
	return 0;
}

int CVICALLBACK f_saturatie (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					tip=3;
			break;
	}
	return 0;
}

int CVICALLBACK ok_param_f_tri (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					f_def[def]=1;
					if (conf==1)   // 1 daca se face pentru functia x 2 pt dx  3 pt y
					{
					TIP_F_X[def][1]=tip;
					GetCtrlVal (panelH_F_TRI, PANEL_F_TRIUNGIULARA_A, &TIP_F_X[def][2]);
					GetCtrlVal (panelH_F_TRI, PANEL_F_TRIUNGIULARA_B, &TIP_F_X[def][3]);
					GetCtrlVal (panelH_F_TRI, PANEL_F_TRIUNGIULARA_C, &TIP_F_X[def][4]);
					}
					if (conf==2)
					{
					TIP_F_dX[def][1]=tip;
					GetCtrlVal (panelH_F_TRI, PANEL_F_TRIUNGIULARA_A, &TIP_F_dX[def][2]);
					GetCtrlVal (panelH_F_TRI, PANEL_F_TRIUNGIULARA_B, &TIP_F_dX[def][3]);
					GetCtrlVal (panelH_F_TRI, PANEL_F_TRIUNGIULARA_C, &TIP_F_dX[def][4]);
					}
					if (conf==3)
					{
					TIP_F_Y[def][1]=tip;
					GetCtrlVal (panelH_F_TRI, PANEL_F_TRIUNGIULARA_A, &TIP_F_Y[def][2]);
					GetCtrlVal (panelH_F_TRI, PANEL_F_TRIUNGIULARA_B, &TIP_F_Y[def][3]);
					GetCtrlVal (panelH_F_TRI, PANEL_F_TRIUNGIULARA_C, &TIP_F_Y[def][4]);
					}
					
					
					GetCtrlVal (panelH_F_TRI, PANEL_F_TRIUNGIULARA_A, &a);
					GetCtrlVal (panelH_F_TRI, PANEL_F_TRIUNGIULARA_B, &b);
					GetCtrlVal (panelH_F_TRI, PANEL_F_TRIUNGIULARA_C, &c);
					
					
						for(i=0;i<100;i++)
					{
					   testx[i]=i;
					   testy[i]=delta(i,a,b,c);
						}
						
					if (def==1)
					{
					 		plotH_Def[1] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_1, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
									   VAL_SOLID, 1, VAL_RED);
					 if (conf==1)
					 		plotH_X[1] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_RED);
					 if (conf==2)
							plotH_dX[1]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_RED);
					 if (conf==3)
							plotH_Y[1] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_RED);
					}
					if (def==2)
					{
					 plotH_Def[2] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_2, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_BLUE);
					 if (conf==1)
					 		plotH_X[2] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_BLUE);
					 if (conf==2)
							plotH_dX[2]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_BLUE);
					 if (conf==3)
							plotH_Y[2] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_BLUE);
					}
					if (def==3)
					{
					 plotH_Def[3] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_3, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_GREEN);
					 if (conf==1)
					 		plotH_X[3] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_GREEN);
					 if (conf==2)
							plotH_dX[3]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_GREEN);
					 if (conf==3)
							plotH_Y[3] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_GREEN);
					}
					if (def==4)
					{
					 plotH_Def[4] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_4, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_CYAN);
					 if (conf==1)
					 		plotH_X[4] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_CYAN);
					 if (conf==2)
							plotH_dX[4]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_CYAN);
					 if (conf==3)
							plotH_Y[4] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_CYAN);
					}
					if (def==5)
					{
					 plotH_Def[5] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_5, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_MAGENTA);
					 if (conf==1)
					 		plotH_X[5] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_MAGENTA);
					 if (conf==2)
							plotH_dX[5]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_MAGENTA);
					 if (conf==3)
							plotH_Y[5] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_MAGENTA);
					}
					if (def==6)
					{
					 plotH_Def[6] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_6, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_YELLOW);
					 if (conf==1)
					 		plotH_X[6] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_YELLOW);
					 if (conf==2)
							plotH_dX[6]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_YELLOW);
					 if (conf==3)
							plotH_Y[6] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_YELLOW);
					}
					if (def==7)
					{
					 plotH_Def[7] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_7, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_BLACK);
					 if (conf==1)
					 		plotH_X[7] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_BLACK);
					 if (conf==2)
							plotH_dX[7]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_BLACK);
					 if (conf==3)
							plotH_Y[7] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_BLACK);
					}
					if (def==8)
					{
					 plotH_Def[8] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_8, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_DK_BLUE);
					 if (conf==1)
					 		plotH_X[8] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_DK_BLUE);
					 if (conf==2)
							plotH_dX[8]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_BLUE);
					 if (conf==3)
							plotH_Y[8] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_BLUE);
					}
					if (def==9)
					{
					 plotH_Def[9] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_9, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_DK_RED);
					 if (conf==1)
					 		plotH_X[9] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_DK_RED);
					 if (conf==2)
							plotH_dX[9]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_RED);
					 if (conf==3)
							plotH_Y[9] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_RED);
					}
					if (def==10)
					{
					 plotH_Def[10] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_10, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											 VAL_SOLID, 1, VAL_DK_GREEN);
					 if (conf==1)
					 		plotH_X[10] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_DK_GREEN);
					 if (conf==2)
							plotH_dX[10]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_GREEN);
					 if (conf==3)
							plotH_Y[10] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_GREEN);
					}
					
					
					
					DiscardPanel (panelH_F_TIP);
					DiscardPanel (panelH_F_TRI);
			break;
	}
	return 0;
}

int CVICALLBACK def_f_2 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					def=2;
				   if (f_def[def]!=1)
				   {
				   panelH_F_TIP = LoadPanel (panelHandle, "c:\\CVI85\\Tip_F.uir", 1);
				   InstallPopup (panelH_F_TIP);
				   }
				   else 
				   {
					choise = ConfirmPopup ("Redefinire Functie de Apartenenta", "Sigur doriti sa redefiniti aceasta Functie de Apartenenta ?");
					 if (choise==1)
					 { 
					 DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_2, -1, VAL_IMMEDIATE_DRAW);
					 f_def[def]=0;
					
					if (conf==1)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==2)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==3)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}  
					   
				   	 panelH_F_TIP = LoadPanel (panelHandle, "c:\\CVI85\\Tip_F.uir", 1);
				   InstallPopup (panelH_F_TIP);
					 }
					 
				   } 
				   
			break;
	}
	return 0;
}

int CVICALLBACK def_f_3 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					def=3;
				   if (f_def[def]!=1)
				   {
				   panelH_F_TIP = LoadPanel (panelHandle, "c:\\CVI85\\Tip_F.uir", 1);
				   InstallPopup (panelH_F_TIP);
				   }
				   else 
				   {
					choise = ConfirmPopup ("Redefinire Functie de Apartenenta", "Sigur doriti sa redefiniti aceasta Functie de Apartenenta ?");
					 if (choise==1)
					 { 
					 DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_3, -1, VAL_IMMEDIATE_DRAW);
					 f_def[def]=0;
					
					if (conf==1)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==2)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==3)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}  
					   
				   	 panelH_F_TIP = LoadPanel (panelHandle, "c:\\CVI85\\Tip_F.uir", 1);
				   InstallPopup (panelH_F_TIP);
					 }
					 
				   } 
			break;
	}
	return 0;
}

int CVICALLBACK def_f_4 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					def=4;
				   if (f_def[def]!=1)
				   {
				   panelH_F_TIP = LoadPanel (panelHandle, "c:\\CVI85\\Tip_F.uir", 1);
				   InstallPopup (panelH_F_TIP);
				   }
				   else 
				   {
					choise = ConfirmPopup ("Redefinire Functie de Apartenenta", "Sigur doriti sa redefiniti aceasta Functie de Apartenenta ?");
					 if (choise==1)
					 { 
					 DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_4, -1, VAL_IMMEDIATE_DRAW);
					 f_def[def]=0;
					
					if (conf==1)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==2)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==3)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}  
					   
				   	 panelH_F_TIP = LoadPanel (panelHandle, "c:\\CVI85\\Tip_F.uir", 1);
				   InstallPopup (panelH_F_TIP);
					 }
					 
				   } 
			break;
	}
	return 0;
}

int CVICALLBACK def_f_5 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					def=5;
				   if (f_def[def]!=1)
				   {
				   panelH_F_TIP = LoadPanel (panelHandle, "c:\\CVI85\\Tip_F.uir", 1);
				   InstallPopup (panelH_F_TIP);
				   }
				   else 
				   {
					choise = ConfirmPopup ("Redefinire Functie de Apartenenta", "Sigur doriti sa redefiniti aceasta Functie de Apartenenta ?");
					 if (choise==1)
					 { 
					 DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_5, -1, VAL_IMMEDIATE_DRAW);
					 f_def[def]=0;
					
					if (conf==1)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==2)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==3)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}  
					   
				   	 panelH_F_TIP = LoadPanel (panelHandle, "c:\\CVI85\\Tip_F.uir", 1);
				   InstallPopup (panelH_F_TIP);
					 }
					 
				   } 
			break;
	}
	return 0;
}

int CVICALLBACK def_f_6 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				def=6;
				   if (f_def[def]!=1)
				   {
				   panelH_F_TIP = LoadPanel (panelHandle, "c:\\CVI85\\Tip_F.uir", 1);
				   InstallPopup (panelH_F_TIP);
				   }
				   else 
				   {
					choise = ConfirmPopup ("Redefinire Functie de Apartenenta", "Sigur doriti sa redefiniti aceasta Functie de Apartenenta ?");
					 if (choise==1)
					 { 
					 DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_6, -1, VAL_IMMEDIATE_DRAW);
					 f_def[def]=0;
					
					if (conf==1)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==2)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==3)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}  
					   
				   	 panelH_F_TIP = LoadPanel (panelHandle, "c:\\CVI85\\Tip_F.uir", 1);
				   InstallPopup (panelH_F_TIP);
					 }
					 
				   } 
			break;
	}
	return 0;
}

int CVICALLBACK def_f_7 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				   def=7;
				   if (f_def[def]!=1)
				   {
				   panelH_F_TIP = LoadPanel (panelHandle, "c:\\CVI85\\Tip_F.uir", 1);
				   InstallPopup (panelH_F_TIP);
				   }
				   else 
				   {
					choise = ConfirmPopup ("Redefinire Functie de Apartenenta", "Sigur doriti sa redefiniti aceasta Functie de Apartenenta ?");
					 if (choise==1)
					 { 
					 DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_7, -1, VAL_IMMEDIATE_DRAW);
					 f_def[def]=0;
					
					if (conf==1)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==2)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==3)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}  
					   
				   	 panelH_F_TIP = LoadPanel (panelHandle, "c:\\CVI85\\Tip_F.uir", 1);
				   InstallPopup (panelH_F_TIP);
					 }
					 
				   } 
			break;
	}
	return 0;
}

int CVICALLBACK def_f_8 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				   def=8;
				   if (f_def[def]!=1)
				   {
				   panelH_F_TIP = LoadPanel (panelHandle, "c:\\CVI85\\Tip_F.uir", 1);
				   InstallPopup (panelH_F_TIP);
				   }
				   else 
				   {
					choise = ConfirmPopup ("Redefinire Functie de Apartenenta", "Sigur doriti sa redefiniti aceasta Functie de Apartenenta ?");
					 if (choise==1)
					 { 
					 DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_8, -1, VAL_IMMEDIATE_DRAW);
					 f_def[def]=0;
					
					if (conf==1)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==2)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==3)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}  
					   
				   	 panelH_F_TIP = LoadPanel (panelHandle, "c:\\CVI85\\Tip_F.uir", 1);
				   InstallPopup (panelH_F_TIP);
					 }
					 
				   } 
			break;
	}
	return 0;
}

int CVICALLBACK def_f_9 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				   def=9;
				   if (f_def[def]!=1)
				   {
				   panelH_F_TIP = LoadPanel (panelHandle, "c:\\CVI85\\Tip_F.uir", 1);
				   InstallPopup (panelH_F_TIP);
				   }
				   else 
				   {
					choise = ConfirmPopup ("Redefinire Functie de Apartenenta", "Sigur doriti sa redefiniti aceasta Functie de Apartenenta ?");
					 if (choise==1)
					 { 
					 DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_9, -1, VAL_IMMEDIATE_DRAW);
					 f_def[def]=0;
					
					if (conf==1)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==2)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==3)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}  
					   
				   	 panelH_F_TIP = LoadPanel (panelHandle, "c:\\CVI85\\Tip_F.uir", 1);
				   InstallPopup (panelH_F_TIP);
					 }
					 
				   } 
			break;
	}
	return 0;
}

int CVICALLBACK def_f_10 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					  def=10; // variabila def reprezinta a cata functie de apartenenta este configurata
				   if (f_def[def]!=1)
				   {
				   panelH_F_TIP = LoadPanel (panelHandle, "c:\\CVI85\\Tip_F.uir", 1);
				   InstallPopup (panelH_F_TIP);
				   }
				   else 
				   {
					choise = ConfirmPopup ("Redefinire Functie de Apartenenta", "Sigur doriti sa redefiniti aceasta Functie de Apartenenta ?");
					 if (choise==1)
					 { 
					 DeleteGraphPlot (panelH_FA_CONF_X, PANEL_GRAPH_F_D_10, -1, VAL_IMMEDIATE_DRAW);
					 f_def[def]=0;
					
					if (conf==1)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_X, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==2)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}
					if (conf==3)
					{
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, plotH_Def[def], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
					}  
					   
				   	 panelH_F_TIP = LoadPanel (panelHandle, "c:\\CVI85\\Tip_F.uir", 1);
				   InstallPopup (panelH_F_TIP);
					 }
					 
				   } 
			break;
	}
	return 0;
}

int CVICALLBACK conf_fa_x (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				 panelH_FA_CONF_X = LoadPanel (panelHandle, "c:\\CVI85\\Conf_F_X.uir", 1);
				 conf=1;
				 if (def_f[1]==1)
				 {
				 choise = ConfirmPopup ("Redefinire Functie de Apartenenta", "Sigur doriti sa redefiniti aceasta Functie de Apartenenta ?"); 
				 	if (choise==1)
				       InstallPopup (panelH_FA_CONF_X);
				 }
				 else
					  InstallPopup (panelH_FA_CONF_X);
			break;
	}
	return 0;
}

int CVICALLBACK conf_f_dx (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				 panelH_FA_CONF_X = LoadPanel (panelHandle, "c:\\CVI85\\Conf_F_X.uir", 1);
				 conf=2;
				 InstallPopup (panelH_FA_CONF_X);
			break;
	}
	return 0;
}

int CVICALLBACK conf_f_y (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				 panelH_FA_CONF_X = LoadPanel (panelHandle, "c:\\CVI85\\Conf_F_X.uir", 1);
				 conf=3;
				 InstallPopup (panelH_FA_CONF_X);
			break;
	}
	return 0;
}

int CVICALLBACK terminare_conf_fa (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					//	panelH_S_MS
						
						//SetCtrlVal (panelH_S_MS, PANEL_NR_D_F_X, NR_F_X);
						DiscardPanel (panelH_FA_CONF);
						
			break;
	}
	return 0;
}



int CVICALLBACK testb (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
				  
				  for(i=0;i<100;i++)
					{
					   testx[i]=i;
					   testy[i]=sigmoidala2(i,3,10,-3,10);
						}
			      PlotXY (panelHandle, PANEL_GRAPH, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_RED);
				
			break;
	}			    
	
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////

int CVICALLBACK back_m (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
						DiscardPanel (panelH_S_MS);
			break;
	}
	return 0;
}

int CVICALLBACK opt_prestabilit (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}

int CVICALLBACK opt_definita (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				   //panelH_FA_CONF = LoadPanel (panelHandle, "c:\\CVI85\\conf_f_apartenenta.uir", 1);
				  //panelH_FA_CONF = LoadPanel (panelHandle, "c:\\Users\\azyl\\Desktop\\Licentza\\CVI85\\conf_f_apartenenta_v_2.uir", 1);
					GetDir (CurrentFolder);
														  // strcat (CurrentFolder, "\\Def_M_Fz.uir");
					panelH_F_TIP = LoadPanel (panelHandle, strcat (CurrentFolder, "\\Def_M_Fz.uir"), 1);
					SetCtrlVal (panelH_F_TIP, PANEL_NR_M_F, NR_F_X);
					InstallPopup (panelH_F_TIP);
			break;
	}
	return 0;
}

int CVICALLBACK select_mod_sim (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				 	GetDir (CurrentFolder);
				 panelH_S_MS = LoadPanel (panelHandle, strcat (CurrentFolder, "\\panou_select_mod_optiune.uir"), 1);
				 InstallPopup (panelH_S_MS);
			break;
	}
	return 0;
}

int CVICALLBACK revenire_a_mod_s (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					DiscardPanel (panelH_FA_CONF);  
			break;
	}
	return 0;
}

int CVICALLBACK ok_param_f_sat_s (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			f_def[def]=1;
						if (tip==1)   // 1 daca se face pentru functia x 2 pt dx  3 pt y
					{
					TIP_F_X[index_e_v][1]=index_t_v;
					GetCtrlVal (panelH_F_SAT_S, PANEL_F_Saturatie_Stanga_A, &TIP_F_X[index_e_v][2]);
					GetCtrlVal (panelH_F_SAT_S, PANEL_F_Saturatie_Stanga_B, &TIP_F_X[index_e_v][3]);
					}
					if (tip==2)
					{
					TIP_F_dX[index_e_v][1]=index_t_v;
					GetCtrlVal (panelH_F_SAT_S, PANEL_F_Saturatie_Stanga_A, &TIP_F_dX[index_e_v][2]);
					GetCtrlVal (panelH_F_SAT_S, PANEL_F_Saturatie_Stanga_B, &TIP_F_dX[index_e_v][3]);
					}
					if (tip==3)
					{
					TIP_F_Y[index_e_v][1]=index_t_v;
					GetCtrlVal (panelH_F_SAT_S, PANEL_F_Saturatie_Stanga_A, &TIP_F_Y[index_e_v][2]);
					GetCtrlVal (panelH_F_SAT_S, PANEL_F_Saturatie_Stanga_B, &TIP_F_Y[index_e_v][3]);
					}
					
					
					GetCtrlVal (panelH_F_SAT_S, PANEL_F_Saturatie_Stanga_A, &a);
					GetCtrlVal (panelH_F_SAT_S, PANEL_F_Saturatie_Stanga_B, &b);
					
					
						for(i=0;i<100;i++)
					{
					   testx[i]=i;
					   testy[i]=satl(i,a,b);
						}
						
					if (def==1)
					{
					 		plotH_Def[1] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_1, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
									   VAL_SOLID, 1, VAL_RED);
					 if (conf==1)
					 		plotH_X[1] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_RED);
					 if (conf==2)
							plotH_dX[1]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_RED);
					 if (conf==3)
							plotH_Y[1] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_RED);
				
					}
					
					DiscardPanel (panelH_F_SAT_S);
			break;
	}
	return 0;
}

int CVICALLBACK f_saturatie_stanga (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					 tip=2;
					 panelH_F_SAT_S = LoadPanel (panelHandle, "c:\\CVI85\\F_Saturatie_Stanga.uir", 1);
					 InstallPopup (panelH_F_SAT_S);
			break;
	}
	return 0;
}

int CVICALLBACK ok_param_f_sat_trapez (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					f_def[def]=1;
					if (conf==1)   // 1 daca se face pentru functia x 2 pt dx  3 pt y
					{
					TIP_F_X[def][1]=tip;
					GetCtrlVal (panelH_F_TRA, PANEL_F_TRAPEZ_A, &TIP_F_X[def][2]);
					GetCtrlVal (panelH_F_TRA, PANEL_F_TRAPEZ_B, &TIP_F_X[def][3]);
					GetCtrlVal (panelH_F_TRA, PANEL_F_TRAPEZ_C, &TIP_F_X[def][4]);
					GetCtrlVal (panelH_F_TRA, PANEL_F_TRAPEZ_D, &TIP_F_X[def][5]);
					}
					if (conf==2)
					{
					TIP_F_dX[def][1]=tip;
					GetCtrlVal (panelH_F_TRA, PANEL_F_TRAPEZ_A, &TIP_F_dX[def][2]);
					GetCtrlVal (panelH_F_TRA, PANEL_F_TRAPEZ_B, &TIP_F_dX[def][3]);
					GetCtrlVal (panelH_F_TRA, PANEL_F_TRAPEZ_C, &TIP_F_dX[def][4]);
					GetCtrlVal (panelH_F_TRA, PANEL_F_TRAPEZ_D, &TIP_F_dX[def][5]);
					
					}
					if (conf==3)
					{
					TIP_F_Y[def][1]=tip;
					GetCtrlVal (panelH_F_TRA, PANEL_F_TRAPEZ_A, &TIP_F_Y[def][2]);
					GetCtrlVal (panelH_F_TRA, PANEL_F_TRAPEZ_B, &TIP_F_Y[def][3]);
					GetCtrlVal (panelH_F_TRA, PANEL_F_TRAPEZ_C, &TIP_F_Y[def][4]);
					GetCtrlVal (panelH_F_TRA, PANEL_F_TRAPEZ_D, &TIP_F_Y[def][5]);
					}
					
					
					GetCtrlVal (panelH_F_TRA, PANEL_F_TRAPEZ_A, &a1);
					GetCtrlVal (panelH_F_TRA, PANEL_F_TRAPEZ_B, &b1);
					GetCtrlVal (panelH_F_TRA, PANEL_F_TRAPEZ_C, &c1);
					GetCtrlVal (panelH_F_TRA, PANEL_F_TRAPEZ_D, &d1);
					
					
					
						for(i=0;i<100;i++)
					{
					   testx[i]=i;
					   testy[i]=pi(i,a1,c1,d1,b1);
						}
						
					if (def==1)
					{
					 		plotH_Def[1] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_1, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
									   VAL_SOLID, 1, VAL_RED);
					 if (conf==1)
					 		plotH_X[1] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_RED);
					 if (conf==2)
							plotH_dX[1]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_RED);
					 if (conf==3)
							plotH_Y[1] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_RED);
					}
					if (def==2)
					{
					 plotH_Def[2] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_2, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_BLUE);
					 if (conf==1)
					 		plotH_X[2] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_BLUE);
					 if (conf==2)
							plotH_dX[2]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_BLUE);
					 if (conf==3)
							plotH_Y[2] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_BLUE);
					}
					if (def==3)
					{
					 plotH_Def[3] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_3, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_GREEN);
					 if (conf==1)
					 		plotH_X[3] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_GREEN);
					 if (conf==2)
							plotH_dX[3]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_GREEN);
					 if (conf==3)
							plotH_Y[3] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_GREEN);
					}
					if (def==4)
					{
					 plotH_Def[4] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_4, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_CYAN);
					 if (conf==1)
					 		plotH_X[4] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_CYAN);
					 if (conf==2)
							plotH_dX[4]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_CYAN);
					 if (conf==3)
							plotH_Y[4] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_CYAN);
					}
					if (def==5)
					{
					 plotH_Def[5] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_5, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_MAGENTA);
					 if (conf==1)
					 		plotH_X[5] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_MAGENTA);
					 if (conf==2)
							plotH_dX[5]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_MAGENTA);
					 if (conf==3)
							plotH_Y[5] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_MAGENTA);
					}
					if (def==6)
					{
					 plotH_Def[6] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_6, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_YELLOW);
					 if (conf==1)
					 		plotH_X[6] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_YELLOW);
					 if (conf==2)
							plotH_dX[6]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_YELLOW);
					 if (conf==3)
							plotH_Y[6] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_YELLOW);
					}
					if (def==7)
					{
					 plotH_Def[7] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_7, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_BLACK);
					 if (conf==1)
					 		plotH_X[7] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_BLACK);
					 if (conf==2)
							plotH_dX[7]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_BLACK);
					 if (conf==3)
							plotH_Y[7] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_BLACK);
					}
					if (def==8)
					{
					 plotH_Def[8] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_8, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_DK_BLUE);
					 if (conf==1)
					 		plotH_X[8] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_DK_BLUE);
					 if (conf==2)
							plotH_dX[8]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_BLUE);
					 if (conf==3)
							plotH_Y[8] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_BLUE);
					}
					if (def==9)
					{
					 plotH_Def[9] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_9, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_DK_RED);
					 if (conf==1)
					 		plotH_X[9] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_DK_RED);
					 if (conf==2)
							plotH_dX[9]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_RED);
					 if (conf==3)
							plotH_Y[9] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_RED);
					}
					if (def==10)
					{
					 plotH_Def[10] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_10, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											 VAL_SOLID, 1, VAL_DK_GREEN);
					 if (conf==1)
					 		plotH_X[10] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_DK_GREEN);
					 if (conf==2)
							plotH_dX[10]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_GREEN);
					 if (conf==3)
							plotH_Y[10] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_GREEN);
					}
					
					
					
					DiscardPanel (panelH_F_TIP);
					DiscardPanel (panelH_F_TRA);
			break;
	}
	return 0;
}

int CVICALLBACK ok_param_f_sat_d (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					f_def[def]=1;
					if (conf==1)   // 1 daca se face pentru functia x 2 pt dx  3 pt y
					{
					TIP_F_X[def][1]=tip;
					GetCtrlVal (panelH_F_SAT_D, PANEL_F_Saturatie_Dreapta_A, &TIP_F_X[def][2]);
					GetCtrlVal (panelH_F_SAT_D, PANEL_F_Saturatie_Dreapta_B, &TIP_F_X[def][3]);
					}
					if (conf==2)
					{
					TIP_F_dX[def][1]=tip;
					GetCtrlVal (panelH_F_SAT_D, PANEL_F_Saturatie_Dreapta_A, &TIP_F_dX[def][2]);
					GetCtrlVal (panelH_F_SAT_D, PANEL_F_Saturatie_Dreapta_B, &TIP_F_dX[def][3]);
					}
					if (conf==3)
					{
					TIP_F_Y[def][1]=tip;
					GetCtrlVal (panelH_F_SAT_D, PANEL_F_Saturatie_Dreapta_A, &TIP_F_Y[def][2]);
					GetCtrlVal (panelH_F_SAT_D, PANEL_F_Saturatie_Dreapta_B, &TIP_F_Y[def][3]);
					}
					
					
					GetCtrlVal (panelH_F_SAT_D, PANEL_F_Saturatie_Dreapta_A, &a);
					GetCtrlVal (panelH_F_SAT_D, PANEL_F_Saturatie_Dreapta_B, &b);
					
					
						for(i=0;i<100;i++)
					{
					   testx[i]=i;
					   testy[i]=gama(i,a,b);
						}
						
					if (def==1)
					{
					 		plotH_Def[1] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_1, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
									   VAL_SOLID, 1, VAL_RED);
					 if (conf==1)
					 		plotH_X[1] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_RED);
					 if (conf==2)
							plotH_dX[1]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_RED);
					 if (conf==3)
							plotH_Y[1] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_RED);
					}
					if (def==2)
					{
					 plotH_Def[2] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_2, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_BLUE);
					 if (conf==1)
					 		plotH_X[2] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_BLUE);
					 if (conf==2)
							plotH_dX[2]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_BLUE);
					 if (conf==3)
							plotH_Y[2] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_BLUE);
					}
					if (def==3)
					{
					 plotH_Def[3] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_3, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_GREEN);
					 if (conf==1)
					 		plotH_X[3] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_GREEN);
					 if (conf==2)
							plotH_dX[3]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_GREEN);
					 if (conf==3)
							plotH_Y[3] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_GREEN);
					}
					if (def==4)
					{
					 plotH_Def[4] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_4, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_CYAN);
					 if (conf==1)
					 		plotH_X[4] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_CYAN);
					 if (conf==2)
							plotH_dX[4]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_CYAN);
					 if (conf==3)
							plotH_Y[4] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_CYAN);
					}
					if (def==5)
					{
					 plotH_Def[5] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_5, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_MAGENTA);
					 if (conf==1)
					 		plotH_X[5] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_MAGENTA);
					 if (conf==2)
							plotH_dX[5]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_MAGENTA);
					 if (conf==3)
							plotH_Y[5] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_MAGENTA);
					}
					if (def==6)
					{
					 plotH_Def[6] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_6, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_YELLOW);
					 if (conf==1)
					 		plotH_X[6] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_YELLOW);
					 if (conf==2)
							plotH_dX[6]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_YELLOW);
					 if (conf==3)
							plotH_Y[6] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_YELLOW);
					}
					if (def==7)
					{
					 plotH_Def[7] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_7, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_BLACK);
					 if (conf==1)
					 		plotH_X[7] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_BLACK);
					 if (conf==2)
							plotH_dX[7]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_BLACK);
					 if (conf==3)
							plotH_Y[7] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_BLACK);
					}
					if (def==8)
					{
					 plotH_Def[8] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_8, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_DK_BLUE);
					 if (conf==1)
					 		plotH_X[8] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_DK_BLUE);
					 if (conf==2)
							plotH_dX[8]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_BLUE);
					 if (conf==3)
							plotH_Y[8] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_BLUE);
					}
					if (def==9)
					{
					 plotH_Def[9] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_9, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_DK_RED);
					 if (conf==1)
					 		plotH_X[9] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_DK_RED);
					 if (conf==2)
							plotH_dX[9]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_RED);
					 if (conf==3)
							plotH_Y[9] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_RED);
					}
					if (def==10)
					{
					 plotH_Def[10] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_10, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											 VAL_SOLID, 1, VAL_DK_GREEN);
					 if (conf==1)
					 		plotH_X[10] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_DK_GREEN);
					 if (conf==2)
							plotH_dX[10]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_GREEN);
					 if (conf==3)
							plotH_Y[10] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_GREEN);
					}
					
					
					
					DiscardPanel (panelH_F_TIP);
					DiscardPanel (panelH_F_SAT_D);
			break;
	}
	return 0;
}

int CVICALLBACK f_saturatie_dreapta (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					 tip=4;
					 panelH_F_SAT_D = LoadPanel (panelHandle, "c:\\CVI85\\Functie_Saturatie_Dreapta.uir", 1);
					 InstallPopup (panelH_F_SAT_D);
			break;
	}
	return 0;
}

int CVICALLBACK reg_brf_d (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			GetDir (CurrentFolder);		
			panelH_F_BRF_D = LoadPanel (panelHandle, strcat (CurrentFolder, "\\Tabela_BRF.uir"), 1);
					//	
					
					
					InsertTableRows (panelH_F_BRF_D, PANEL_TABLE_BRF, -1, NR_F_dX, VAL_CELL_RING);
					InsertTableColumns (panelH_F_BRF_D, PANEL_TABLE_BRF, -1, NR_F_X, VAL_CELL_RING);
							 
					for(i=0;i<NR_F_dX;i++)
					{
						for(j=0;j<NR_F_X;j++)
						{
							for(k=0;k<NR_F_Y;k++)
							{
								InsertTableCellRingItem (panelH_F_BRF_D, PANEL_TABLE_BRF, MakePoint(j+1,i+1), k, mult_f_e_Y[k]);
							}
							SetTableColumnAttribute (panelH_F_BRF_D, PANEL_TABLE_BRF, j+1, ATTR_USE_LABEL_TEXT, 1);
							SetTableColumnAttribute (panelH_F_BRF_D, PANEL_TABLE_BRF, j+1, ATTR_LABEL_TEXT, mult_f_e_X[j]);
							
							
						}
						    SetTableRowAttribute (panelH_F_BRF_D, PANEL_TABLE_BRF, i+1, ATTR_USE_LABEL_TEXT, 1);
							SetTableRowAttribute (panelH_F_BRF_D, PANEL_TABLE_BRF, i+1, ATTR_LABEL_TEXT, mult_f_e_dX[i]);
					}
					
						SetTableColumnAttribute (panelH_F_BRF_D, PANEL_TABLE_BRF, -1, ATTR_SIZE_MODE, VAL_USE_EXPLICIT_SIZE);
						SetTableColumnAttribute (panelH_F_BRF_D, PANEL_TABLE_BRF, -1, ATTR_COLUMN_WIDTH, 150);
						SetTableRowAttribute (panelH_F_BRF_D, PANEL_TABLE_BRF, -1, ATTR_SIZE_MODE, VAL_SIZE_TO_CELL_FONT);
						InstallPopup (panelH_F_BRF_D); 
			break;
	}
	return 0;
}

int CVICALLBACK select_m_d (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			GetDir (CurrentFolder);		
			
			
				   panelH_S_MD = LoadPanel (panelHandle, strcat (CurrentFolder,"\\Selectare_Metode_Defuzificare.uir"), 1);
				   SetCtrlIndex (panelH_S_MD, PANEL_RING_S_MET_D, (TIP_M-1));
				  InstallPopup (panelH_S_MD);
			break;
	}
	return 0;
}



int CVICALLBACK revenire_s_m (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					   DiscardPanel (panelH_S_MD);
			break;
	}
	return 0;
}

int CVICALLBACK revenire_brf (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				  DiscardPanel (panelH_F_BRF_D);
			break;
	}
	return 0;
}

int CVICALLBACK f_gausiana (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				   	 tip=5;
					 panelH_F_GAUSS = LoadPanel (panelHandle, "c:\\CVI85\\F_GAUSS.uir", 1);
					 InstallPopup (panelH_F_GAUSS);
			break;
	}
	return 0;
}

int CVICALLBACK ok_param_f_sat_gauss (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			f_def[def]=1;
						if (conf==1)   // 1 daca se face pentru functia x 2 pt dx  3 pt y
					{
					TIP_F_X[def][1]=tip;
					GetCtrlVal (panelH_F_GAUSS, PANEL_F_GAUSS_C, &TIP_F_X[def][2]);
					GetCtrlVal (panelH_F_GAUSS, PANEL_F_GAUSS_S, &TIP_F_X[def][3]);
					}
					if (conf==2)
					{
					TIP_F_dX[def][1]=tip;
					GetCtrlVal (panelH_F_GAUSS, PANEL_F_GAUSS_C, &TIP_F_dX[def][2]);
					GetCtrlVal (panelH_F_GAUSS, PANEL_F_GAUSS_S, &TIP_F_dX[def][3]);
					}
					if (conf==3)
					{
					TIP_F_Y[def][1]=tip;
					GetCtrlVal (panelH_F_GAUSS, PANEL_F_GAUSS_C, &TIP_F_Y[def][2]);
					GetCtrlVal (panelH_F_GAUSS, PANEL_F_GAUSS_S, &TIP_F_Y[def][3]);
					}
					
					
					GetCtrlVal (panelH_F_GAUSS, PANEL_F_GAUSS_C, &a);
					GetCtrlVal (panelH_F_GAUSS, PANEL_F_GAUSS_S, &b);
					
					
						for(i=0;i<100;i++)
					{
					   testx[i]=i;
					   testy[i]=gauss(i,a,b);
						}
						
					if (def==1)
					{
					 		plotH_Def[1] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_1, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
									   VAL_SOLID, 1, VAL_RED);
					 if (conf==1)
					 		plotH_X[1] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_RED);
					 if (conf==2)
							plotH_dX[1]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_RED);
					 if (conf==3)
							plotH_Y[1] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_RED);
					}
					if (def==2)
					{
					 plotH_Def[2] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_2, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_BLUE);
					 if (conf==1)
					 		plotH_X[2] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_BLUE);
					 if (conf==2)
							plotH_dX[2]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_BLUE);
					 if (conf==3)
							plotH_Y[2] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_BLUE);
					}
					if (def==3)
					{
					 plotH_Def[3] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_3, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_GREEN);
					 if (conf==1)
					 		plotH_X[3] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_GREEN);
					 if (conf==2)
							plotH_dX[3]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_GREEN);
					 if (conf==3)
							plotH_Y[3] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_GREEN);
					}
					if (def==4)
					{
					 plotH_Def[4] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_4, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_CYAN);
					 if (conf==1)
					 		plotH_X[4] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_CYAN);
					 if (conf==2)
							plotH_dX[4]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_CYAN);
					 if (conf==3)
							plotH_Y[4] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_CYAN);
					}
					if (def==5)
					{
					 plotH_Def[5] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_5, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_MAGENTA);
					 if (conf==1)
					 		plotH_X[5] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_MAGENTA);
					 if (conf==2)
							plotH_dX[5]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_MAGENTA);
					 if (conf==3)
							plotH_Y[5] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_MAGENTA);
					}
					if (def==6)
					{
					 plotH_Def[6] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_6, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_YELLOW);
					 if (conf==1)
					 		plotH_X[6] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_YELLOW);
					 if (conf==2)
							plotH_dX[6]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_YELLOW);
					 if (conf==3)
							plotH_Y[6] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_YELLOW);
					}
					if (def==7)
					{
					 plotH_Def[7] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_7, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_BLACK);
					 if (conf==1)
					 		plotH_X[7] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_BLACK);
					 if (conf==2)
							plotH_dX[7]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_BLACK);
					 if (conf==3)
							plotH_Y[7] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_BLACK);
					}
					if (def==8)
					{
					 plotH_Def[8] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_8, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_DK_BLUE);
					 if (conf==1)
					 		plotH_X[8] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_DK_BLUE);
					 if (conf==2)
							plotH_dX[8]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_BLUE);
					 if (conf==3)
							plotH_Y[8] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_BLUE);
					}
					if (def==9)
					{
					 plotH_Def[9] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_9, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_DK_RED);
					 if (conf==1)
					 		plotH_X[9] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_DK_RED);
					 if (conf==2)
							plotH_dX[9]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_RED);
					 if (conf==3)
							plotH_Y[9] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_RED);
					}
					if (def==10)
					{
					 plotH_Def[10] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_10, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											 VAL_SOLID, 1, VAL_GREEN);
					 if (conf==1)
					 		plotH_X[10] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_GREEN);
					 if (conf==2)
							plotH_dX[10]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_GREEN);
					 if (conf==3)
							plotH_Y[10] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_GREEN);
					}
					
					
				
					DiscardPanel (panelH_F_TIP);
					DiscardPanel (panelH_F_GAUSS);
			break;
	}
	return 0;
}

int CVICALLBACK f_s_shape (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				     tip=6;
					 panelH_F_S_SHAPE = LoadPanel (panelHandle, "c:\\CVI85\\F_S_Shape.uir", 1);
					 InstallPopup (panelH_F_S_SHAPE);
			break;
	}
	return 0;
}

int CVICALLBACK f_z_shape (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					 tip=7;
					 panelH_F_Z_SHAPE = LoadPanel (panelHandle, "c:\\CVI85\\F_Z_Shape.uir", 1);
					 InstallPopup (panelH_F_Z_SHAPE);
			break;
	}
	return 0;
}

int CVICALLBACK ok_param_f_s_shape (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				   f_def[def]=1;
						if (conf==1)   // 1 daca se face pentru functia x 2 pt dx  3 pt y
					{
					TIP_F_X[def][1]=tip;
					GetCtrlVal (panelH_F_S_SHAPE, PANEL_F_S_SHAPE_A, &TIP_F_X[def][2]);
					GetCtrlVal (panelH_F_S_SHAPE, PANEL_F_S_SHAPE_B, &TIP_F_X[def][3]);
					}
					if (conf==2)
					{
					TIP_F_dX[def][1]=tip;
					GetCtrlVal (panelH_F_S_SHAPE, PANEL_F_S_SHAPE_A, &TIP_F_dX[def][2]);
					GetCtrlVal (panelH_F_S_SHAPE, PANEL_F_S_SHAPE_B, &TIP_F_dX[def][3]);
					}
					if (conf==3)
					{
					TIP_F_Y[def][1]=tip;
					GetCtrlVal (panelH_F_S_SHAPE, PANEL_F_S_SHAPE_A, &TIP_F_Y[def][2]);
					GetCtrlVal (panelH_F_S_SHAPE, PANEL_F_S_SHAPE_B, &TIP_F_Y[def][3]);
					}
					
					
					GetCtrlVal (panelH_F_S_SHAPE, PANEL_F_S_SHAPE_A, &a);
					GetCtrlVal (panelH_F_S_SHAPE, PANEL_F_S_SHAPE_B, &b);
					
					
						for(i=0;i<100;i++)
					{
					   testx[i]=i;
					   testy[i]=sshape(i,a,b);
						}
						
					if (def==1)
					{
					 		plotH_Def[1] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_1, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
									   VAL_SOLID, 1, VAL_RED);
					 if (conf==1)
					 		plotH_X[1] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_RED);
					 if (conf==2)
							plotH_dX[1]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_RED);
					 if (conf==3)
							plotH_Y[1] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_RED);
					}
					if (def==2)
					{
					 plotH_Def[2] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_2, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_BLUE);
					 if (conf==1)
					 		plotH_X[2] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_BLUE);
					 if (conf==2)
							plotH_dX[2]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_BLUE);
					 if (conf==3)
							plotH_Y[2] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_BLUE);
					}
					if (def==3)
					{
					 plotH_Def[3] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_3, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_GREEN);
					 if (conf==1)
					 		plotH_X[3] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_GREEN);
					 if (conf==2)
							plotH_dX[3]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_GREEN);
					 if (conf==3)
							plotH_Y[3] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_GREEN);
					}
					if (def==4)
					{
					 plotH_Def[4] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_4, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_CYAN);
					 if (conf==1)
					 		plotH_X[4] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_CYAN);
					 if (conf==2)
							plotH_dX[4]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_CYAN);
					 if (conf==3)
							plotH_Y[4] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_CYAN);
					}
					if (def==5)
					{
					 plotH_Def[5] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_5, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_MAGENTA);
					 if (conf==1)
					 		plotH_X[5] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_MAGENTA);
					 if (conf==2)
							plotH_dX[5]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_MAGENTA);
					 if (conf==3)
							plotH_Y[5] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_MAGENTA);
					}
					if (def==6)
					{
					 plotH_Def[6] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_6, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_YELLOW);
					 if (conf==1)
					 		plotH_X[6] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_YELLOW);
					 if (conf==2)
							plotH_dX[6]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_YELLOW);
					 if (conf==3)
							plotH_Y[6] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_YELLOW);
					}
					if (def==7)
					{
					 plotH_Def[7] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_7, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_BLACK);
					 if (conf==1)
					 		plotH_X[7] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_BLACK);
					 if (conf==2)
							plotH_dX[7]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_BLACK);
					 if (conf==3)
							plotH_Y[7] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_BLACK);
					}
					if (def==8)
					{
					 plotH_Def[8] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_8, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_DK_BLUE);
					 if (conf==1)
					 		plotH_X[8] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_DK_BLUE);
					 if (conf==2)
							plotH_dX[8]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_BLUE);
					 if (conf==3)
							plotH_Y[8] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_BLUE);
					}
					if (def==9)
					{
					 plotH_Def[9] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_9, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_DK_RED);
					 if (conf==1)
					 		plotH_X[9] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_DK_RED);
					 if (conf==2)
							plotH_dX[9]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_RED);
					 if (conf==3)
							plotH_Y[9] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_RED);
					}
					if (def==10)
					{
					 plotH_Def[10] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_10, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											 VAL_SOLID, 1, VAL_GREEN);
					 if (conf==1)
					 		plotH_X[10] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_GREEN);
					 if (conf==2)
							plotH_dX[10]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_GREEN);
					 if (conf==3)
							plotH_Y[10] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_GREEN);
					}
					
					
				
					DiscardPanel (panelH_F_TIP);
					DiscardPanel (panelH_F_S_SHAPE);
			break;
	}
	return 0;
}

int CVICALLBACK ok_param_f_z_shape (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				   f_def[def]=1;
						if (conf==1)   // 1 daca se face pentru functia x 2 pt dx  3 pt y
					{
					TIP_F_X[def][1]=tip;
					GetCtrlVal (panelH_F_Z_SHAPE, PANEL_F_Z_SHAPE_A, &TIP_F_X[def][2]);
					GetCtrlVal (panelH_F_Z_SHAPE, PANEL_F_Z_SHAPE_B, &TIP_F_X[def][3]);
					}
					if (conf==2)
					{
					TIP_F_dX[def][1]=tip;
					GetCtrlVal (panelH_F_Z_SHAPE, PANEL_F_Z_SHAPE_A, &TIP_F_dX[def][2]);
					GetCtrlVal (panelH_F_Z_SHAPE, PANEL_F_Z_SHAPE_B, &TIP_F_dX[def][3]);
					}
					if (conf==3)
					{
					TIP_F_Y[def][1]=tip;
					GetCtrlVal (panelH_F_Z_SHAPE, PANEL_F_Z_SHAPE_A, &TIP_F_Y[def][2]);
					GetCtrlVal (panelH_F_Z_SHAPE, PANEL_F_Z_SHAPE_B, &TIP_F_Y[def][3]);
					}
					
					
					GetCtrlVal (panelH_F_Z_SHAPE, PANEL_F_Z_SHAPE_A, &a);
					GetCtrlVal (panelH_F_Z_SHAPE, PANEL_F_Z_SHAPE_B, &b);
					
					
						for(i=0;i<100;i++)
					{
					   testx[i]=i;
					   testy[i]=zshape(i,a,b);
						}
						
					if (def==1)
					{
					 		plotH_Def[1] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_1, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
									   VAL_SOLID, 1, VAL_RED);
					 if (conf==1)
					 		plotH_X[1] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_RED);
					 if (conf==2)
							plotH_dX[1]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_RED);
					 if (conf==3)
							plotH_Y[1] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_RED);
					}
					if (def==2)
					{
					 plotH_Def[2] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_2, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_BLUE);
					 if (conf==1)
					 		plotH_X[2] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_BLUE);
					 if (conf==2)
							plotH_dX[2]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_BLUE);
					 if (conf==3)
							plotH_Y[2] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_BLUE);
					}
					if (def==3)
					{
					 plotH_Def[3] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_3, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_GREEN);
					 if (conf==1)
					 		plotH_X[3] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_GREEN);
					 if (conf==2)
							plotH_dX[3]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_GREEN);
					 if (conf==3)
							plotH_Y[3] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_GREEN);
					}
					if (def==4)
					{
					 plotH_Def[4] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_4, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_CYAN);
					 if (conf==1)
					 		plotH_X[4] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_CYAN);
					 if (conf==2)
							plotH_dX[4]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_CYAN);
					 if (conf==3)
							plotH_Y[4] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_CYAN);
					}
					if (def==5)
					{
					 plotH_Def[5] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_5, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_MAGENTA);
					 if (conf==1)
					 		plotH_X[5] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_MAGENTA);
					 if (conf==2)
							plotH_dX[5]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_MAGENTA);
					 if (conf==3)
							plotH_Y[5] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_MAGENTA);
					}
					if (def==6)
					{
					 plotH_Def[6] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_6, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_YELLOW);
					 if (conf==1)
					 		plotH_X[6] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_YELLOW);
					 if (conf==2)
							plotH_dX[6]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_YELLOW);
					 if (conf==3)
							plotH_Y[6] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_YELLOW);
					}
					if (def==7)
					{
					 plotH_Def[7] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_7, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_BLACK);
					 if (conf==1)
					 		plotH_X[7] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_BLACK);
					 if (conf==2)
							plotH_dX[7]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_BLACK);
					 if (conf==3)
							plotH_Y[7] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_BLACK);
					}
					if (def==8)
					{
					 plotH_Def[8] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_8, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_DK_BLUE);
					 if (conf==1)
					 		plotH_X[8] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_DK_BLUE);
					 if (conf==2)
							plotH_dX[8]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_BLUE);
					 if (conf==3)
							plotH_Y[8] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_BLUE);
					}
					if (def==9)
					{
					 plotH_Def[9] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_9, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											VAL_SOLID, 1, VAL_DK_RED);
					 if (conf==1)
					 		plotH_X[9] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_DK_RED);
					 if (conf==2)
							plotH_dX[9]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_RED);
					 if (conf==3)
							plotH_Y[9] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_DK_RED);
					}
					if (def==10)
					{
					 plotH_Def[10] = PlotXY (panelH_FA_CONF_X, PANEL_GRAPH_F_D_10, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE,
											 VAL_SOLID, 1, VAL_GREEN);
					 if (conf==1)
					 		plotH_X[10] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_X, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_GREEN);
					 if (conf==2)
							plotH_dX[10]= PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_dX, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_GREEN);
					 if (conf==3)
							plotH_Y[10] = PlotXY (panelH_FA_CONF, PANEL_GRAPH_F_D_Y, &testx, &testy, 100, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
									VAL_GREEN);
					}
					
					
				
					DiscardPanel (panelH_F_TIP);
					DiscardPanel (panelH_F_Z_SHAPE);
			break;
	}
	return 0;
}





int CVICALLBACK def_m_fz (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					GetCtrlIndex (panelH_F_TIP, PANEL_DEF_M_FZ, &index_e);
					GetValueFromIndex (panelH_F_TIP, PANEL_DEF_M_FZ, index_e, &index_e_v);
			
					if(tip==1)
				 {
				 	SetCtrlVal (panelH_F_TIP, PANEL_PARAM_A, TIP_F_X[index_e_v][1]);
					SetCtrlVal (panelH_F_TIP, PANEL_PARAM_B, TIP_F_X[index_e_v][2]);
					SetCtrlVal (panelH_F_TIP, PANEL_PARAM_C, TIP_F_X[index_e_v][3]);
					SetCtrlVal (panelH_F_TIP, PANEL_PARAM_D, TIP_F_X[index_e_v][4]);
				 }
				 else
					 if(tip==2)
				 {
				 	SetCtrlVal (panelH_F_TIP, PANEL_PARAM_A, TIP_F_dX[index_e_v][1]);
					SetCtrlVal (panelH_F_TIP, PANEL_PARAM_B, TIP_F_dX[index_e_v][2]);
					SetCtrlVal (panelH_F_TIP, PANEL_PARAM_C, TIP_F_dX[index_e_v][3]);
					SetCtrlVal (panelH_F_TIP, PANEL_PARAM_D, TIP_F_dX[index_e_v][4]);
				 }
					 else
						 if(tip==3)
				 {
				 	SetCtrlVal (panelH_F_TIP, PANEL_PARAM_A, TIP_F_Y[index_e_v][1]);
					SetCtrlVal (panelH_F_TIP, PANEL_PARAM_B, TIP_F_Y[index_e_v][2]);
					SetCtrlVal (panelH_F_TIP, PANEL_PARAM_C, TIP_F_Y[index_e_v][3]);
					SetCtrlVal (panelH_F_TIP, PANEL_PARAM_D, TIP_F_Y[index_e_v][4]);
				 }
			
						 
						 
						 
						 
						 
					DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, -1, VAL_IMMEDIATE_DRAW);
			
			
			
				    SetCtrlAttribute (panelH_F_TIP, PANEL_DEF_T_M, ATTR_DIMMED, 0);
				   
				    GetCtrlIndex (panelH_F_TIP, PANEL_DEF_M_FZ, &index_e);
			 		GetValueFromIndex (panelH_F_TIP, PANEL_DEF_M_FZ, index_e, &index_e_v);
			 
			 
			  			 SetCtrlVal (panelH_F_TIP, PANEL_RADIOBUTTON_M_F, 1);
						 SetCtrlVal (panelH_F_TIP, PANEL_RADIOBUTTON_F_F, 0);
						 SetCtrlAttribute (panelH_F_TIP, PANEL_GRAPH_F, ATTR_VISIBLE, 1);
						 SetCtrlAttribute (panelH_F_TIP, PANEL_GRAPH_F_X, ATTR_VISIBLE, 0);
						 SetCtrlAttribute (panelH_F_TIP, PANEL_GRAPH_F_dX, ATTR_VISIBLE, 0);
						 SetCtrlAttribute (panelH_F_TIP, PANEL_GRAPH_F_Y, ATTR_VISIBLE, 0);
			 
			 
			 
			 if (tip==1)
			 SetCtrlVal (panelH_F_TIP, PANEL_ETICHETA_M, mult_f_e_X[index_e]);
			 else
				 if (tip==2)
					SetCtrlVal (panelH_F_TIP, PANEL_ETICHETA_M, mult_f_e_dX[index_e]);
				 else
					 if (tip==3)
						 SetCtrlVal (panelH_F_TIP, PANEL_ETICHETA_M, mult_f_e_Y[index_e]);
				   
			break;
			
		case EVENT_VAL_CHANGED:
			 GetCtrlIndex (panelH_F_TIP, PANEL_DEF_M_FZ, &index_e);
			 GetValueFromIndex (panelH_F_TIP, PANEL_DEF_M_FZ, index_e, &index_e_v);
			 
			 DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, -1, VAL_IMMEDIATE_DRAW);
			 
			 
			 
			 if (tip==1)
			 SetCtrlVal (panelH_F_TIP, PANEL_ETICHETA_M, mult_f_e_X[index_e]);
			 else
				 if (tip==2)
					SetCtrlVal (panelH_F_TIP, PANEL_ETICHETA_M, mult_f_e_dX[index_e]);
				 else
					 if (tip==3)
						 SetCtrlVal (panelH_F_TIP, PANEL_ETICHETA_M, mult_f_e_Y[index_e]);
			break;
	}
	return 0;
}

int CVICALLBACK rev_d_m_f (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				    DiscardPanel (panelH_FA_CONF);
			break;
		
		case EVENT_VAL_CHANGED:
			//def=GetCtrlVal (, , ) ;
			
			break;
	}
	return 0;
}

int CVICALLBACK eticheta_m (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
		
		case EVENT_VAL_CHANGED:
				 GetCtrlIndex (panelH_F_TIP, PANEL_DEF_M_FZ, &index_e);
				 GetValueFromIndex (panelH_F_TIP, PANEL_DEF_M_FZ, index_e, &index_e_v);
				 if (tip==1)
				 {
				 	GetCtrlVal (panelH_F_TIP, PANEL_ETICHETA_M, mult_f_e_X[index_e]);
				 	ReplaceListItem (panelH_F_TIP, PANEL_DEF_M_FZ, index_e, mult_f_e_X[index_e], index_e_v);
				 }
				  else
					  if (tip==2)
				 {
				 	GetCtrlVal (panelH_F_TIP, PANEL_ETICHETA_M, mult_f_e_dX[index_e]);
				 	ReplaceListItem (panelH_F_TIP, PANEL_DEF_M_FZ, index_e, mult_f_e_dX[index_e], index_e_v);
				 }
				 else
					 if (tip==3)
				 {
				 	GetCtrlVal (panelH_F_TIP, PANEL_ETICHETA_M, mult_f_e_Y[index_e]);
				 	ReplaceListItem (panelH_F_TIP, PANEL_DEF_M_FZ, index_e, mult_f_e_Y[index_e], index_e_v);
				 }
				 
				 
				 
			break;
	}
	return 0;
}

int CVICALLBACK def_f_fz (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{	
		case EVENT_VAL_CHANGED:
			GetCtrlIndex (panelH_F_TIP, PANEL_DEF_F_FZ, &index);
			GetValueFromIndex (panelH_F_TIP, PANEL_DEF_F_FZ, index, &tip);
			
			 DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, -1, VAL_IMMEDIATE_DRAW);
			
			if (tip==1)
				SetCtrlVal (panelH_F_TIP, PANEL_NR_M_F, NR_F_X);
			else
				if (tip==2)
					SetCtrlVal (panelH_F_TIP, PANEL_NR_M_F, NR_F_dX);
				else
					if (tip==3)
					   SetCtrlVal (panelH_F_TIP, PANEL_NR_M_F, NR_F_Y);
			
			break;
			
		case EVENT_COMMIT:
				   
					SetCtrlAttribute (panelH_F_TIP, PANEL_DEF_M_FZ, ATTR_DIMMED, 0);
					SetCtrlAttribute (panelH_F_TIP, PANEL_ETICHETA_M, ATTR_DIMMED, 0);
			
					ClearListCtrl (panelH_F_TIP, PANEL_DEF_M_FZ);
				   
					
					if(tip==1)
				 {
				 	SetCtrlVal (panelH_F_TIP, PANEL_PARAM_A, TIP_F_X[index_e_v][2]);
					SetCtrlVal (panelH_F_TIP, PANEL_PARAM_B, TIP_F_X[index_e_v][3]);
					SetCtrlVal (panelH_F_TIP, PANEL_PARAM_C, TIP_F_X[index_e_v][4]);
					SetCtrlVal (panelH_F_TIP, PANEL_PARAM_D, TIP_F_X[index_e_v][5]);
				 }
				 else
					 if(tip==2)
				 {
				 	SetCtrlVal (panelH_F_TIP, PANEL_PARAM_A, TIP_F_dX[index_e_v][2]);
					SetCtrlVal (panelH_F_TIP, PANEL_PARAM_B, TIP_F_dX[index_e_v][3]);
					SetCtrlVal (panelH_F_TIP, PANEL_PARAM_C, TIP_F_dX[index_e_v][4]);
					SetCtrlVal (panelH_F_TIP, PANEL_PARAM_D, TIP_F_dX[index_e_v][5]);
				 }
					 else
						 if(tip==3)
				 {
				 	SetCtrlVal (panelH_F_TIP, PANEL_PARAM_A, TIP_F_Y[index_e_v][2]);
					SetCtrlVal (panelH_F_TIP, PANEL_PARAM_B, TIP_F_Y[index_e_v][3]);
					SetCtrlVal (panelH_F_TIP, PANEL_PARAM_C, TIP_F_Y[index_e_v][4]);
					SetCtrlVal (panelH_F_TIP, PANEL_PARAM_D, TIP_F_Y[index_e_v][5]);
				 }
				   
					
						 SetCtrlVal (panelH_F_TIP, PANEL_RADIOBUTTON_M_F, 0);
						 SetCtrlVal (panelH_F_TIP, PANEL_RADIOBUTTON_F_F, 1);
						 SetCtrlAttribute (panelH_F_TIP, PANEL_GRAPH_F, ATTR_VISIBLE, 0);
						 if(tip==1)
						 {
						 SetCtrlAttribute (panelH_F_TIP, PANEL_GRAPH_F_X, ATTR_VISIBLE, 1);
						 SetCtrlAttribute (panelH_F_TIP, PANEL_GRAPH_F_dX, ATTR_VISIBLE, 0);
						 SetCtrlAttribute (panelH_F_TIP, PANEL_GRAPH_F_Y, ATTR_VISIBLE, 0);
						 }
						 else
							 if(tip==2)
							 {
								SetCtrlAttribute (panelH_F_TIP, PANEL_GRAPH_F_X, ATTR_VISIBLE, 0);
						 		SetCtrlAttribute (panelH_F_TIP, PANEL_GRAPH_F_dX, ATTR_VISIBLE, 1);
						 		SetCtrlAttribute (panelH_F_TIP, PANEL_GRAPH_F_Y, ATTR_VISIBLE, 0);
						 
							 }
							 else
								 if(tip==3)
								 {
									 SetCtrlAttribute (panelH_F_TIP, PANEL_GRAPH_F_X, ATTR_VISIBLE, 0);
						 			 SetCtrlAttribute (panelH_F_TIP, PANEL_GRAPH_F_dX, ATTR_VISIBLE, 0);
						 			 SetCtrlAttribute (panelH_F_TIP, PANEL_GRAPH_F_Y, ATTR_VISIBLE, 1);
						 
								 }
					
					
					
				   
				   if (tip==1)
				   {
					   for (i=0;i<NR_F_X;i++)
					   {
						 
						 InsertListItem (panelH_F_TIP, PANEL_DEF_M_FZ, -1, mult_f_e_X[i], i);
					   }
				   }
				   else
					   if (tip==2)
					   {
						  for (i=0;i<NR_F_dX;i++)
					   			{
						 
						 			InsertListItem (panelH_F_TIP, PANEL_DEF_M_FZ, -1, mult_f_e_dX[i], i);
					   			} 
					   }
					   else
						   if (tip==3)
						   {
							   for (i=0;i<NR_F_Y;i++)
					   				{
						 
						 				InsertListItem (panelH_F_TIP, PANEL_DEF_M_FZ, -1, mult_f_e_Y[i], i);
					   				}
						   }
						   
						   
						   
			 GetCtrlIndex (panelH_F_TIP, PANEL_DEF_M_FZ, &index_e);			   
			 if (tip==1)
			 SetCtrlVal (panelH_F_TIP, PANEL_ETICHETA_M, mult_f_e_X[index_e]);
			 else
				 if (tip==2)
					SetCtrlVal (panelH_F_TIP, PANEL_ETICHETA_M, mult_f_e_dX[index_e]);
				 else
					 if (tip==3)
						 SetCtrlVal (panelH_F_TIP, PANEL_ETICHETA_M, mult_f_e_Y[index_e]);
						   
						   
						   
						   
			break;
	}
	return 0;
}

int CVICALLBACK config_f (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				   //panelH_F_TIP = LoadPanel (panelHandle, "c:\\Users\\azyl\\Desktop\\Licentza\\CVI85\\Def_M_Fz.uir", 1); 
				   ClearListCtrl (panelH_F_TIP, PANEL_DEF_M_FZ);
				   if (tip==1)
				   {
					   for (i=0;i<NR_F_X;i++)
					   {
						 
						 InsertListItem (panelH_F_TIP, PANEL_DEF_M_FZ, -1, mult_f_e_X[i], i);
					   }
				   }
				   else
					   if (tip==2)
					   {
						  for (i=0;i<NR_F_dX;i++)
					   			{
						 
						 			InsertListItem (panelH_F_TIP, PANEL_DEF_M_FZ, -1, mult_f_e_dX[i], i);
					   			} 
					   }
					   else
						   if (tip==3)
						   {
							   for (i=0;i<NR_F_Y;i++)
					   				{
						 
						 				InsertListItem (panelH_F_TIP, PANEL_DEF_M_FZ, -1, mult_f_e_X[i], i);
					   				}
						   }
				   InstallPopup (panelH_F_TIP);
			break;
	}
	return 0;
}

int CVICALLBACK rev_d_m (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				   DiscardPanel (panelH_F_TIP);
			break;
	}
	return 0;
}

int CVICALLBACK nr_m_f (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					  ClearListCtrl (panelH_F_TIP, PANEL_DEF_M_FZ);
				   if (tip==1)
				   {
					   for (i=0;i<NR_F_X;i++)
					   {
						 
						 InsertListItem (panelH_F_TIP, PANEL_DEF_M_FZ, -1, mult_f_e_X[i], i);
					   }
				   }
				   else
					   if (tip==2)
					   {
						  for (i=0;i<NR_F_dX;i++)
					   			{
						 
						 			InsertListItem (panelH_F_TIP, PANEL_DEF_M_FZ, -1, mult_f_e_dX[i], i);
					   			} 
					   }
					   else
						   if (tip==3)
						   {
							   for (i=0;i<NR_F_Y;i++)
					   				{
						 
						 				InsertListItem (panelH_F_TIP, PANEL_DEF_M_FZ, -1, mult_f_e_Y[i], i);
					   				}
						   }
			break;
		case EVENT_VAL_CHANGED:
			
			SetCtrlAttribute (panelH_F_TIP, PANEL_DEF_M_FZ, ATTR_DIMMED, 0);
			SetCtrlAttribute (panelH_F_TIP, PANEL_ETICHETA_M, ATTR_DIMMED, 0);
			
			if (tip==1)
				  GetCtrlVal (panelH_F_TIP, PANEL_NR_M_F, &NR_F_X);
			else
				if (tip==2)
					GetCtrlVal (panelH_F_TIP, PANEL_NR_M_F, &NR_F_dX);
				else
					if (tip==3)
					GetCtrlVal (panelH_F_TIP, PANEL_NR_M_F, &NR_F_Y);
			break;
	}
	return 0;
}


int CVICALLBACK def_t_m (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					
				DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, -1, VAL_IMMEDIATE_DRAW);
			
				 GetCtrlIndex (panelH_F_TIP, PANEL_DEF_T_M, &index_t);
				 GetValueFromIndex (panelH_F_TIP, PANEL_DEF_T_M, index_t, &index_t_v);
				 SetCtrlAttribute (panelH_F_TIP, PANEL_PARAM_A, ATTR_DIMMED, 1);
				 SetCtrlAttribute (panelH_F_TIP, PANEL_PARAM_B, ATTR_DIMMED, 1);
				 SetCtrlAttribute (panelH_F_TIP, PANEL_PARAM_C, ATTR_DIMMED, 1);
				 SetCtrlAttribute (panelH_F_TIP, PANEL_PARAM_D, ATTR_DIMMED, 1);
				 
				
				 
				  if (index_t_v==1)
				  {
					  //panelH_F_SAT_S = LoadPanel (panelHandle, "c:\\Users\\azyl\\Desktop\\Licentza\\CVI85\\F_Saturatie_Stanga.uir", 1);
					  //InstallPopup (panelH_F_SAT_S);
					  SetCtrlAttribute (panelH_F_TIP, PANEL_PARAM_A, ATTR_DIMMED, 0);
					  SetCtrlAttribute (panelH_F_TIP, PANEL_PARAM_B, ATTR_DIMMED, 0);
					  DeleteImage (panelH_F_TIP, PANEL_PICTURE_M);
					  DisplayImageFile (panelH_F_TIP, PANEL_PICTURE_M, "c:\\Users\\azyl\\Desktop\\Licentza\\CVI85\\F_Saturatie_S.bmp");
					  
					  
					  
				  }
				  
				    
				  if (index_t_v==2) 
				  {
					 //panelH_F_SAT_D = LoadPanel (panelHandle, "c:\\Users\\azyl\\Desktop\\Licentza\\CVI85\\Functie_Saturatie_Dreapta.uir", 1);
					 //InstallPopup (panelH_F_SAT_D);
					   SetCtrlAttribute (panelH_F_TIP, PANEL_PARAM_A, ATTR_DIMMED, 0);
					  SetCtrlAttribute (panelH_F_TIP, PANEL_PARAM_B, ATTR_DIMMED, 0);
					  DeleteImage (panelH_F_TIP, PANEL_PICTURE_M);
					  DisplayImageFile (panelH_F_TIP, PANEL_PICTURE_M, "c:\\Users\\azyl\\Desktop\\Licentza\\CVI85\\F_Saturatie_D.bmp");
				  }
				  
				  
				  if (index_t_v==3)
				  {
					 //panelH_F_TRI = LoadPanel (panelHandle, "c:\\Users\\azyl\\Desktop\\Licentza\\CVI85\\F_Triunghiulara.uir", 1);
				   	 //InstallPopup (panelH_F_TRI);
					  SetCtrlAttribute (panelH_F_TIP, PANEL_PARAM_A, ATTR_DIMMED, 0);
				 	  SetCtrlAttribute (panelH_F_TIP, PANEL_PARAM_B, ATTR_DIMMED, 0);
				      SetCtrlAttribute (panelH_F_TIP, PANEL_PARAM_C, ATTR_DIMMED, 0);
					  DeleteImage (panelH_F_TIP, PANEL_PICTURE_M);
					  DisplayImageFile (panelH_F_TIP, PANEL_PICTURE_M, "c:\\Users\\azyl\\Desktop\\Licentza\\CVI85\\F_Saturatie_Tri.bmp");
				  }
				  
					
				  if (index_t_v==4)
				  {
						//panelH_F_TRA = LoadPanel (panelHandle, "c:\\Users\\azyl\\Desktop\\Licentza\\CVI85\\F_Trapezoidala.uir", 1);
			   			//InstallPopup (panelH_F_TRA);  
					SetCtrlAttribute (panelH_F_TIP, PANEL_PARAM_A, ATTR_DIMMED, 0);
				 	SetCtrlAttribute (panelH_F_TIP, PANEL_PARAM_B, ATTR_DIMMED, 0);
				 	SetCtrlAttribute (panelH_F_TIP, PANEL_PARAM_C, ATTR_DIMMED, 0);
				 	SetCtrlAttribute (panelH_F_TIP, PANEL_PARAM_D, ATTR_DIMMED, 0);
					DeleteImage (panelH_F_TIP, PANEL_PICTURE_M);
					  DisplayImageFile (panelH_F_TIP, PANEL_PICTURE_M, "c:\\Users\\azyl\\Desktop\\Licentza\\CVI85\\F_Saturatie_Trap.bmp");
				  }
			   
				   
				  if (index_t_v==5)
				  {
					  //panelH_F_GAUSS = LoadPanel (panelHandle, "c:\\Users\\azyl\\Desktop\\Licentza\\CVI85\\F_GAUSS.uir", 1);
					 //InstallPopup (panelH_F_GAUSS);	
					  SetCtrlAttribute (panelH_F_TIP, PANEL_PARAM_A, ATTR_DIMMED, 0);
					  SetCtrlAttribute (panelH_F_TIP, PANEL_PARAM_B, ATTR_DIMMED, 0);
				  }
				  
				  if (index_t_v==6)
				  {
					 //panelH_F_S_SHAPE = LoadPanel (panelHandle, "c:\\Users\\azyl\\Desktop\\Licentza\\CVI85\\F_S_Shape.uir", 1);
					 //InstallPopup (panelH_F_S_SHAPE); 
					  SetCtrlAttribute (panelH_F_TIP, PANEL_PARAM_A, ATTR_DIMMED, 0);
					  SetCtrlAttribute (panelH_F_TIP, PANEL_PARAM_B, ATTR_DIMMED, 0);
				  }
					  
					 
					if (index_t_v==7)
					{
						 
					 //panelH_F_Z_SHAPE = LoadPanel (panelHandle, "c:\\Users\\azyl\\Desktop\\Licentza\\CVI85\\F_Z_Shape.uir", 1);
					 //InstallPopup (panelH_F_Z_SHAPE);
						SetCtrlAttribute (panelH_F_TIP, PANEL_PARAM_A, ATTR_DIMMED, 0);
					  SetCtrlAttribute (panelH_F_TIP, PANEL_PARAM_B, ATTR_DIMMED, 0);
					}
					
					 
					 
					
					 
					
				 
			break;
	}
	return 0;
}

int CVICALLBACK rev_s_s (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				   	DiscardPanel (panelH_F_SAT_S);     
			break;
	}
	return 0;
}

int CVICALLBACK param_a (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				    
			
				    GetCtrlIndex (panelH_F_TIP, PANEL_DEF_M_FZ, &index_e);
				    GetValueFromIndex (panelH_F_TIP, PANEL_DEF_M_FZ, index_e, &index_e_v);
			
			
					GetCtrlIndex (panelH_F_TIP, PANEL_DEF_T_M, &index_t);
				    GetValueFromIndex (panelH_F_TIP, PANEL_DEF_T_M, index_t, &index_t_v);
					
			
					GetCtrlVal (panelH_F_TIP, PANEL_PARAM_A, &a);
					GetCtrlVal (panelH_F_TIP, PANEL_PARAM_B, &b);
					GetCtrlVal (panelH_F_TIP, PANEL_PARAM_C, &c);
					GetCtrlVal (panelH_F_TIP, PANEL_PARAM_D, &d);
				if(tip==1)
				{
					if (index_t_v==1)
					{
						for (i=1;i<100;i++)
						{
							v_x_X[index_e_v][i]=i;
					   		v_y_X[index_e_v][i]=satl(i,a,b);
						}
						
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
					}
					 else
						 if (index_t_v==2)
							{
								for (i=1;i<100;i++)
									{
										v_x_X[index_e_v][i]=i;
					   					v_y_X[index_e_v][i]=gama(i,a,b);
									}
																
						 DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
							}
						 else
							 if (index_t_v==3)
								{
									for (i=1;i<100;i++)
										{
											v_x_X[index_e_v][i]=i;
					   						v_y_X[index_e_v][i]=delta(i,a,b,c);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==4)
								{
									for (i=1;i<100;i++)
										{
											v_x_X[index_e_v][i]=i;
					   						v_y_X[index_e_v][i]=pi(i,a,c,d,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==5)
								{
									for (i=1;i<100;i++)
										{
											v_x_X[index_e_v][i]=i;
					   						v_y_X[index_e_v][i]=gauss(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==6)
								{
									for (i=1;i<100;i++)
										{
											v_x_X[index_e_v][i]=i;
					   						v_y_X[index_e_v][i]=sshape(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==7)
								{
									for (i=1;i<100;i++)
										{
											v_x_X[index_e_v][i]=i;
					   						v_y_X[index_e_v][i]=zshape(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 
							 
				}			 
				else
						if(tip==2)
				{
					if (index_t_v==1)
					{
						for (i=1;i<100;i++)
						{
							v_x_dX[index_e_v][i]=i;
					   		v_y_dX[index_e_v][i]=satl(i,a,b);
						}
						
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, VAL_RED);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, VAL_RED);
					}
					 else
						 if (index_t_v==2)
							{
								for (i=1;i<100;i++)
									{
										v_x_dX[index_e_v][i]=i;
					   					v_y_dX[index_e_v][i]=gama(i,a,b);
									}
																
						 DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
							}
						 else
							 if (index_t_v==3)
								{
									for (i=1;i<100;i++)
										{
											v_x_dX[index_e_v][i]=i;
					   						v_y_dX[index_e_v][i]=delta(i,a,b,c);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==4)
								{
									for (i=1;i<100;i++)
										{
											v_x_dX[index_e_v][i]=i;
					   						v_y_dX[index_e_v][i]=pi(i,a,c,d,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==5)
								{
									for (i=1;i<100;i++)
										{
											v_x_dX[index_e_v][i]=i;
					   						v_y_dX[index_e_v][i]=gauss(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==6)
								{
									for (i=1;i<100;i++)
										{
											v_x_dX[index_e_v][i]=i;
					   						v_y_dX[index_e_v][i]=sshape(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==7)
								{
									for (i=1;i<100;i++)
										{
											v_x_dX[index_e_v][i]=i;
					   						v_y_dX[index_e_v][i]=zshape(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 
							 
				}
				else
						if(tip==3)
				{
					if (index_t_v==1)
					{
						for (i=1;i<100;i++)
						{
							v_x_Y[index_e_v][i]=i;
					   		v_y_Y[index_e_v][i]=satl(i,a,b);
						}
						
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, VAL_RED);
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_Y, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, VAL_RED);
					}
					 else
						 if (index_t_v==2)
							{
								for (i=1;i<100;i++)
									{
										v_x_Y[index_e_v][i]=i;
					   					v_y_Y[index_e_v][i]=gama(i,a,b);
									}
																
						 DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_Y, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
							}
						 else
							 if (index_t_v==3)
								{
									for (i=1;i<100;i++)
										{
											v_x_Y[index_e_v][i]=i;
					   						v_y_Y[index_e_v][i]=delta(i,a,b,c);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_Y, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==4)
								{
									for (i=1;i<100;i++)
										{
											v_x_Y[index_e_v][i]=i;
					   						v_y_Y[index_e_v][i]=pi(i,a,c,d,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_Y, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==5)
								{
									for (i=1;i<100;i++)
										{
											v_x_Y[index_e_v][i]=i;
					   						v_y_Y[index_e_v][i]=gauss(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_Y, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==6)
								{
									for (i=1;i<100;i++)
										{
											v_x_Y[index_e_v][i]=i;
					   						v_y_Y[index_e_v][i]=sshape(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_Y, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==7)
								{
									for (i=1;i<100;i++)
										{
											v_x_Y[index_e_v][i]=i;
					   						v_y_Y[index_e_v][i]=zshape(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 
							 
				}			 
							 
							 
							 
							 
							 
					if (tip==1)
					{
				    TIP_F_X[index_e_v][0]=index_t_v;
					TIP_F_X[index_e_v][1]=a;
					TIP_F_X[index_e_v][2]=b;
					TIP_F_X[index_e_v][3]=c;
					TIP_F_X[index_e_v][4]=d;
					}
					else
						if (tip==2)
					{
				    TIP_F_dX[index_e_v][0]=index_t_v;
					TIP_F_dX[index_e_v][1]=a;
					TIP_F_dX[index_e_v][2]=b;
					TIP_F_dX[index_e_v][3]=c;
					TIP_F_dX[index_e_v][4]=d;
					}
						else
							if (tip==3)
					{
				    TIP_F_Y[index_e_v][0]=index_t_v;
					TIP_F_Y[index_e_v][1]=a;
					TIP_F_Y[index_e_v][2]=b;
					TIP_F_Y[index_e_v][3]=c;
					TIP_F_Y[index_e_v][4]=d;
					}
							
					
					
			break;
	}
	return 0;
}

int CVICALLBACK param_b (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

				    GetCtrlIndex (panelH_F_TIP, PANEL_DEF_M_FZ, &index_e);
				    GetValueFromIndex (panelH_F_TIP, PANEL_DEF_M_FZ, index_e, &index_e_v);
			
			
					GetCtrlIndex (panelH_F_TIP, PANEL_DEF_T_M, &index_t);
				    GetValueFromIndex (panelH_F_TIP, PANEL_DEF_T_M, index_t, &index_t_v);
					
			
					GetCtrlVal (panelH_F_TIP, PANEL_PARAM_A, &a);
					GetCtrlVal (panelH_F_TIP, PANEL_PARAM_B, &b);
					GetCtrlVal (panelH_F_TIP, PANEL_PARAM_C, &c);
					GetCtrlVal (panelH_F_TIP, PANEL_PARAM_D, &d);
				if(tip==1)
				{
					if (index_t_v==1)
					{
						for (i=1;i<100;i++)
						{
							v_x_X[index_e_v][i]=i;
					   		v_y_X[index_e_v][i]=satl(i,a,b);
						}
						
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
					}
					 else
						 if (index_t_v==2)
							{
								for (i=1;i<100;i++)
									{
										v_x_X[index_e_v][i]=i;
					   					v_y_X[index_e_v][i]=gama(i,a,b);
									}
																
						 DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
							}
						 else
							 if (index_t_v==3)
								{
									for (i=1;i<100;i++)
										{
											v_x_X[index_e_v][i]=i;
					   						v_y_X[index_e_v][i]=delta(i,a,b,c);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==4)
								{
									for (i=1;i<100;i++)
										{
											v_x_X[index_e_v][i]=i;
					   						v_y_X[index_e_v][i]=pi(i,a,c,d,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==5)
								{
									for (i=1;i<100;i++)
										{
											v_x_X[index_e_v][i]=i;
					   						v_y_X[index_e_v][i]=gauss(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==6)
								{
									for (i=1;i<100;i++)
										{
											v_x_X[index_e_v][i]=i;
					   						v_y_X[index_e_v][i]=sshape(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==7)
								{
									for (i=1;i<100;i++)
										{
											v_x_X[index_e_v][i]=i;
					   						v_y_X[index_e_v][i]=zshape(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 
							 
				}			 
				else
						if(tip==2)
				{
					if (index_t_v==1)
					{
						for (i=1;i<100;i++)
						{
							v_x_dX[index_e_v][i]=i;
					   		v_y_dX[index_e_v][i]=satl(i,a,b);
						}
						
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, VAL_RED);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, VAL_RED);
					}
					 else
						 if (index_t_v==2)
							{
								for (i=1;i<100;i++)
									{
										v_x_dX[index_e_v][i]=i;
					   					v_y_dX[index_e_v][i]=gama(i,a,b);
									}
																
						 DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
							}
						 else
							 if (index_t_v==3)
								{
									for (i=1;i<100;i++)
										{
											v_x_dX[index_e_v][i]=i;
					   						v_y_dX[index_e_v][i]=delta(i,a,b,c);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==4)
								{
									for (i=1;i<100;i++)
										{
											v_x_dX[index_e_v][i]=i;
					   						v_y_dX[index_e_v][i]=pi(i,a,c,d,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==5)
								{
									for (i=1;i<100;i++)
										{
											v_x_dX[index_e_v][i]=i;
					   						v_y_dX[index_e_v][i]=gauss(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==6)
								{
									for (i=1;i<100;i++)
										{
											v_x_dX[index_e_v][i]=i;
					   						v_y_dX[index_e_v][i]=sshape(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==7)
								{
									for (i=1;i<100;i++)
										{
											v_x_dX[index_e_v][i]=i;
					   						v_y_dX[index_e_v][i]=zshape(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 
							 
				}
				else
						if(tip==3)
				{
					if (index_t_v==1)
					{
						for (i=1;i<100;i++)
						{
							v_x_Y[index_e_v][i]=i;
					   		v_y_Y[index_e_v][i]=satl(i,a,b);
						}
						
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, VAL_RED);
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_Y, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, VAL_RED);
					}
					 else
						 if (index_t_v==2)
							{
								for (i=1;i<100;i++)
									{
										v_x_Y[index_e_v][i]=i;
					   					v_y_Y[index_e_v][i]=gama(i,a,b);
									}
																
						 DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_Y, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
							}
						 else
							 if (index_t_v==3)
								{
									for (i=1;i<100;i++)
										{
											v_x_Y[index_e_v][i]=i;
					   						v_y_Y[index_e_v][i]=delta(i,a,b,c);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_Y, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==4)
								{
									for (i=1;i<100;i++)
										{
											v_x_Y[index_e_v][i]=i;
					   						v_y_Y[index_e_v][i]=pi(i,a,c,d,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_Y, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==5)
								{
									for (i=1;i<100;i++)
										{
											v_x_Y[index_e_v][i]=i;
					   						v_y_Y[index_e_v][i]=gauss(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_Y, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==6)
								{
									for (i=1;i<100;i++)
										{
											v_x_Y[index_e_v][i]=i;
					   						v_y_Y[index_e_v][i]=sshape(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_Y, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==7)
								{
									for (i=1;i<100;i++)
										{
											v_x_Y[index_e_v][i]=i;
					   						v_y_Y[index_e_v][i]=zshape(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 
							 
				}			 
							 
							 
							 
							 
							 
					if (tip==1)
					{
				    TIP_F_X[index_e_v][0]=index_t_v;
					TIP_F_X[index_e_v][1]=a;
					TIP_F_X[index_e_v][2]=b;
					TIP_F_X[index_e_v][3]=c;
					TIP_F_X[index_e_v][4]=d;
					}
					else
						if (tip==2)
					{
				    TIP_F_dX[index_e_v][0]=index_t_v;
					TIP_F_dX[index_e_v][1]=a;
					TIP_F_dX[index_e_v][2]=b;
					TIP_F_dX[index_e_v][3]=c;
					TIP_F_dX[index_e_v][4]=d;
					}
						else
							if (tip==3)
					{
				    TIP_F_Y[index_e_v][0]=index_t_v;
					TIP_F_Y[index_e_v][1]=a;
					TIP_F_Y[index_e_v][2]=b;
					TIP_F_Y[index_e_v][3]=c;
					TIP_F_Y[index_e_v][4]=d;
					}
							
					
					
			break;
	}
	return 0;
}

int CVICALLBACK param_c (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

				    GetCtrlIndex (panelH_F_TIP, PANEL_DEF_M_FZ, &index_e);
				    GetValueFromIndex (panelH_F_TIP, PANEL_DEF_M_FZ, index_e, &index_e_v);
			
			
					GetCtrlIndex (panelH_F_TIP, PANEL_DEF_T_M, &index_t);
				    GetValueFromIndex (panelH_F_TIP, PANEL_DEF_T_M, index_t, &index_t_v);
					
			
					GetCtrlVal (panelH_F_TIP, PANEL_PARAM_A, &a);
					GetCtrlVal (panelH_F_TIP, PANEL_PARAM_B, &b);
					GetCtrlVal (panelH_F_TIP, PANEL_PARAM_C, &c);
					GetCtrlVal (panelH_F_TIP, PANEL_PARAM_D, &d);
				if(tip==1)
				{
					if (index_t_v==1)
					{
						for (i=1;i<100;i++)
						{
							v_x_X[index_e_v][i]=i;
					   		v_y_X[index_e_v][i]=satl(i,a,b);
						}
						
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
					}
					 else
						 if (index_t_v==2)
							{
								for (i=1;i<100;i++)
									{
										v_x_X[index_e_v][i]=i;
					   					v_y_X[index_e_v][i]=gama(i,a,b);
									}
																
						 DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
							}
						 else
							 if (index_t_v==3)
								{
									for (i=1;i<100;i++)
										{
											v_x_X[index_e_v][i]=i;
					   						v_y_X[index_e_v][i]=delta(i,a,b,c);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==4)
								{
									for (i=1;i<100;i++)
										{
											v_x_X[index_e_v][i]=i;
					   						v_y_X[index_e_v][i]=pi(i,a,c,d,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==5)
								{
									for (i=1;i<100;i++)
										{
											v_x_X[index_e_v][i]=i;
					   						v_y_X[index_e_v][i]=gauss(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==6)
								{
									for (i=1;i<100;i++)
										{
											v_x_X[index_e_v][i]=i;
					   						v_y_X[index_e_v][i]=sshape(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==7)
								{
									for (i=1;i<100;i++)
										{
											v_x_X[index_e_v][i]=i;
					   						v_y_X[index_e_v][i]=zshape(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 
							 
				}			 
				else
						if(tip==2)
				{
					if (index_t_v==1)
					{
						for (i=1;i<100;i++)
						{
							v_x_dX[index_e_v][i]=i;
					   		v_y_dX[index_e_v][i]=satl(i,a,b);
						}
						
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, VAL_RED);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, VAL_RED);
					}
					 else
						 if (index_t_v==2)
							{
								for (i=1;i<100;i++)
									{
										v_x_dX[index_e_v][i]=i;
					   					v_y_dX[index_e_v][i]=gama(i,a,b);
									}
																
						 DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
							}
						 else
							 if (index_t_v==3)
								{
									for (i=1;i<100;i++)
										{
											v_x_dX[index_e_v][i]=i;
					   						v_y_dX[index_e_v][i]=delta(i,a,b,c);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==4)
								{
									for (i=1;i<100;i++)
										{
											v_x_dX[index_e_v][i]=i;
					   						v_y_dX[index_e_v][i]=pi(i,a,c,d,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==5)
								{
									for (i=1;i<100;i++)
										{
											v_x_dX[index_e_v][i]=i;
					   						v_y_dX[index_e_v][i]=gauss(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==6)
								{
									for (i=1;i<100;i++)
										{
											v_x_dX[index_e_v][i]=i;
					   						v_y_dX[index_e_v][i]=sshape(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==7)
								{
									for (i=1;i<100;i++)
										{
											v_x_dX[index_e_v][i]=i;
					   						v_y_dX[index_e_v][i]=zshape(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 
							 
				}
				else
						if(tip==3)
				{
					if (index_t_v==1)
					{
						for (i=1;i<100;i++)
						{
							v_x_Y[index_e_v][i]=i;
					   		v_y_Y[index_e_v][i]=satl(i,a,b);
						}
						
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, VAL_RED);
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_Y, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, VAL_RED);
					}
					 else
						 if (index_t_v==2)
							{
								for (i=1;i<100;i++)
									{
										v_x_Y[index_e_v][i]=i;
					   					v_y_Y[index_e_v][i]=gama(i,a,b);
									}
																
						 DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_Y, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
							}
						 else
							 if (index_t_v==3)
								{
									for (i=1;i<100;i++)
										{
											v_x_Y[index_e_v][i]=i;
					   						v_y_Y[index_e_v][i]=delta(i,a,b,c);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_Y, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==4)
								{
									for (i=1;i<100;i++)
										{
											v_x_Y[index_e_v][i]=i;
					   						v_y_Y[index_e_v][i]=pi(i,a,c,d,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_Y, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==5)
								{
									for (i=1;i<100;i++)
										{
											v_x_Y[index_e_v][i]=i;
					   						v_y_Y[index_e_v][i]=gauss(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_Y, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==6)
								{
									for (i=1;i<100;i++)
										{
											v_x_Y[index_e_v][i]=i;
					   						v_y_Y[index_e_v][i]=sshape(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_Y, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==7)
								{
									for (i=1;i<100;i++)
										{
											v_x_Y[index_e_v][i]=i;
					   						v_y_Y[index_e_v][i]=zshape(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 
							 
				}			 
							 
							 
							 
							 
							 
					if (tip==1)
					{
				    TIP_F_X[index_e_v][0]=index_t_v;
					TIP_F_X[index_e_v][1]=a;
					TIP_F_X[index_e_v][2]=b;
					TIP_F_X[index_e_v][3]=c;
					TIP_F_X[index_e_v][4]=d;
					}
					else
						if (tip==2)
					{
				    TIP_F_dX[index_e_v][0]=index_t_v;
					TIP_F_dX[index_e_v][1]=a;
					TIP_F_dX[index_e_v][2]=b;
					TIP_F_dX[index_e_v][3]=c;
					TIP_F_dX[index_e_v][4]=d;
					}
						else
							if (tip==3)
					{
				    TIP_F_Y[index_e_v][0]=index_t_v;
					TIP_F_Y[index_e_v][1]=a;
					TIP_F_Y[index_e_v][2]=b;
					TIP_F_Y[index_e_v][3]=c;
					TIP_F_Y[index_e_v][4]=d;
					}
							
					
					
			break;
	}
	return 0;
}

int CVICALLBACK param_d (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

				    GetCtrlIndex (panelH_F_TIP, PANEL_DEF_M_FZ, &index_e);
				    GetValueFromIndex (panelH_F_TIP, PANEL_DEF_M_FZ, index_e, &index_e_v);
			
			
					GetCtrlIndex (panelH_F_TIP, PANEL_DEF_T_M, &index_t);
				    GetValueFromIndex (panelH_F_TIP, PANEL_DEF_T_M, index_t, &index_t_v);
					
			
					GetCtrlVal (panelH_F_TIP, PANEL_PARAM_A, &a);
					GetCtrlVal (panelH_F_TIP, PANEL_PARAM_B, &b);
					GetCtrlVal (panelH_F_TIP, PANEL_PARAM_C, &c);
					GetCtrlVal (panelH_F_TIP, PANEL_PARAM_D, &d);
				if(tip==1)
				{
					if (index_t_v==1)
					{
						for (i=1;i<100;i++)
						{
							v_x_X[index_e_v][i]=i;
					   		v_y_X[index_e_v][i]=satl(i,a,b);
						}
						
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
					}
					 else
						 if (index_t_v==2)
							{
								for (i=1;i<100;i++)
									{
										v_x_X[index_e_v][i]=i;
					   					v_y_X[index_e_v][i]=gama(i,a,b);
									}
																
						 DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
							}
						 else
							 if (index_t_v==3)
								{
									for (i=1;i<100;i++)
										{
											v_x_X[index_e_v][i]=i;
					   						v_y_X[index_e_v][i]=delta(i,a,b,c);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==4)
								{
									for (i=1;i<100;i++)
										{
											v_x_X[index_e_v][i]=i;
					   						v_y_X[index_e_v][i]=pi(i,a,c,d,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==5)
								{
									for (i=1;i<100;i++)
										{
											v_x_X[index_e_v][i]=i;
					   						v_y_X[index_e_v][i]=gauss(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==6)
								{
									for (i=1;i<100;i++)
										{
											v_x_X[index_e_v][i]=i;
					   						v_y_X[index_e_v][i]=sshape(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==7)
								{
									for (i=1;i<100;i++)
										{
											v_x_X[index_e_v][i]=i;
					   						v_y_X[index_e_v][i]=zshape(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_X, plotH_X[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_X[index_e_v][1], &v_y_X[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 
							 
				}			 
				else
						if(tip==2)
				{
					if (index_t_v==1)
					{
						for (i=1;i<100;i++)
						{
							v_x_dX[index_e_v][i]=i;
					   		v_y_dX[index_e_v][i]=satl(i,a,b);
						}
						
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, VAL_RED);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, VAL_RED);
					}
					 else
						 if (index_t_v==2)
							{
								for (i=1;i<100;i++)
									{
										v_x_dX[index_e_v][i]=i;
					   					v_y_dX[index_e_v][i]=gama(i,a,b);
									}
																
						 DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
							}
						 else
							 if (index_t_v==3)
								{
									for (i=1;i<100;i++)
										{
											v_x_dX[index_e_v][i]=i;
					   						v_y_dX[index_e_v][i]=delta(i,a,b,c);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==4)
								{
									for (i=1;i<100;i++)
										{
											v_x_dX[index_e_v][i]=i;
					   						v_y_dX[index_e_v][i]=pi(i,a,c,d,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==5)
								{
									for (i=1;i<100;i++)
										{
											v_x_dX[index_e_v][i]=i;
					   						v_y_dX[index_e_v][i]=gauss(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==6)
								{
									for (i=1;i<100;i++)
										{
											v_x_dX[index_e_v][i]=i;
					   						v_y_dX[index_e_v][i]=sshape(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==7)
								{
									for (i=1;i<100;i++)
										{
											v_x_dX[index_e_v][i]=i;
					   						v_y_dX[index_e_v][i]=zshape(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_dX, plotH_dX[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_dX[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_dX, &v_x_dX[index_e_v][1], &v_y_dX[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 
							 
				}
				else
						if(tip==3)
				{
					if (index_t_v==1)
					{
						for (i=1;i<100;i++)
						{
							v_x_Y[index_e_v][i]=i;
					   		v_y_Y[index_e_v][i]=satl(i,a,b);
						}
						
						DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, VAL_RED);
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_Y, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, VAL_RED);
					}
					 else
						 if (index_t_v==2)
							{
								for (i=1;i<100;i++)
									{
										v_x_Y[index_e_v][i]=i;
					   					v_y_Y[index_e_v][i]=gama(i,a,b);
									}
																
						 DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_Y, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
							}
						 else
							 if (index_t_v==3)
								{
									for (i=1;i<100;i++)
										{
											v_x_Y[index_e_v][i]=i;
					   						v_y_Y[index_e_v][i]=delta(i,a,b,c);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_Y, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==4)
								{
									for (i=1;i<100;i++)
										{
											v_x_Y[index_e_v][i]=i;
					   						v_y_Y[index_e_v][i]=pi(i,a,c,d,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_Y, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==5)
								{
									for (i=1;i<100;i++)
										{
											v_x_Y[index_e_v][i]=i;
					   						v_y_Y[index_e_v][i]=gauss(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_X[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_Y, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==6)
								{
									for (i=1;i<100;i++)
										{
											v_x_Y[index_e_v][i]=i;
					   						v_y_Y[index_e_v][i]=sshape(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_Y, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 else
							 if (index_t_v==7)
								{
									for (i=1;i<100;i++)
										{
											v_x_Y[index_e_v][i]=i;
					   						v_y_Y[index_e_v][i]=zshape(i,a,b);
										}
																
						 			DisableBreakOnLibraryErrors ();
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						DeleteGraphPlot (panelH_F_TIP, PANEL_GRAPH_F_Y, plotH_Y[index_e_v], VAL_IMMEDIATE_DRAW);
						EnableBreakOnLibraryErrors ();
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
						plotH_Y[index_e_v] = PlotXY (panelH_F_TIP, PANEL_GRAPH_F_X, &v_x_Y[index_e_v][1], &v_y_Y[index_e_v][1], 99, VAL_DOUBLE, VAL_DOUBLE,
													 VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 10, color[index_e_v]);
								}
							 
							 
				}			 
							 
							 
							 
							 
							 
					if (tip==1)
					{
				    TIP_F_X[index_e_v][0]=index_t_v;
					TIP_F_X[index_e_v][1]=a;
					TIP_F_X[index_e_v][2]=b;
					TIP_F_X[index_e_v][3]=c;
					TIP_F_X[index_e_v][4]=d;
					}
					else
						if (tip==2)
					{
				    TIP_F_dX[index_e_v][0]=index_t_v;
					TIP_F_dX[index_e_v][1]=a;
					TIP_F_dX[index_e_v][2]=b;
					TIP_F_dX[index_e_v][3]=c;
					TIP_F_dX[index_e_v][4]=d;
					}
						else
							if (tip==3)
					{
				    TIP_F_Y[index_e_v][0]=index_t_v;
					TIP_F_Y[index_e_v][1]=a;
					TIP_F_Y[index_e_v][2]=b;
					TIP_F_Y[index_e_v][3]=c;
					TIP_F_Y[index_e_v][4]=d;
					}
							
					
					
			break;
	}
	return 0;
}

int CVICALLBACK radiobutton_m_f (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					 GetCtrlVal (panelH_F_TIP, PANEL_RADIOBUTTON_F_F, &m_or_f);
					 if (m_or_f==1)
					 {
						 SetCtrlVal (panelH_F_TIP, PANEL_RADIOBUTTON_F_F, 0);
						 SetCtrlAttribute (panelH_F_TIP, PANEL_GRAPH_F, ATTR_VISIBLE, 1);
						 SetCtrlAttribute (panelH_F_TIP, PANEL_GRAPH_F_X, ATTR_VISIBLE, 0);
						 SetCtrlAttribute (panelH_F_TIP, PANEL_GRAPH_F_dX, ATTR_VISIBLE, 0);
						 SetCtrlAttribute (panelH_F_TIP, PANEL_GRAPH_F_Y, ATTR_VISIBLE, 0);
						 
					 }
			break;
	}
	return 0;
}

int CVICALLBACK radiobutton_f_f (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					 GetCtrlVal (panelH_F_TIP, PANEL_RADIOBUTTON_M_F, &m_or_f);
					 if (m_or_f==1)
					 {
						 SetCtrlVal (panelH_F_TIP, PANEL_RADIOBUTTON_M_F, 0);
						 SetCtrlAttribute (panelH_F_TIP, PANEL_GRAPH_F, ATTR_VISIBLE, 0);
						 if(tip==1)
						 SetCtrlAttribute (panelH_F_TIP, PANEL_GRAPH_F_X, ATTR_VISIBLE, 1);
						 else
							 if(tip==2)
						 SetCtrlAttribute (panelH_F_TIP, PANEL_GRAPH_F_dX, ATTR_VISIBLE, 1);
							 else
								 if(tip==3)
						 SetCtrlAttribute (panelH_F_TIP, PANEL_GRAPH_F_Y, ATTR_VISIBLE, 1);
						 
					 }
			break;
	}
	return 0;
}

int CVICALLBACK acc_brf (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					for(i=0;i<NR_F_dX;i++)
					{
						for(j=0;j<NR_F_X;j++)
						{
						//GetTableCellRangeVals (panelH_F_BRF_D, PANEL_TABLE_BRF, MakePoint(j+1,i+1), BRF_E[i][j], VAL_ROW_MAJOR);
						//GetTableCellFromPoint (panelH_F_BRF_D, PANEL_TABLE_BRF, MakePoint(j+1,i+1), &BRF_E[i][j]);
						GetTableCellVal (panelH_F_BRF_D, PANEL_TABLE_BRF, MakePoint(j+1,i+1), BRF_E[i][j]);
								
							
						}
						    
					}
					ArrayToFile ("c:\\Users\\azyl\\Desktop\\Licentza\\CVI85\\BRF_E.txt", BRF_E, VAL_CHAR, 100, 10, VAL_GROUPS_TOGETHER,
								 VAL_GROUPS_AS_ROWS, VAL_SEP_BY_COMMA, 10, VAL_ASCII, VAL_TRUNCATE);
					
					
			break;
	}
	return 0;
}

int CVICALLBACK ErrorCallBack (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
            RS232Error = ReturnRS232Err ();
            DisplayRS232Error ();
            break;
        case EVENT_RIGHT_CLICK :
            break;
	}
	return 0;
}

int CVICALLBACK ComStatusCallBack (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				   com_status = GetComStat (comport);
        DisplayComStatus ();
			break;
	}
	return 0;
}

int CVICALLBACK rev_com_conf (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					DiscardPanel (panelH_COM_CONF); 
			break;
	}
	return 0;
}

int CVICALLBACK ring_s_met_d (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			
			
			
				 GetCtrlIndex (panelH_S_MD, PANEL_RING_S_MET_D, &index_s_md);
				 GetValueFromIndex (panelH_S_MD, PANEL_RING_S_MET_D, index_s_md, &index_s_md_v);
				 TIP_M=index_s_md_v;
			break;
	}
	return 0;
}

int CVICALLBACK rulare_d_u (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int panelH;
	switch (event)
	{
		case EVENT_COMMIT:
				   
					if (flag_S==1)
					{
				   genBuffer();
				   strLen = StringLength (buffer);
				   FlushInQ (comport);
				   			   
				   //nr_biti_w=(ComWrt (comport, buffer, 127))/8;
				   for( i=0;i<strlen(buffer);i++)
					   {
						   if(((i+1)%128)==0)
						   {
				   			while(read==0)
				   				{
									nr=GetInQLen(comport);
									if (nr>=8)
									{
				   					ComRdTerm (comport, &readBuf[0],GetInQLen (comport) , 13);
				   					 if (strcmp(readBuf,"received")==0)  
										 read=1;
									}
				   				}
							ComWrtByte (comport, buffer[i]);
							   read=0;
					   		}
						   else
						   {
							   ComWrtByte (comport, buffer[i]);
							   read=0;
						   }
					   }
							   
						   
				   //nr_biti_w=nr_biti_w+(ComWrt (comport, buffer_1, 127))/8;
				   					      
				   sprintf (buf2, "%i", nr_biti_w);
				   strcat (writeBuf, "\n");
				   strcat (writeBuf, buffer);
				   MessagePopup ("Nr de biti trimisi", buf2);
				   SetCtrlVal (panelH_S_MS, PANEL_TEXTBOX1, "");
				   SetCtrlVal (panelH_S_MS, PANEL_TEXTBOX1, buffer);
				   //ResetTextBox (panelH_COM_CONF, P_COM_CONF_TEXTBOX_O, "");
				   //SetCtrlVal (panelH_COM_CONF, P_COM_CONF_TEXTBOX_O, buffer);
				   //SetCtrlVal (panelH_COM_CONF, P_COM_CONF_TEXTBOX_O_H, buffer);
				   
				   
				   
					//strLen = GetInQLen (1);
            		//ComRd (1, readBuf, strLen);
            		//SetCtrlVal (gPanelHandle, PANEL_OUTOUT_STRING, readBuf);
					}
					else
						MessagePopup ("Atentie", "Nu ati configurat si deschis portul serial pentru a realiza comunicarea cu microprocesorul");						
				   
				   
			break;
	}
	return 0;
}

int CVICALLBACK numeric_nr_int (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}

int CVICALLBACK inchide (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				DisableBreakOnLibraryErrors ();
				CloseCom (comport);
				EnableBreakOnLibraryErrors ();
				SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_PROGRAMEAZA, ATTR_VISIBLE, 1);
				SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_INCHIDE, ATTR_VISIBLE, 0);
				SetCtrlAttribute (panelHandle, PANEL_LED_SERIALA, ATTR_CTRL_VAL, 0);
				SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_READ_S, ATTR_DIMMED, 1);
				SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_WRITE_S, ATTR_DIMMED, 1);
				SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_GET_S_I, ATTR_DIMMED, 1);
				SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_GET_S_O, ATTR_DIMMED, 1);
				SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_ERROR, ATTR_DIMMED, 1);
				SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_COMSTATUS, ATTR_DIMMED, 1);
				
				SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_PORT_NAME, ATTR_DIMMED, 0);
				SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_VITEZA, ATTR_DIMMED, 0);
				SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_PARITATE, ATTR_DIMMED, 0);
				SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_NR_BITI, ATTR_DIMMED, 0);
				SetCtrlAttribute (panelH_COM_CONF, P_COM_CONF_NR_B_STOP, ATTR_DIMMED, 0);
				
				flag_S=0;
			break;
	}
	return 0;
}

int CVICALLBACK read_s (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					if(GetInQLen (comport)>0)
					{
													  
				   //ComRdTerm (comport, &readBuf[0],GetInQLen (comport) , 13);
				   ResetTextBox (panelH_COM_CONF, P_COM_CONF_TEXTBOX_I, "");
				   SetCtrlVal (panelH_COM_CONF, P_COM_CONF_TEXTBOX_I, readBuf);
				   SetCtrlVal (panelH_COM_CONF, P_COM_CONF_TEXTBOX_I_H, readBuf);
					}

			break;
	}
	return 0;
}

int CVICALLBACK write_s (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					 nr_send=0; 
				   FlushInQ (comport);
				    genBuffer();
					//InstallComCallback (comport, LWRS_RXCHAR, 1, (int)gEventChar[0], ReceptieS, 0);
					InstallComCallback (comport, LWRS_RXCHAR | LWRS_RXFLAG, 1, 0, ReceptieS, 0);
				   strLen = StringLength (buffer);
				   //FlushInQ (comport);
				   nr_biti_w=(ComWrt (comport, buffer, strLen))/8;
				   sprintf (buf2, "%i", &nr_biti_w);
				   strcat (writeBuf, "\n");
				   strcat (writeBuf, buffer);
			break;
	}
	return 0;
}

int CVICALLBACK get_s_i (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
				   sprintf (buf1, "%i", GetInQLen (comport));
				  MessagePopup ("NR de biti in buffer-ul de intrare",buf1 );
			break;
	}
	return 0;
}

int CVICALLBACK get_s_o (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				  sprintf (buf1, "%i", GetOutQLen (comport));
				  MessagePopup ("NR de biti in buffer-ul de iesire",buf1 );
			break;
	}
	return 0;
}

int CVICALLBACK rescriere (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}

int CVICALLBACK read_s_reverse (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					  if(GetInQLen (comport)>0)
					{
													  
				   ComRdTerm (comport, &readBuf[0],GetInQLen (comport) , 13);
				   
				  
  					//NR_F_X=retintfrst(readBuf,0);
  					//NR_F_dX=retintfrst(readBuf,2);
  					//NR_F_Y=retintfrst(readBuf,4);
  				
				   
				   
				   
				   ResetTextBox (panelH_COM_CONF, P_COM_CONF_TEXTBOX_I, "");
				   SetCtrlVal (panelH_COM_CONF, P_COM_CONF_TEXTBOX_I, readBuf);
				   SetCtrlVal (panelH_COM_CONF, P_COM_CONF_TEXTBOX_I_H, readBuf);
					}
			break;
	}
	return 0;
}

int CVICALLBACK to_delete_me (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				   //ResetTextBox (panelH_COM_CONF, P_COM_CONF_TEXTBOX_I, "");
				   //SetCtrlVal (panelH_COM_CONF, P_COM_CONF_TEXTBOX_I, readBuf);
				   //SetCtrlVal (panelH_COM_CONF, P_COM_CONF_TEXTBOX_I_H, readBuf);
			
					ComWrt (comport, "aaaaaaaaaaaaaaaaa", 16);
			break;
	}
	return 0;
}
