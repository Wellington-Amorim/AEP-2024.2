/*Exerc?cio 4:
Contexto: Escreva um programa que determine se um número é um
quadrado perfeito. Um quadrado perfeito é um  número que pode ser
expresso como o produto de outro número por ele mesmo.*/

#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	int num, raiz;
	
	// Entrada do número escolhido
	printf("Digite um número: ");
	scanf("%d",&num);
	
	// A variável raiz recebe a raiz quadrada da variável num
	raiz = sqrt(num);
	
	// Saídas
	if(num == raiz * raiz){
		printf("\nO número %d é um quadrado perfeito!",num);	
	}
	else{
		printf("\nO número %d não é um quadrado perfeito.",num);	
	}
		
return 0;	
}
	
