#include <Arduino.h>
/*
  Arduino code for generate 40Khz signal in A0 - A3 pins
*/

//Generate exact delay for recreate wave
//ref: http://www.nongnu.org/avr-libc/user-manual/inline_asm.html
#define delayTime asm volatile("nop\n" "nop\n" "nop\n" "nop\n" "nop\n" "nop\n" "nop\n" "nop\n" "nop\n" "nop\n" "nop\n" "nop\n" "nop\n" "nop\n");

void setup() {
  DDRC = 0b00111111;
  PORTC = 0b00000000;
  //Generate 40KHz signal using timer1 and interrupts
  //Ref: https://arduinodiy.wordpress.com/2012/02/28/timer-interrupts/
  OCR1A = (F_CPU/40000L)-1;
  OCR1B = (F_CPU/40000L)>>2;
  TCCR1A = bit(WGM10)| bit(WGM11)| bit(COM1B1);
  TCCR1B = bit(WGM12)| bit(WGM13)| bit(CS10);
  pinMode(10, OUTPUT);
  pinMode(11, INPUT_PULLUP);
}

void loop() {
  //Manual wave for change driver polarity producing 40KHz signal on top and inverse
  //signal on bottom
  while(PINB & 0b00001000);
  PORTC = 0x6;
  delayTime;
  PORTC = 0xc;
  delayTime;
  PORTC = 0xc;
  delayTime;
  PORTC = 0xc;
  delayTime;
  PORTC = 0xc;
  delayTime;
  PORTC = 0xc;
  delayTime;
  PORTC = 0x9;
  delayTime;
  PORTC = 0x9;
  delayTime;
  PORTC = 0x9;
  delayTime;
  PORTC = 0x9;
  delayTime;
  PORTC = 0x9;
  delayTime;
  PORTC = 0x9;
  delayTime;
  PORTC = 0x9;
  delayTime;
  PORTC = 0x3;
  delayTime;
  PORTC = 0x3;
  delayTime;
  PORTC = 0x3;
  delayTime;
  PORTC = 0x3;
  delayTime;
  PORTC = 0x3;
  delayTime;
  PORTC = 0x6;
  delayTime;
  PORTC = 0x6;
  delayTime;
  PORTC = 0x6;
  delayTime;
  PORTC = 0x6;
  delayTime;
  PORTC = 0x6;
  delayTime;
  PORTC = 0x6;
  delayTime;
}
