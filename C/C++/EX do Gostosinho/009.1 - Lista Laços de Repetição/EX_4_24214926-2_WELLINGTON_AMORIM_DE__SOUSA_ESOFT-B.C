/*4.Crie um programa que exiba a tabuada do 7 usando um
laço for*/

#include <stdio.h>

int main(){
    int num = 7,soma = 0;
    for(int i=0;i<=10;i++){
        soma = num * i;
        printf("%d x %d = %d\n",num,i,soma);
        soma = 0;
    }
return 0;   
}