#include <main.h>
#include <math.h>
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG,NOCPD
#use delay(clock=4000000)
#include <PIC18F4520_registers.h>
#define LCD_RS_PIN PIN_D0
#define LCD_RW_PIN PIN_D1
#define LCD_ENABLE_PIN PIN_D2
#define LCD_DATA4 PIN_D3
#define LCD_DATA5 PIN_D4
#define LCD_DATA6 PIN_D5
#define LCD_DATA7 PIN_D6
#include<lcd.c>
#include <ds1302.c>

#use rs232(baud=9600, xmit=pin_c6, rcv=pin_c7, parity=N, stop=1)
#use i2c (master,sda=pin_c4,scl=pin_c3,slow=100000)
#include<input.c>
#include <2402.c>
#use fast_io(b)
#use fast_io(d)

char sifre[131]={};

const float KARTUS =169043.48 ;// KARTUS OMRU sn cinsinden -- 2817.4 dk ya ESITTIR

int kesme=0;

int32 i=0;
int degisken2=0,degisken3=0,degisken4=0,degisken5=0,degisken6=0,degisken7=0,degisken8=0;
int coz,flag,key=3;
int h0,h1,h2,h3,h4,h5,h6,h7,h8,h9,h10,h11,h12,h13,h14,h15,h16,h17,h18,h19,h20,h21,h22,h23,h24,h25,h26,h27,h28,h29,h30,h31;
int h32,h33,h34,h35,h36,h37,h38,h39,h40,h41,h42,h43,h44,h45,h46,h47,h48,h49,h50,h51,h52,h53,h54,h55,h56,h57,h58,h59,h60,h61,h62;
int h63,h64,h65,h66,h67,h68,h69,h70,h71,h72,h73,h74,h75,h76,h77,h78,h79,h80,h81,h82,h83,h84,h85,h86,h87,h88,h89;
int h90,h91,h92,h93,h94,h95,h96,h97,h98,h99,h100,h101,h102,h103,h104,h105,h106,h107,h108,h109,h110,h111,h112,h113;
int h114,h115,h116,h117,h118,h119,h120,h121,h122,h123,h124,h125,h126,h127,h128,h129,h130;
int ptesibassaat1,ptesibasdk1,ptesibitsaat1,ptesibitdk1,ptesibassaat2,ptesibasdk2,ptesibitsaat2,ptesibitdk2;
int salibassaat1,salibasdk1,salibitsaat1,salibitdk1,salibassaat2,salibasdk2,salibitsaat2,salibitdk2;
int carbassaat1,carbasdk1,carbitsaat1,carbitdk1,carbassaat2,carbasdk2,carbitsaat2,carbitdk2;
int perbassaat1,perbasdk1,perbitsaat1,perbitdk1,perbassaat2,perbasdk2,perbitsaat2,perbitdk2;
int cumabassaat1,cumabasdk1,cumabitsaat1,cumabitdk1,cumabassaat2,cumabasdk2,cumabitsaat2,cumabitdk2;
int ctesibassaat1,ctesibasdk1,ctesibitsaat1,ctesibitdk1,ctesibassaat2,ctesibasdk2,ctesibitsaat2,ctesibitdk2;
int pazarbassaat1,pazarbasdk1,pazarbitsaat1,pazarbitdk1,pazarbassaat2,pazarbasdk2,pazarbitsaat2,pazarbitdk2,bugunsaat,bugundk,day;
void gunal(void);void bugun (void);
int sifrecoz(char c);
void saatcevir(void);
void tanimla(void);
void pazartesi1(void);void sali1(void);void carsamba1(void);void persembe1(void);
void cuma1(void);void cumartesi1(void);void pazar1(void);
void pazartesi2(void);void sali2(void);void carsamba2(void);void persembe2(void);
void cuma2(void);void cumartesi2(void);void pazar2(void);
void ortalama(void);
void gunkontrol(void);
void toplama(void);
void calistir(void);
void sifirla(int gn);
int farkal(int dk);
void bekleme(void);
void calis(void);
void ata(int t);
void eeprom();
void pazartesi_test();
void sali_test();
void carsamba_test();
void persembe_test();
void cuma_test();
void cumartesi_test();
void pazar_test();
signed int32 ptesisaat,ptesidk,salisaat,salidk,carsaat,cardk,persaat,perdk,cumasaat,cumadk,ctesisaat,ctesidk,pazarsaat,pazardk;
signed int32 ptesisaat2,ptesidk2,salisaat2,salidk2,carsaat2,cardk2,persaat2,perdk2,cumasaat2,cumadk2,ctesisaat2,ctesidk2,pazarsaat2,pazardk2;
signed int32 toplamsn,toplamdk;
signed int32 ptesitoplamdk,salitoplamdk,cartoplamdk,pertoplamdk,cumatoplamdk,ctesitoplamdk,pazartoplamdk ;
signed int32 ptesitoplamdk2,salitoplamdk2,cartoplamdk2,pertoplamdk2,cumatoplamdk2,ctesitoplamdk2,pazartoplamdk2;
float tetik,bekle,oran,pasifsn;
unsigned int32 sn1,sn3;
unsigned int32 sayi=0;
//unsigned int32 sn2,sn4,sayi;
int zet=20;
void run1(void); void run2(void);
int16 s1,s2,s3,s4,s5;
int1 eeprom_hazir;
int eeprom_test;


byte saniye,dakika,saat,gun,ay,yil,haftanin_gunu;
byte degisken=0;

unsigned int son,anliktmr;
#define settmr 7

#int_timer0
void timer0_kesmesi()
{ 
  if(sayi==0)
  {
    output_high(pin_b0);
  }
  
  sayi++;
  
  if(sayi==sn3)
  {
    output_low(pin_b0);
  }
  
  if(sayi==120000)
  {
    sayi=0;
  }
  
  anliktmr=get_timer0();
  son=anliktmr+settmr; 
  set_timer0(son); 
}

#int_rda
void serihaberlesme()
{  
   key=0;
   sifre[i]=getc();
   i++;
   if(i==131)
   {  
      i=0;   
      zet=2;
      kesme=1;
      key=1; 
      clear_interrupt(INT_RDA);
      disable_interrupts(int_rda); 
   }
}


void main()
{
// setup_psp(PSP_DISABLED);
setup_oscillator(OSC_4MHZ);
setup_adc_ports(NO_ANALOGS);
setup_adc(ADC_OFF);
setup_CCP1(CCP_OFF);
setup_CCP2(CCP_OFF);
lcd_init();  
enable_interrupts(GLOBAL);
enable_interrupts(int_rda);
set_tris_d(0x00);
output_d(0x00);
set_tris_b(0x00);
output_b(0x00);
rtc_init();
setup_timer_0(RTCC_INTERNAL | RTCC_DIV_4 | RTCC_8_BIT);
set_timer0(13);
    
baslangic:  
bit_clear(eeprom_test,0);
//disable_interrupts(int_timer0);
INTCON.T0IE=0;
output_high(pin_b0);
delay_ms(500);
output_low(pin_b0);
degisken=read_ext_eeprom(171);
delay_ms(20);
   
while(read_ext_eeprom(171)<32)
{    
   enable_interrupts(int_rda);
   
if(key==1)
{ 
   tanimla();
   pazartesi1(); 
   pazartesi2();
   sali1();
   sali2();
   carsamba1();
   carsamba2();
   persembe1();
   persembe2();
   cuma1();
   cuma2();
   cumartesi1();
   cumartesi2();
   pazar1();
   pazar2();
   toplama();  //yorum satýrýna alýnabilir nusrette deðil fatihte yorum satýrýndaydý.       
   //set_timer0(13);  //yoruma alýnabilir
   sayi=0;

   if(zet==2)
   {  
   bugun();
   rtc_set_datetime(1,1,22,day,bugunsaat,bugundk);
              
   write_eeprom(80,0);//kesme yapýldýgýna dair ROM a deger yazýldý 
   delay_ms(15);
   write_eeprom(81,0);//kesme yapýldýgýna dair ROM a deger yazýldý 
   delay_ms(15);
   write_eeprom(82,0);//kesme yapýldýgýna dair ROM a deger yazýldý 
   delay_ms(15);
   write_eeprom(83,0);//kesme yapýldýgýna dair ROM a deger yazýldý 
   delay_ms(15);
   write_eeprom(84,0);//kesme yapýldýgýna dair ROM a deger yazýldý 
   delay_ms(15);
   write_eeprom(85,0);//kesme yapýldýgýna dair ROM a deger yazýldý 
   delay_ms(15);
   write_eeprom(86,0);//kesme yapýldýgýna dair ROM a deger yazýldý
   delay_ms(15);
   zet=10;
   }          
   key=3;
}
      
   while(key==3)
   {        
      rtc_get_time(saat,dakika,saniye);
      rtc_get_date(gun,ay,yil,haftanin_gunu);
      toplama();

//******************************************************* PAZARTESI CALISMA SARTI **********************************************************        
      if(haftanin_gunu==1)
      { 
         rtc_get_time(saat,dakika,saniye);
         rtc_get_date(gun,ay,yil,haftanin_gunu); 
         delay_ms(30);    
         ata(1);//S1-S2-S3-S4-S5 hesaplanýr

         flag=INTCON.T0IE;
         printf(lcd_putc,"\f");
         lcd_gotoxy(1,1);//LCD belirtilen satýr ve sütuna git komutu
         printf(lcd_putc,"%ld %ld %ld %d %d",s1,s3,s2,haftanin_gunu,flag);  
         lcd_gotoxy(1,2);
         printf(lcd_putc,"%ld %ld",sn1,sn3);
         delay_ms(100);

         if(read_eeprom(0)==1 && read_eeprom(1)==0)   //PAZARTESI 1 ACIK-PAZARTESI 2 KAPALI *********************************************
         {     
            pazartesi_test();     
            if(bit_test(eeprom_test,1)==1)
            {
               bit_clear(eeprom_test,1);
               goto baslangic;
            }
                    
            if(((s1) <= (s3)) && ((s3) < (s2)))
            {                      
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
                     
               calistir();  

               if(kesme==1)
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;    
               }
            } 
            else
            {
               //disable_interrupts(int_timer0);
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
               //set_timer0(13);
            }
       
            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }   
         }
          
         else if(read_eeprom(0)==0 && read_eeprom(1)==1)   //PAZARTESI 1 KAPALI - PAZARTESI 2 ACIK******************************************* 
         {
            pazartesi_test();
                  
            if(bit_test(eeprom_test,1)==1)
            {
               bit_clear(eeprom_test,1);
               goto baslangic;
            }
                  
            if(((s4) <= (s3) && (s3) < (s5)))
            {    
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir();   
               if(kesme==1)
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;
               }
            }
            else
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
               //set_timer0(13);
            }
     
            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }
         }
         
         else if(read_eeprom(0)==1 && read_eeprom(1)==1)   //PAZARTESI 1 ACIK - PAZARTESI 2 ACIK ****************************************************
         {
            pazartesi_test();
                  
            if(bit_test(eeprom_test,1)==1)
            {
               bit_clear(eeprom_test,1);
               goto baslangic;
            }
                  
            if(((s1) <= (s3) && (s3) <= (s2)))
            {
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir();
               if(kesme==1)
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;
               }    
            }
                  
            if(((s1) < (s3) && (s3) > (s2) && (s3) < (s4)))
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
               //set_timer0(13);
            }       
            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }
                  
            if(((s4) <= (s3) && (s3) <= (s5)))
            { 
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir();
               if(kesme==1)
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;
               }
            }
            if(((s4) < (s3) && (s3) > (s5)))
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
               //set_timer0(13);
            }
                  
            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }
         }   
            output_low(pin_b6);
      }
  
//******************************************************* SALI CALISMA SARTI *****************************************************************          
      else if(haftanin_gunu==2)
      {  
         rtc_get_time(saat,dakika,saniye);
         rtc_get_date(gun,ay,yil,haftanin_gunu);
         delay_ms(30);
         
         ata(2);
            
         flag=INTCON.T0IE;
         printf(lcd_putc,"\f");
         lcd_gotoxy(1,1);//LCD belirtilen satýr ve sütuna git komutu
         printf(lcd_putc,"%ld %ld %ld %d %d",s1,s3,s2,haftanin_gunu,flag);  
         lcd_gotoxy(1,2);
         printf(lcd_putc,"%ld %ld %ld ",s4,s3,s5);
         delay_ms(100);
              
            
         if(read_eeprom(2)==1 && read_eeprom(3)==0)   //SALI 1 ACIK - SALI 2 KAPALI *******************************************************
         {     
            sali_test();
            
            if(bit_test(eeprom_test,2)==1)
            {
                bit_clear(eeprom_test,2);
                goto baslangic;
            }
                 
               
            if(((s1) <= (s3)) && ((s3) <= (s2)))
            { 
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir();
               if(kesme==1)
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;
               }
            }
            else
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
               //set_timer0(13);
            }
                  
            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }        
         }
            
         else if(read_eeprom(2)==0 && read_eeprom(3)==1)   //SALI 2 ACIK - SALI 1 KAPALI ********************************************************
         {
            sali_test();
               
            if(bit_test(eeprom_test,2)==1)
            {
               bit_clear(eeprom_test,2);
                goto baslangic;
            }

            if(((s4) <= (s3) && (s3) < (s5)))
            { 
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir();
               if(kesme==1)
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;
               }
            }
            else
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
               //set_timer0(13);
            }

            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }      
         }
         
         else if(read_eeprom(2)==1 && read_eeprom(3)==1)   //SALI 1 ACIK - SALI 2 ACIK *********************************************************
         {
            sali_test();
            
            if(bit_test(eeprom_test,2)==1)
            {
                bit_clear(eeprom_test,2);
                goto baslangic;
            }
            if(((s1) <= (s3) && (s3) <= (s2)))
            {
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir();
               if(kesme==1)
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;
               }  
            }
            if(((s1) < (s3) && (s3) > (s2) && (s3) < (s4)))
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
               //set_timer0(13);
            }

            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }
                  
            if(((s4) <= (s3) && (s3) < (s5)))
            {
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir();
               if(kesme==1)    
               { 
                  kesme=0;
                  goto baslangic;
                  key=1;
               }
            }
            if(((s4) < (s3) && (s3) > (s5)))
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
               //set_timer0(13);
            }

            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }
         }
      }
     
//******************************************************* CARSAMBA CALISMA SARTI **************************************************************          
      else if(haftanin_gunu==3)
      { 
         rtc_get_time(saat,dakika,saniye);
         rtc_get_date(gun,ay,yil,haftanin_gunu);
         delay_ms(30);  
         ata(3);
            
         flag=INTCON.T0IE;
         printf(lcd_putc,"\f");
         lcd_gotoxy(1,1);//LCD belirtilen satýr ve sütuna git komutu
         printf(lcd_putc,"%ld %ld %ld %d %d",s1,s3,s2,haftanin_gunu,flag);  
         lcd_gotoxy(1,2);
         printf(lcd_putc,"%02d:%02d:%02d ",saat,dakika,saniye);
         delay_ms(100);
            
            
         if(read_eeprom(4)==1 && read_eeprom(5)==0)   //CARSAMBA 1 ACIK - CARSAMBA 2 KAPALI *************************************************
         {  
            carsamba_test();
                  
            if(bit_test(eeprom_test,3)==1)
            {
               bit_clear(eeprom_test,3);
               goto baslangic;
            }
                 
            if(((s1) <= (s3)) && ((s3) < (s2)))
            {  
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir();
               if(kesme==1)
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;
               }
            } 
            else
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
               //set_timer0(13);
            }
                  
            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }
         }
            
         else if(read_eeprom(4)==0 && read_eeprom(5)==1)   //CARSAMBA 2 ACIK - CARSAMBA 1 KAPALI *************************************************
         {
            carsamba_test();
                  
            if(bit_test(eeprom_test,3)==1)
            {
               bit_clear(eeprom_test,3);
               goto baslangic;
            }
                  
            if(((s4) <= (s3) && (s3) < (s5)))
            {  
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir();                   
               if(kesme==1)
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;
               }
            }
            else
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
               //set_timer0(13);
            }
            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }
         }
         
         else if(read_eeprom(4)==1 && read_eeprom(5)==1)   //CARSAMBA 1 ACIK - CARSAMBA 2 ACIK *************************************************
         {
            carsamba_test();
                  
            if(bit_test(eeprom_test,3)==1)
            {
               bit_clear(eeprom_test,3);
               goto baslangic;
            }

            if(((s1) <= (s3) && (s3) < (s2)))
            {   
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir();
               if(kesme==1)
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;
               }  
            }
            if(((s1) < (s3) && (s3) > (s2) && (s3) < (s4)))
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
               //set_timer0(13);
            }

            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }
                  
            if(((s4) <= (s3) && (s3) < (s5)))
            { 
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir();
               if(kesme==1)
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;
               }
            }
            if(((s4) < (s3) && (s3) > (s5)))
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
               //set_timer0(13);
            }

            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }
         }    
      }
//******************************************************* PERSEMBE CALISMA SARTI ***************************************************************          
      else if(haftanin_gunu==4)
      { 
         rtc_get_time(saat,dakika,saniye);
         rtc_get_date(gun,ay,yil,haftanin_gunu);
         delay_ms(30);
         ata(4);
            
         flag=INTCON.T0IE;
         printf(lcd_putc,"\f");
         lcd_gotoxy(1,1);//LCD belirtilen satýr ve sütuna git komutu
         printf(lcd_putc,"%ld %ld %ld %d %d",s1,s3,s2,haftanin_gunu,flag);  
         lcd_gotoxy(1,2);
         printf(lcd_putc,"%02d:%02d:%02d ",saat,dakika,saniye);
         delay_ms(100);
            
            
         if(read_eeprom(6)==1 && read_eeprom(7)==0)   //PERSEMBE 1 ACIK - PERSEMBE 2 KAPALI *************************************************
         {
            persembe_test();
                   
            if(bit_test(eeprom_test,4)==1)
            {
               bit_clear(eeprom_test,4);
               goto baslangic;
            }
            
            if(((s1) <= (s3)) && ((s3) < (s2)))
            {      
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir();
               if(kesme==1)
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;
               }
            } 
            else
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
            }

            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }
         }
            
         else if(read_eeprom(6)==0 && read_eeprom(7)==1)   //PERSEMBE 2 ACIK - PERSEMBE 1 KAPALI *************************************************
         {
            persembe_test();
                   
            if(bit_test(eeprom_test,4)==1)
            {
               bit_clear(eeprom_test,4);
               goto baslangic;
            }
                  
            if(((s4) <= (s3) && (s3) < (s5)))
            {                   
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir(); 
               if(kesme==1)
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;
               }
            }
            else
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
            }
            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }
         }
         
         else if(read_eeprom(6)==1 && read_eeprom(7)==1)   //PERSEMBE 1 ACIK - PERSEMBE 2 ACIK *************************************************
         {
            persembe_test();
                   
            if(bit_test(eeprom_test,4)==1)
            {
               bit_clear(eeprom_test,4);
               goto baslangic;
            }
                  
            if(((s1) <= (s3) && (s3) < (s2)))
            {                 
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir();
               if(kesme==1)
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;
               }  
            }
            if(((s1) < (s3) && (s3) > (s2) && (s3) < (s4)))
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
            }

            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }
                  
            if(((s4) <= (s3) && (s3) < (s5)))
            {
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir();
               if(kesme==1)
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;
               }
            }
            if(((s4) < (s3) && (s3) > (s5)))
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
            }
            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }
         } 
      }   
//******************************************************* CUMA CALISMA SARTI ************************************************************       
      else if(haftanin_gunu==5)
      {  
         rtc_get_time(saat,dakika,saniye);
         rtc_get_date(gun,ay,yil,haftanin_gunu);
         delay_ms(30);  
         ata(5);
            
         flag=INTCON.T0IE;
         printf(lcd_putc,"\f");
         lcd_gotoxy(1,1);//LCD belirtilen satýr ve sütuna git komutu
         printf(lcd_putc,"%ld %ld %ld %d %d",s1,s3,s2,haftanin_gunu,flag);  
         lcd_gotoxy(1,2);
         printf(lcd_putc,"%02d:%02d:%02d ",saat,dakika,saniye);
         delay_ms(100);            
            
         if(read_eeprom(8)==1 && read_eeprom(9)==0)   //CUMA 1 ACIK - CUMA 2 KAPALI *************************************************
         {
            cuma_test();
            if(bit_test(eeprom_test,5)==1)
            {
               bit_clear(eeprom_test,5);
               goto baslangic;
            }
                          
            if(((s1) <= (s3)) && ((s3) < (s2)))
            { 
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir();
               if(kesme==1)
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;
               }
            } 
            else
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
            }
            if(kesme==1)
            { 
                kesme=0;
               key=1;
               goto baslangic;
            }
         }
            
         else if(read_eeprom(8)==0 && read_eeprom(9)==1)   //CUMA 2 ACIK - CUMA 1 KAPALI *************************************************
         {
            cuma_test();
            if(bit_test(eeprom_test,5)==1)
            {
                   bit_clear(eeprom_test,5);
                   goto baslangic;
            }

            if(((s4) <= (s3) && (s3) < (s5)))
            {  
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir();
               if(kesme==1)
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;
               }
            }
            else
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
            }

            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }
         }
         
         else if(read_eeprom(8)==1 && read_eeprom(9)==1)   //CUMA 1 ACIK - CUMA 2 ACIK *************************************************
         {
            cuma_test();
                  
            if(bit_test(eeprom_test,5)==1)
            {
               bit_clear(eeprom_test,5);
               goto baslangic;
            }

            if(((s1) <= (s3) && (s3) < (s2)))
            {
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir();
               if(kesme==1)
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;
               }  
            }
            if(((s1) < (s3) && (s3) > (s2) && (s3) < (s4)))
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
            }
            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }
                  
            if(((s4) <= (s3) && (s3) < (s5)))
            {  
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir();
               if(kesme==1)   
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;
               }
            }
            if(((s4) < (s3) && (s3) > (s5)))
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
            }
            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }
         }
      }    
//******************************************************* CUMARTESI CALISMA SARTI ****************************************************************        
      else if(haftanin_gunu==6)
      { 
         rtc_get_time(saat,dakika,saniye);
         rtc_get_date(gun,ay,yil,haftanin_gunu);
         delay_ms(30); 
         ata(6);
         
         flag=INTCON.T0IE;
         printf(lcd_putc,"\f");
         lcd_gotoxy(1,1);//LCD belirtilen satýr ve sütuna git komutu
         printf(lcd_putc,"%ld %ld %ld %d %d",s1,s3,s2,haftanin_gunu,flag);  
         lcd_gotoxy(1,2);
         printf(lcd_putc,"%02d:%02d:%02d ",saat,dakika,saniye);
         delay_ms(100);
            
         if(read_eeprom(10)==1 && read_eeprom(11)==0)   //CUMARTESÝ 1 ACIK-CUMARTESÝ 2 KAPALI *************************************************
         {
            cumartesi_test();
                 
            if(bit_test(eeprom_test,6)==1)
            {
               bit_clear(eeprom_test,6);
               goto baslangic;
            }
            
            if(((s1) <= (s3)) && ((s3) < (s2)))
            {   
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir();
               if(kesme==1)
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;
               }
            } 
            else
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
            }

            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }
         }
            
         else if(read_eeprom(10)==0 && read_eeprom(11)==1)   //CUMARTESÝ 2 ACIK-CUMARTESÝ 1 KAPALI *************************************************
         {
            cumartesi_test();
                 
            if(bit_test(eeprom_test,6)==1)
            {
               bit_clear(eeprom_test,6);
               goto baslangic;
            }  
            if(((s4) <= (s3) && (s3) < (s5)))
            { 
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir();            
               if(kesme==1)
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;
               }
            }
            else
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
            }

            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }
         }
         
         else if(read_eeprom(10)==1 && read_eeprom(11)==1)   //CUMARTESÝ 1 ACIK-CUMARTESÝ 2 ACIK *************************************************
         {
            cumartesi_test();
                 
            if(bit_test(eeprom_test,6)==1)
            {
               bit_clear(eeprom_test,6);
               goto baslangic;
            }
                  
            if(((s1) <= (s3) && (s3) < (s2)))
            {
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir();
               if(kesme==1)
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;
               }  
            }
            if(((s1) < (s3) && (s3) > (s2) && (s3) < (s4)))
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
            }

            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }
                  
            if(((s4) <= (s3) && (s3) < (s5)))
            {
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir();
               if(kesme==1)
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;
               }
            }
            if(((s4) < (s3) && (s3) > (s5)))
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
            }

            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }
         }
      }    
//******************************************************* PAZAR CALISMA SARTI ***********************************************************
      else if(haftanin_gunu==7)
      { 
         rtc_get_time(saat,dakika,saniye);
         rtc_get_date(gun,ay,yil,haftanin_gunu);
         delay_ms(30);
            
         ata(7);
            
         flag=INTCON.T0IE;
         printf(lcd_putc,"\f");
         lcd_gotoxy(1,1);//LCD belirtilen satýr ve sütuna git komutu
         printf(lcd_putc,"%ld %ld %ld %d %d",s1,s3,s2,haftanin_gunu,flag);  
         lcd_gotoxy(1,2);
         printf(lcd_putc,"%ld %ld %ld ",s4,s3,s5);
         delay_ms(100);

         if(read_eeprom(12)==1 && read_eeprom(13)==0)   //PAZAR 1 ACIK-PAZAR 2 KAPALI *************************************************
         {
            pazar_test();
                 
            if(bit_test(eeprom_test,7)==1)
            {
               bit_clear(eeprom_test,7);
               goto baslangic;
            }
            
            if(((s1) <= (s3)) && ((s3) < (s2)))
            { 
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir();
               if(kesme==1)
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;
               }
            }  
            else
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
            }

            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }
         }
            
         else if(read_eeprom(12)==0 && read_eeprom(13)==1)   //PAZAR 2 ACIK-PAZAR 1 KAPALI *************************************************
         {
            pazar_test();
                 
            if(bit_test(eeprom_test,7)==1)
            {
               bit_clear(eeprom_test,7);
               goto baslangic;
            }

            if(((s4) <= (s3) && (s3) < (s5)))
            { 
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir();
               if(kesme==1)
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;
               }
            }
            else
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
            }
            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }
         }
         
         else if(read_eeprom(12)==1 && read_eeprom(13)==1)  //PAZAR 1 ACIK-PAZAR 2 ACIK *****************************************************
         {
            pazar_test();
            
            if(bit_test(eeprom_test,7)==1)
            {
               bit_clear(eeprom_test,7);
               goto baslangic;
            }

            if(((s1) <= (s3) && (s3) < (s2)))
            {
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir();
               if(kesme==1)
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;
               }  
            }
            if(((s1) < (s3) && (s3) > (s2) && (s3) < (s4)))
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
            }

            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }
                  
            if(((s4) <= (s3) && (s3) < (s5)))
            {
               eeprom();
               if(bit_test(eeprom_test,0)==1)
               {
                  bit_clear(eeprom_test,0);
                  goto baslangic;
               }
               calistir();
               if(kesme==1)
               { 
                  kesme=0;
                  key=1;
                  goto baslangic;
               }
            }
            if(((s4) < (s3) && (s3) > (s5)))
            {
               if(INTCON.T0IE==1)
               {
                  INTCON.T0IE=0;
                  output_low(pin_b0);
                  sayi=0;
               }
            }

            if(kesme==1)
            { 
               kesme=0;
               key=1;
               goto baslangic;
            }        
         } 
      }
   }
   }//while TRUE
}//MAIN FONK. BITIS NOKTASI




//******************************************************************************* ALINAN DEÐERLER EEPROMA YAZILIYOR*********************************************************************************************************************
void tanimla(void)
{
h0=sifrecoz(sifre[0]);    h1=sifrecoz(sifre[1]);    h2=sifrecoz(sifre[2]);    h3=sifrecoz(sifre[3]);    h4=sifrecoz(sifre[4]);    h5=sifrecoz(sifre[5]);    h6=sifrecoz(sifre[6]);    h7=sifrecoz(sifre[7]);    h8=sifrecoz(sifre[8]);
h9=sifrecoz(sifre[9]);    h10=sifrecoz(sifre[10]);  h11=sifrecoz(sifre[11]);  h12=sifrecoz(sifre[12]);  h13=sifrecoz(sifre[13]);  h14=sifrecoz(sifre[14]);  h15=sifrecoz(sifre[15]);  h16=sifrecoz(sifre[16]);  h17=sifrecoz(sifre[17]);
h18=sifrecoz(sifre[18]);  h19=sifrecoz(sifre[19]);  h20=sifrecoz(sifre[20]);  h21=sifrecoz(sifre[21]);  h22=sifrecoz(sifre[22]);  h23=sifrecoz(sifre[23]);  h24=sifrecoz(sifre[24]);  h25=sifrecoz(sifre[25]);  h26=sifrecoz(sifre[26]);
h27=sifrecoz(sifre[27]);  h28=sifrecoz(sifre[28]);  h29=sifrecoz(sifre[29]);  h30=sifrecoz(sifre[30]);  h31=sifrecoz(sifre[31]);  h32=sifrecoz(sifre[32]);  h33=sifrecoz(sifre[33]);  h34=sifrecoz(sifre[34]);  h35=sifrecoz(sifre[35]);
h36=sifrecoz(sifre[36]);  h37=sifrecoz(sifre[37]);  h38=sifrecoz(sifre[38]);  h39=sifrecoz(sifre[39]);  h40=sifrecoz(sifre[40]);  h41=sifrecoz(sifre[41]);  h42=sifrecoz(sifre[42]);  h43=sifrecoz(sifre[43]);  h44=sifrecoz(sifre[44]);
h45=sifrecoz(sifre[45]);  h46=sifrecoz(sifre[46]);  h47=sifrecoz(sifre[47]);  h48=sifrecoz(sifre[48]);  h49=sifrecoz(sifre[49]);  h50=sifrecoz(sifre[50]);  h51=sifrecoz(sifre[51]);  h52=sifrecoz(sifre[52]);  h53=sifrecoz(sifre[53]);
h54=sifrecoz(sifre[54]);  h55=sifrecoz(sifre[55]);  h56=sifrecoz(sifre[56]);  h57=sifrecoz(sifre[57]);  h58=sifrecoz(sifre[58]);  h59=sifrecoz(sifre[59]);  h60=sifrecoz(sifre[60]);  h61=sifrecoz(sifre[61]);  h62=sifrecoz(sifre[62]);
h63=sifrecoz(sifre[63]);  h64=sifrecoz(sifre[64]);  h65=sifrecoz(sifre[65]);  h66=sifrecoz(sifre[66]);  h67=sifrecoz(sifre[67]);  h68=sifrecoz(sifre[68]);  h69=sifrecoz(sifre[69]);  h70=sifrecoz(sifre[70]);  h71=sifrecoz(sifre[71]);
h72=sifrecoz(sifre[72]);  h73=sifrecoz(sifre[73]);  h74=sifrecoz(sifre[74]);  h75=sifrecoz(sifre[75]);  h76=sifrecoz(sifre[76]);  h77=sifrecoz(sifre[77]);  h78=sifrecoz(sifre[78]);  h79=sifrecoz(sifre[79]);  h80=sifrecoz(sifre[80]);
h81=sifrecoz(sifre[81]);  h82=sifrecoz(sifre[82]);  h83=sifrecoz(sifre[83]);  h84=sifrecoz(sifre[84]);  h85=sifrecoz(sifre[85]);  h86=sifrecoz(sifre[86]);  h87=sifrecoz(sifre[87]);  h88=sifrecoz(sifre[88]);  h89=sifrecoz(sifre[89]);
h90=sifrecoz(sifre[90]);  h91=sifrecoz(sifre[91]);  h92=sifrecoz(sifre[92]);  h93=sifrecoz(sifre[93]);  h94=sifrecoz(sifre[94]);  h95=sifrecoz(sifre[95]);  h96=sifrecoz(sifre[96]);  h97=sifrecoz(sifre[97]);  h98=sifrecoz(sifre[98]);
h99=sifrecoz(sifre[99]);  h100=sifrecoz(sifre[100]);h101=sifrecoz(sifre[101]);h102=sifrecoz(sifre[102]);h103=sifrecoz(sifre[103]);h104=sifrecoz(sifre[104]);h105=sifrecoz(sifre[105]);h106=sifrecoz(sifre[106]);h107=sifrecoz(sifre[107]);
h108=sifrecoz(sifre[108]);h109=sifrecoz(sifre[109]);h110=sifrecoz(sifre[110]);h111=sifrecoz(sifre[111]);h112=sifrecoz(sifre[112]);h113=sifrecoz(sifre[113]);h114=sifrecoz(sifre[114]);h115=sifrecoz(sifre[115]);h116=sifrecoz(sifre[116]);
h117=sifrecoz(sifre[117]);h118=sifrecoz(sifre[118]);h119=sifrecoz(sifre[119]);h120=sifrecoz(sifre[120]);h121=sifrecoz(sifre[121]);h122=sifrecoz(sifre[122]);h123=sifrecoz(sifre[123]);h124=sifrecoz(sifre[124]);
h125=sifrecoz(sifre[125]);h126=sifrecoz(sifre[126]);h127=sifrecoz(sifre[127]);h128=sifrecoz(sifre[128]);h129=sifrecoz(sifre[129]);h130=sifrecoz(sifre[130]);

//******************************************************************************** ANAHTAR DEÐERLERÝ EEPROMA YAZILIYOR ********************************************************************************************************************
write_eeprom(0,h0);write_eeprom(1,h9);write_eeprom(2,h18);write_eeprom(3,h27);write_eeprom(4,h36);write_eeprom(5,h45);write_eeprom(6,h54);write_eeprom(7,h63);write_eeprom(8,h72);  //GUN AC/KAPA ANAHTARLARI
write_eeprom(9,h81); write_eeprom(10,h90);write_eeprom(11,h99);write_eeprom(12,h108);write_eeprom(13,h117);        
}

//******************************************************* PAZARTESI 1 FONKSIYONU*****************************************
void pazartesi1(void)
{
ptesibassaat1=((h1*10)+h2);
write_eeprom(14,ptesibassaat1);

ptesibasdk1=((h3*10)+h4);
write_eeprom(15,ptesibasdk1);

ptesibitsaat1=((h5*10)+h6);
write_eeprom(16,ptesibitsaat1);

ptesibitdk1=((h7*10)+h8);
write_eeprom(17,ptesibitdk1);
}

//******************************************************* PAZARTESI 2 FONKSIYONU*****************************************
void pazartesi2 (void)
{
ptesibassaat2=((h10*10)+h11);
write_eeprom(18,ptesibassaat2);

ptesibasdk2=((h12*10)+h13);
write_eeprom(19,ptesibasdk2);

ptesibitsaat2=((h14*10)+h15);
write_eeprom(20,ptesibitsaat2);

ptesibitdk2=((h16*10)+h17);
write_eeprom(21,ptesibitdk2);
}

//******************************************************* SALI 1 FONKSIYONU*****************************************
void sali1 (void)
{
salibassaat1=((h19*10)+h20);
write_eeprom(22,salibassaat1);

salibasdk1=((h21*10)+h22);
write_eeprom(23,salibasdk1);

salibitsaat1=((h23*10)+h24);
write_eeprom(24,salibitsaat1);

salibitdk1=((h25*10)+h26);
write_eeprom(25,salibitdk1);
}

//******************************************************* SALI 2 FONKSIYONU*****************************************
void sali2 (void)
{
salibassaat2=((h28*10)+h29);
write_eeprom(26,salibassaat2);

salibasdk2=((h30*10)+h31);
write_eeprom(27,salibasdk2);

salibitsaat2=((h32*10)+h33);
write_eeprom(28,salibitsaat2);

salibitdk2=((h34*10)+h35);
write_eeprom(29,salibitdk2);
}

//******************************************************* CARSAMBA 1 FONKSIYONU*****************************************
void carsamba1 (void)
{
carbassaat1=((h37*10)+h38);
write_eeprom(30,carbassaat1);

carbasdk1=((h39*10)+h40);
write_eeprom(31,carbasdk1);

carbitsaat1=((h41*10)+h42);
write_eeprom(32,carbitsaat1);

carbitdk1=((h43*10)+h44);
write_eeprom(33,carbitdk1);
}

//******************************************************* CARSAMBA 2 FONKSIYONU*****************************************
void carsamba2 (void)
{
carbassaat2=((h46*10)+h47);
write_eeprom(34,carbassaat2);

carbasdk2=((h48*10)+h49);
write_eeprom(35,carbasdk2);

carbitsaat2=((h50*10)+h51);
write_eeprom(36,carbitsaat2);

carbitdk2=((h52*10)+h53);
write_eeprom(37,carbitdk2);
}

//******************************************************* PERSEMBE 1 FONKSIYONU*****************************************
void persembe1 (void)
{
perbassaat1=((h55*10)+h56);
write_eeprom(38,perbassaat1);

perbasdk1=((h57*10)+h58);
write_eeprom(39,perbasdk1);

perbitsaat1=((h59*10)+h60);
write_eeprom(40,perbitsaat1);

perbitdk1=((h61*10)+h62);
write_eeprom(41,perbitdk1);
}

//******************************************************* PERSEMBE 2 FONKSIYONU*****************************************
void persembe2 (void)
{
perbassaat2=((h64*10)+h65);
write_eeprom(42,perbassaat2);

perbasdk2=((h66*10)+h67);
write_eeprom(43,perbasdk2);

perbitsaat2=((h68*10)+h69);
write_eeprom(44,perbitsaat2);

perbitdk2=((h70*10)+h71);
write_eeprom(45,perbitdk2);
}

//******************************************************* CUMA 1 FONKSIYONU*********************************************
void cuma1 (void)
{
cumabassaat1=((h73*10)+h74);
write_eeprom(46,cumabassaat1);

cumabasdk1=((h75*10)+h76);
write_eeprom(47,cumabasdk1);

cumabitsaat1=((h77*10)+h78);
write_eeprom(48,cumabitsaat1);

cumabitdk1=((h79*10)+h80);
write_eeprom(49,cumabitdk1);
}

//******************************************************* CUMA 2 FONKSIYONU*********************************************
void cuma2 (void)
{
cumabassaat2=((h82*10)+h83);
write_eeprom(50,cumabassaat2);

cumabasdk2=((h84*10)+h85);
write_eeprom(51,cumabasdk2);

cumabitsaat2=((h86*10)+h87);
write_eeprom(52,cumabitsaat2);

cumabitdk2=((h88*10)+h89);
write_eeprom(53,cumabitdk2);
}

//******************************************************* CUMARTESI 1 FONKSIYONU*****************************************
void cumartesi1 (void)
{
ctesibassaat1=((h91*10)+h92);
write_eeprom(54,ctesibassaat1);

ctesibasdk1=((h93*10)+h94);
write_eeprom(55,ctesibasdk1);

ctesibitsaat1=((h95*10)+h96);
write_eeprom(56,ctesibitsaat1);

ctesibitdk1=((h97*10)+h98);
write_eeprom(57,ctesibitdk1);
}

//******************************************************* CUMARTESI 2 FONKSIYONU******************************************

void cumartesi2 (void)
{
ctesibassaat2=((h100*10)+h101);
write_eeprom(58,ctesibassaat2);

ctesibasdk2=((h102*10)+h103);
write_eeprom(59,ctesibasdk2);

ctesibitsaat2=((h104*10)+h105);
write_eeprom(60,ctesibitsaat2);

ctesibitdk2=((h106*10)+h107);
write_eeprom(61,ctesibitdk2);
}

//******************************************************* PAZAR 1 FONKSIYONU*********************************************

void pazar1 (void)
{
pazarbassaat1=((h109*10)+h110);
write_eeprom(62,pazarbassaat1);

pazarbasdk1=((h111*10)+h112);
write_eeprom(63,pazarbasdk1);

pazarbitsaat1=((h113*10)+h114);
write_eeprom(64,pazarbitsaat1);

pazarbitdk1=((h115*10)+h116);
write_eeprom(65,pazarbitdk1);
}

//******************************************************* PAZAR 2 FONKSIYONU**********************************************

void pazar2 (void)
{
pazarbassaat2=((h118*10)+h119);
write_eeprom(66,pazarbassaat2);

pazarbasdk2=((h120*10)+h121);
write_eeprom(67,pazarbasdk2);

pazarbitsaat2=((h122*10)+h123);
write_eeprom(68,pazarbitsaat2);

pazarbitdk2=((h124*10)+h125);
write_eeprom(69,pazarbitdk2);
}

//******************************************************* BUGUN FONKSIYONU************************************************
void bugun (void)
{
   day=h126;
   bugunsaat=((h127*10)+h128);
   bugundk=((h129*10)+h130);
}

//******************************************TOPLAMA FONKSIYONU************************************************************

void toplama(void)
{
  //******************************* PAZARTESI 1 GUNU TOPLAM DK************************************
  
   if(read_eeprom(0)==1)// pazartesi1 günü acik ise
   {
      ptesisaat=read_eeprom(16)-read_eeprom(14);// 0 dan kucuk degilse islem aynen uygulanir
      ptesidk=read_eeprom(17)-read_eeprom(15);// 0 dan kucuk degilse islem aynen uygulanir
      ptesitoplamdk=(60*ptesisaat)+(ptesidk);
   }
   else if(read_eeprom(0)==0)// pazartesi1 günü kapali ise
   {
      ptesitoplamdk=0;
   }
     //******************************* PAZARTESI 2 GUNU TOPLAM DK***********************************
  
   if(read_eeprom(1)==1)// pazartesi2 günü acik ise
   {
      ptesisaat2=read_eeprom(20)-read_eeprom(18);// 0 dan kucuk degilse islem aynen uygulanir
      ptesidk2=read_eeprom(21)-read_eeprom(19);// 0 dan kucuk degilse islem aynen uygulanir
      ptesitoplamdk2=(60*ptesisaat2)+(ptesidk2);
   }
   else if(read_eeprom(1)==0)// pazartesi2 günü kapali ise
   {
      ptesitoplamdk2=0;
   }
   
   //********************************** SALI 1 GUNU TOPLAM DK***************************************
   if(read_eeprom(2)==1)// sali1 günü acik ise
   {
      salisaat=read_eeprom(24)-read_eeprom(22);
      salidk=read_eeprom(25)-read_eeprom(23);
      salitoplamdk=(60*salisaat)+(salidk);
   }
   else if(read_eeprom(2)==0)// sali1 günü kapali ise
   {
      salitoplamdk=0;  
   }
   
   
    //********************************** SALI 2 GUNU TOPLAM DK************************************
   if(read_eeprom(3)==1)// sali2 günü acik ise
   {
      salisaat2=read_eeprom(28)-read_eeprom(26);
      salidk2=read_eeprom(29)-read_eeprom(27);     
      salitoplamdk2=(60*salisaat2)+(salidk2);
   }
   else if(read_eeprom(3)==0)// sali2 günü kapali ise
   {
      salitoplamdk2=0;
   }
   
 
 //*********************************CARSAMBA 1 GUNU TOPLAM DK*************************************
   if(read_eeprom(4)==1)// carsamba1 günü acik ise
   {
      carsaat=read_eeprom(32)-read_eeprom(30);
      cardk=read_eeprom(33)-read_eeprom(31);   
      cartoplamdk=(60*carsaat)+(cardk);
   }
   else if(read_eeprom(4)==0)// carsamba1 günü kapali ise
   {
      cartoplamdk=0;
   }
   
   //*********************************CARSAMBA 2 GUNU TOPLAM DK***********************************
   if(read_eeprom(5)==1)// carsamba2 günü acik ise
   {
      carsaat2=read_eeprom(36)-read_eeprom(34);
      cardk2=read_eeprom(37)-read_eeprom(35);
      cartoplamdk2=(60*carsaat2)+(cardk2);
   }
   else if(read_eeprom(5)==0)// carsamba2 günü kapali ise
   {
      cartoplamdk2=0;
   }
   
   //*****************************PERSEMBE 1 GUNU TOPLAM DK****************************************
   if(read_eeprom(6)==1)// persembe1 günü acik ise
   {
      persaat=read_eeprom(40)-read_eeprom(38);
      perdk=read_eeprom(41)-read_eeprom(39);  
      pertoplamdk=(60*persaat)+(perdk);
   }
   else if(read_eeprom(6)==0)// persembe1 günü kapali ise
   {
      pertoplamdk=0;
   }
   
   
   //*****************************PERSEMBE 2 GUNU TOPLAM DK****************************************
   if(read_eeprom(7)==1)// persembe2 günü acik ise
   {
      persaat2=read_eeprom(44)-read_eeprom(42);
      perdk2=read_eeprom(45)-read_eeprom(43);
      pertoplamdk2=(60*persaat2)+(perdk2);
   }
   else if(read_eeprom(7)==0)// persembe2 günü kapali ise
   {
      pertoplamdk2=0;
   }
   

 //********************************* CUMA 1 GUNU TOPLAM DK******************************************
   if(read_eeprom(8)==1)// cuma günü acik ise
   {
      cumasaat=read_eeprom(48)-read_eeprom(46);
      cumadk=read_eeprom(49)-read_eeprom(47);
      cumatoplamdk=(60*cumasaat)+(cumadk);
   }
   else if(read_eeprom(8)==0)// cuma günü kapali ise
   {
      cumatoplamdk=0;
   }
   
   //********************************* CUMA 2 GUNU TOPLAM DK****************************************
   if(read_eeprom(9)==1)// cuma2 günü acik ise
   {
      cumasaat2=read_eeprom(52)-read_eeprom(50);
      cumadk2=read_eeprom(53)-read_eeprom(51);
      cumatoplamdk2=(60*cumasaat2)+(cumadk2);
   }
   else if(read_eeprom(9)==0)// cuma2 günü kapali ise
   {
      cumatoplamdk2=0;
   }
     

   //****************************** CUMARTESI 1 GUNU TOPLAM DK**************************************
   if(read_eeprom(10)==1)// cumartesi1 günü acik ise
   {
      ctesisaat=read_eeprom(56)-read_eeprom(54);
      ctesidk=read_eeprom(57)-read_eeprom(55);
      ctesitoplamdk=(60*ctesisaat)+(ctesidk);
   }
   else if(read_eeprom(10)==0)// cumartesi1 günü kapali ise
   {
      ctesitoplamdk=0;
   }
 
      //****************************** CUMARTESI 2 GUNU TOPLAM DK************************************
   if(read_eeprom(11)==1)// cumartesi2 günü acik ise
   {
      ctesisaat2=read_eeprom(60)-read_eeprom(58);
      ctesidk2=read_eeprom(61)-read_eeprom(59);
      ctesitoplamdk2=(60*ctesisaat2)+(ctesidk2);
   }
   else if(read_eeprom(11)==0)// cumartesi2 günü kapali ise
   {
      ctesitoplamdk2=0;
   }
     
   
   
//********************************* PAZAR 1 GUNU TOPLAM DK********************************************
   if(read_eeprom(12)==1)// pazar1 günü acik ise
   {
      pazarsaat=read_eeprom(64)-read_eeprom(62);
      pazardk=read_eeprom(65)-read_eeprom(63);
      pazartoplamdk=(60*pazarsaat)+(pazardk);
   }
   else if(read_eeprom(12)==0)// pazar1 günü kapali ise
   {
      pazartoplamdk=0;
   }
 
 
 //********************************* PAZAR 2 GUNU TOPLAM DK********************************************
   if(read_eeprom(13)==1)// pazar2 günü acik ise
   {
      pazarsaat2=read_eeprom(68)-read_eeprom(66);
      pazardk2=read_eeprom(69)-read_eeprom(67); 
      pazartoplamdk2=(60*pazarsaat2)+(pazardk2);
   }
   else if(read_eeprom(13)==0)// pazar2 günü kapali ise
   {
      pazartoplamdk2=0; 
   }
 
   toplamdk=ptesitoplamdk+salitoplamdk+cartoplamdk+pertoplamdk+cumatoplamdk+ctesitoplamdk+pazartoplamdk+ptesitoplamdk2+salitoplamdk2+cartoplamdk2+pertoplamdk2+cumatoplamdk2+ctesitoplamdk2+pazartoplamdk2;
   toplamsn=toplamdk*60;// CALISMA SURELERI ICINDEKI TOPLAM sn DEGERI
   pasifsn=((toplamsn)-(((KARTUS)/30)*7));//PASIF CALISMA SURESI
   oran=(pasifsn/((KARTUS/30)*7));//PASIF CALISMA SURESI ILE AKTIF CALISMA SURESI ORANI
   tetik=(120/(oran+1));//120 sn lik periyot içinde tetik süresi hesaplandi
   bekle=oran*tetik;//120 sn lik PERIYODUN BEKLEME SURESI
   bekle=bekle*1000;//bekleme suresi sn den msn ye cevrilir
   tetik=tetik*1000;//tetik suresi sn den msn ye cevrilir
   sn1=(bekle)-fmod((bekle),1);  // BEKLEME msn tam kýsmý hesaplanýyor
   //sn2=fmod((bekle/4),1)*1000;       // BEKLEME usn deðgeri hesaplaniyor
   sn3=((tetik)-fmod((tetik),1));  // TETIK msn tam kýsmý hesaplanýyor
   //sn4=fmod((tetik/4),1)*1000;       // TETIK usn degeri hesaplaniyor
}


int sifrecoz(char harf)
{
   if(harf=='c')
   {
     coz=0; 
   }
   else if(harf=='d')
   {
     coz=1; 
   }
   else if(harf=='e')
   {
     coz=2; 
   }
   else if(harf=='n')
   {
     coz=3; 
   }
   else if(harf=='g')
   {
     coz=4; 
   }
   else if(harf=='h')
   {
     coz=5; 
   }
   else if(harf=='m')
   {
     coz=6; 
   }
   else if(harf=='p')
   {
     coz=7; 
   }
   else if(harf=='r')
   {
     coz=8; 
   }
   else if(harf=='s')
   {
     coz=9; 
   }

   return coz;
}


void sifirla(int gn)
{

 if(gn!=1)
   {
      degisken2=0;
      write_eeprom(80,degisken2);
      delay_ms(15);
   }

 if(gn!=2)
   {
      degisken3=0;
      write_eeprom(81,degisken3);
      delay_ms(15);
   }

 if(gn!=3)
   {
      degisken4=0;
      write_eeprom(82,degisken4);
      delay_ms(15);
   }

 if(gn!=4)
   {
      degisken5=0;
      write_eeprom(83,degisken5);
      delay_ms(15);
   }

 if(gn!=5)
   {
      degisken6=0;
      write_eeprom(84,degisken6);
      delay_ms(15);
   }

 if(gn!=6)
   {
      degisken7=0;
      write_eeprom(85,degisken7);
      delay_ms(15);
   }

 if(gn!=7)
   {
      degisken8=0;
      write_eeprom(86,degisken8);
      delay_ms(15);
   }
}

void ata(int t)
{
  if(t==1)
  {
   s1=read_eeprom(14);//baslangic saati
   s1=s1*60;
   s1=s1+read_eeprom(15);//s1+dakika
   
   s2=read_eeprom(16);//bitis saati
   s2=s2*60;
   s2=s2+read_eeprom(17);//bitis dakikasi
   
   s3=(int16)saat*60;//RTC SAAT
   s3=s3+(int16)dakika;//RTC DAKIKA
   
   s4=read_eeprom(18);//baslangic saati 2
   s4=s4*60;
   s4=s4+read_eeprom(19);
   
   s5=read_eeprom(20);//bitis saati 2
   s5=s5*60;
   s5=s5+read_eeprom(21);
   
  }
   
  else if(t==2)
  {
   s1=read_eeprom(22);//baslangic saati
   s1=s1*60;
   s1=s1+read_eeprom(23);//s1+dakika
   
   s2=read_eeprom(24);//bitis saati
   s2=s2*60;
   s2=s2+read_eeprom(25);//bitis dakikasi
   
   s3=(int16)saat*60;//RTC SAAT
   s3=s3+(int16)dakika;//RTC DAKIKA
   
   s4=read_eeprom(26);//baslangic saati 2
   s4=s4*60;
   s4=s4+read_eeprom(27);
   
   s5=read_eeprom(28);//bitis saati 2
   s5=s5*60;
   s5=s5+read_eeprom(29);
  }
  else if(t==3)
  {
   s1=read_eeprom(30);//baslangic saati
   s1=s1*60;
   s1=s1+read_eeprom(31);//s1+dakika
   
   s2=read_eeprom(32);//bitis saati
   s2=s2*60;
   s2=s2+read_eeprom(33);//bitis dakikasi
   
   s3=(int16)saat*60;//RTC SAAT
   s3=s3+(int16)dakika;//RTC DAKIKA
   
   s4=read_eeprom(34);//baslangic saati 2
   s4=s4*60;
   s4=s4+read_eeprom(35);
   
   s5=read_eeprom(36);//bitis saati 2
   s5=s5*60;
   s5=s5+read_eeprom(37);
  }
   
  else if(t==4)
  {
   s1=read_eeprom(38);//baslangic saati
   s1=s1*60;
   s1=s1+read_eeprom(39);//s1+dakika
   
   s2=read_eeprom(40);//bitis saati
   s2=s2*60;
   s2=s2+read_eeprom(41);//bitis dakikasi
   
   s3=(int16)saat*60;//RTC SAAT
   s3=s3+(int16)dakika;//RTC DAKIKA
   
   s4=read_eeprom(42);//baslangic saati 2
   s4=s4*60;
   s4=s4+read_eeprom(43);
   
   s5=read_eeprom(44);//bitis saati 2
   s5=s5*60;
   s5=s5+read_eeprom(45);
  }
  else if(t==5)
  {
   s1=read_eeprom(46);//baslangic saati
   s1=s1*60;
   s1=s1+read_eeprom(47);//s1+dakika
   
   s2=read_eeprom(48);//bitis saati
   s2=s2*60;
   s2=s2+read_eeprom(49);//bitis dakikasi
   
   s3=(int16)saat*60;//RTC SAAT
   s3=s3+(int16)dakika;//RTC DAKIKA
   
   s4=read_eeprom(50);//baslangic saati 2
   s4=s4*60;
   s4=s4+read_eeprom(51);
   
   s5=read_eeprom(52);//bitis saati 2
   s5=s5*60;
   s5=s5+read_eeprom(53);
  }
  else if(t==6)
  {
   s1=read_eeprom(54);//baslangic saati
   s1=s1*60;
   s1=s1+read_eeprom(55);//s1+dakika
   
   s2=read_eeprom(56);//bitis saati
   s2=s2*60;
   s2=s2+read_eeprom(57);//bitis dakikasi
   
   s3=(int16)saat*60;//RTC SAAT
   s3=s3+(int16)dakika;//RTC DAKIKA
   
   s4=read_eeprom(58);//baslangic saati 2
   s4=s4*60;
   s4=s4+read_eeprom(59);
   
   s5=read_eeprom(60);//bitis saati 2
   s5=s5*60;
   s5=s5+read_eeprom(61);
  }
  else if(t==7)
  {
   s1=read_eeprom(62);//baslangic saati
   s1=s1*60;
   s1=s1+read_eeprom(63);//s1+dakika
   
   s2=read_eeprom(64);//bitis saati
   s2=s2*60;
   s2=s2+read_eeprom(65);//bitis dakikasi
   
   s3=(int16)saat*60;//RTC SAAT
   s3=s3+(int16)dakika;//RTC DAKIKA
   
   s4=read_eeprom(66);//baslangic saati 2
   s4=s4*60;
   s4=s4+read_eeprom(67);
   
   s5=read_eeprom(68);//bitis saati 2
   s5=s5*60;
   s5=s5+read_eeprom(69);
  }
}

void eeprom()
{
   eeprom_hazir=ext_eeprom_ready();
   if(eeprom_hazir==0)
   {  
      sayi=0;
      disable_interrupts(int_timer0); 
      output_low(pin_b0);
      bit_set(eeprom_test,0);
      printf(lcd_putc,"\f");
      lcd_gotoxy(1,1);//LCD belirtilen satýr ve sütuna git komutu
      printf(lcd_putc,"KARTI TAKINIZ"); 
      delay_ms(5);               
   }
}


void pazartesi_test()
{
   if(read_eeprom(80)<2)
   {              
      degisken2++;
      if(degisken2==1)
      {
         disable_interrupts(GLOBAL);
         degisken++;
         write_ext_eeprom(171,degisken);
         clear_interrupt(INT_RDA);
         enable_interrupts(GLOBAL);
         INTCON.T0IE==0;
         if(read_ext_eeprom(171)>31)
         {
            key=3;
            degisken=0;
            sayi=0;
            //disable_interrupts(int_timer0);
            bit_set(eeprom_test,1);   
         }
      }
                  
      if(degisken2==3)
      {         
         degisken2=2;
         write_eeprom(80,degisken2);
         delay_ms(10);
         sifirla(1);           
      }             
   }
}

void sali_test()
{
   if(read_eeprom(81)<2)
   {
      degisken3++;
      if(degisken3==1)
      {
         disable_interrupts(GLOBAL);
         degisken++;
         write_ext_eeprom(171,degisken);
         clear_interrupt(INT_RDA);
         enable_interrupts(GLOBAL);
         INTCON.T0IE==0;
         if(read_ext_eeprom(171)>31)
         {
            key=3;
            degisken=0;
            bit_set(eeprom_test,2);   
         }
      }
                 
      if(degisken3==3)
      {
         degisken3=2;
         write_eeprom(81,degisken3);
         delay_ms(10);
         sifirla(2);                
      }
   }
}

void carsamba_test()
{
   if(read_eeprom(82)<2)
   {                
      degisken4++;
      if(degisken4==1)
      { 
         disable_interrupts(GLOBAL);
         degisken++;
         write_ext_eeprom(171,degisken);
         clear_interrupt(INT_RDA);
         enable_interrupts(GLOBAL);
         INTCON.T0IE==0;
         if(read_ext_eeprom(171)>31)
         {
            key=3;
            degisken=0;
            bit_set(eeprom_test,3);   
         }
      }          
      if(degisken4==3)
      {
         degisken4=2;
         write_eeprom(82,degisken4);
         delay_ms(10);
         sifirla(3); 
      }
   }
}

void persembe_test()
{
   if(read_eeprom(83)<2)
   { 
      degisken5++;
      if(degisken5==1)
      { 
         disable_interrupts(GLOBAL);
         degisken++;
         write_ext_eeprom(171,degisken);
         clear_interrupt(INT_RDA);
         enable_interrupts(GLOBAL);
         INTCON.T0IE==0;
         if(read_ext_eeprom(171)>31)
         {
            key=3;
            degisken=0;
            bit_set(eeprom_test,4);  
         }
      }
                 
      if(degisken5==3)
      {
         degisken5=2;
         write_eeprom(83,degisken5);
         delay_ms(10);
         sifirla(4); 
      }
   }
}

void cuma_test()
{
   if(read_eeprom(84)<2)
   {
      degisken6++;
      if(degisken6==1)
      { 
         disable_interrupts(GLOBAL);
         degisken++;
         write_ext_eeprom(171,degisken);
         clear_interrupt(INT_RDA);
         enable_interrupts(GLOBAL);
         INTCON.T0IE==0;
         if(read_ext_eeprom(171)>31)
         {
            key=3;
            degisken=0;
            bit_set(eeprom_test,5);  
         }
      }
      if(degisken6==3)
      {
         degisken6=2;
         write_eeprom(84,degisken5);
         delay_ms(10);
         sifirla(5); 
      }
   }
}

void cumartesi_test()
{
   if(read_eeprom(85)<2)
   {               
      degisken7++;
      if(degisken7==1)
      { 
         disable_interrupts(GLOBAL);
         degisken++;
         write_ext_eeprom(171,degisken);
         clear_interrupt(INT_RDA);
         enable_interrupts(GLOBAL);
         INTCON.T0IE==0;
         if(read_ext_eeprom(171)>31)
         {
            key=3;
            degisken=0;
            bit_set(eeprom_test,6); 
         }
      }
                 
      if(degisken7==3)
      {
         degisken7=2;
         write_eeprom(85,degisken7);
         delay_ms(10);
         sifirla(6); 
      }
   }
}

void pazar_test()
{
   if(read_eeprom(86)<2)
   {
      degisken8++;
      if(degisken8==1)
      { 
         disable_interrupts(GLOBAL);
         degisken++;
         write_ext_eeprom(171,degisken);
         clear_interrupt(INT_RDA);
         enable_interrupts(GLOBAL);
         INTCON.T0IE==0;
         if(read_ext_eeprom(171)>31)
         {
            key=3;
            degisken=0;
            bit_set(eeprom_test,7); 
         } 
      }
                 
      if(degisken8==3)
      {
         degisken8=2;
         write_eeprom(86,degisken8);
         delay_ms(10);
         sifirla(7);
      }
   }
}

void calistir(void)
{
//enable_interrupts(int_rda);
   if(INTCON.T0IE==0)
   {
      set_timer0(settmr);
      INTCON.T0IE=1;
      //enable_interrupts(INT_timer0);
      enable_interrupts(GLOBAL);
   }
}















