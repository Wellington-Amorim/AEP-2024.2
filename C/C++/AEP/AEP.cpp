/*SISTEMA DE SUGURANÇA
O objetivo é criar um sistema de criptografia para uma empresa que sofre com problemas de segurança.*/ 
//Bora codar, Ryanzinho!!!!
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>

// Authors: Ryan R. Silva, Wellington Amorim

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

// Desenha o menu
void menu() {                                                                  
    int op = 0, ch, i;

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
                gotoxy(48,12);
                printf("[ Cadastrar Usuário  ]");
                break;
            case 1:
                gotoxy(48,14);
                printf("[  Alterar Usuário   ]");
                break;
            case 2:
                gotoxy(48,16);
                printf("[  Excluir Usuário   ]");
                break;
            case 3:
                gotoxy(48,18);
                printf("[  Listar Usuários   ]");
                break;
            case 4:
                gotoxy(48,20);
                printf("[  Créditos          ]");
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
}
//------------------------------------------------------------------------------------------------------------
void cadastrarUsuario() {
	int x=42,y=9;
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
    
    
	getch();
	menu();
}
//------------------------------------------------------------------------------------------------------------
void alterarUsuario() {
	int x=42,y=9;
	bordas();
	
	//interface padrão
	textcolor(13);								
    gotoxy(47,9);
    printf("--- Alterar  Usuário ---");
    
    textcolor(0);
    textbackground(8);
    gotoxy(x+1,y+2);
    printf("Usuário:                       ");
    
    gotoxy(x+1,y+4);
    printf("Modificar:                     ");

    gotoxy(x+1,y+6);
    printf("Nova senha:                    ");
	
	gotoxy(x+1,y+8);
    printf("Confirmar senha:               ");    
    textcolor(0);
		
	getch();
	menu();
}
//------------------------------------------------------------------------------------------------------------
void excluirUsuario() {
	int x=42,y=9;
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
		
	getch();
	menu();
}
//------------------------------------------------------------------------------------------------------------
void listarUsuarios() {
	int x=42,y=9;
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
 	textcolor(0);
				
	getch();
	menu();
}
//------------------------------------------------------------------------------------------------------------
void mostraCreditos() {
	int x=42,y=9;
	
	textbackground(0);
	bordas();

	textcolor(14);
    gotoxy(51,9);
    printf("--- Créditos ---");
    
    //fundo amarelo
   	textbackground(14);                      
    for(int i=0;i<12;i++){
    	gotoxy(x,y+i+1);
    	printf("                                  "); 	
	}
	
	//futuro conteúdo
	textcolor(0);								
	textbackground(14); 
	gotoxy(x+11,y+6);
	printf("CARREGANDO...");
    textbackground(0);
    
	getch();
	menu();
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
