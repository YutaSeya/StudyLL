#ifndef __MOTOR_H
#define __MOTOR_H

#include <stdint.h>

void TIM3_PWM_Out( uint32_t ch1, uint32_t ch2 );
void motorControl( int left, int right );
void enableMotorICStby( void );

#endif /* __MOTOR_H */