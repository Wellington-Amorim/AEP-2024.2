/*Exercício15:
Contexto:Um programa deve validar uma senha fornecida pelo usuário. A
senha é considerada válida se tiver pelo menos 8 caracteres e conter pelo
menos uma letra maiúscula, uma letra minúscula, um número e um caractere
especial.*/

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

int main(){
	setlocale(LC_ALL,"Portuguese");

    char senha[50];
    int maiusculo, minusculo, numero, CaractereS;

    printf("Escreva uma senha contendo as seguntes regras:\n");
    printf("Pelo menos 8 caracteres\nPelo menos 1 letra maiúscula e 1 letra minúscula\nPelo menos 1 número e 1 caractere especial.\nDIGITE SUA SENHA:");
    fgets(senha, sizeof(senha), stdin);
	
	printf("\n\nVocê digitou %s\n\n",senha);
		// Leitura do 1° caractere
		if (isupper(senha[0])){
			maiusculo = 1;	
		}
		if (islower(senha[0])){
			 minusculo = 1; 
		}
	    if (isdigit(senha[0])){
	    	 numero = 1;
		}
		if (ispunct(senha[0])){
			 CaractereS = 1;
		}
		// Leitura do 2° caractere
    	if (isupper(senha[1])){
    		 maiusculo = 1;
		}
		if (islower(senha[1])){
			 minusculo = 1; 
		}
		if (isdigit(senha[1])){
			 numero = 1;
		}
		if (ispunct(senha[1])){
			 CaractereS = 1;
		}
		// Leitura do 3° caractere
	    if (isupper(senha[2])){
	    	 maiusculo = 1;
		}
		if (islower(senha[2])){
			 minusculo = 1; 
		}
    	if (isdigit(senha[2])){
    		 numero = 1;
		}
		if (ispunct(senha[2])){
			 CaractereS = 1;
		}
		// Leitura do 4° caractere
    	if (isupper(senha[3])){
    		 maiusculo = 1;
		}
		if (islower(senha[3])){
			 minusculo = 1; 
		}
    	if (isdigit(senha[3])){
    		 numero = 1;
		}
		if (ispunct(senha[3])){
			 CaractereS = 1;
		}
    	// Leitura do 5° caractere
		if (isupper(senha[4])){
			 maiusculo = 1;
		}
		if (islower(senha[4])){
			 minusculo = 1; 
		}
 		if (isdigit(senha[4])){
 			 numero = 1;
		}
		if (ispunct(senha[4])){
			 CaractereS = 1;
		}
		// Leitura do 6° caractere
		if (isupper(senha[5])){
			 maiusculo = 1;
		}
		if (islower(senha[5])){
			 minusculo = 1; 
		}
    	if (isdigit(senha[5])){
    		 numero = 1;
		}
		if (ispunct(senha[5])){
			 CaractereS = 1;
		}
		// Leitura do 7° caractere
    	if (isupper(senha[6])){
    		 maiusculo = 1;
		}
		if (islower(senha[6])){
			 minusculo = 1; 
		}
    	if (isdigit(senha[6])){
    		 numero = 1;
		}
		if (ispunct(senha[6])){
			 CaractereS = 1;
		}
		// Leitura do 8° caractere
		if (isupper(senha[7])){
			 maiusculo = 1;
		}
		if (islower(senha[7])){
			 minusculo = 1; 
		}
 		if (isdigit(senha[7])){
 			 numero = 1; 	
		}
		if (ispunct(senha[7])){
			 CaractereS = 1;
		}
	
	// Se a senha tiver pelo menos: 1 caractere; 1 letra maúscula; 1 letra minúscula, 1 número e 1 caractere especial
	// É válido
	if(strlen(senha) > 8 && maiusculo == 1 && minusculo == 1 && numero == 1 && CaractereS == 1){
		printf("É válido!");	
	}
	// Não é válido
    else{
    	printf("Não é válido!");
	}	
	
		
return 0;
}
