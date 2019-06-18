#ifndef __MOTOR_H
#define __MOTOR_H

#include <stdint.h>

void motorControl( int left, int right );
void enableMotorICStby( void );

#endif /* __MOTOR_H */