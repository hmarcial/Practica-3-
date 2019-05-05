#include <18F4620.h>
#include <stdio.h>
#include <stdlib.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#use fast_io(c)
#define __DEBUG_SERIAL__ //Si comentas esta linea se deshabilita el debug por serial y el PIN_C6 puede ser usado en forma digital I/O
#use RS232(BAUD=9600, XMIT=PIN_C6, RCV=PIN_C7, BITS=8, PARITY=N, STOP=1)
void clean(void);
char Numero[25];
float result = 0;
int i=0;
int caluclo =0;
#INT_RDA
void main (void){
    //printf("\fIngresa los datos=\n");
    while(TRUE){
    if(kbhit()){
        Numero[i]=getch();
        if(Numero[i]>=42 && Numero[i]<=62 || Numero[i]==13){
            printf("%c",Numero[i]);
            if(Numero[i]==13){
            caluclo=1;
        }
        i++;
        if(caluclo == 1){
        result = atof(Numero);
        printf("%f \n",result);
        clean();
        }
    }
   }
   }
}
void clean(void){
       result=0;
       for(int clear=0; clear<i;clear++){
          if(Numero[clear]!=NULL){
              Numero[clear]=NULL;
         }
      }
      i=0;
      caluclo=0;

   }
