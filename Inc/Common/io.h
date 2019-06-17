/*
 * io.h
 * Author: sora
 */

#ifndef __IO_H
#define __IO_H

#include <stdint.h>

uint8_t getPushSW( void );
void setFullColorLed( uint8_t data );
void setUILed( uint8_t data );

#endif /* __IO_H */
