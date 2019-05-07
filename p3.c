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
char Numero2[25];
float result = 0;
float result2 = 0;
int i=0;
int j=0;
int caluclo =0;
int calculo =0;
#INT_RDA
void main (void){
    printf("\fIngresa los datos=\n");
    while(TRUE){
    if(kbhit()){
    if(caluclo ==1){
        Numero2[j]=getch();
        if(Numero2[j]>=42 && Numero2[j]<=62 || Numero2[j]==13){
            printf("%c",Numero2[j]);
            if(Numero2[j]==13){
                calculo=2;
            }
        
            j++;
            if(calculo==2){
            result = atof(Numero);
            result2 = atof(Numero2);
            printf("%f \n",result);
            printf("%f \n",result2);
            clean();
            }
        }
    
    }else{
        Numero[i]=getch();
        if(Numero[i]>=42 && Numero[i]<=62 || Numero[i]==13){
            printf("%c",Numero[i]);
            if(Numero[i]==13){
            caluclo=1;
        }
        
        i++;
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
