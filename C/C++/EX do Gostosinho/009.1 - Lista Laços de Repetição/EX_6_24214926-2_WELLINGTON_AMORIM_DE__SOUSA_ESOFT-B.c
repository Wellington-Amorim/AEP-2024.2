/*6.Faça um programa que calcule a média de altura de
uma turma de alunos usando um laço for. O número de
alunos deve ser solicitado.*/

#include <stdio.h>


int main(){
    float altura,aux;
    int quantidade;

    printf("Quantos alunos ha em sua sala?\n");
    scanf("%d",&quantidade);

    printf("\nCALCULO DA MEDIA DOS ALUNOS");

    for(int i=1;i<=quantidade;i++){
        printf("\nAluno %d:",i);
        scanf("%f",&aux);
        altura += aux;
    }
    aux = altura/quantidade;
    printf("\nA media eh: %.2f",aux);
return 0;   
}