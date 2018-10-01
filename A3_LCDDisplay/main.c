#include "msp.h"
#include <DCODELAY.h>

/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

    set_DCO(FREQ_1500_KHz);

//    P4->SEL0 |= BIT3; // Outputs MCLK on P4.3
//    P4->SEL1 &= ~BIT3;
//    P4->DIR |= BIT3;

      P1->DIR |= BIT0;
      P3->DIR |= BIT3;


      while (1) {
          delay_us(0);
          P1->OUT ^= BIT0;
          P3->OUT ^= BIT3;
      }
}
