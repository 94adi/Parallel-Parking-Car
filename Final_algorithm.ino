#include<infrared2.h>
#include<Arduino.h>
#include<configuration.h>
#include <timerconfig.h>
#include<ultrasonicsenzor2.h>
#include<Std_Types.h>
#include<LEDS.h>
#include<motorcontrol.h>
typedef enum{s0,s1,s2,s3}detection_status;
typedef enum{p0,p1,p2,p3,p4,p5}parking_algo;
uint16 index=0;
uint8 u8new_value=0;
float fThreshDS1=2.0;
float fThreshDS2=4.0;
float fThreshDS3=2.0;
uint8 ds=s0;
uint8 parkingstatus=p0;
float distance1;
float distance2;
uint16 u16duration; 
uint16 u16dist; 


void setup()
{
  Serial.begin(9600);
  pinMode(LEDPINRED, OUTPUT);
 pinMode(LEDPINGREEN, OUTPUT);
 vsetupArdumoto();
  // initialize timer1 
  cli();           // disable all interrupts
  TCCR5A = 0;
  TCCR5B = 0;
  TCNT1  = 0;

  OCR5A = 200;            // compare match register 16MHz/256/2Hz
  TCCR5B |= (1 << WGM52);   // CTC mode
  TCCR5B |= (1 << CS50);    // 1024 prescaler 
  TCCR5B |= (1 << CS52);
  TIMSK5 |= (1 << OCIE5A);  // enable timer compare interrupt
  sei();             // enable all interrupts
}


void loop()
{
  if(u8new_value==1)
  {
    u8new_value=0;
    VChangeDetectionStatus();
    
     
  }
}
ISR(TIMER5_COMPA_vect)          // timer compare interrupt service routine
{
  u32_osSystemCounter+=5;
  if(u32_osSystemCounter%4==0)
     {   
        VUpdateColor(ds);
        distance1=f_getDistancefromIR(ANALOGINPUT0);
        distance2=f_getDistancefromIR(ANALOGINPUT1);
        u16duration = u16getTimeInUs();
        u16dist = u16getDistanceInCm(u16duration);
        Serial.print(distance1);
        Serial.print("cm  ");
        Serial.print(distance2);
        Serial.print("cm  ");
        Serial.print(u16dist);
        Serial.print("cm");
        Serial.println();
        u8new_value=1;
     }

}
void VChangeDetectionStatus()
{
    if(distance1<=fThreshDS1&&distance2<=fThreshDS1&&ds==s0)
      ds=s1;
    if(distance1>=fThreshDS2&&distance2>=fThreshDS2&&ds==s1)
      ds=s2;
    if(distance1<=fThreshDS3&&distance2<=fThreshDS3&&ds==s2)
      {
        ds=s3;
      }
    if(ds==s3)
    {
      ParkingAlgo();
    }
}

void ParkingAlgo()
{  
  
   switch(parkingstatus)
    {
      case p0:{vdriveArdumoto(0, 1, 100);
                if(distance2>=fThreshDS2)
               {  
                parkingstatus=p1;
                Serial.println();
                Serial.print("p1");
                Serial.println();
                Serial.println();
                Serial.println();
               }  break;}
      case p1:{vMotorB_right();
                if(distance1>=fThreshDS2&&u16dist<=8)
               {  
                parkingstatus=p2;
                Serial.println();
                Serial.print("p2");
                Serial.println();
                Serial.println();
                Serial.println();
               }  break;}
      case p2:{vstopArdumoto(1);
                if(distance2<=fThreshDS2&&u16dist<=6)
               {  
                parkingstatus=p3;
                Serial.println();
                Serial.print("p3");
                Serial.println();
                Serial.println();
                Serial.println();
               }  break;}
      case p3:{vMotorB_left();
                if(distance2<=fThreshDS1&&distance1<=fThreshDS1&&u16dist<=6)
               {  
                parkingstatus=p4;
                Serial.println();
                Serial.print("p4");
                Serial.println();
                Serial.println();
                Serial.println();
               }  break;}
      case p4:{vstopArdumoto(0);
              vMotorB_right();
              vdriveArdumoto(0, 0, 100);
                if(u16dist>=6)
               {  
                parkingstatus=p5;
                Serial.println();
                Serial.print("p5");
                Serial.println();
                Serial.println();
                Serial.println();
               }  break;}
      case p5:{vstopArdumoto(1);
              vdriveArdumoto(0, 1, 100);
                if(u16dist<=4)
               {  
                vstopArdumoto(0);
                ds=4;
               }  break;}
      default:{Serial.print("Error");break;}
    }
}
