/*9.Fa�a um programa que leia uma sequ�ncia de n�meros 
inteiros positivos do usu�rio e determine qual � o maior e o menor n�mero da sequ�ncia. 
O programa deve continuar lendo n�meros at� que o usu�rio insira um n�mero negativo.*/

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