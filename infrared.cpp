#include <Std_Types.h>
#include "configuration.h"
#include "Arduino.h"
#include "infrared.h"

float f_GetDistanceInfrared(uint8 u8_sensor)
{
	uint16 u16voltage;
	if(u8_sensor == 0)
	u16voltage = analogRead(A0);
	if(u8_sensor == 1)
	u16voltage = analogRead(A1);
	return (float)(FACTOR/u16voltage)-OFFSET;
}