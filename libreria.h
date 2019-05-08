#include <18F4620.h>
#include <stdio.h>
#include <stdlib.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#use fast_io(c)
#define __DEBUG_SERIAL__ //Si comentas esta linea se deshabilita el debug por serial y el PIN_C6 puede ser usado en forma digital I/O
#use RS232(BAUD=9600, XMIT=PIN_C6, RCV=PIN_C7, BITS=8, PARITY=N, STOP=1)
char Numero[25];
char Numero2[25];
char operacion[4];
float result = 0;
float result2 = 0;
float fin=0;
int i=0;
int j=0;
int k=0;
int caluclo =0;
int calculo =0;
#INT_RDA
void clean(void);
void dale(void);
void clean(void){
       result=0;
       result2=0;
       fin=0;
       for(int clear=0; clear<i;clear++){
          if(Numero[clear]!=NULL){
              Numero[clear]=NULL;
         }
      }
      for(int cle=0; cle<j;cle++){
          if(Numero2[cle]!=NULL){
              Numero2[cle]=NULL;
         }
      }
      for(int cl=0; cl<k;cl++){
          if(operacion[cl]!=NULL){
              operacion[cl]=NULL;
         }
      }
      k=0;
      i=0;
      j=0;
      caluclo=0;
      calculo=0;
   }
void dale(void){
    switch(operacion[k])
            {
            case '+':
            fin= result + result2;
            printf("%.4f \n",fin);
            clean();
            break;
            case '-':
            fin= result - result2;
            printf("%.4f \n",fin);
            clean();
            break;
            case '*':
            fin= result * result2;
            printf("%.4f \n",fin);
            clean();
            break;
            case '/':
            fin= result / result2;
            printf("%.4f \n",fin);
            clean();
            break;
            }


}
