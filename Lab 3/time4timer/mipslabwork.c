/* mipslabwork.c

  Farhan Syed
  Abhinav Sasikumar 

  2022
*/

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

int timeoutcount = 0;
int mytime = 0x5957;

char textstring[] = "text, more text, and even more text!";

/* Interrupt Service Routine */
void user_isr( void )
{
  return;
}

/* Lab-specific initialization goes here */
volatile int* trisE = (volatile int*) 0xbf886100;

void labinit( void ) {
  *trisE &= 0xffffff00;  
  TRISD |= 0x00fe0;       /// 0000 0000 1111 1110 0000

  T2CON = 0x70;        // 256 prescaling, 0111 0000 bits 6-4      bit 1 is 0 for internal clock
  PR2 = (80000000/256)/10 ;   // 80 mil / 256 / 10 = 31250, interrupts 10 times per second
  TMR2 = 0;

  T2CON |= 0x8000; //  bit 15 = turning timer on

  return;
}

volatile int* portE = (volatile int*) 0xbf886110;
/* This function is called repetitively from the main program */
void labwork( void )
{

  int buttonValue = getbtns();
  int switchValue = getsw();

  if(buttonValue & 0b0100){ //button 4
    mytime &= 0x0fff; 
    mytime |= (switchValue << 12);
  }
  if(buttonValue & 0b010){ //button 3
    mytime &= 0xf0ff;
    mytime |= (switchValue << 8);
  }
  if(buttonValue & 0b001){ //button 2
    mytime &= 0xff0f;
    mytime |= (switchValue << 4);
  }
  
  //delay( 1000 );
  if(IFS(0) & 0x100){ //T2IF --> 8th bit 
    timeoutcount++;
    IFS(0)  &= ~0x100; //resetting the 8th bit
    if(timeoutcount == 10){
      time2string( textstring, mytime );
      display_string( 3, textstring );
      display_update();
      tick( &mytime );
      timeoutcount = 0;
  
      *portE += 0x1;    
    };
  }
  display_image(96, icon);
}
