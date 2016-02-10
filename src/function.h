#ifndef function_H
#define function_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "graphic.h"
#include "ADT/Boolean/boolean.h"
#include "ADT/Matriks/Matriks.h"
#include "ADT/Stack/stack.h"
#include "ADT/MesinKata/mesinkata.h"
#include "ADT/Waktu/adtwaktu.h"
#include "ADT/Tree/tree.h"
#include "ADT/MapNilai/mapnilai.h"
#include "ADT/ADTPriorityQueue/PrioQue.h"
#include "ADT/ListPlayer/listplayer.h"
#include "ADT/FileIO/BTeksternal.h"

el arr[17];
el arr2[17];
Kata ID;
Kata ID2;
int IDstat;
Tree  T; //Tree menjadi global variabel untuk kamus data
LPlayer ListPlayer; //List User

/**** Fungsi Utama ****/
void Menu();
/* I.S. Sembarang															 */
/* F.S. Menu telah ditampilkan dan pilihan mendapatkan nilai baru			 */
/* Proses: Menampilkan menu dan mengisikan pilihan sesuai dengan kursor menu */

void Register();
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */

void Login(Kata *K);
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */

void HowToPlay();
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */

void About();
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */

void MenuLogin();
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */

void MyHighScore();
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */

void AllHighScore();
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */

void Play(int board);
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */

void PlayDual(int board);
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */

#endif
