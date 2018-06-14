#include<timerconfig.h>
#include<Arduino.h>

void v_TimerConfig()
{
	cli();
	TCCR5A = 0;
	TCCR5B = 0;
	TIMSK5 |= (1<<OCIE5A);
	TCCR5B |= (1<<CS50) | (1<<CS52) | (1<<WGM52);
	OCR5A = 0X4E;
	sei();
	
}