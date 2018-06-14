#include "ultrasonicsenzor.h"
#include "configuration.h"
#include "Std_Types.h"
#include <Arduino.h>

uint16 u16getTimeInUs()
{
  uint16 u16duration;
  pinMode(PARALLAXPIN,OUTPUT);
  digitalWrite(PARALLAXPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(PARALLAXPIN, HIGH);
  delayMicroseconds(5);
  digitalWrite(PARALLAXPIN, LOW);
  delayMicroseconds(650);
  pinMode(PARALLAXPIN,INPUT);
  u16duration = pulseIn(PARALLAXPIN,HIGH);
  return u16duration;
}

uint16 u16getDistanceInCm(uint16 u16duration)
{
	return((u16duration/2)/29);
}