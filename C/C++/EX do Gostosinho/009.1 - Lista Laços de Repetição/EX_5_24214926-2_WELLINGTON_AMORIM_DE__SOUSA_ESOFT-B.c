/*5.Implemente um jogo de adivinhação onde o
computador escolhe um número aleatório e o jogador
deve acertar usando um laço do-while. Dica: use a
função rand().*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int num = 0,x = rand()%11; //O PC escolheu o número 8 kkk
    do{
        printf("Tente adivinhar o numero de 0 a 10:\n");
        scanf(" %d", &num);

    }while(num!=x);
return 0;   
}