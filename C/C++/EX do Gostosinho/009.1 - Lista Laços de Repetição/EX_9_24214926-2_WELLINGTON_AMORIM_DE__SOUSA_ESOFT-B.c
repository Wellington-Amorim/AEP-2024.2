/*9.Faça um programa que leia uma sequência de números 
inteiros positivos do usuário e determine qual é o maior e o menor número da sequência. 
O programa deve continuar lendo números até que o usuário insira um número negativo.*/

#include <stdio.h>

int main(){
    int num=0,maior=0,i=0;

    do{
        printf("\nDigite um numero: ");
        scanf("%d",&num);
            if(num > maior){
                maior = num;
            }
        printf("\nO numero %d eh o maior",maior);
        
        printf("\nSe quiser  sair, digite um numero negativo: \n");
        scanf("%d",&num);

    }while(i>=0);

return 0;
}