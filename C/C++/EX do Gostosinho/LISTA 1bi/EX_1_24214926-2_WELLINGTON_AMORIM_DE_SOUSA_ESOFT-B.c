/*Exercício 1:
Contexto: Uma loja oferece desconto progressivo de acordo com o valor da
compra. Se o valor for at? R$100, não há desconto. Se for entre R$100 e R$500, o desconto é de 10%. Acima de R$500, o desconto ? de 20%.Escreva um
programa que calcule o valor total a pagar.*/

#include <stdio.h>
#include <locale.h>
  
int main(void){
 setlocale(LC_ALL,"Portuguese");	
 float valor;	
	
	printf("Digite o valor da compra:\n");
		scanf("%f",&valor);
	
	if(valor <= 100){
		printf("N?o h? desconto.\n");
		printf("O valor total a ser pago ? R$%f\n",valor);
	}
	else if(valor >= 100 && valor <= 500){
		valor = valor * 10/100;
		printf("O desconto ? de 10 porcento.\n");
		printf("O valor total a ser pago ? R$%f\n",valor);
	}
	else if(valor > 500){
		valor = valor * 10/100;
		printf("O desconto ? de 20 porcento.\n");
		printf("O valor total a ser pago ? R$%f\n",valor);
	}
	else("O valor informado n?o existe.\n");
			
return 0;			
}  
  