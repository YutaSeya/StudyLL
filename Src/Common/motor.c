#include "motor.h"
#include "tim.h"

void TIM3_PWM_Out( uint32_t ch1, uint32_t ch2 )
{
	if ( ch1 < 0 ) ch1 = 0;
	if ( ch1 > 399 ) ch1 = 399;

	if ( ch2 < 0 ) ch2 = 0;
	if ( ch2 > 399 ) ch2 = 399;

	LL_TIM_OC_SetCompareCH1(TIM3, ch1);

	LL_TIM_OC_SetCompareCH2(TIM3, ch2);
}

void motorControl( int left, int right )
{
  uint32_t pwm_left = 0;
  uint32_t pwm_right = 0;

  if ( left >= 0 ) {
    pwm_left = (uint32_t)left;
    LL_GPIO_ResetOutputPin(IN1_L_GPIO_Port, IN1_L_Pin);
    LL_GPIO_SetOutputPin(IN2_L_GPIO_Port, IN2_L_Pin);
  } else {
    pwm_left = (int32_t)(-1 * left);
    LL_GPIO_SetOutputPin(IN1_L_GPIO_Port, IN1_L_Pin);
    LL_GPIO_ResetOutputPin(IN2_L_GPIO_Port, IN2_L_Pin);
  }

  if ( right >= 0 ) {
    pwm_right = (uint32_t)right;
    LL_GPIO_SetOutputPin(IN1_R_GPIO_Port, IN1_R_Pin);
    LL_GPIO_ResetOutputPin(IN2_R_GPIO_Port, IN2_R_Pin);
  } else {
    pwm_right = (int32_t)(-1 * right);
    LL_GPIO_ResetOutputPin(IN1_R_GPIO_Port, IN1_R_Pin);
    LL_GPIO_SetOutputPin(IN2_R_GPIO_Port, IN2_R_Pin);
  }

  TIM3_PWM_Out( pwm_left, pwm_right );

}

void enableMotorICStby( void )
{
  LL_GPIO_SetOutputPin( stby_GPIO_Port, stby_Pin );
}