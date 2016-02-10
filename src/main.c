#include "function.h"

int main(){
	/* Kamus Lokal */

	/* Algoritma */
	CreateT(&T);
	initTermios();
	ResizeTerminal;
	Clear;
	resetTermios();
	CreateListPlayer(&ListPlayer);
	bacaSugesti(&ListPlayer);
	bacaScore(&ListPlayer);
	IDstat = 0;
	STARTKATA(); //Akses Dictionary
	while(!EndKata){ //Membentuk tree
		AddST(&T, CKata);
		ADVKATA();
	}
	Menu();
	MoveCursorToEnd;
	ShowCursor;
}
