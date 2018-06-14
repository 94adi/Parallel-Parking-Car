
#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include <Std_Types.h>
#include "Arduino.h"

/*-------PIN Declaration-------*/ 

  /* IR Sensor */
  #define ANALOGINPUT0 A0  			/* Analog input pin for IR_Front sensor  */
  #define ANALOGINPUT1 A1  			/* Analog input pin for IR_Rear sensor 	 */
  
  /* Motor A */ 
  #define PWMA 3  					/* PWM control (speed) for motor A 		 */
  #define DIRA 5  					/* Direction control for motor A 		 */

  /* Motor B */ 
  #define PWMB 6  					/* PWM control (speed) for motor B		 */
  #define DIRB 9 					/* Direction control for motor B		 */
 
  /*Parallax Ping Sensor*/ 
  #define PARALLAXPIN 7   			/* I/O Pin for reading the time between  */ 
									/* the rising edge and falling edge 	 */

  /*LED*/
  #define LEDPINRED 10      		/* RED anode of LED connected to pin 9	 */
  #define LEDPINGREEN 11   			/* GREEN anode of LED connected to pin10 */
  
  /*-------Variable Declaration-------*/ 
  
  /* OS */
  extern uint32 u32_osSystemCounter;   
  
  /*Detection status*/
  extern uint16 u16_detectionStatus; 
  extern uint8 u8_parkingstatus;
  
  /* Distance from Infrared */
  extern uint16 u16_distanceIR_front; 
  extern uint16 u16_distanceIR_rear; 
  

  
   /*-------Function Declaration-------*/  
  
  /* Pin Mode Set */
  extern void vsetPinMode();
  

/*---------------------------------*/  

#endif /*CONFIGURATION_H*/ 
