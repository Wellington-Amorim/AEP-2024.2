/*10.Faça um programa que leia várias notas de 2 disciplinas
e apresente a média dos alunos de cada disciplina.
Utilize laço for.*/

#include <stdio.h>


int main(){
    int quantidade = 0,q = 0;
    float nota = 0,media = 0;

    printf("MATERIA 1\nEscreva a quantidade de notas: ");
    scanf("%d",&quantidade);
    q += quantidade;

    for(int i=1;i<=quantidade;i++){
        printf("Nota %d da primmeira materia: ",i);
        scanf("%f",&nota);
        media += nota;
    }

    printf("\nMATERIA 2\nEscreva a quantidade de notas: ");
    scanf("%d",&quantidade);
    q += quantidade; 

    for(int x=1;x<=quantidade;x++){
        printf("Nota %d da primmeira materia: ",x);
        scanf("%f",&nota);
        media += nota;
    }
    media = media/q;
    printf("\nA media eh: %.2f",media);
    
return 0;   
}