#include "interrupt.h"

#include "variable.h"
#include "encoder.h"

void interrupt( void )
{
  updateEncoder( &left_real, &right_real );
}