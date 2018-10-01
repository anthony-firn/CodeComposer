#include "msp.h"
#include <DCODelay.h>

/*
 * DCODelay.c
 *
 *  Created on: Oct 1, 2018
 *      Author: adfortne
 */

void delay_us(int delay) {
    int i;
    int freqPower;
    int setup;
    int d;
    int n;

    switch (CS->CTL0) {
    case FREQ_1500_KHz :
        freqPower = 1;
        setup = 50;
        d = 133;
        n = 8;
        break;

    case FREQ_3_MHz :
        freqPower = 2;
        setup = 25;
        d = 138;
        n = 8;
        break;

    case FREQ_6_MHz :
        freqPower = 4;
        setup = 14;
        d = 138;
        n = 8;
        break;

    case FREQ_12_MHz :
        freqPower = 8;
        setup = 7;
        d = 138;
        n = 8;
        break;

    case FREQ_24_MHz :
        freqPower = 16;
        setup = 4;
        d = 138;
        n = 8;
        break;

    case FREQ_48_MHz :
        freqPower = 32;
        setup = 2;
        d = 148;
        n = 8;
        break;
    }

    if (setup >= delay)
        return;

    for (i = 0; i < ((delay-setup)*freqPower*n)/d; i++);
}

void set_DCO(uint32_t selectedFreq) {
    if (selectedFreq == FREQ_48_MHz) {
        /* Transition to VCORE Level 1: AM0_LDO --> AM1_LDO */
        while ((PCM->CTL1 & PCM_CTL1_PMR_BUSY));
        PCM->CTL0 = PCM_CTL0_KEY_VAL | PCM_CTL0_AMR_1;
        while ((PCM->CTL1 & PCM_CTL1_PMR_BUSY));
        /* Configure Flash wait-state to 1 for both banks 0 & 1 */
        FLCTL->BANK0_RDCTL = (FLCTL->BANK0_RDCTL &
                ~(FLCTL_BANK0_RDCTL_WAIT_MASK)) | FLCTL_BANK0_RDCTL_WAIT_1;
        FLCTL->BANK1_RDCTL = (FLCTL->BANK0_RDCTL &
                ~(FLCTL_BANK1_RDCTL_WAIT_MASK)) | FLCTL_BANK1_RDCTL_WAIT_1;
    }

    CS->KEY = CS_KEY_VAL;
    CS->CTL0 = selectedFreq;
    CS->CTL1 &= ~(CS_CTL1_SELM_MASK | CS_CTL1_DIVM_MASK) | CS_CTL1_SELM_3;
    CS->KEY = 0;
}
