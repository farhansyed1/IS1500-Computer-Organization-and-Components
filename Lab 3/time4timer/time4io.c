#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"

int getsw(void) {
   return ((PORTD >> 8) & 0xF);             // 0000 0111 0000 0000
}

int getbtns(void){
    return ((PORTD >> 5) & 0x7);
}