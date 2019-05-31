#include <Mate.h>
void clean(void);
void total(void);
char cadena[50];
float result = 0;
float result2 = 0;
int h=0;
int flagRecibido = 0;
int Caso = 0;
#INT_RDA
void serial_isr(){
  if(kbhit()){
      cadena[h]=getch();  
      flagRecibido=1;
  }
}
void main (void){
    enable_interrupts(global);
    enable_interrupts(int_rda);
    printf("Ingresa los datos de la siguiente manera numero 1 enter numero 2 enter operacion=  \n");
    while(TRUE){
      if(flagRecibido==1){
         flagRecibido=0;
        
        switch(Caso){
          case 0:
            if(cadena[h]>=48 && cadena[h]<=57 || cadena[h]==43 || cadena[h] ==45 || cadena[h] ==46 ){
               printf("%c",cadena[h]);
               h++;
            }
             if(cadena[h] == 13){
                 result=atof(cadena);
                 printf("\n\r");
                 printf("%f",result);
                 printf("\n\r");
                 clean();
                 Caso = 1;}
         break;
         case 1:
            if(cadena[h]>=48 && cadena[h]<=57 || cadena[h]==43 || cadena[h] ==45 || cadena[h] ==46 ){
               printf("%c",cadena[h]);         
               h++;
            }
            if(cadena[h] == 13){
               result2=atof(cadena);
               printf("\n\r");
               printf("%f",result2);
               printf("\n\r");
               clean();
               Caso = 2;
            }
         break;
         case 2:
            if(cadena[h]==42 || cadena[h]==43 || cadena[h]==45 || cadena[h] ==47){
               printf("%c",cadena[h]);
               operaciones(cadena,h,result,result2);
            }
            clean();
            total();
         break;
         
        }        
    }

  }
}
void clean(void){
      for(int c=0; c<=h;c++){
          if(cadena[c]!=NULL){
              cadena[c]=NULL;
         }
      }
      h=0;
}
void total(void){
   result = 0;
   result2 = 0;
   Caso = 0;
}
