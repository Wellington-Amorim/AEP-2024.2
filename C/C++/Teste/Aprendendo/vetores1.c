// Vetoreres
#include <stdio.h>
#include <unistd.h>

int main(){
    int vet[5] = {10,20,30,40,50};
    int i;

    for(i=0;i<5;i++){
        printf("%d ", vet[i]);
        sleep(1);
    }

return 0;    
}