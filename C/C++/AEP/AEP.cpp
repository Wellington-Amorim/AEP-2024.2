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
void textbackground(int newcolor);
void textcolor(int newcolor);
// Cabeçalho da gotoxy()
void gotoxy(int x, int y);

// É necessário pra registrar o contexto da janela atual
text_info vActual = {0, 0, 79, 24, WHITE, WHITE, C80, 25, 80, 1, 1};

int main() {
	setlocale(LC_ALL,"Portuguese");
	int i;
	
	for(i = 5;i<40;i++) {
		gotoxy(i,3);
		printf("+");
	}
	for(i = 4;i<16;i++) {
		gotoxy(5,i);
		printf("|");
	}
return 0;
}

// ========================================== Área de Funções ================================================
// Função trazida do <conio.c> (precisa do <windows.h> 
void gotoxy(int x, int y) 									//GOTOXY
{ 
   COORD c;

   if(x < 1 || x > vActual.screenwidth || 
      y < 1 || y > vActual.screenheight) return;
   vActual.curx = x;
   vActual.cury = y;
   c.X = vActual.winleft + x - 1;
   c.Y = vActual.wintop + y - 1;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
// -----------------------------------------------------------------------------------------------------------
/* Menu: desenha a borda e realca a opcao selecionada, chamando o procedimento desejado
  ao apertar enter - Uma variavel muda de valor conforme se aperta as setas, mudando o realce */
void menu() {											//MENU
	int op = 1, ch, i;
	
	// Desenha o menu
	for(i = 5;i<40;i++) {
		gotoxy(i,3);
		printf("=");
	}
	for(i = 4;i<25;i++) {
		gotoxy(5,i);
		printf("||");
	}
	
	// Loop para ler as setinhas
	do {
		ch = getch();
		if(ch == 0 || ch == 224){
			if(getch() == 80) {
				if(op < 4) {
					op++;	
				}
				else {
					op = 1;
				}
			}
			else if(getch() == 72) {
				if(op > 1) {
					op--;
				}
				else {
					op = 4;
				}
			}
        }
		// Realce do texto de acordo com o valor de 'op'	
		switch(op) {
			case 1:
			break;
			
			case 2:
			break;
			
			case 3:
			break;
			
			case 4:
			break;
		}				
	} while(ch != 27);
}
// -----------------------------------------------------------------------------------------------------------
// Função trazida do <conio.c> (precisa do <windows.h>
void textbackground(int newcolor) 							//TEXTBACKGROUND
{
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
      (csbi.wAttributes & 0x0f) | (newcolor << 4));
   vActual.attribute = (csbi.wAttributes & 0x0f) | (newcolor << 4);
}
// -----------------------------------------------------------------------------------------------------------
// Função trazida do <conio.c> (precisa do <windows.h>
void textcolor(int newcolor) 								//TEXTCOLOR
{
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
      (csbi.wAttributes & 0xf0) | newcolor);
   vActual.attribute = (csbi.wAttributes & 0xf0) | newcolor;
}
