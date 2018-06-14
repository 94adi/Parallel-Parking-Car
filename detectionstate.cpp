#include <Std_Types.h>
#include "configuration.h"
#include "Arduino.h"
#include "detectionstate.h"
#include "infrared.h"

float f_offsetdistanceIRcar = 3;
float f_offsetdistanceIRspace = 8;
float f_distanceIR_front = 0;
float f_distanceIR_rear = 0;

void v_detectionState()
{
	if(u16_detectionStatus == S0 && f_distanceIR_front <= f_offsetdistanceIRcar && f_distanceIR_rear <= f_offsetdistanceIRcar )
	{
		u16_detectionStatus = S1;
	}
	else if(u16_detectionStatus == S1 && f_distanceIR_front >= f_offsetdistanceIRspace && f_distanceIR_rear >= f_offsetdistanceIRspace)
	{
		u16_detectionStatus = S2;
	}
	else if(u16_detectionStatus == S2 && f_distanceIR_front <= f_offsetdistanceIRcar && f_distanceIR_rear <= f_offsetdistanceIRcar)
	{
		u16_detectionStatus = S3;
	}
}