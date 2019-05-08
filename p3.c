#include <libreria.h>
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
            operacion[k] = getch();
            if(operacion[k]==42 || operacion[k]==43 || operacion[k]==45 || operacion[k] ==47){
            printf("%c",operacion[k]);
            result = atof(Numero);
            result2 = atof(Numero2);
            dale();
            k++;
            }
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
