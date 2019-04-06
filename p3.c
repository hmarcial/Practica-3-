#include <18F4620.h>
#include <stdio.h>
#include <stdlib.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#use fast_io(c)
#int_RDA
char Cadena[25];
float flotante;
int i =0;
#define __DEBUG_SERIAL__ //Si comentas esta linea se deshabilita el debug por serial y el PIN_C6 puede ser usado en forma digital I/O
#use RS232(BAUD=9600, XMIT=PIN_C6, RCV=PIN_C7, BITS=8, PARITY=N, STOP=1)

void main (void){
SET_TRIS_C(0x80);
   enable_interrupts(INT_RDA);
   enable_interrupts(GLOBAL);
while(TRUE){
   {
   printf("Teclea Numero 1: ");
   if(kbhit()){
   Cadena[i] = getch();
   i++;
   }
   }while(Cadena[i]!= 97);
   flotante = atof(Cadena);
   printf("%f",flotante);
}
}
