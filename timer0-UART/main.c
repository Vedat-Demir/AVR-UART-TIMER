/*
 * timer0-UART.c
 *
 * Created: 30.08.2022 11:57:52
 * Author : 90553
 */ 

#include <avr/io.h>
#define F_CPU 16000000

#include "usart.c"
#include "timer0.c"



int main(void)
{	
	DDRB=0xff;
	PORTB=0xFF;
	char data='T';
	
	//USART_INIT();
    /* Replace with your application code */
    while (1) 
    {
		
		data=USART_RECEIVE();
		
		if(data == 'B'){
			while(1){
				TIMER0_DELAY();
				PORTB=0x00;
				TIMER0_DELAY();;
				PORTB=0xFF;
				data=USART_RECEIVE();
				if(data == 'T'){
					PORTB=0xff;
					break;
				}else if (data == 'F'){
					PORTB=0x00;
					break;
				}
			}
				
		}
		else if(data =='T')PORTB=0xff;
		else if(data == 'F')PORTB=0x00;
    }
}

