/*
 * usart.c
 *
 * Created: 31.08.2022 00:12:53
 *  Author: 90553
 */ 
 #include <avr/io.h>
 #define BAUD 9600
 #define F_CPU 16000000
 #define BAUDRATE ((F_CPU/BAUD/16)-1)

 void USART_INIT(){
	 /*Set baud rate */
	 UBRR0H = (unsigned char)(BAUDRATE>>8);
	 UBRR0L = (unsigned char)BAUDRATE;
	 /*Enable receiver and transmitter */
	 UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	 /* Set frame format: 8data, 2stop bit */
	 UCSR0C = (1<<USBS0)|(3<<UCSZ00);
 }

 void USART_SEND(unsigned char data){
	 /* Wait for empty transmit buffer */
	 while (!(UCSR0A & (1<<UDRE0)));
	 /* Put data into buffer, sends the data */
	 UDR0 = data;
 }
 unsigned char USART_RECEIVE(){
	 /* Wait for data to be received */
	 while (!(UCSR0A & (1<<RXC0)));
	 /* Get and return received data from buffer */
	 return UDR0;
 }