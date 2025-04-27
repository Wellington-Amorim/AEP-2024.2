/*SISTEMA DE SUGURANÇA
O objetivo é criar um sistema de criptografia para uma empresa que sofre com problemas de segurança.*/ 
//Bora codar, Ryanzinho!!!!
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include <unistd.h>

// Authors: Ryan R. Silva, Wellington Amorim

FILE* arquivo;

void bordas();
void menu();
void cadastrarUsuario();
void alterarUsuario();
void excluirUsuario();
void listarUsuarios();
void mostraCreditos();
void gotoxy(int x, int y);
void textcolor(int color);
void textbackground(int color);
void hideCursor();
void showCursor();
void criptografar(char* text, int troca);
void descriptografar(char* text, int troca);
void telinha();

int main() {
    setlocale(LC_ALL, "Portuguese");

	menu();

return 0;
}
// ========================================== Área de Funções ================================================

void bordas() {
    int i;
    
    system("cls");	//limpa tela

    for(i = 42;i<76;i++) {      //horizontal
        textcolor(9);
        gotoxy(i,8);
        printf("=");
        gotoxy(i,22);
        printf("=");
	}
	for(i = 9;i<22;i++) {       //vertical
        gotoxy(40,i);
        printf("||");
        gotoxy(76,i);
        printf("||");
	}
        gotoxy(40,22);      //bordas
        printf("#");
        gotoxy(77,22);
        printf("#");
        gotoxy(40,8);
        printf("#");
        gotoxy(77,8);
        printf("#");
           
        textcolor(15);
}
//--------------------------------------------------------------------------------------------------------
// Desenha o menu
void menu() {                                                                  
    int op = 0, ch, i;

	system("cls");
    bordas();
    textcolor(0);
    textbackground(1);
    gotoxy(42,9);
    printf("              M E N U             ");
    hideCursor();

    do {
        // Imprime de acordo com "op"
        for (i = 0; i < 5; i++) {
            if(op == i) {
                textcolor(0);
                textbackground(15);
            }
            else {
                textcolor(15);
                textbackground(0);
            }

            switch (i) {
            case 0:
                gotoxy(47,12);
                printf("   Cadastrar Usuário    ");
                break;
            case 1:
                gotoxy(47,14);
                printf("   Alterar Usuário      ");
                break;
            case 2:
                gotoxy(47,16);
                printf("   Excluir Usuário      ");
                break;
            case 3:
                gotoxy(47,18);
                printf("   Listar Usuários      ");
                break;
            case 4:
                gotoxy(47,20);
                printf("   Créditos             ");
                break;
            }
        }
        
        // Verifica as setas
        ch = getch();
        if (ch == 0 || ch == 224) {
           ch = getch();
        }

        if (ch == 80) { // seta para baixo
            if (op < 4) {
                op++;
            } 
            else {
                op = 0;
            }
        } else if (ch == 72) { // seta para cima
            if (op > 0) {
                op--;
            } 
            else {
                op = 4;
            }
        } else if (ch == 13) {
				switch(op) {
		    		case 0:
		    			cadastrarUsuario();
		    			break;
		    		case 1:
		    			alterarUsuario();
						break;
		    		case 2:
		    			excluirUsuario();
		    			break;
		    		case 3:
		    			listarUsuarios();
						break;
		    		case 4:
		    			mostraCreditos();
		    			break;
				}
		  		break;
		}
    } while (ch != 27);
    
    textcolor(15);
    textbackground(0);
    
    printf("\n\n\n\n\n");
}
//------------------------------------------------------------------------------------------------------------
void cadastrarUsuario() {
	int x=42,y=9, i;
	char usuario[30], senha[30], confirmaSenha[30];
	bool upper = false, lower = false, special = false, number = false, eightChar = false;
	char ch;
	
	bordas();
	
	//interface padrão
	textcolor(10);								
    gotoxy(x+4,y);
    printf("--- Cadastrar  Usuário ---");
    
    textcolor(0);
    textbackground(8);
    gotoxy(x+1,y+2);
    printf("Usuário:                       ");

    gotoxy(x+1,y+4);
    printf("Senha:                         ");
	
	gotoxy(x+1,y+6);
    printf("Confirmar senha:               ");    
    textcolor(0);
    
    // Input de Usuario
    do {
    	gotoxy(x+9,y+2);
		showCursor();
		
		
		textcolor(0);
		textbackground(8);
		fgets(usuario, sizeof(usuario), stdin);
		
		if(strlen(usuario) < 5) {
			hideCursor();
			gotoxy(x+1,y+8);
			textcolor(4);
			printf("Usuário: mínimo 4 caracteres.");
			gotoxy(x+1,y+9);
			printf("Pressione ESC para sair.");
			gotoxy(x+1,y+10);
			printf("Ou ENTER p/ continuar.");
			
			ch = getch();
			
			if(ch == 27) {
				menu();
				return;
			}
			
			textcolor(0);
    		textbackground(8);
    		gotoxy(x+1,y+2);
    		printf("Usuário:                       ");
			textcolor(15);
		}
		else {
			gotoxy(x+1,y+8);
			textcolor(15);
			printf("                              ");
			gotoxy(x+1,y+9);
			printf("                              ");
			gotoxy(x+1,y+10);
		} 
	} while(strlen(usuario) < 5);		
	
	criptografar(usuario, 3);	
	
	// Input da Senha
	do {
		gotoxy(x+7,y+4);
		
		textcolor(0);
		textbackground(8);
		fgets(senha, sizeof(senha), stdin);	
		
		// VERIFICAÇÕES DA SENHA
		// Tamanho
		if(strlen(senha) > 8)
			eightChar = true;
		// Maiúsculo
		for(i=0; i < strlen(senha); i++) {
			if(isupper(senha[i])) {
				upper = true;
				break;
			}
		}
		// Minúsculo
		for(i=0; i < strlen(senha); i++) {
			if(islower(senha[i])) {
				lower = true;
				break;
			}
		}
		// Caractere Especial
		for(i=0; i < strlen(senha); i++) {
			if((senha[i] >= 33 && senha[i] <= 47) || (senha[i] >= 58 && senha[i] <= 64)) {
				special = true;
			} 
		}
		// Numero
		for(i=0; i < strlen(senha); i++) {
			if(isdigit(senha[i])) {
				number = true;
				break;
			}
		}
		
		
		if(upper == false || lower == false || special == false || number == false || eightChar == false) {
			gotoxy(x+1,y+8);
			textcolor(4);
			printf("Senha:");
			gotoxy(x+1,y+9);
			printf("- Mínimo 8 caracteres.");
			gotoxy(x+1,y+10);
			printf("- Min. 1 maiúscula e minúscula");
			gotoxy(x+1,y+11);
			printf("- 1 Caractere especial");
			gotoxy(x+1,y+12);
			printf("- 1 Número");
			
			textcolor(0);
    		textbackground(8);
    		gotoxy(x+1,y+4);
    		printf("Senha:                         ");
    		textcolor(15);
		}
		else {
			gotoxy(x+1,y+8);
			textcolor(15);
			printf("                              ");
			gotoxy(x+1,y+9);
			printf("                              ");
			gotoxy(x+1,y+10);
			printf("                              ");
			gotoxy(x+1,y+11);
			printf("                              ");
			gotoxy(x+1,y+12);
			printf("                              ");
		}	
	} while(upper == false || lower == false || special == false || number == false || eightChar == false);
	
	// Input Confirma Senha
    do {
    	gotoxy(x+17,y+6);
		textcolor(0);
		textbackground(8);
		fgets(confirmaSenha, sizeof(confirmaSenha), stdin);
		
		if(strcmp(senha, confirmaSenha) != 0) {
			gotoxy(x+1,y+8);
			textcolor(4);
			printf("As senhas não são iguais!");
			textcolor(0);
    		textbackground(8);
			gotoxy(x+1,y+6);
    		printf("Confirmar senha:               ");    
    		textcolor(0);	
		}	
		else {
			gotoxy(x+1,y+8);
			textcolor(15);
			printf("                              ");
		}
	} while(strcmp(senha, confirmaSenha) != 0);
    
    // Confirma sucesso do cadastro.
	hideCursor();
	criptografar(senha, 3);
	
	arquivo = fopen("cadastros.txt", "a");
	fprintf(arquivo, usuario);
	fprintf(arquivo,senha);
	
	fclose(arquivo);
	
	gotoxy(x+1,y+8);
	textcolor(2);
	textbackground(0);
	printf("> Usuário Cadastrado com sucesso.");
	gotoxy(x+1,y+9);
	printf("Pressione qualquer");
	gotoxy(x+1,y+10);
	printf("tecla para voltar...");
	textcolor(15);
	textbackground(0);
	
	getch();
	menu();
}
//------------------------------------------------------------------------------------------------------------
void alterarUsuario() {
	int x=42,y=9, i;
	char usuario[30], novaSenha[30], confirmaNova[30], linha[255];
	FILE* temp = fopen("temp.txt", "w");
	bool usuarioEnc = false, upper = false, lower = false, special = false, number = false, eightChar = false, linhaUsuario = false;
	
	bordas();
	
	//interface padrão
	textcolor(13);								
    gotoxy(47,9);
    printf("--- Alterar  Usuário ---");
    
    textcolor(0);
    textbackground(8);
    gotoxy(x+1,y+2);
    printf("Usuário:                        ");
    
    gotoxy(x+1,y+4);
    printf("Nova Senha:                     ");

    gotoxy(x+1,y+6);
    printf("Confirmar Senha:                ");
	   
    textcolor(0);
    
    // Input usuário
    do {
    	textcolor(0);
    	textbackground(8);
    	gotoxy(x+9,y+2);
		showCursor();
		fgets(usuario, sizeof(usuario), stdin);
			
		
		criptografar(usuario, 3);
		
		arquivo = fopen("cadastros.txt", "r");
		
		if(arquivo == NULL) {
			gotoxy(x+1,y+8);
			textcolor(4);
			printf("Arquivo não encontrado!");
			return;
		}
		
		while(fgets(linha, sizeof(linha), arquivo) != NULL) {
			if(strcmp(linha, usuario) == 0) {
				usuarioEnc = true;
			}
		}
		if(usuarioEnc == false) {
			hideCursor();
			gotoxy(x+1,y+8);
			textcolor(4);
			printf("Usuário não encontrado!");
			gotoxy(x+1,y+9);
			printf("Pressione ESC para sair.");
			gotoxy(x+1,y+10);
			printf("Ou enter p/ continuar.");
			if(getch() == 27) {
				menu();
				return;
			}
			textcolor(0);
    		textbackground(8);
    		gotoxy(x+1,y+2);
    		printf("Usuário:                       ");
    		textcolor(15);
		}
		else {
			gotoxy(x+1,y+8);
			textcolor(0);
			printf("                       ");
			gotoxy(x+1,y+9);
			printf("                       ");
			gotoxy(x+1,y+10);
			printf("                       ");
		}
	} while(usuarioEnc == false);
	
	// Input Senha
	do {
		textcolor(0);
		textbackground(8);
		gotoxy(x+12,y+4);
		fgets(novaSenha, sizeof(novaSenha), stdin);	
		
		// VERIFICAÇÕES DA SENHA
		// Tamanho
		if(strlen(novaSenha) > 8)
			eightChar = true;
		// Maiúsculo
		for(i=0; i < strlen(novaSenha); i++) {
			if(isupper(novaSenha[i])) {
				upper = true;
				break;
			}
		}
		// Minúsculo
		for(i=0; i < strlen(novaSenha); i++) {
			if(islower(novaSenha[i])) {
				lower = true;
				break;
			}
		}
		// Caractere Especial
		for(i=0; i < strlen(novaSenha); i++) {
			if((novaSenha[i] >= 33 && novaSenha[i] <= 47) || (novaSenha[i] >= 58 && novaSenha[i] <= 64)) {
				special = true;
			} 
		}
		// Numero
		for(i=0; i < strlen(novaSenha); i++) {
			if(isdigit(novaSenha[i])) {
				number = true;
				break;
			}
		}
		
		if(upper == false || lower == false || special == false || number == false || eightChar == false) {
			gotoxy(x+1,y+8);
			textcolor(4);
			printf("Senha:");
			gotoxy(x+1,y+9);
			printf("- Mínimo 8 caracteres.");
			gotoxy(x+1,y+10);
			printf("- Min. 1 maiúscula e minúscula");
			gotoxy(x+1,y+11);
			printf("- 1 Caractere especial");
			gotoxy(x+1,y+12);
			printf("- 1 Número");	
			
			textcolor(0);
    		textbackground(8);
    		gotoxy(x+1,y+4);
    		printf("Nova Senha:                     ");
		}
		else {
			gotoxy(x+1,y+8);
			textcolor(15);
			printf("                              ");
			gotoxy(x+1,y+9);
			printf("                              ");
			gotoxy(x+1,y+10);
			printf("                              ");
			gotoxy(x+1,y+11);
			printf("                              ");
			gotoxy(x+1,y+12);
			printf("                              ");
		}
	} while(upper == false || lower == false || special == false || number == false || eightChar == false);
	
	
	// Confirma Senha
	do {
		textcolor(0);
		textbackground(8);
		gotoxy(x+17,y+6);
		fgets(confirmaNova, sizeof(confirmaNova), stdin);
		
		if(strcmp(confirmaNova, novaSenha) != 0) {
			gotoxy(x+1,y+8);
			textcolor(4);
			printf("As senhas não são iguais!");
			
			textcolor(0);
    		textbackground(8);
    		gotoxy(x+1,y+6);
    		printf("Confirmar Senha:                    ");
		}
		else {
			gotoxy(x+1,y+8);
			textcolor(0);
			printf("                         ");
			textcolor(15);	
		}
	} while(strcmp(confirmaNova, novaSenha) != 0);
	
	criptografar(novaSenha, 3);
	hideCursor();
	
	rewind(arquivo);
		
	while(fgets(linha, sizeof(linha), arquivo) != NULL) {
		if(strcmp(linha, usuario) == 0) {
			linhaUsuario = true;
			fprintf(temp, "%s", linha);
			continue;
		}
		
		if(linhaUsuario == true) {
			fprintf(temp, "%s", novaSenha);
			linhaUsuario = false;
		} else {
			fprintf(temp, "%s", linha);	
		}
	}
	
	fclose(arquivo);
	fclose(temp);
	
	remove("cadastros.txt");
	rename("temp.txt", "cadastros.txt");
	
	gotoxy(x+1,y+8);
	textcolor(2);
	textbackground(0);
	printf("> Usuário Alterado com sucesso.");
	gotoxy(x+1,y+9);
	printf("Pressione qualquer");
	gotoxy(x+1,y+10);
	printf("tecla para voltar...");
	textcolor(15);
	textbackground(0);
		
	getch();
	menu();
}
//------------------------------------------------------------------------------------------------------------
void excluirUsuario() {
	FILE* temp;
	int x=42,y=9;
	int op = 0, ch, i, ver = 0;
	char usuario[30], linha[255];
	bool encontrado = false;
	bordas();
	
	//interface padrão
	textcolor(12);								
    gotoxy(47,9);
    printf("--- Excluir  Usuário ---");
    
    textcolor(0);
    textbackground(8);
    gotoxy(x+1,y+2);
    printf("Usuário:                       ");
    
    //quadrado vermelho
   	textbackground(4);                      
    for(int i=0;i<3;i++){
    	gotoxy(x+1,y+5+i);
    	printf("                ");
		y+=1;
		
		if(i<2){
			gotoxy(x+1,y+5+i);
    		printf("                ");
    	}
	}
	
	gotoxy(x+5,y+4);
	printf("EXCLUIR");
	textbackground(0);
	
	textcolor(7);
	gotoxy(x+23,y+4);
	printf("SAIR");
	
	// Input nome do usuário
	do {
		gotoxy(x+9,y-1);
		showCursor();
		textcolor(0);
    	textbackground(8);
		fgets(usuario, sizeof(usuario), stdin);
		
		criptografar(usuario, 3);
		
		hideCursor();
		
		do {
			for(i=0; i<2; i++) {
				if(op == i) {
					textcolor(9);
				}	
				else {
					textcolor(0);
				}
				
				switch (i) {
					case 0:
						gotoxy(43,19);
						printf("^^^^^^^^^^^^^^^^");
						break;
					case 1:
						gotoxy(59,19);
						printf("^^^^^^^^^^^^^^^^");
						break;
			    }		
			}
			
			ch = getch();
	        if (ch == 0 || ch == 224) {
	           ch = getch();
	        }
	        
	        if(ch == 77) {
	        	if(op < 1) {
	        		op++;
				}
				else {
					op = 0;
				}
			} 
			else if(ch == 75) {
				if(op > 0) {
					op--;
				}
				else {
					op = 1;
				}	
			}
		} while(ch != 13);
		
	} while(ch != 13);
	
	arquivo = fopen("cadastros.txt", "r");
	temp = fopen("temp.txt", "w");
	
	switch(op) {
		case 0:
			while(fgets(linha, sizeof(linha), arquivo) != NULL) {
				if(strcmp(linha, usuario) != 0 && ver < 1) {
					fprintf(temp, linha);
				}
				else if(strcmp(linha, usuario) == 0) {
					ver = 1;
					encontrado = true;	
				}
				else {
					ver = 0;
				}	
			}
			break;
		case 1:
			menu();
			return;			
			break;
	}
	
	fclose(arquivo);
	fclose(temp);
	
	remove("cadastros.txt");
	rename("temp.txt", "cadastros.txt");
	
	gotoxy(x+1,y+7);
	if(encontrado) {
		textcolor(2);
		printf("Usuario removido.");
		textcolor(15);
	}
	else {
		textcolor(4);
		printf("Usuário não encontrado.");
		textcolor(15);
	}
	
	gotoxy(x+1,y+8);
	printf("Pressione qualquer botão");
	gotoxy(x+1,y+9);
	printf("Para voltar...");
	
	getch();
	menu();
}
//------------------------------------------------------------------------------------------------------------
void listarUsuarios() {
	int x=42,y=9, i = y+3;
	char linha[255];
	char ch;
	int op = 0;
	bordas();

	textcolor(11);
    gotoxy(47,9);
    printf("--- Listar  Usuários ---");
	
	//fundo cinza
	textcolor(0);	 
    textbackground(8);                          
    for(int i=0;i<12;i++){
    	gotoxy(x,y+i+1);
    	printf("                                  "); 	
	}
 	textcolor(1);
 	textbackground(8);
 	gotoxy(x+2,y+2);
 	printf("Usuário");
 	gotoxy(x+15,y+2);
 	printf("Senha");
 	gotoxy(x,y+14);
 	textbackground(0);
 	textcolor(15);
 	printf("Pressione ESC p/ voltar");
 	
 	arquivo = fopen("cadastros.txt", "r");
 	
 	if(arquivo == NULL) {
 		gotoxy(x+2,y+5);
 		textcolor(0);
 		textbackground(8);
 		printf("Nenhum usuário encontrado.");
 		menu();
		return;
	 }
 	do {
		while(fgets(linha, sizeof(linha), arquivo) != NULL) {
		descriptografar(linha, 3);
		textcolor(0);
		textbackground(8);
		gotoxy(x+2,i);
		printf("%s",linha);
					
		fgets(linha, sizeof(linha), arquivo);
		gotoxy(x+15,i);
		printf("%s",linha);
					
		i++;
		textbackground(0);
		textcolor(15);
		}
		
		ch = getch();
		if(ch == 224 || ch < 0) {
			ch = getch();
		}
	} while(ch != 27);
 	 
 	fclose(arquivo);
	system("cls");
	menu();
}
//------------------------------------------------------------------------------------------------------------
void mostraCreditos() {
	int x=42,y=9;
	char ch;
	
	textbackground(0);
	bordas();

	textcolor(14);
    gotoxy(51,9);
    printf("--- Créditos ---");
    
    //fundo amarelo
   	textbackground(14);                      
	telinha();
	
	//carregando
	textcolor(0);								
	textbackground(14); 
	gotoxy(x+11,y+6);
	printf("CARREGANDO...");
	sleep(1.5);		
	gotoxy(x+11,y+6);
	printf("             ");
	
	
char lin[13][100] = {                   //|
        " Esse projeto foi feito por Ryan",
        "Raniel e Wellington Amorim",
		"no nosso 2º semestre em Engenharia",
		"de Software.",
		" Nós só temos a agradecer por tudo",
		"que aconteceu nesse curto tempo!",
        " Um grande abraço a todos os",
		"professores, amigos, e todos que",
		"nos acompanharam",
		"até o presente momento.  ",
        "", ""
    };
	
	for(int i=0; i<13; i++){
		gotoxy(x,y+2);
		
		if(i == 4){
			sleep(1);
		}
		if(i == 6){
			sleep(1);
		}
		for(int j=0; j < strlen(lin[i]); j++){	
			ch = lin[i][j];
			printf("%c",ch);
			fflush(stdout);
			usleep(10000);	
		}
		y++;	
	} 
	textcolor(12);	 
    textbackground(14);
	gotoxy(x+24,y-2);
	printf("<3");
	textcolor(0);
	textbackground(14);
	
	//retorna
	fflush(stdin);		
	if(getch() == 27) {
		textbackground(0);
		menu();
	}

	telinha();
	
	// limpa a matriz
	memset(lin, '\0', sizeof(lin));
	

	// frase do Ryanzinho  "É melhor cometer erros no seu
	// próprio caminho do que vencer no caminho de outra pessoa"

    strcpy(lin[0], " Agora, fique com esta frase");
    strcpy(lin[1], "recomendada pelo Ryanzinho...");
    strcpy(lin[2], "                             ");
    strcpy(lin[3], "   \"É melhor cometer erros no");
    strcpy(lin[4], "       seu próprio caminho  ");
    strcpy(lin[5], "     do que vencer no caminho  ");
    strcpy(lin[6], "        de outra pessoa...\"");
    strcpy(lin[7], "                             ");
    strcpy(lin[8], "              ~ Fyodor Dotoesvky");
    
    x=42,y=9;
    gotoxy(x,y);
	for(int i=0; i<13; i++){
		gotoxy(x,y+2);
		if(i == 3){
			textcolor(8);
			textbackground(14);
		}
		if(i == 8){
			textcolor(7);
			textbackground(14);
		}
		for(int j=0; j < strlen(lin[i]); j++){	
			ch = lin[i][j];
			printf("%c",ch);
			fflush(stdout);
			usleep(10000);	
		}
		y++;	
	}

	
	fflush(stdin);		
	if(getch() == 27) {
		textbackground(0);
		menu();
	}
	
	memset(lin, '\0', sizeof(lin));
	
	strcpy(lin[0], "        *****     *****       ");
	strcpy(lin[1], "      *       * *       *     ");
	strcpy(lin[2], "     *         *         *    ");
	strcpy(lin[3], "     *                  *     ");
	strcpy(lin[4], "       *              *       ");
	strcpy(lin[5], "         *          *         ");
	strcpy(lin[6], "           *     *            ");
	strcpy(lin[7], "              *               ");
	strcpy(lin[8], "MUUUITO OBRIGADO, PROFESSORES!");
	
	
	textcolor(0);
    textbackground(12);
    telinha();
	for(int i=0; i<9; i++){
		usleep(50000);
		gotoxy(x+1,y-11);
		printf("%s", lin[i]);
		y++;
	}
	
	sleep(2);	
	telinha();
	sleep(2);
	
	memset(lin, '\0', sizeof(lin));
	strcpy(lin[0], "GOSTOSINHO");
	strcpy(lin[1], "CAMILA");
	strcpy(lin[2], "CIDÃO");
	strcpy(lin[3], "ALEXANDRE");
	strcpy(lin[4], "MORENO");
	strcpy(lin[5], "MESSIAS");
	strcpy(lin[6], "JESUS");
	strcpy(lin[7], "JOÃO PEDRO");	

	int a, b, c, d, e, f, g, h;
	a=x;
	b=x;
	c=x;
	d=x;
	e=x;
	f=x;
	g=x;
	h=x;		
	for(int i=0; i<20; i++){
		usleep(70000);
		telinha();
		
		if(i >= 2){			//GOSTOSINHO
			gotoxy(a,y-20);
        	printf("%s", lin[0]);
        	a++;
    	}
    	if(i > 4){			//CAMILA
			gotoxy(b,y-18);
        	printf("%s", lin[1]);
        	b++;
    	}
		if(i > 10){			//CIDÃO
			gotoxy(c,y-17);
        	printf("%s", lin[2]);
        	c++;
    	}
    	if(i > 0){			//ALEXANDRE
			gotoxy(d,y-16);
        	printf("%s", lin[3]);
        	d++;
    	}
    	if(i > 7){			//MORENO
			gotoxy(e,y-15);
        	printf("%s", lin[4]);
        	e++;
    	}
    	if(i > 9){			//MESSIAS
			gotoxy(f,y-13);
        	printf("%s", lin[5]);
        	f++;
    	}
    	if(i > 1){			//JESUS
			gotoxy(g,y-12);
        	printf("%s", lin[6]);
        	g++;
    	}
        if(i > 9){			//JOÃO PEDRO
			gotoxy(h,y-10);
        	printf("%s", lin[7]);
        	h++;	
    	}
	}
	sleep(4);
	fflush(stdin);		
	
	textcolor(0);
    textbackground(0);
    
	menu();
}
//------------------------------------------------------------------------------------------------------------
void telinha(){
	int x=42,y=9;
	for(int i=0;i<12;i++){
    	gotoxy(x,y+i+1);
    	printf("                                  "); 	
	}	
}
//------------------------------------------------------------------------------------------------------------
void gotoxy(int x, int y) {                                                    
    COORD c;
    c.X = x - 1; 
    c.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
//------------------------------------------------------------------------------------------------------------
void textcolor(int color) {                                                     
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
} 
//------------------------------------------------------------------------------------------------------------
void textbackground(int color) {                                                
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            (csbi.wAttributes & 0x0F) | (color << 4));
} 
//------------------------------------------------------------------------------------------------------------
void hideCursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
//------------------------------------------------------------------------------------------------------------
void showCursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = TRUE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
//------------------------------------------------------------------------------------------------------------
// Criptografa o texto usando a Cifra de César
void criptografar(char *text, int troca) {
	
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + troca) % 26 + 'a';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' + troca) % 26 + 'A';
        }
    }
}
//------------------------------------------------------------------------------------------------------------
void descriptografar(char *text, int troca) {
    criptografar(text, 26 - troca);
}