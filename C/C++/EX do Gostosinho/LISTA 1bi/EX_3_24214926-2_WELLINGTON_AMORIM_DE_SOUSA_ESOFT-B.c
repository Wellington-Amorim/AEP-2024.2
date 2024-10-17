/*Exerc�cio 3:
Contexto: Uma empresa concede b�nus de sal�rio de acordo coma avalia��o
de desempenho de um funcion�rio.Se a avalia��o for A, ob�nus � de 15% do
sal�rio. Se for B, o b�nus � de 10%. Se for C, o b�nus � de 5%. Caso contr�rio,
n�o h� b�nus. Escreva um programa que calcule o sal�rio final do funcion�rio.*/

#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	float salario;
	char avaliacao;
	
	// Ler o sal�rio
	printf("Digite o seu sal�rio: R$");
	scanf("%f",&salario);
	
	// Apaga o dados do teclado
	fflush(stdin);
	
	// Ler o caractere
	printf("\nDigite a sua avalia��o de C a A: ");
	avaliacao = getchar();
	
	// Sa�das poss�veis
	if(avaliacao == 'A'){
		salario = salario + (salario * 15/100);
		printf("\nVoc� recebeu um aumento de 15%%.\nO seu sal�rio � de R$%.2f.",salario);	
	}
	else if(avaliacao == 'B'){
		salario = salario + (salario * 10/100);
		printf("\nVoc� recebeu um aumento de 10%%.\nO seu sal�rio � de R$%.2f.",salario);	
	}
	else if(avaliacao == 'C'){
		printf("O seu sal�rio � de R$%.2f.",salario);	
	}	
	else{
		printf("Erro ao informar a avalia��o.\nTente novamente.\nOpite por digitar A, B ou C.");
	}
return 0;	
}
