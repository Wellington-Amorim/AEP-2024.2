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
void gotoxy(int x, int y);
void textcolor(int color);
void textbackground(int color);

int main() {
    setlocale(LC_ALL, "Portuguese");

	menu();

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");

return 0;
}
// ========================================== Área de Funções ================================================

void bordas() {
    int i;

    for(i = 5;i<41;i++) {
        gotoxy(i,2);
        printf("=");
        gotoxy(i,16);
        printf("=");
	}
	for(i = 3;i<16;i++) {
        gotoxy(5,i);
        printf("|");
        gotoxy(40,i);
        printf("|");
	}
}

// Desenha o menu
void menu() {                                                                  
    int op = 0, ch, i;

    bordas();
    gotoxy(17,4);
    printf("--- MENU ---");

    do {
        // Imprime de acordo com "op"
        for (i = 0; i < 4; i++) {
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
                gotoxy(7,6);
                printf("[ Cadastrar Usuário ]");
                break;
            case 1:
                gotoxy(7,7);
                printf("[  Alterar Usuário  ]");
                break;
            case 2:
                gotoxy(7,8);
                printf("[  Excluir Usuário  ]");
                break;
            case 3:
                gotoxy(7,9);
                printf("[  Listar Usuários  ]");
                break;
            case 4:
                gotoxy(7,10);
                printf("[  Créditos         ]");
                break;
            }
        }
        
        // Verifica as setas
        ch = getch();
        if (ch == 0 || ch == 224) {
           ch = getch();
        }

        if (ch == 80) { // seta para baixo
            if (op < 3) {
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
                op = 3;
            }
        }
    } while (ch != 27);
    
    
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
