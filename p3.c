#include <Mate.h>
void clean(void);
void total(void);
char cadena[50];
char operador;
float resultado = 0;
float resultado2 = 0;
int puntero=0;
int flagRecibido = 0;
int Caso = 0;
int MensajeInicio =1;
#INT_RDA
void serial_isr(){
  if(kbhit()){
      cadena[puntero]=getch();  
      flagRecibido=1;
      puntero++;
  }
}
void main (void){
    enable_interrupts(global);
    enable_interrupts(int_rda);
    while(TRUE){
      if(MensajeInicio==1){
         MensajeInicio=0;
         printf("Ingresa los datos de la siguiente manera numero 1 enter numero 2 enter operacion=  \n");
      }
      if(flagRecibido==1){
         flagRecibido=0;      
        switch(Caso){
          case 0:
            if(cadena[puntero-1]>=48 && cadena[puntero-1]<=57 || cadena[puntero-1]==43 || cadena[puntero-1] ==45 || cadena[puntero-1] ==46 ){
               printf("%c",cadena[puntero-1]);         
            }
             if(cadena[puntero-1] == 13){
                 resultado=atof(cadena);
                 printf("\n\r");
                 printf("%f",resultado);
                 printf("\n\r");
                 clean();
                 Caso = 1;
                 }
         break;
         case 1:
            if(cadena[puntero-1]>=48 && cadena[puntero-1]<=57 || cadena[puntero-1]==43 || cadena[puntero-1] ==45 || cadena[puntero-1] ==46 ){
               printf("%c",cadena[puntero-1]);         
            }
            if(cadena[puntero-1] == 13){
               resultado2=atof(cadena);
               printf("\n\r");
               printf("%f",resultado2);
               printf("\n\r");
               clean();
               Caso = 2;
            }
         break;
         case 2:
            if(cadena[puntero-1]==42 || cadena[puntero-1]==43 || cadena[puntero-1]==45 || cadena[puntero-1] ==47){
               printf("%c",cadena[puntero-1]);
               operador = cadena[puntero-1];
            }
            if(cadena[puntero-1] ==13){
               printf("\n\r");
               clean();
               Caso =3;
            }
         break;
         case 3:
            printf("El resultador es: ");
            operaciones(operador,resultado,resultado2);
            clean();
            total();
            MensajeInicio=1;
        }        
    }

  }
}
void clean(void){
      for(int c=0; c<=puntero;c++){
          if(cadena[c]!=NULL){
              cadena[c]=NULL;
         }
      }
      puntero=0;
}
void total(void){
   resultado = 0;
   resultado2 = 0;
   Caso = 0;
   operador=NULL;
}
