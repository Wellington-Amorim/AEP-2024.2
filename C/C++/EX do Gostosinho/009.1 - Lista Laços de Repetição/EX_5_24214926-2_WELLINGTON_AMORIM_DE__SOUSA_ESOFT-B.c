/*5.Implemente um jogo de adivinha��o onde o
computador escolhe um n�mero aleat�rio e o jogador
deve acertar usando um la�o do-while. Dica: use a
fun��o rand().*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int num = 0,x = rand()%11; //O PC escolheu o n�mero 8 kkk
    do{
        printf("Tente adivinhar o numero de 0 a 10:\n");
        scanf(" %d", &num);

    }while(num!=x);
return 0;   
}