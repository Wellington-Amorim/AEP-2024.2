/*Exerc?cio 4:
Contexto: Escreva um programa que determine se um n�mero � um
quadrado perfeito. Um quadrado perfeito � um  n�mero que pode ser
expresso como o produto de outro n�mero por ele mesmo.*/

#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	int num, raiz;
	
	// Entrada do n�mero escolhido
	printf("Digite um n�mero: ");
	scanf("%d",&num);
	
	// A vari�vel raiz recebe a raiz quadrada da vari�vel num
	raiz = sqrt(num);
	
	// Sa�das
	if(num == raiz * raiz){
		printf("\nO n�mero %d � um quadrado perfeito!",num);	
	}
	else{
		printf("\nO n�mero %d n�o � um quadrado perfeito.",num);	
	}
		
return 0;	
}
	