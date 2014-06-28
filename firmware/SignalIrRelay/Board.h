/*
 * Board.h
 *
 * Created: 5/25/2014 8:24:04 AM
 *  Author: val
 */ 


#ifndef BOARD_H_
#define BOARD_H_

#include <stdint.h>
#include <avr/io.h>

#define F_CPU 8000000L

struct bits {
	uint8_t b0:1;
	uint8_t b1:1;
	uint8_t b2:1;
	uint8_t b3:1;
	uint8_t b4:1;
	uint8_t b5:1;
	uint8_t b6:1;
	uint8_t b7:1;
} __attribute__((__packed__));
#define BIT(name,pin,reg) \
((*(volatile struct bits*)&reg##name).b##pin)

#define IN PIN
#define OUT PORT
#define DIR DDR

#define LED1(reg) BIT(B,5,reg)
#define SW0(reg) BIT(D,1,reg)
#define SW1(reg) BIT(D,2,reg)
#define PWM1(reg) BIT(D,3,reg)

#define TMP_SENSOR_ADC_CH 0
#define AVSS 4.0
#define AREFmV AVSS * 1000

#endif /* BOARD_H_ */