/**/

#include <stdio.h>
#include <locale.h>
#define PRIMEIRO_NOME "Wellington"

int main(){
	setlocale(LC_ALL,"Portuguese");

	const char SEGUNDO_NOME = "Amorim";

	printf("O meu primeiro nome � %s, e o meu sobrenome � %s.",PRIMEIRO_NOME,SEGUNDO_NOME);	

return 0;	
}

	