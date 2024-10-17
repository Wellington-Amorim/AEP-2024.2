/*8.Escreva um programa que verifique se um número é
primo usando um laço for.*/

#include <stdio.h>

int main(){
    int num,aux;

    printf("Escreva qualquer numero: ");
    scanf("%d",&num);

    for(int i=1;i<=num;i++){
        if(num%i == 0){
            aux += 1;
        }
    }
    if(aux==2){
        printf("O numero eh primo!");
    }else{
        printf("Nao eh numero primo.");
    }
return 0;   
}