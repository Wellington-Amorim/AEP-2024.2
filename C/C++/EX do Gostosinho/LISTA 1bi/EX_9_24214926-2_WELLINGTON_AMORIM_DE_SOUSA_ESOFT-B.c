/*Exerc?cio9:
Contexto:Escrevaumprogramaquedetermineseumn?mero?umn?mero
primo.Umn?meroprimo?aqueleques??divis?velpor1eporelemesmo.*/

#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	int num;
	
    // Entrada
	printf("Digite um n?mero: ");
	scanf("%d",&num);
	
    // Se o número digitado for diferente de 1, 2 e 3
	if(num != 1 && num != 2 && num != 3) {

        // Se o resto do número dividido por 2 ou 3 for diferente de 0, o n?mero n?o ser? primo
		if(num % 2 == 0 || num % 3 == 0){
			printf("O n?mero n?o ? primo.");	
		} 
        // Sen?o, o número é primo. Porque o número primo só pode ser divisível por 1 e ele mesmo
		else{
			printf("É primo porr@@@!");
	    } 	
	}

    // Sen?o, o n?mero digitado é 1, 2 ou 3
	else{
        // Se num for igual 1, ent?o num n?o ? primo 
		if(num == 1){
			printf("O n?mero n?o ? primo.");	
		}
        // Caso conntr?rio, significa que o n?mero ? 2 ou 3, sendo um n?mero primo
		else{
			printf("? primo porr@@@!");
		}	
	} 

// Fim	
return 0;	
}
