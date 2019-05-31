#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#use fast_io(c)
#define __DEBUG_SERIAL__ //Si comentas esta linea se deshabilita el debug por serial y el PIN_C6 puede ser usado en forma digital I/O
#use RS232(BAUD=9600, XMIT=PIN_C6, RCV=PIN_C7, BITS=8, PARITY=N, STOP=1)
void operaciones(char operacion[],int k,float result,float result2){
float fin =0;
switch(operacion[k])
            {
            case '+':
            fin= result + result2;
            printf(" = %.4f \n",fin);
            getch();
            printf("\f");
            break;
            case '-':
            fin= result - result2;
            printf(" = %.4f \n",fin);
            getch();
            printf("\f");
            break;
            case '*':
            fin= result * result2;
            printf(" = %.4f \n",fin);
            getch();
            printf("\f");
            break;
            case '/':
            if(result2==0){
            printf(" = No es Posible la Division entre 0");
            }else{
            fin= result / result2;
            printf(" = %.4f \n",fin);
            }
            getch();
            printf("\f");
            break;
            }
}
