#include "interrupt.h"

#include "variable.h"
#include "config.h"

#include "encoder.h"
#include "buzzer.h"


void interrupt( void )
{
  updateEncoder( &left_real, &right_real );
  buzzerControl();
  left_real.distance += left_real.velocity * dt;
  right_real.distance += right_real.velocity * dt;
}