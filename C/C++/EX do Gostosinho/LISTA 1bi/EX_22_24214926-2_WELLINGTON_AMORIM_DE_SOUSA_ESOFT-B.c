/*Exercício22:
Contexto:Escreva um programa que converta uma temperatura em graus
Celsius para Fahrenheit ouvice-versa, dependendo da escolha do usuário.*/

//Para converter graus Celsius em Fahrenheit, a fórmula é F = C x 1,8 + 32
//Para converter graus Fahrenheit em Celsius, a fórmula é C = (F - 32) / 1,8 ou C = 5/9.(F - 32).

#include <stdio.h>
#include <locale.h>
#include <math.h>
int main(){
	setlocale(LC_ALL,"Portuguese");
	
	char temp;
	float f,c;
	
	f = 0;
	c = 0;
	
	printf("CONVERSÃO DE TEMPERATURA\nConverta graus Celsius para Fahrenheit e ouvice-versa\n""F"" para descubrir os Fahrenheit\n""C"" para descubrir os Celsius\n\nDIGITE: ");
	scanf(" %c",&temp);
	
	if(temp == 'F' || temp == 'f'){
		printf("\nQual a temperatura em Celsius?\n");
		scanf("%f",&c);
		f = c * 1.8 + 32;
		printf("\nO Celsius para Fahrenheit resultou em: %.1f°F",f);
	}
	else if(temp == 'C' || temp == 'c'){
		printf("\nQual a temperatura em Fahrenheit?\n");
		scanf("%f",&f);
		c = (f-32)/1.8;
		printf("\nO Fahrenheit para Celsius resultou em: %.1f°C",c);
	}
	else{
		printf("\n\nInválido. Tente novamente.");	
	}
	
return 0;	
}


