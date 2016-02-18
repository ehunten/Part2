/*
 * File:   timer.c
 * Authors: Evelyn Hunten
 *
 * Created 2/16/16
 */

#include <xc.h>
#include "timer.h"

#define PRESC256 3
#define CLEAR 0
#define ENABLE 1
#define DEFAULT 7
#define PRVAL 49

void delayUs(unsigned int delay){

    //Create a delay for "delay" micro seconds using timer 2
    
      TMR2 = 0;
      PR2 = delay*PRVAL;
      IFS0bits.T2IF = 0;
      T1CONbits.ON = 1;
      
      while (IFS0bits.T2IF == CLEAR) {
        T2CONbits.ON = CLEAR;
      }
    
}
