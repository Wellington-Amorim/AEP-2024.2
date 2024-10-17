/*3.Solicite ao usuário que insira 5 números e calcule sua
média usando um laço do-while.*/

#include <stdio.h>

int main(){
    int num = 0, i = 1;
    do{
        printf("Numero %d: ",i);
        scanf("%d",&num);
        i++;
    }while(i<=5);
return 0;   
}
