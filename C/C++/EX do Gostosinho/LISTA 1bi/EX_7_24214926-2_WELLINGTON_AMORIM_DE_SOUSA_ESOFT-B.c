/*Exerc?cio7:
Contexto: Voc? est? desenvolvendo um sistema de login. Os usu?rios devem
fornecer um nome de usu?rio e uma senha. Se ambos estiverem corretos, o
programa deve exibir "Acessoconcedido". Caso contr?rio, deve exibir "Acesso
negado".*/

#include <stdio.h>
#include <locale.h>


int main(){
    setlocale(LC_ALL, "Portuguese");
    char nome;

    printf("NOME: ");
    scanf("%s",nome);

    printf(nome);

return 0;    
}
