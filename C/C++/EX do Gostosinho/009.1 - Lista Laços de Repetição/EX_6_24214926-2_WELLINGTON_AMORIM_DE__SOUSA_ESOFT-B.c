/*6.Fa�a um programa que calcule a m�dia de altura de
uma turma de alunos usando um la�o for. O n�mero de
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