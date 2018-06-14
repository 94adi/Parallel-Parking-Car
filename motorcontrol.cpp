
/*Includes*/ 
//Needs std_types, configuration, supervision headers 
#include <Std_Types.h>
#include <configuration.h>
#include <Arduino.h>
#include <motorcontrol.h>
#include <util/delay.h>

uint8 MOTOR_A = 0;
uint8 MOTOR_B = 1;
uint8 CW = 0;
uint8 CCW = 1;

/* Setup for Ardumoto */
void vsetupArdumoto()
{  
  //Initialize all pins as low:
  digitalWrite(PWMA, LOW);
  digitalWrite(PWMB, LOW);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, LOW);
}

/*Ardumoto drive*/ 
void vdriveArdumoto(uint8 motor, uint8 dir, uint8 spd)
{
  if (motor == MOTOR_A)
  {
    digitalWrite(DIRA, dir);
    analogWrite(PWMA, spd);
  }
  else if (motor == MOTOR_B)
  {
    digitalWrite(DIRB, dir);
    analogWrite(PWMB, spd);
  } 
} 
/* Drive Forward */

void vdriveforward(uint8 motor, uint8 spd)
{
	if (motor == MOTOR_A)
  {
    analogWrite(PWMA, spd);
  }
  else if (motor == MOTOR_B)
  {
    analogWrite(PWMB, spd);
  } 
}
/* Stop Ardumoto */ 
void vstopArdumoto(uint8 motor)
{
  vdriveArdumoto(motor, 0, 0);
}

/* Steers Left */
void vMotorB_left()
{
	vdriveArdumoto(MOTOR_B, CCW, 0);
}	

/* Steers right */
void vMotorB_right()
{
  	vdriveArdumoto(MOTOR_B, CW, 0);
}