/*
 * File:   timer.c
 * Authors: Evelyn Hunten
 *
 * Created 2/16/16
 */

#include <xc.h>
#include "timer.h"

#define PRESC1 0
#define CLEAR 0
#define ENABLE 1
#define DEFAULT 7
#define PRVAL 9

void initTimer2(){
    IFS0bits.T2IF = CLEAR;          // Put the flag down
    TMR2 = CLEAR;                   //Clear TMR2
    PR2 = PRVAL;                    //Set PRvalue
    T2CONbits.TCKPS = PRESC1;       //Set prescalar
    T2CONbits.TCS = CLEAR;          //Set Oscillator
    IEC0bits.T2IE = ENABLE;         //enable interrupt
    IPC1bits.T1IP = DEFAULT;        //interrupt priority
    T2CONbits.ON = ENABLE;          //turn timer on
}

void delayUs(unsigned int delay){

    //Create a delay for "delay" micro seconds using timer 2
    
      TMR2 = 0;
      PR2 = delay*PRVAL;
      IFS0bits.T2IF = 0;
      T2CONbits.ON = 1;
      
      while (IFS0bits.T2IF == CLEAR);
      T2CONbits.ON = CLEAR;
      IFS0bits.T2IF = 0;
    
}
