#include <stdio.h>
#include <unistd.h>

int main(){
    for(int i=1;i<21;i++){
        printf("%i\a\n",i);
        sleep(1);
    }
return 0;
}