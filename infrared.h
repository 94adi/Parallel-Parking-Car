#ifndef _INFRARED_H_
#define _INFRARED_H_
#include <Std_Types.h>
#include "Arduino.h"

#define FACTOR (float)1286.5
#define OFFSET (float)1.0

extern float f_GetDistanceInfrared(uint8 u8_sensor);
extern float f_distanceIR_front;
extern float f_distanceIR_rear;
#endif