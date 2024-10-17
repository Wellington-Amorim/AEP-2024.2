#include <stdio.h>

int fatorial(int n){
    if(n == 0) return 1;
return n * fatorial(n - 1);    
}

int main(){
    int result = fatorial(5);
    printf("%i",result);
return 0;    
}