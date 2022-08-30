/*
 * timer0.c
 *
 * Created: 31.08.2022 00:14:47
 *  Author: 90553
 */ 
 #include <avr/io.h>
 void TIMER0_DELAY(){
	 
	 for(uint16_t i=0;i<62700;i++){
		 TCCR0A=0x00;
		 TCCR0B=0x01;
		 TCNT0=0x00;
		 while((TIFR0 & (1<<TOV0))==0);
		 TIFR0 |=(1<<TOV0);
	 }

 }