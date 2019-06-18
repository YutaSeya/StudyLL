#ifndef __BUZZER_H
#define __BUZZER_H

#include <stdint.h>

// music scale
#define NORMAL 799U
#define C_SCALE 3058U
#define D_SCALE 2727U
#define E_SCALE 2427U
#define F_SCALE 2290U
#define G_SCALE 2040U
#define A_SCALE 1818U
#define B_SCALE 1620U
#define C_H_SCALE 1529U

void setBuzzerMonophonic( uint16_t scale, uint16_t time_beep );
void buzzerControl( void );

#endif /* __BUZZER_H */