#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

int main(){
    setlocale(LC_ALL,"Portuguese");

    char idioma[20], x;
    int hora = 0, minuto = 0, segundo = 0, i = 0;

        printf("Dê enter para comerçar...");
        x = getchar();
        

    printf("TESTE DE FLUÊNCIA");
        sleep(2);
        system("cls");
    printf("ESTÁ PRONTO?\r");
        sleep(1);
    printf("ESPERO QUE SIM.\r");
        sleep(1 );

    do{    
        printf("English or Spanish?\n");
        fgets(idioma,sizeof(idioma),stdin);
            idioma[strcspn(idioma,"\n")] = 0;
    
        if(strcmp(idioma,"ENGLISH") == 0 || strcmp(idioma,"English") == 0 || strcmp(idioma,"english") == 0){
            printf("\nWho moves first is gay!\n");
            i = 1;
        }else if(strcmp(idioma,"SPANISH") == 0 || strcmp(idioma,"Spanish") == 0 || strcmp(idioma,"spanish") == 0){
            printf("\n¡Quien se mueve primero es gay!\n");
            i = 1;
        }else{
            printf("\nÉ PRA ESCREVER O IDIOMA, GÊNIO!\n");
            sleep(2);
            system("cls");
        }
    }while(i == 0);    
    
    while(1){
        segundo++;

        if(segundo == 60){
            segundo = 0;
            minuto++;

            if(minuto == 60){
            minuto = 0;
            hora++;
            }
        }

        printf("%02i:%02i:%02i\r",hora,minuto,segundo);

        fflush(stdout);

        sleep(1);
       
    }

return 0;    
}