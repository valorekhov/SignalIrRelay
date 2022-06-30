
/*
 * main.cpp
 *
 * Created: 5/24/2014 8:14:21 PM
 *  Author: val
 */ 

//#include <Arduino.h>
#include "Board.h"
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <IRRemote.hpp>

unsigned int codes[4][151] = {
	{
		//Off Sequence
		4950, 2400, 500, 800, 500, 250, 500, 300, 500, 800, 500, 800, 500, 300, 450, 350, 450, 350, 450, 300, 500, 300, 450, 850, 450, 350, 450, 350, 400, 900, 400, 400, 350, 400, 400, 900, 400, 400, 400, 400, 350, 950, 350, 950, 350, 950, 350, 450, 350, 450, 350, 450, 300, 450, 350, 450, 300, 500, 300, 500, 300, 450, 300, 500, 300, 500, 300, 500, 300, 450, 300, 500, 300, 500, 300, 500, 250, 500, 300, 500, 300, 500, 300, 450, 300, 500, 300, 500, 300, 500, 300, 450, 300, 500, 300, 500, 300, 500, 300, 450, 300, 500, 300, 1000, 300, 500, 300, 500, 250, 1050, 300, 450, 300, 500, 300, 500, 300, 450, 300, 500, 300, 500, 300, 1000, 300, 500, 300, 450, 300, 500, 300, 500, 300, 500, 300, 450, 300, 500, 300, 1000, 300, 1000, 300, 500, 300, 500, 300,10000,0,11000,4950
	},
	{
		//Fan LOW sequence, louver High position
		0x1324, 0x9C4, 0x15E, 0x3B6, 0x15E, 0x1C2, 0x15E, 0x1C2, 0x15E, 0x3B6, 0x15E, 0x3B6, 0x15E, 0x1C2,
                0x12C, 0x1C2, 0x15E, 0x1C2, 0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x3E8, 0x12C, 0x1F4, 0xFA, 0x1F4, 0x12C,
                0x1F4, 0x12C, 0x1F4, 0x12C, 0x3E8, 0x12C, 0x1C2, 0x12C, 0x3E8, 0x12C, 0x3E8, 0x12C, 0x1F4, 0x12C, 0x1F4,
                0x12C, 0x1F4, 0x12C, 0x1C2, 0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x1C2, 0x12C, 0x1F4, 0x12C,
                0x1F4, 0x12C, 0x1F4, 0x12C, 0x1C2, 0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x1F4, 0xFA, 0x1F4, 0x12C, 0x1F4,
                0x12C, 0x1F4, 0x12C, 0x1C2, 0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x1C2, 0x12C, 0x1F4, 0x12C,
                0x1F4, 0x12C, 0x1F4, 0x12C, 0x1C2, 0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x1C2, 0x12C, 0x3E8,
                0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x3E8, 0x12C, 0x1C2, 0x15E, 0x1C2, 0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C,
                0x1C2, 0x12C, 0x41A, 0x12C, 0x3E8, 0x12C, 0x1C2, 0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x1F4, 0xFA, 0x1F4,
                0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x3E8, 0x12C, 0x3E8, 0x12C, 0x1C2, 0x12C, 0x41A, 0x12C, 10000, 0,
                11000, 4950	},
	{
		//Fan MED sequence, louver High
		0x13BA, 0x8FC, 0x258, 0x2BC, 0x866, 0x2EE, 0x226, 0x2EE, 0x546, 0x96, 0x258, 0xFA, 0x226, 0xFA, 0x226,
                0xC8, 0x226, 0x2EE, 0x226, 0xFA, 0x226, 0xFA, 0x1F4, 0x12C, 0x1F4, 0x320, 0x1F4, 0x12C, 0x1C2, 0x352,
                0x1C2, 0x15E, 0x190, 0x15E, 0x190, 0x190, 0x190, 0x384, 0x190, 0x190, 0x190, 0x190, 0x15E, 0x1C2, 0x15E,
                0x190, 0x190, 0x190, 0x15E, 0x1C2, 0x15E, 0x1C2, 0x15E, 0x1C2, 0x12C, 0x1C2, 0x15E, 0x1C2, 0x12C, 0x1F4,
                0x12C, 0x1F4, 0x12C, 0x1C2, 0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x1F4, 0xFA, 0x1F4, 0x12C, 0x1F4, 0x12C,
                0x1F4, 0x12C, 0x1C2, 0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x1C2, 0x12C, 0x1F4, 0x12C, 0x1F4,
                0x12C, 0x1F4, 0x12C, 0x1C2, 0x12C, 0x1F4, 0x12C, 0x3E8, 0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x3E8, 0x12C,
                0x1C2, 0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x1C2, 0x12C, 0x1F4, 0x12C, 0x3E8, 0x12C, 0x3E8, 0x12C, 0x1F4,
                0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x1C2, 0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x3E8, 0x12C,
                0x3E8, 0x12C, 0x1C2, 0x12C, 0x1F4, 0x12C, 10000, 0, 11000, 4950	},
	{
		//Fan High sequence, louver high
		5000, 2350, 500, 800, 500, 250, 550, 250, 550, 750, 550, 750, 550, 250, 500, 300, 500, 300, 500, 250, 500, 300, 450, 850, 450, 350, 450, 350, 400, 900, 400, 400, 350, 400, 400, 950, 350, 400, 400, 400, 350, 950, 400, 900, 400, 900, 350, 450, 350, 450, 350, 450, 300, 450, 350, 450, 350, 450, 300, 500, 300, 450, 300, 500, 300, 500, 300, 500, 300, 450, 300, 500, 300, 500, 300, 500, 250, 500, 300, 500, 300, 500, 300, 450, 300, 500, 300, 500, 300, 500, 300, 450, 300, 500, 300, 500, 300, 500, 250, 500, 300, 500, 300, 1000, 300, 500, 300, 500, 300, 1000, 300, 450, 300, 500, 300, 500, 300, 500, 250, 500, 300, 1000, 300, 1000, 300, 500, 300, 500, 300, 500, 300, 450, 300, 500, 300, 500, 300, 500, 300, 1000, 250, 1050, 300, 450, 300, 1000, 300,10000,0,11000,4950
	}/*,
	{
		 //Fan LOW sequence, louver all positions
                0x1388, 0x92E, 0x226, 0x2EE, 0x226, 0xC8, 0x226, 0xC8, 0x258, 0x2EE, 0x226, 0x2EE, 0x226, 0xFA, 0x1F4,
                0xFA, 0x226, 0xFA, 0x226, 0xFA, 0x1F4, 0x12C, 0x1F4, 0x320, 0x1F4, 0x12C, 0x1C2, 0x15E, 0x1C2, 0x12C,
                0x1C2, 0x15E, 0x190, 0x384, 0x190, 0x384, 0x190, 0x190, 0x190, 0x190, 0x15E, 0x3B6, 0x15E, 0x1C2, 0x15E,
                0x190, 0x190, 0x190, 0x15E, 0x1C2, 0x15E, 0x1C2, 0x15E, 0x1C2, 0x12C, 0x1C2, 0x15E, 0x1C2, 0x15E, 0x1C2,
                0x12C, 0x1F4, 0x12C, 0x1C2, 0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x1C2, 0x12C, 0x1F4, 0x12C,
                0x1F4, 0x12C, 0x1C2, 0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x1C2, 0x12C, 0x1F4, 0x12C, 0x1F4,
                0x12C, 0x1F4, 0x12C, 0x1C2, 0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x1C2, 0x12C, 0x3E8, 0x12C,
                0x1F4, 0x12C, 0x1F4, 0x12C, 0x3E8, 0x12C, 0x1F4, 0x12C, 0x1C2, 0x12C, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x1C2,
                0x12C, 0x41A, 0x12C, 0x3E8, 0x12C, 0x3E8, 0x12C, 0x3E8, 0x12C, 0x1F4, 0x12C, 0x1C2, 0x12C, 0x1F4, 0x12C,
                0x1F4, 0x12C, 0x1F4, 0xFA, 0x1F4, 0x12C, 0x1F4, 0x12C, 0x3E8, 0x12C, 0x1F4, 0x12C, 10000, 0, 11000, 4950	}
                */
};


IRsend irsend;
char currentSpeed;

void fan(uint8_t speed){	
		//LED1(PORT) = speed > 0 ? 1 : 0;
		for(uint8_t i=0; i<2; i++){
			irsend.sendRaw(codes[speed], 151, 38);
		}
		currentSpeed = speed;
}

uint16_t readAdc(uint8_t ch){
	
		ADMUX = (1<<REFS0);
		ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);

	_delay_ms(2);
	
	// select the corresponding channel 0~7
	ch &= 0b00000111;  // AND operation with 7
	 
	ADMUX = (ADMUX & 0xF8)|ch; // clears the bottom 3 bits before ORing
	
	// start single conversion
	// write �1? to ADSC
	ADCSRA |= (1<<ADSC);
	
	// wait for conversion to complete
	// ADSC becomes �0? again
	// till then, run loop continuously
	while(ADCSRA & (1<<ADSC));
	return (ADC);
}

//Temp is returned as C * 10 to avoid returning a float
int16_t readTemperature(){
	uint16_t reading = readAdc(0);
	float voltagemV = reading * AREFmV / 1023.0 ;  // Voltage at pin in milliVolts = (reading from ADC) * (AREF (mV)/1024)
	return (voltagemV - 500);
}

void blink(uint8_t times){
	for(uint8_t i=0; i<times; i++){
		LED1(PORT) = 1;
		_delay_ms(250);
		LED1(PORT) = 0;
		_delay_ms(250);
	}
}

bool getSwitchReading(){
	char ones=0, zeroes=0, i;
	for(i=0;i<10;i++){		
		if(SW1(IN)){ // read pin == 1
			ones++;
			} else { // read pin == 0
			zeroes++;
		}
		_delay_ms(10);
	}
	return ones>zeroes;
}

int main (void)
{
	int16_t temp = 200;
	char state = 0;
	char speed = 0;
	uint16_t zoneTicks = 0;
	PORTB=0x00;
	PORTD=0x00;	
	LED1(DDR) = 1;
	SW1(DDR) = 0;
		
	//while(1){
			//temp = readTemperature();
			//blink((temp / 10) - 20);
			//_delay_ms(10000);
	//}
	//while(1){
			//bool switchValue = getSwitchReading();
			//if (!switchValue)
				//LED1(PORT) =   1; 
					//else  
				//LED1(PORT) = 0;
			//_delay_ms(100);
	//}

	while(1){
		char switchValue = getSwitchReading();
		//stable reading
		if ( !switchValue ){ // switch is on, action in the zone (no edge transition) 
				if (speed > 0)
					blink(speed);
				if (zoneTicks-- <= 0){
					temp = readTemperature();
					
					//Cooling/heating mode speed selections. Values are in C, x10 to represent fractional C values as int
					if (temp >= 320 || temp <= 190)
						speed = 3;
						else if (temp >= 290 || temp <= 200)
						  speed = 2; 
						  else speed = 1;
				    if (speed != currentSpeed){
						char dif = speed - currentSpeed;
						if (dif > 0){			// Ramp up by stepping through speeds incrementally
							for(uint8_t i = currentSpeed + 1; i< speed; i++){
								fan(i);
								_delay_ms(5000);
							}
						} 
						fan(speed);
						zoneTicks = 300;
					}
				}
			}  else {
				if ( (switchValue ^ state) && switchValue ){ // switch is off, action on edge transition
					LED1(PORT) = 1;
					//Ramp down: run fan on low for approx < 1 min to equalize dT between Tcoil and Tambient
					if (speed != 1)
						fan(1);
					for(uint16_t i = 0; i< 5; i++){
						switchValue = getSwitchReading();
						if (!switchValue)				//call for Fan came in during the ramp down period
							break;
						_delay_ms(900);
					}					
					LED1(PORT) = 0;
					zoneTicks = 0;

					if (switchValue)					//no call for Fan at the end of ramp down, turn fan off.
						fan(0);
				}
				speed = 0;	
			}
			
		if (switchValue ^ state){
			state = switchValue;
		}
		
		//Sleep 
		_delay_ms(900);
	}
}

