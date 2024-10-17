#include <stdio.h>
#include <unistd.h>

int main(){
    int vet[3] = {0};
    int i;

    for(i=1;i<4;i++){
        printf("Insira o elemento da posição %d: ",i);
        scanf(" %d", &vet[i]);
    }

    printf("\nVocê digitou: ");

    for(i=1;i<4;i++){
        printf("%d ",vet[i]);
        sleep(1);
    }

return 0;    
}
