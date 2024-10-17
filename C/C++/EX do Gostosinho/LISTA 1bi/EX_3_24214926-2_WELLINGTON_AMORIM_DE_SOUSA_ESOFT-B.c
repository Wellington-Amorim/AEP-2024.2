/*Exercício 3:
Contexto: Uma empresa concede bônus de salário de acordo coma avaliação
de desempenho de um funcionário.Se a avaliação for A, obônus é de 15% do
salário. Se for B, o bônus é de 10%. Se for C, o bônus é de 5%. Caso contrário,
não há bônus. Escreva um programa que calcule o salário final do funcionário.*/

#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	float salario;
	char avaliacao;
	
	// Ler o salário
	printf("Digite o seu salário: R$");
	scanf("%f",&salario);
	
	// Apaga o dados do teclado
	fflush(stdin);
	
	// Ler o caractere
	printf("\nDigite a sua avaliação de C a A: ");
	avaliacao = getchar();
	
	// Saídas possíveis
	if(avaliacao == 'A'){
		salario = salario + (salario * 15/100);
		printf("\nVocê recebeu um aumento de 15%%.\nO seu salário é de R$%.2f.",salario);	
	}
	else if(avaliacao == 'B'){
		salario = salario + (salario * 10/100);
		printf("\nVocê recebeu um aumento de 10%%.\nO seu salário é de R$%.2f.",salario);	
	}
	else if(avaliacao == 'C'){
		printf("O seu salário é de R$%.2f.",salario);	
	}	
	else{
		printf("Erro ao informar a avaliação.\nTente novamente.\nOpite por digitar A, B ou C.");
	}
return 0;	
}

