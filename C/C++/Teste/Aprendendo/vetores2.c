#include <stdio.h>
#include <unistd.h>

int main(){
    int vet[3] = {0};
    int i;

    for(i=1;i<4;i++){
        printf("Insira o elemento da posi��o %d: ",i);
        scanf(" %d", &vet[i]);
    }

    printf("\nVoc� digitou: ");

    for(i=1;i<4;i++){
        printf("%d ",vet[i]);
        sleep(1);
    }

return 0;    
}
