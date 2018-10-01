/*
 * DCODelay.h
 *
 *  Created on: Oct 1, 2018
 *      Author: adfortne
 */

#ifndef DCODELAY_H_
#define DCODELAY_H_

#define FREQ_1500_KHz   CS_CTL0_DCORSEL_0 // Nominal DCO Frequency Range (MHz): 1 to 2
#define FREQ_3_MHz      CS_CTL0_DCORSEL_1 // Nominal DCO Frequency Range (MHz): 2 to 4
#define FREQ_6_MHz      CS_CTL0_DCORSEL_2 // Nominal DCO Frequency Range (MHz): 4 to 8
#define FREQ_12_MHz     CS_CTL0_DCORSEL_3 // Nominal DCO Frequency Range (MHz): 8 to 16
#define FREQ_24_MHz     CS_CTL0_DCORSEL_4 // Nominal DCO Frequency Range (MHz): 16 to 32
#define FREQ_48_MHz     CS_CTL0_DCORSEL_5 // Nominal DCO Frequency Range (MHz): 32 to 64S

void delay_us(int delay)
void set_DCO(uint32_t selectedFreq)

#endif /* DCODELAY_H_ */
