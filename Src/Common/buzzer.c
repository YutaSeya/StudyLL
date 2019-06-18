#include "buzzer.h"
#include "tim.h"
#include "main.h"

static uint16_t buzzer_counter = 1;
static uint16_t beep_time = 0;

void setBuzzerMonophonic( uint16_t scale, uint16_t time_beep )
{
    LL_TIM_SetPrescaler(TIM2, scale);
    TIM2_PWM_Out( 99, 0 );
    buzzer_counter = 0;
    beep_time = time_beep;
}

void buzzerControl( void )
{
  if ( buzzer_counter > beep_time ){
    TIM2_PWM_Out( 0, 0 );
  } else {
    buzzer_counter++;
  }

}