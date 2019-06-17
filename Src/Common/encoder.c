/*
 * encoder.c
 * Author: sora
 */

#include "encoder.h"
#include "tim.h"

void TIM_Encoder_Start( void )
{
  LL_TIM_EnableCounter(TIM1);
  LL_TIM_EnableCounter(TIM8);
}