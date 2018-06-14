/* Defines */
#include <Std_Types.h>
#include "configuration.h"
#include "Arduino.h"

/*-------PIN Declaration-------*/ 


  
  uint32 u32_osSystemCounter = 0;   /* OS time from power up in ms			 */   
  uint16 u16_detectionStatus = 0;   /* Detection status 					 */
  uint8  u8_parkingstatus = 0;      /* Parking status 						 */
  uint16 u16_distanceIR_front = 0;  /* Voltage read from IR_Front sensor     */
  uint16 u16_distanceIR_rear = 0;   /* Voltage read from IR_Rear sensor 	 */
 
  /* Pin Mode Set */
  void vsetPinMode()
  {
	  pinMode(ANALOGINPUT0, INPUT);
	  pinMode(ANALOGINPUT1, INPUT);
	  pinMode(PARALLAXPIN, INPUT);	/* Pin mode will change for measurement purposes */
	  pinMode(PWMA, OUTPUT);
	  pinMode(PWMB, OUTPUT);
	  pinMode(DIRA, OUTPUT);
	  pinMode(DIRB, OUTPUT); 
	  pinMode(LEDPINRED, OUTPUT);
	  pinMode(LEDPINGREEN, OUTPUT);
  }
  
/*---------------------------------*/  
