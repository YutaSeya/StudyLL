/*
 * encoder.c
 * Author: sora
 */

#include "encoder.h"
#include "tim.h"

#include "config.h"

void TIM_Encoder_Start( void )
{
  LL_TIM_EnableCounter(TIM1);
  LL_TIM_EnableCounter(TIM8);
}

float getEncoderLeftVelocity( void )
{
  uint16_t cnt = TIM8->CNT;
  //uint16_t cnt = LL_TIM_GetCounter(TIM8);
  int16_t enc;
  float omega;
  float velocity;

  TIM8->CNT = 0;
  //LL_TIM_SetCounter(TIM8,0);

  if ( cnt > 32767 ) enc = (int16_t)cnt;
  else enc = (int16_t)cnt;

  omega = (float)enc * 2.0f / MACHINE_ENC_CNT_PER_ROT  * PI / dt;

  velocity = omega / dt * MACHINE_WHEEL_RADIUS;

  return velocity;

}

float getEncoderRightVelocity( void )
{
  uint16_t cnt = TIM1->CNT;
  //uint16_t cnt = LL_TIM_GetCounter(TIM1);
  int16_t enc;
  float omega;
  float velocity;

  TIM1->CNT = 0;
  //LL_TIM_SetCounter(TIM1,0);

  if ( cnt > 32767 ) enc = -1 * (int16_t)cnt;
  else enc = -1 * (int16_t)cnt;

  omega = (float)enc * 2.0f / MACHINE_ENC_CNT_PER_ROT  * PI / dt;

  velocity = omega / dt * MACHINE_WHEEL_RADIUS;

  return velocity;

}

void updateEncoder( t_run *left, t_run *right )
{
  left->velocity = getEncoderLeftVelocity();
  right->velocity = getEncoderRightVelocity();
}