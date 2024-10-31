/*SISTEMA DE SUGURANÇA
O objetivo é criar um sistema de criptografia para uma empresa que sofre com problemas de segurança.*/ 
//Bora codar, Ryanzinho!!!!
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>

// Authors: Ryan R. Silva, Wellington Amorim

void menu();
void gotoxy(int x, int y);
void textcolor(int color);
void textbackground(int color);

int main() {
    setlocale(LC_ALL, "Portuguese");
    int i;

    for(i = 5;i<40;i++) {
		gotoxy(i,2);
		printf("=");
		gotoxy(i,16);
		printf("=");
	}
	for(i = 3;i<16;i++) {
		gotoxy(5,i);
		printf("|");
		gotoxy(39,i);
		printf("|");
	}
	
	gotoxy(8,4);
	printf("> Selecione uma opção:");
	
	gotoxy(8,6);
	printf("[ Cadastrar Usuário ]");
	gotoxy(8,8);
	printf("[  Alterar Usuário  ]");
	gotoxy(8,10);
	printf("[  Excluir Usuário  ]");
	gotoxy(8,12);
	printf("[  Listar Usuários  ]");

    printf("\n\n\n\n\n");

    return 0;
}
// ========================================== Área de Funções ================================================
// Funções adicionais como menu, etc., podem ser colocadas aqui
//------------------------------------------------------------------------------------------------------------
void menu() {                                                                   //MENU
    int op = 1, ch, i;

    // Desenha o menu
    for (i = 5; i < 40; i++) {
        gotoxy(i, 3);
        printf("=");
    }
    for (i = 4; i < 25; i++) {
        gotoxy(5, i);
        printf("||");
    }

    // Loop para ler as setinhas
    do {
        ch = getch();
        if (ch == 0 || ch == 224) {
            int arrow = getch();
            if (arrow == 80) { // seta para baixo
                if (op < 4) {
                    op++;
                } else {
                    op = 1;
                }
            } else if (arrow == 72) { // seta para cima
                if (op > 1) {
                    op--;
                } else {
                    op = 4;
                }
            }
        }
    } while (ch != 27);  // 27 é o código ASCII para a tecla ESC
}
//------------------------------------------------------------------------------------------------------------
// Função para definir a posição do cursor no console
void gotoxy(int x, int y) {                                                     //GOTOXY
    COORD c;
    c.X = x - 1;  // Subtrair 1 para se alinhar ao zero-based index do Windows
    c.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
//------------------------------------------------------------------------------------------------------------
// Função para definir a cor do texto
void textcolor(int color) {                                                     //TEXTCOLOR
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
//------------------------------------------------------------------------------------------------------------
// Função para definir a cor de fundo do texto
void textbackground(int color) {                                                //TEXTBACKGROUND
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            (csbi.wAttributes & 0x0F) | (color << 4));
}
