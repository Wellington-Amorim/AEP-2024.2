#include <stdio.h>

int main(){
    char nome[50];

    printf("ESCREVA:\n");
    fgets(nome,sizeof(nome),stdin);

    printf("%s",nome);
return 0;    
}