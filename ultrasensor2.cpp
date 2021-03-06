#include <Std_Types.h>
#include "configuration.h"
#include "Arduino.h"
#include "ultrasensor.h"

 	
float f_duration = 0;
float f_distance = 0;
float f_Ultrasonic2()
{
	
	pinMode(PARALLAXPIN, OUTPUT);
	digitalWrite(PARALLAXPIN, LOW);
	delayMicroseconds(2);
    digitalWrite(PARALLAXPIN, HIGH);
    delayMicroseconds(5);
    digitalWrite(PARALLAXPIN, LOW);
	delayMicroseconds(5);
    pinMode(6, INPUT);
    delayMicroseconds(650);
    f_duration = pulseIn(6, HIGH);
	f_distance = f_duration/58;
	if(f_distance - (int)f_distance >= 0.5)
	{
		return (float)((int)f_distance + 0.5);
	}
	else
	{
		return  (float)((int)f_distance);
	}
}