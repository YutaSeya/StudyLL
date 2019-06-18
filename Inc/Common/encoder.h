/*
 * encoder.h
 * Author: sora
 */

#ifndef __ENCODER_H
#define __ENCODER_H

#include <stdint.h>
#include "variable.h"

void TIM_Encoder_Start( void );

float getEncoderLeftVelocity( void );
float getEncoderRightVelocity( void );

void updateEncoder( t_run *left, t_run *right );

#endif /* __ENCODER_H */