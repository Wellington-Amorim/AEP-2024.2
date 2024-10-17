/*Exercício 2:
Contexto: Um caixa eletr?nico precisa entregar uma quantia solicitada pelo
usu?rio utilizando a menor quantidade possível de notas de R$100, R$50, R$20, R$10 e R$5.Escreva um programa que receba o valor e apresente a
distribuição de notas. 
1
*/
#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL,"Portuguese");
    int valor, notas100, notas50, notas20, notas10, notas5, restante;

    // Solicita o valor ao usu?rio
    printf("Digite o valor a ser sacado: ");
    scanf("%d", &valor);

    // Calcula a quantidade de notas de cada valor
    notas100 = valor / 100;
    restante = valor % 100;
    
    notas50 = restante / 50;
    restante = restante % 50;
    
    notas20 = restante / 20;
    restante = restante % 20;
    
    notas10 = restante / 10;
    restante = restante % 10;
    
    notas5 = restante / 5;
    restante = restante % 5;

    // Exibe a distribuição de notas
    printf("Notas de R$100: %d\n", notas100);
    printf("Notas de R$50: %d\n", notas50);
    printf("Notas de R$20: %d\n", notas20);
    printf("Notas de R$10: %d\n", notas10);
    printf("Notas de R$5: %d\n", notas5);

    // Se ainda houver restante, significa que o valor não é multiplo de 5
    if (restante > 0) {
        printf("Não é possível sacar o valor exato, faltam R$%d.\n", restante);
    }

return 0;
}

