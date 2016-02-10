#include "graphic.h"


/**** Deal with terminal I/O interfaces ****/
void resetTermios(){
/* restore new terminal i/o settings */
	tcsetattr(0,TCSANOW,&old_termios);
}
void initTermios(){
/* initialize new terminal i/o settings */
	tcgetattr(0,&old_termios); // store old terminal
	new_termios = old_termios; // assign to new setting
	new_termios.c_lflag &= ~ICANON; // disable buffer i/o
	new_termios.c_lflag &= ~ECHO; // disable echo mode
	tcsetattr(0,TCSANOW,&new_termios); // use new terminal setting
}

/**** Detect & read pressed key ****/
int kbhit(){
/* detect keyboard press */
	struct timeval tv = {0L,0L};
	fd_set fds;
	FD_ZERO(&fds);
	FD_SET(0,&fds);
	return select(1,&fds,NULL,NULL,&tv);
}
char getch(){
/* read 1 character */
	char ch;
	ch = getchar();
	return ch;
}

/**** Draw on terminal ****/
void PrintLayout(){
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */
	/* Kamus Lokal */
	int i;

	/* Algoritma */
	printf(FontBlue Bold "  _  _  _                _                                  ______ \n"); //ASCI Art - Judul
	printf(" | || || |              | |                        _       / __   |\n");
	printf(" | || || | ___   ____ _ | | ____ ____   ____ ____ | |_ ___| | //| |\n");
	printf(" | ||_|| |/ _ \\ / ___) || |/ _  |    \\ / _  )  _ \\|  _|___) |// | |\n");
	printf(" | |___| | |_| | |  ( (_| ( ( | | | | ( (/ /| | | | |__   |  /__| |\n");
	printf("  \\______|\\___/|_|   \\____|\\_||_|_|_|_|\\____)_| |_|\\___)   \\_____/\n" Reset);
	printf("\t\t\t\t\t\t\tby AnakGajah\n"); //Nama Team
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	PrintXY(1, 9, "╭──────────────────────────────────────────────────────────────────╮\n"); //Border
	for (i = 1; i <= 17; i++){
		PrintXY(1, 9 + i, "│                                                                  │\n");
	}
	PrintXY(1, 27, "╰──────────────────────────────────────────────────────────────────╯\n");
}
void PrintLayoutDual(){
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */
	/* Kamus Lokal */
	
	/* Algoritma */
	PrintXY(33, 1, FontBlue Bold "  _  _  _                _                                  ______ \n"); //ASCI Art - Judul
	PrintXY(33, 2, " | || || |              | |                        _       / __   |\n");
	PrintXY(33, 3, " | || || | ___   ____ _ | | ____ ____   ____ ____ | |_ ___| | //| |\n");
	PrintXY(33, 4, " | ||_|| |/ _ \\ / ___) || |/ _  |    \\ / _  )  _ \\|  _|___) |// | |\n");
	PrintXY(33, 5, " | |___| | |_| | |  ( (_| ( ( | | | | ( (/ /| | | | |__   |  /__| |\n");
	PrintXY(33, 6, "  \\______|\\___/|_|   \\____|\\_||_|_|_|_|\\____)_| |_|\\___)   \\_____/\n" Reset);
	PrintXY(33, 7, "\t\t\t\t\t\t\tby AnakGajah\n"); //Nama Team
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	PrintXY(1, 9, "╭────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮\n"); //Border
	PrintXY(1, 27, "╰────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╯\n");
}
void PrintMatriks(){
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */
	/* Kamus Lokal */
	int i, j;

	/* Algoritma */
	PrintXY(3, 10, "╭───────┬───────┬───────┬───────╮"); //Matrix Border
	for (i = 1; i <= 12; i += 4){
		PrintXY(3, 13 + i, "├───────┼───────┼───────┼───────┤");
	}
	for(i = 1; i <= 33; i += 8){
		for (j = 1; j <= 13; j += 4){
			PrintXY(2 + i, 10 + j, "│");
			PrintXY(2 + i, 11 + j, "│");
			PrintXY(2 + i, 12 + j, "│");
		}
	}
	PrintXY(3, 26, "╰───────┴───────┴───────┴───────╯");
}
void PrintMatriksDual(){
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */
	/* Kamus Lokal */
	int i, j;

	/* Algoritma */
	PrintXY(3, 10, "╭───────┬───────┬───────┬───────╮"); //Matrix Border
	for (i = 1; i <= 12; i += 4){
		PrintXY(3, 13 + i, "├───────┼───────┼───────┼───────┤");
	}
	for(i = 1; i <= 33; i += 8){
		for (j = 1; j <= 13; j += 4){
			PrintXY(2 + i, 10 + j, "│");
			PrintXY(2 + i, 11 + j, "│");
			PrintXY(2 + i, 12 + j, "│");
		}
	}
	PrintXY(3, 26, "╰───────┴───────┴───────┴───────╯");
	PrintXY(100, 10, "╭───────┬───────┬───────┬───────╮"); //Matrix Border
	for (i = 1; i <= 12; i += 4){
		PrintXY(100, 13 + i, "├───────┼───────┼───────┼───────┤");
	}
	for(i = 1; i <= 33; i += 8){
		for (j = 1; j <= 13; j += 4){
			PrintXY(99 + i, 10 + j, "│");
			PrintXY(99 + i, 11 + j, "│");
			PrintXY(99 + i, 12 + j, "│");
		}
	}
	PrintXY(100, 26, "╰───────┴───────┴───────┴───────╯");

}
void PrintStatistik(){
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */
	/* Kamus Lokal */
	int i;

	/* Algoritma */
	PrintXY(3, 12, "         Statistik Board [ ]         "); //Container Statistik
	PrintXY(3, 13, "╔═══════════════════════════════════╗");
	for (i = 1; i <= 10; i++){
		PrintXY(3, 13+i, "║                                   ║");
	}
	PrintXY(5, 15, FontBlue "TOTAL PEMAIN");
	PrintXY(5, 18, "RATA-RATA SELURUH SCORE");
	PrintXY(5, 21, "RANKING KESULITAN BOARD" Reset);

	PrintXY(3, 24, "╚═══════════════════════════════════╝");
}
void PrintGajah(){
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */
	/* Kamus Lokal */

	/* Algoritma */
	PrintXY(3, 11, FontBlue Bold "       .-\"````\"\"-._     .-\"```\"-.\n"); //Ascii Art - Gajah
	PrintXY(3, 12, "    .'            '._.'         \"._\n");
	PrintXY(3, 13, "  .'            .-'`         _    _'.__\n");
	PrintXY(3, 14, " /               '._       /`    /  \\  \\\n");
	PrintXY(3, 15, "| |                 '.__.-'      \\_o/_o/\n");
	PrintXY(3, 16, "|/|                                  =}\n");
	PrintXY(3, 17, "/\\;                                  =}\n");
	PrintXY(3, 18, "\\/ \\          \\            \\  C)     =}\n");
	PrintXY(3, 19, "    '.         |           /'-/      /\n");
	PrintXY(3, 20, "      \\        | /      / / .'     .'\n");
	PrintXY(3, 21, "       \\     _/-|      | | /    .-'\n");
	PrintXY(3, 22, "        \\      | \\    _/_/ | =/`\n");
	PrintXY(3, 23, "        /     =|=| \\    \\ \\ | =|\n");
	PrintXY(3, 24, "        |    _/_/  /   _/_/  \\  \\\n");
	PrintXY(3, 25, "        |    | |  /    | |    )__\\\n");
	PrintXY(3, 26, "        \\__nnn\\n\\ \\__nnn\\n\\\n" Reset);
}
