// ******************************************************************************************* //
//
// File:    main.c
// Authors: Evelyn Hunten
//
// Created 2/16/16 
// ******************************************************************************************* //

#include <xc.h>
#include <sys/attribs.h>
#include "lcd.h"
#include "timer.h"
#include "config.h"
#include "interrupt.h"


// ******************************************************************************************* //

int main(void)
{
    SYSTEMConfigPerformance(10000000);
    initTimer2();
    initLCD();
    
    while(1)
    {
        testLCD();
    }
    
    return 0;
}
