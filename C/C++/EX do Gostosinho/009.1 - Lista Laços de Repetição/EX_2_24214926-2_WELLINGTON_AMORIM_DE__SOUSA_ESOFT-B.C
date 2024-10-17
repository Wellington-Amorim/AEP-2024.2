/*2.Calcule a soma dos números de 1 a 100 usando um laço while.*/

#include <stdio.h>


int main(){
    int x = 1, y = 0;
    while (x<=100){
        y += x;
        x++;
    }
    printf("A soma de 1 ah 100 eh: %d",y);
return 0;   
}
