/*
 * io.c
 *
 *  Created on: Jun 17, 2019
 *      Author: alcne
 */


#include "io.h"
#include "gpio.h"
#include "main.h"

uint8_t getPushSW( void )
{
	return ~(LL_GPIO_IsInputPinSet(pushsw_GPIO_Port, pushsw_Pin)) & 0x01;
}

void setFullColorLed( uint8_t data )
{
  uint8_t red = data & 0x01;
  uint8_t green = (data & 0x02) >> 1;
  uint8_t blue = (data & 0x04) >> 2;

  if ( red == 0 ) LL_GPIO_SetOutputPin(fledred_GPIO_Port, fledred_Pin);
  else LL_GPIO_ResetOutputPin(fledred_GPIO_Port, fledred_Pin);

  if ( green == 0 ) LL_GPIO_SetOutputPin(fledgreen_GPIO_Port, fledgreen_Pin);
  else LL_GPIO_ResetOutputPin(fledgreen_GPIO_Port, fledgreen_Pin);

  if ( blue == 0 ) LL_GPIO_SetOutputPin(fledblue_GPIO_Port, fledblue_Pin);
  else LL_GPIO_ResetOutputPin(fledblue_GPIO_Port, fledblue_Pin);

}

void setUILed( uint8_t data )
{
  uint8_t left = data & 0x01;
  uint8_t right = (data & 0x02) >> 1;

  if ( left == 0 ) LL_GPIO_SetOutputPin(led1_GPIO_Port, led1_Pin);
  else LL_GPIO_ResetOutputPin(led1_GPIO_Port, led1_Pin);

  if ( right == 0 ) LL_GPIO_SetOutputPin(led2_GPIO_Port, led2_Pin);
  else LL_GPIO_ResetOutputPin(led2_GPIO_Port, led2_Pin);

}