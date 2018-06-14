#ifndef MOTORCONTROL_H 
#define MOTORCONTROL_H


extern uint8 MOTOR_A;
extern uint8 MOTOR_B;
extern uint8 CW;
extern uint8 CCW;
extern void vdriveArdumoto(uint8 motor, uint8 dir, uint8 spd); 
extern void vstopArdumoto(uint8 motor); 
extern void vMotorB_left(); 
extern void vMotorB_right();
extern void vsetupArdumoto();  
extern void vdriveforward(uint8 motor, uint8 spd);


#endif 