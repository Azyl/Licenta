/*
 * Write Example
 *
 * This sketch creates a new file and writes 100 lines to the file.
 * No error checks on write in this example.
 */
/*
#include <SdFat.h>
#include <SdFatUtil.h>

Sd2Card card;
SdVolume volume;
SdFile root;
SdFile file;


*/
//################################################################################
//declaratii::


double long time;
double x,dx,y;
double mx[10], mdx[10],W[10][10],TIP_F_X[10][5],TIP_F_dX[10][5],TIP_F_Y[10][5],Fy[10],Cy[10];
char BRF_E[10][10];//[20], ;
char mult_f_e_Y[10];//[20];
int NR_P=100,sensorValue=0,NR_F_X,NR_F_dX,NR_F_Y,i,j,nr,k,l;
char inByteBuffer[32] ;         // incoming serial byte
short int Optiune=1;
byte nr_read;
//char stringc[20];

/*
char name[] = "CONF_00.TXT";
int16_t n;
uint8_t buf[7];// nothing special about 7, just a lucky number.
//declaratii::
//################################################################################
// store error strings in flash to save RAM
#define error(s) error_P(PSTR(s))

void error_P(const char* str) {
  PgmPrint("error: ");
  SerialPrintln_P(str);
  if (card.errorCode()) {
    PgmPrint("SD error: ");
    Serial.print(card.errorCode(), HEX);
    Serial.print(',');
    Serial.println(card.errorData(), HEX);
  }
  while(1);
}
/*
 * Write CR LF to a file
 */ /*
void writeCRLF(SdFile& f) {
  f.write((uint8_t*)"\r\n", 2);
}
/*
 * Write an unsigned number to a file
 */ /*
void writeNumber(SdFile& f, uint32_t n) {
  uint8_t buf[10];
  uint8_t i = 0;
  do {
    i++;
    buf[sizeof(buf) - i] = n%10 + '0';
    n /= 10;
  } 
  while (n);
  f.write(&buf[sizeof(buf) - i], i);
}
/*
 * Write a string to a file
 */ /*
void writeString(SdFile& f, char *str) {
  uint8_t n;
  for (n = 0; str[n]; n++);
  f.write((uint8_t *)str, n);
}







*/ 
void reset_s(char string[])
{

  for (unsigned short i=0;i<sizeof(string);i++)
    string[i]='\0';
}
/*
void establishContact(short int RW)
{
  short int retry=0;
  if (RW==1)

    while (Serial.available() <= 0) 
    {
      Serial.print('A');   // send a capital A
      delay(300);
      retry++;
      // if (retry==500)
      //  break;
    }
  else
    if (RW==2)

      while (Serial.available() <= 0) 
      {
        Serial.print('B');   // send a capital A
        delay(300);
        retry++;
        // if (retry==500)
        //   break;
      }

}

/* 
void SDprintDouble(SdFile& f,double val, byte precision)
{
  // prints val with number of decimal places determine by precision
  // precision is a number from 0 to 6 indicating the desired decimial places
  // example: printDouble( 3.1415, 2); // prints 3.14 (two decimal places)

  writeNumber(f,(int(val)));  //prints the int part
  if( precision > 0) {
    writeString(f,"."); // print the decimal point
    unsigned long frac;
    unsigned long mult = 1;
    byte padding = precision -1;
    while(precision--)
      mult *=10;

    if(val >= 0)
      frac = (val - int(val)) * mult;
    else
      frac = (int(val)- val ) * mult;
    unsigned long frac1 = frac;
    while( frac1 /= 10 )
      padding--;
    while(  padding--)
      writeString(f,"0");
    //Serial.print(frac,DEC) ;
    writeNumber(f,frac);
  }
}



void SprintDouble( double val, byte precision){
  // prints val with number of decimal places determine by precision
  // precision is a number from 0 to 6 indicating the desired decimial places
  // example: printDouble( 3.1415, 2); // prints 3.14 (two decimal places)

  Serial.print (int(val));  //prints the int part
  if( precision > 0) {
    Serial.print("."); // print the decimal point
    unsigned long frac;
    unsigned long mult = 1;
    byte padding = precision -1;
    while(precision--)
      mult *=10;

    if(val >= 0)
      frac = (val - int(val)) * mult;
    else
      frac = (int(val)- val ) * mult;
    unsigned long frac1 = frac;
    while( frac1 /= 10 )
      padding--;
    while(  padding--)
      Serial.print("0");
    Serial.print(frac,DEC) ;
  }
}


*/
//declarare si implementare functii pt fuzzy:::
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



double maxim (double a, double b)
{
  if (a>b)
    return a;
  else
    if (a=b)
      return a;
    else
      return b;
}

double minimul (double a, double b)
{
    if(a>b)
    {
       return b;
    }
    return a;
    
//  if (a<b)
//    return a;
//  else
//    if (a=b)
//      return a;
//    else
//      return b;
}
////]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]////


void fuzz(double u,byte tip_v,double m[], int NR_F, double TIP_F[10][5])

{
  float es;


  if (tip_v==2)
    {
      es=((255-215)/100)+0;//trebuie vazut intervalul pt variabila de intrare x !!!!
      for (unsigned short i=0; i<NR_F;i++)
      {
        if (TIP_F[i][0]==1)
          m[i]= satl(u,(TIP_F[i][1]*es),(TIP_F[i][2]*es));
        else
          if (TIP_F[i][0]==2)
            m[i]= gama(u,(TIP_F[i][1]*es),(TIP_F[i][2]*es));
          else
            if (TIP_F[i][0]==3)
              m[i]= delta(u,(TIP_F[i][1]*es),(TIP_F[i][2]*es),(TIP_F[i][3]*es));
            else
              if (TIP_F[i][0]==4)
                m[i]= pi(u,(TIP_F[i][1]*es),(TIP_F[i][2]*es),(TIP_F[i][3]*es),(TIP_F[i][4]*es));
              else
                if (TIP_F[i][0]==5)
                  m[i]= gauss(u,(TIP_F[i][1]*es),(TIP_F[i][2]*es));
                else
                  if (TIP_F[i][0]==6)
                    m[i]= sshape(u,(TIP_F[i][1]*es),(TIP_F[i][2]*es));
                  else
                    if (TIP_F[i][0]==7)
                      m[i]= zshape(u,(TIP_F[i][1]*es),(TIP_F[i][2]*es));

      }
    }
  else

      if (tip_v==1)
    {
      es=((800-0)/100)+0;//trebuie vazut intervalul pt variabila de intrare x !!!!
      for (unsigned short i=0; i<NR_F;i++)
      {
        if (TIP_F[i][0]==1)
          m[i]= satl(u,(TIP_F[i][1]*es),(TIP_F[i][2]*es));
        else
          if (TIP_F[i][0]==2)
            m[i]= gama(u,(TIP_F[i][1]*es),(TIP_F[i][2]*es));
          else
            if (TIP_F[i][0]==3)
              m[i]= delta(u,(TIP_F[i][1]*es),(TIP_F[i][2]*es),(TIP_F[i][3]*es));
            else
              if (TIP_F[i][0]==4)
                m[i]= pi(u,(TIP_F[i][1]*es),(TIP_F[i][2]*es),(TIP_F[i][3]*es),(TIP_F[i][4]*es));
              else
                if (TIP_F[i][0]==5)
                  m[i]= gauss(u,(TIP_F[i][1]*es),(TIP_F[i][2]*es));
                else
                  if (TIP_F[i][0]==6)
                    m[i]= sshape(u,(TIP_F[i][1]*es),(TIP_F[i][2]*es));
                  else
                    if (TIP_F[i][0]==7)
                      m[i]= zshape(u,(TIP_F[i][1]*es),(TIP_F[i][2]*es));

      }
    }
    else
      if (tip_v==3)
      {
        es=((255-225)/100)+0;
        for (unsigned short i=0; i<NR_F;i++)
        {
          if (TIP_F[i][0]==1)
            m[i]= satl(u,(TIP_F[i][1]*es),(TIP_F[i][2]*es));
          else
            if (TIP_F[i][0]==2)
              m[i]= gama(u,(TIP_F[i][1]*es),(TIP_F[i][2]*es));
            else
              if (TIP_F[i][0]==3)
                m[i]= delta(u,(TIP_F[i][1]*es),(TIP_F[i][2]*es),(TIP_F[i][3]*es));
              else
                if (TIP_F[i][0]==4)
                  m[i]= pi(u,(TIP_F[i][1]*es),(TIP_F[i][2]*es),(TIP_F[i][3]*es),(TIP_F[i][4]*es));
                else
                  if (TIP_F[i][0]==5)
                    m[i]= gauss(u,(TIP_F[i][1]*es),(TIP_F[i][2]*es));
                  else
                    if (TIP_F[i][0]==6)
                      m[i]= sshape(u,(TIP_F[i][1]*es),(TIP_F[i][2]*es));
                    else
                      if (TIP_F[i][0]==7)
                        m[i]= zshape(u,(TIP_F[i][1]*es),(TIP_F[i][2]*es));

        }
      }

}

/*
//void inferenta(double Optiune, int NR_F_X,int NR_F_dX,double W[10][10],double mx[],double mdx[])
void inferenta(int NR_F_X,int NR_F_dX,double W[][10],double mx[],double mdx[])
{
//if (Optiune==1)
//{
  for (unsigned short i=0; i<NR_F_X; i++)
    for (unsigned short j=0; j<NR_F_dX; j++)
    {
       W[i][j]=minim(mx[i],mdx[j]);

    }
//}
}
*/

void inferenta(double W[][10],double mx[],double mdx[])
{

  for (unsigned short i=0; i<10; i++)
    for (unsigned short j=0; j<10; j++)
      W[i][j]=minimul(mx[i],mdx[j]);
}


//void calc_ponderi(double Optiune,int NR_F_X,int NR_F_dX, int NR_F_Y, double W[10][10],char BRF_E[10][10][20],char mult_f_e_Y[10][20],double Fy[10])
void calc_ponderi(double Optiune,int NR_F_X,int NR_F_dX, int NR_F_Y, double W[10][10],char BRF_E[10][10],char mult_f_e_Y[10],double Fy[10])
{
  double max=0;
  if (Optiune==1)
  {
    for(unsigned short k=0;k<NR_F_Y;k++)
    {          
      for (unsigned short i=0; i<NR_F_X; i++)
        for (unsigned short j=0; j<NR_F_dX; j++)
          if (mult_f_e_Y[k]==BRF_E[i][j])
            if (max<W[i][j])
              max=W[i][j];
      Fy[k]=max;
      max=0;
    }
  }
}


//double ls(double Fy[],double TIP_F[])
//{
//for(unsigned short i=0; i<NR_F_Y;i++)
//    {
//      if(Fy[i]!=0)
//      {
//        minim=TIP_F[i][1];
//        return minim;
//      }
//    }
//}
//double ld(double Fy[],double TIP_F[])
//{
//  for(unsigned short i=NR_F_Y; i>0;i--)
//    {
//      if(Fy[i]!=0)
//      {
//        if (TIP_F[i][1]==1)
//          maxim=TIP_F[i][2];
//        else
//        if (TIP_F[i][1]==2)
//          maxim=TIP_F[i][2];
//        else
//        if (TIP_F[i][1]==3)
//          maxim=TIP_F[i][3];
//        else
//        if (TIP_F[i][1]==4)
//          maxim=TIP_F[i][4];
//        
//        return maxim;
//      }
//    }
//
//}

double defuzificare(double Optiune,int NR_P, int NR_F_Y, double Fy[10],double TIP_F[10][5])
{
  double minim=1025, maxim=-1025, Cy[10], d,suma_c=0,suma_f=0,l=(255-215)/NR_P+1, h=0.1,pas=0; 





  //  
  //  for(unsigned short i=0;i<NR_F_Y;i++)
  //  {
  //    
  //    
  //    suma_c += Fy[i]*TIP_F[i][2];
  //    suma_f += Fy[i];
  //  }
  //  
  //  y = suma_c/suma_f*100+50;
  //  if(y>255)y=255;
  //  
  //  return y;

  if (Optiune==1)
  {
    //double minim=1025, maxim=-1025, Cy[10], d,suma_c=0,suma_f=0, h=0,pas=0;
    for(unsigned short i=0; i<NR_F_Y;i++)
    {
      if(Fy[i]!=0)
      {
       // h=0;
        //pas=h;
        if (TIP_F[i][0]==1)
        {
         //h=((255-225)/NR_P)+0;
         
          //pas=0+h;
          pas=h;
          while (pas<=255)
          {
            d= satl(pas,(TIP_F[i][1]*l),(TIP_F[i][2]*l));
            if (d==Fy[i])
            {
              if (pas<minim)
              {
                minim=pas;
//                Serial.print("minim ");
//                Serial.println(minim);
//                Serial.print("pas ");
//                Serial.println(pas);
              }
              if (pas>maxim)
              {
                maxim=pas;
//                Serial.print("maxim ");
//                Serial.println(maxim);
//                Serial.print("pas ");
//                Serial.println(pas);
              }
            }
            pas=pas+h;


          }
          Cy[i]=(minim+maxim)/2;
        }
        else
          if (TIP_F[i][0]==2)
          {
            pas=h;
            while (pas<=255)
            {
              d= gama(pas,TIP_F[i][1]*l,TIP_F[i][2]*l);
              if (d==Fy[i]) 
              {
                if (pas<minim)
                {
                  minim=pas;
//                  Serial.print("minim ");
//                  Serial.println(minim);
//                  Serial.print("pas ");
//                  Serial.println(pas);
                }
                if (pas>maxim)
                {
                  maxim=pas;
//                  Serial.print("maxim ");
//                  Serial.println(maxim);
//                  Serial.print("pas ");
//                  Serial.println(pas);
                }
              }
              pas=pas+h;


            }
            Cy[i]=(minim+maxim)/2;
          }
          else
            if (TIP_F[i][0]==3)
            {
              pas=h;
              while (pas<=255)
              {
                d= delta(pas,TIP_F[i][1]*l,TIP_F[i][2]*l,TIP_F[i][3]*l);
                if (d==Fy[i]) 
                {
                  if (pas<minim)
                  {
                    minim=pas;
//                    Serial.print("minim ");
//                    Serial.println(minim);
//                    Serial.print("pas ");
//                    Serial.println(pas);
                  }
                  if (pas>maxim)
                  {
                    maxim=pas;
//                    Serial.print("maxim ");
//                    Serial.println(maxim);
//                    Serial.print("pas ");
//                    Serial.println(pas);
                  }
                }
                pas=pas+h;


              }
              Cy[i]=(minim+maxim)/2;
            }
            else
              if (TIP_F[i][0]==4)
              {
                pas=h;
                while (pas<=255)
                {
                  d= pi(pas,TIP_F[i][1]*l,TIP_F[i][2]*l,TIP_F[i][3]*l,TIP_F[i][4]*l);
                  if (d==Fy[i]) 
                  {
                    if (pas<minim)
                    {
                      minim=pas;
//                      Serial.print("minim ");
//                      Serial.println(minim);
//                      Serial.print("pas ");
//                      Serial.println(pas);
                    }
                    if (pas>maxim)
                    {
                      maxim=pas;
//                      Serial.print("maxim ");
//                      Serial.println(maxim);
//                      Serial.print("pas ");
//                      Serial.println(pas);
                    }
                  }
                  pas=pas+h;


                }
                Cy[i]=(minim+maxim)/2;
              }
              else
                if (TIP_F[i][0]==5)
                {
                 pas=h;
                  while (pas<=255)
                  {
                    d= gauss(pas,TIP_F[i][1]*l,TIP_F[i][2]*l);
                    if (d==Fy[i]) 
                    {
                      if (pas<minim)
                        minim=pas;
                      if (pas>maxim)
                        maxim=pas;
                    }
                    pas=pas+h;


                  }
                  Cy[i]=(minim+maxim)/2;
                }
                else
                  if (TIP_F[i][0]==6)
                  {
                    pas=h;
                    while (pas<=255)
                    {
                      d= sshape(pas,TIP_F[i][1]*l,TIP_F[i][2]*l);
                      if (d==Fy[i]) 
                      {
                        if (pas<minim)
                        {
                          minim=pas;
//                          Serial.print("minim ");
//                          Serial.println(minim);
                        }
                        if (pas>maxim)
                        {
                          maxim=pas;
//                          Serial.print("maxim ");
//                          Serial.println(maxim);
                        }
                      }
                      pas=pas+h;


                    }
                    Cy[i]=(minim+maxim)/2;
                  }
                  else
                    if (TIP_F[i][0]==7)
                    {
                      pas=h;
                      while (pas<=255)
                      {
                        d= zshape(pas,TIP_F[i][1]*l,TIP_F[i][2]*l);
                        if (d==Fy[i]) 
                        {
                          if (pas<minim)
                          {
                            minim=pas;
//                            Serial.print("minim ");
//                            Serial.println(minim);
                          }
                          if (pas>maxim)
                          {
                            maxim=pas;
//                            Serial.print("maxim ");
//                            Serial.println(maxim);
                          }
                        }
                        pas=pas+h;


                      }
                      Cy[i]=(minim+maxim)/2;
                    }

      }
      minim=1025;
      maxim=-1025;
      pas=h;
    }
  }

  for(unsigned short i=0;i<NR_F_Y;i++)
  {
    if(Fy[i]!=0)
    {
      suma_c+=Fy[i]*Cy[i];
      suma_f+=Fy[i];
    }
  }
  
  y=255-(suma_c/suma_f)-30;
  if (y>255) y=255;
  else
  if (y<0) y=0;
  return (y);  
  //return Y;
}



//declarare si implementare functii pt fuzzy:::
//###############################################################################


////////$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$//////////////////////////////
/////////////////////////////////////////////////////////////////////////////
void setup(void) 
{

  //##################################################################################  

  //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
  //initializare pini
  //int pwm 3
  //int senz 
  //##################################################################################  
  dx=253;
  //initializare variabile  
  //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


  Serial.begin(9600);

  // initialize the SD card at SPI_HALF_SPEED to avoid bus errors with
  // breadboards.  use SPI_FULL_SPEED for better performance.
 // if (!card.init(SPI_FULL_SPEED,8)) error("card.init failed");

  // initialize a FAT volume
//  if (!volume.init(&card)) error("volume.init failed");

  // open the root directory
//  if (!root.openRoot(&volume)) error("openRoot failed");

}
///////////////////////////$$$$$$$$$$$$$$$$$$$$////////////////////////////////////////
void loop()
{
/*
  //////////////////////////////////////////////
  //Serial.println("Send the config string ");
  Serial.flush();
  while (!Serial.available())
  {
    Serial.print("0");
  }
  i=0;
  nr=0;
  nr_read=0;
  reset_s(inByteBuffer);
  Serial.println(Serial.available()); //daca o scot nu merge lol
  while (nr<128)
  {
    while (!Serial.available());
    inByteBuffer[i]=Serial.read();
    Serial.print("0");
    nr_read++;
    delay(10);
    if (inByteBuffer[i]=='#')
    {
      inByteBuffer[i+1]='\0';
      nr++;
      if (nr==1)
      {
        NR_F_X=atoi(inByteBuffer);
      }
      else
        if (nr==2)
        {
          NR_F_dX=atoi(inByteBuffer);
        }
        else
          if (nr==3)
          {
            NR_F_Y=atoi(inByteBuffer);
          }
          else 
            if ((nr>3)&&(nr<54))
          {
            TIP_F_X[(nr-4)/5][(nr-4)%5]=atof(inByteBuffer);
          }
          else
            if ((nr>53)&&(nr<104))
            {
              TIP_F_dX[(nr-54)/5][(nr-54)%5]=atof(inByteBuffer);
            }
            else
              if ((nr>103)&&(nr<154))
              {
                TIP_F_X[(nr-104)/5][(nr-104)%5]=atof(inByteBuffer);
              }
      reset_s(inByteBuffer);
      i=0;
    }
    else
    {
      i=i+1;
    }
  }

  delay(10);

  // create a new file
/*
  for (uint8_t i = 0; i < 100; i++) {
    name[5] = i/10 + '0';
    name[6] = i%10 + '0';
    if (file.open(&root, name, O_CREAT | O_EXCL | O_WRITE)) break;
  }
  if (!file.isOpen()) error ("file.create");
  Serial.print("Writing to: ");
  Serial.println(name);
  writeNumber(file, NR_F_X);
  writeString(file, "#");
  writeNumber(file, NR_F_dX);
  writeString(file, "#");
  writeNumber(file, NR_F_Y);
  writeString(file, "#");
  for(byte i=0;i<10;i++)
  {
    for(byte j=0;j<5;j++)
    {
      SDprintDouble(file,TIP_F_X[i][j],6);
      writeString(file, "#");
    }
  }
  for(byte i=0;i<10;i++)
  {
    for(byte j=0;j<5;j++)
    {
      SDprintDouble(file,TIP_F_dX[i][j],6);
      writeString(file, "#");
    }
  }
  for(byte i=0;i<10;i++)
  {
    for(byte j=0;j<5;j++)
    {
      SDprintDouble(file,TIP_F_Y[i][j],6);
      writeString(file, "#");
    }
  }


  writeString(file, "\n");
  writeString(file, "\n");
  writeString(file, "NR_F_X ");
  writeNumber(file, NR_F_X);
  writeString(file, "\n");
  writeString(file, "NR_F_dX ");
  writeNumber(file, NR_F_dX);
  writeString(file, "\n");
  writeString(file, "NR_F_Y ");
  writeNumber(file, NR_F_Y);
  writeString(file, "\n");
  for(byte i=0;i<10;i++)
  {
    for(byte j=0;j<5;j++)
    {
      writeString(file, "TIP_F_X ");
      SDprintDouble(file,TIP_F_X[i][j],6);
      writeString(file, "\n");
    }
    writeString(file, "\n");
  }
  for(byte i=0;i<10;i++)
  {
    for(byte j=0;j<5;j++)
    {
      writeString(file, "TIP_F_dX ");
      SDprintDouble(file,TIP_F_dX[i][j],6);
      writeString(file, "\n");
    }
    writeString(file, "\n");
  }
  for(byte i=0;i<10;i++)
  {
    for(byte j=0;j<5;j++)
    {
      writeString(file, "TIP_F_Y ");
      SDprintDouble(file,TIP_F_Y[i][j],6);
      writeString(file, "\n");
    }
    writeString(file, "\n");
  }


  // close file and force write of all data to the SD card
  file.close();

  Serial.println("Done.Write");
  Serial.println();

  Serial.print("Reading from: ");
  Serial.println(name);
  Serial.println();

  // copy file to serial port
  file.open(&root, name, O_READ);
  if (!file.isOpen())
    error ("file.open");
  else
    while ((n = file.read(buf, sizeof(buf))) > 0) 
    {
      for (uint8_t i = 0; i < n; i++) Serial.print(buf[i]);
    }
  /* easier way
   int16_t c;
   while ((c = file.read()) > 0) Serial.print((char)c);
   */
   NR_F_X=5;
   NR_F_dX=3;
   NR_F_Y=3;
   TIP_F_X[0][0]=1;
   TIP_F_X[0][1]=20;
   TIP_F_X[0][2]=30;
   
   TIP_F_X[1][0]=3;
   TIP_F_X[1][1]=20;
   TIP_F_X[1][2]=30;
   TIP_F_X[1][3]=45;
   
   TIP_F_X[2][0]=3;
   TIP_F_X[2][1]=30;
   TIP_F_X[2][2]=45;
   TIP_F_X[2][3]=55;
   
   TIP_F_X[3][0]=3;
   TIP_F_X[3][1]=50;
   TIP_F_X[3][2]=65;
   TIP_F_X[3][3]=75;
   
   TIP_F_X[4][0]=2;
   TIP_F_X[4][1]=70;
   TIP_F_X[4][2]=90;
   
   TIP_F_dX[0][0]=1;
   TIP_F_dX[0][1]=0;
   TIP_F_dX[0][2]=30;
   
   TIP_F_dX[1][0]=4;
   TIP_F_dX[1][1]=25;
   TIP_F_dX[1][2]=30;
   TIP_F_dX[1][3]=55;
   TIP_F_dX[1][4]=60;
   
   TIP_F_dX[2][0]=2;
   TIP_F_dX[2][1]=55;
   TIP_F_dX[2][2]=70;
   
   TIP_F_Y[0][0]=1;
   TIP_F_Y[0][1]=0;
   TIP_F_Y[0][2]=30;
   
   TIP_F_Y[1][0]=4;
   TIP_F_Y[1][1]=25;
   TIP_F_Y[1][2]=30;
   TIP_F_Y[1][3]=55;
   TIP_F_Y[1][4]=60;
   
   
   
   
   TIP_F_Y[2][0]=2;
   TIP_F_Y[2][1]=55;
   TIP_F_Y[2][2]=70;
   

   
 mult_f_e_Y[0]='A';
 mult_f_e_Y[1]='B';
 mult_f_e_Y[2]='C';
         
BRF_E[0][0]='A';
BRF_E[0][1]='A';
BRF_E[0][2]='B';


BRF_E[1][0]='B';
BRF_E[1][1]='B';
BRF_E[1][2]='B';

BRF_E[2][0]='B';
BRF_E[2][1]='B';
BRF_E[2][2]='C';

BRF_E[3][0]='C';
BRF_E[3][1]='C';
BRF_E[3][2]='C';

BRF_E[4][0]='C';
BRF_E[4][1]='C';
BRF_E[4][2]='C';

   
   
  Serial.println("\nDone.read");
//  file.close();
// Serial.flush();

  ///////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////

  //////////////////////////////////////////////

  while(1)
  {
    /*
    file.open(&root, name,O_WRITE);
    if (!file.isOpen()) error ("file.create");
    else
    {
      Serial.print("Writing to: ");
      Serial.println(name);
      writeString(file, "\0");
      writeString(file, "x ");
      */
     // x=653-analogRead(A0);
        x=analogRead(A0);
        Serial.print("X= ");
        Serial.println(x);
//      writeNumber(file, dx);
      //SDprintDouble(file,dx,6);



      //Serial.println(x);
      fuzz(x,1,mx,NR_F_X,TIP_F_X);
      for(unsigned short i=0;i<NR_F_X;i++)
      {
      Serial.print("mx ");
      Serial.println(mx[i]); 
      }
      
      fuzz(dx,2,mdx,NR_F_dX,TIP_F_dX);
      for(unsigned short i=0;i<NR_F_dX;i++)
      {
        Serial.print("mdx ");
        Serial.println(mdx[i]); 
      }
      
     inferenta(W,mx,mdx);
  for(unsigned short i=0;i<10;i++)
  {
    for (unsigned short j=0;j<10;j++)
    {
      Serial.print("W ");
      Serial.print(int(W[i][j]));
      //SprintDouble(*W[i],2); 
    }
    Serial.println();
  }


      
      calc_ponderi(Optiune,NR_F_X,NR_F_dX,NR_F_Y,W,BRF_E,mult_f_e_Y,Fy);
      for(unsigned short i=0;i<NR_F_Y;i++)
      {
        Serial.print("Fy ");
        Serial.println(Fy[i]); 
      }
      
      
      y=defuzificare(Optiune,NR_P,NR_F_Y,Fy,TIP_F_Y);
     
      Serial.print("Y ");
      analogWrite(5, y);
      Serial.println(y);
      dx=x;
      /*
      time = micros();
      //delay(100);
      //Serial.println(x);
      // Serial.println(dx);
      // SprintDouble(time,0);
       // Serial.println(y);
       analogWrite(5, y);
      // if (Serial.available() > 0) {
      // get incoming byte:
      //   inByte = Serial.read();
      //  if (inByte=='B') // sper ca e corect
      //   break;
      //}
      // dx=y;
      
      if (Serial.available()>10)
      {
//file.close();
        break;
      }
      */
    }
 
  }















