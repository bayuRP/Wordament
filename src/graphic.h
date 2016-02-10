#ifndef graphic_H
#define graphic_H
#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>


/**** Formatting ****/
/* Terminal */
#define ResizeTerminal 		printf("\033[8;30;69;t");
#define ResizeDual 			printf("\033[8;30;134;t");
#define Clear 				printf("\033c");

/* Cursor */
#define HideCursor			printf("\033[?25l");
#define ShowCursor			printf("\033[?25h");
#define MoveCursorToEnd		printf("\033[28;1H");	
#define GoToXY(x, y)		printf("\033[%d;%dH", y, x);
#define PrintXY(x, y, s)	printf("\033[%d;%dH%s", y, x, s);

/* Font */
#define Reset				"\033[0m"
#define Bold				"\033[1m"
#define Italic				"\033[3m"
#define Underline			"\033[4m"
#define Cross				"\033[9m"

/* Font Color */
#define FontRed				"\033[31m"
#define FontGreen			"\033[32m"
#define FontYellow			"\033[33m"
#define FontBlue			"\033[34m"
#define FontMagenta			"\033[35m"
#define FontCyan			"\033[36m"
#define FontWhite			"\033[37m"


/**** Deal with terminal I/O interfaces ****/
static struct termios old_termios, new_termios;
void resetTermios();
/* restore new terminal i/o settings */
void initTermios();
/* initialize new terminal i/o settings */

/**** Detect & read pressed key ****/
int kbhit();
/* detect keyboard press */
char getch();
/* read 1 character */


/**** Draw ons terminal ****/
void PrintLayout();
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */
void PrintLayoutDual();
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */
void PrintMatriks();
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */
void PrintMatriksDual();
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */
void PrintStatistik();
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */
void PrintGajah();
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */


#endif