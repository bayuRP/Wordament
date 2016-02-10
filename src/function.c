#include "function.h"


/**** Fungsi Utama ****/
void Menu(){
/* I.S. Sembarang															 */
/* F.S. Menu telah ditampilkan dan pilihan mendapatkan nilai baru			 */
/* Proses: Menampilkan menu dan mengisikan pilihan sesuai dengan kursor menu */
	/* Kamus Lokal */
	char cc;
	int pilihan;

	/* Algoritma */
	initTermios();
	pilihan = 1;
	do{
		Clear;
		HideCursor;
		PrintLayout();
		PrintMatriks();
		PrintXY(7, 12, FontBlue Bold "W"); PrintXY(15, 12, "O"); PrintXY(23, 12, "R");
		PrintXY(31, 12, "D"); PrintXY(23, 16, "A"); PrintXY(15, 20, "M");
		PrintXY(7, 24, "E"); PrintXY(15, 24, "N"); PrintXY(23, 24, "T" Reset);
		if (pilihan < 1){ //Status terpilihnya menu (1-5)
			pilihan = 1;
		} else if (pilihan > 5){
			pilihan = 5;
		}
		PrintXY(47, 16, "REGISTER\n");
		PrintXY(47, 17, "LOGIN\n");
		PrintXY(47, 18, "HOW TO PLAY\n");
		PrintXY(47, 19, "ABOUT\n");
		PrintXY(47, 20, "CLOSE\n");
		switch(pilihan){
			case 1 :
				PrintXY(47, 16, FontBlue Bold Underline "REGISTER\n" Reset);
				break;
			case 2 :
				PrintXY(47, 17, FontBlue Bold Underline "LOGIN\n" Reset);
				break;
			case 3 :
				PrintXY(47, 18, FontBlue Bold Underline "HOW TO PLAY\n" Reset);
				break;
			case 4 :
				PrintXY(47, 19, FontBlue Bold Underline "ABOUT\n" Reset);
				break;
			case 5 :
				PrintXY(47, 20, FontBlue Bold Underline "CLOSE\n" Reset);
				break;
		}
		if (!kbhit()){ //Membaca tuts keyboard
			cc = getch();
			if (cc == 'w'){
				pilihan--;
			} else if (cc == 'x'){
				pilihan++;
			}
		}
	} while	(cc != 's');
	resetTermios();
	switch(pilihan){
		case 1:
			Register();
			break;
		case 2:
			Login(&ID);
			break;
		case 3:
			HowToPlay();
			break;
		case 4:
			About();
			break;
		case 5:
			tulisSugesti(ListPlayer);
			tulisScore(ListPlayer);
			break;
	}
}

void Register(){
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */
	/* Kamus Lokal */
	int i, j;
	char cc;

	/* Algoritma */
	initTermios();
	Clear;
	HideCursor;
	PrintLayout();
	PrintXY(31, 16, FontBlue "REGISTER\n" Reset);
	PrintXY(21, 17, "╭───────────────────────────╮\n");
	PrintXY(21, 18, "│ User ID :                 │\n");
	PrintXY(21, 19, "╰───────────────────────────╯\n");
	PrintXY(24, 21, "[" FontYellow "enter" Reset "] ok     [" FontYellow "/" Reset "] back\n");
	GoToXY(33, 18);
	ShowCursor;
	i = 0;
	memset(ID.TabKata, 0, sizeof(ID.TabKata));
	ID.Length = 0;
	do{
		if (!kbhit()){
			cc = getch();
			if (cc == '\n'){
				break;
			} else if ((cc == 127) && (i >= 1)){
				ID.TabKata[i] = '\0';
				i--;
			} else if ((isalnum(cc)) && (i <= 14)){
				i++;
				ID.TabKata[i] = cc;
			}
			Clear;
			PrintLayout();
			PrintXY(31, 16, FontBlue "REGISTER\n" Reset);
			PrintXY(21, 17, "╭───────────────────────────╮\n");
			PrintXY(21, 18, "│ User ID :                 │\n");
			PrintXY(21, 19, "╰───────────────────────────╯\n");
			PrintXY(24, 21, "[" FontYellow "enter" Reset "] ok     [" FontYellow "/" Reset "] back\n");
			if ((!isalnum(cc)) && (cc != 127) && (cc != '/')){
				PrintXY(22, 20, "User ID harus alfanumerik!!\n");
			}
			GoToXY(33, 18);
			for (j = 0; j <= i; j++){
				printf(FontGreen "%c" Reset, ID.TabKata[j]);
			}
		}
	} while ((cc != '\n') && (cc != '/'));
	HideCursor;
	ID.Length = i;
	if (cc == '\n'){
		if (!searchPlayer(ListPlayer, ID)){
			InsertVLastLPlayer(&ListPlayer, ID);
			PrintXY(21, 20, "User ID berhasil didaftarkan!\n");
			PrintXY(24, 21, "                       \n");
			PrintXY(36, 26, "press " FontYellow "any key" Reset " to continue...\n");
			getch();
			resetTermios();
			Menu();
		} else{
			PrintXY(23, 20, "User ID telah terdaftar!!\n");
			PrintXY(22, 21, "[" FontYellow "enter" Reset "] retry      [" FontYellow "/" Reset "] back\n");
			do{
				cc = getch();
			} while ((cc != '\n') && (cc != '/'));
			resetTermios();
			if (cc == '\n'){
				Register();
			} else{
				Menu();
			}
		}
	} else{
		resetTermios();
		Menu();
	}
}

void Login(Kata *K){
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */
	/* Kamus Lokal */
	int i, j;
	boolean valid;
	char cc;

	/* Algoritma */
	initTermios();
	Clear;
	HideCursor;
	PrintLayout();
	PrintXY(33, 16, FontBlue "LOGIN\n" Reset);
	PrintXY(21, 17, "╭───────────────────────────╮\n");
	PrintXY(21, 18, "│ User ID :                 │\n");
	PrintXY(21, 19, "╰───────────────────────────╯\n");
	PrintXY(24, 21, "[" FontYellow "enter" Reset "] ok     [" FontYellow "/" Reset "] back\n");
	GoToXY(33, 18);
	ShowCursor;
	i = 0;
	memset((*K).TabKata, 0, sizeof((*K).TabKata));
	HideCursor;
	(*K).Length = 0;
	do{
		if (!kbhit()){
			cc = getch();
			if (cc == '\n'){
				break;
			} else if ((cc == 127) && (i >= 1)){
				(*K).TabKata[i] = '\0';
				i--;
			} else if ((isalnum(cc)) && (i <= 14)){
				i++;
				(*K).TabKata[i] = cc;
			}
			Clear;
			PrintLayout();
			PrintXY(33, 16, FontBlue "LOGIN\n" Reset);
			PrintXY(21, 17, "╭───────────────────────────╮\n");
			PrintXY(21, 18, "│ User ID :                 │\n");
			PrintXY(21, 19, "╰───────────────────────────╯\n");
			PrintXY(24, 21, "[" FontYellow "enter" Reset "] ok     [" FontYellow "/" Reset "] back\n");
			if ((!isalnum(cc)) && (cc != 127) && (cc != '/')){
				PrintXY(22, 20, "User ID harus alfanumerik!!\n");
			}
			GoToXY(33, 18);
			for (j = 0; j <= i; j++){
				printf(FontGreen "%c" Reset, (*K).TabKata[j]);
			}
		}
	} while ((cc != '\n') && (cc != '/'));
	(*K).Length = i;
	HideCursor;
	if (cc == '\n'){
		if (searchPlayer(ListPlayer, *K)){
			resetTermios();
			MenuLogin();
		} else{
			PrintXY(23, 20, "User ID tidak ditemukan!!\n");
			PrintXY(22, 21, "[" FontYellow "enter" Reset "] retry      [" FontYellow "/" Reset "] back\n");
			do{
				cc = getch();
			} while ((cc != '\n') && (cc != '/'));
			resetTermios();
			if (cc == '\n'){
				Login(K);
			} else{
				if (IDstat == 0){
					Menu();
				} else{
					MenuLogin();
				}
			}
		}
	} else{
		resetTermios();
		if (IDstat == 0){
			Menu();
		} else{
			MenuLogin();
		}
	}
}

void HowToPlay(){
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */
	/* Kamus Lokal */
	char cc;
	int page;

	/* Algoritma */
	initTermios();
	page = 1;
	do{
		Clear;
		HideCursor;
		PrintLayout();
		if (page < 1){
			page = 1;
		} else if (page > 5){
			page = 5;
		}
		PrintXY(29, 10, FontBlue "How to Play\n" Reset);
		if (page == 1){
			PrintXY(6, 12, "Pemain dapat membentuk suatu kata dengan cara memulai dari\n");
			PrintXY(6, 13, "salah satu petak, kemudian meneruskannya ke sekeliling pe-\n");
			PrintXY(6, 14, "tak tersebut. Setiap petak dalam board hanya dapat dipakai\n");
			PrintXY(6, 15, "maksimal satu kali untuk membentuk satu kata. Kata yang di\n");
			PrintXY(6, 16, "bentuk lalu akan dicek ke dalam kamus kata. Jika kata ter-\n");
			PrintXY(6, 17, "sebut ditemukan di dalam kamus kata, maka pemain akan men-\n");
			PrintXY(6, 18, "dapatkan skor yang bergantung pada kata tersebut dan huruf\n");
			PrintXY(6, 19, "penyusunnya. Kata yang telah dibentuk sebelumnya pada per-\n");
			PrintXY(6, 20, "mainan yang sama tidak akan mendapatkan skor.\n");
		} else if (page == 2){
			PrintXY(6, 12, "Kata yang panjangnya lebih dari 10 karakter akan mendapat-\n");
			PrintXY(6, 13, "kan bonus 10 poin. Setiap pemain diberikan waktu 120 menit\n");
			PrintXY(6, 14, "untuk membentuk sebanyak mungkin kata dari board. Di dalam\n");
			PrintXY(6, 15, "permainan diberikan juga fitur suggestion yang berisi kata\n");
			PrintXY(6, 16, "yang pernah ditebak sebelumnya dari board itu dalam permai\n");
			PrintXY(6, 17, "nan yang telah lampau. Dalam permainan disediakan 10 macam\n");
			PrintXY(6, 18, "(0-9) pilihan board berbeda dengan '16' karakter yang ber-\n");
			PrintXY(6, 19, "beda juga di setiap boardnya.\n");
		} else if (page == 3){
			PrintXY(6, 12, "Setelah anda login, akan ada 5 menu sebagai berikut:\n");
			PrintXY(6, 13, "  >Play\n");
			PrintXY(6, 14, "    Berfungsi untuk memulai permainan.\n");
			PrintXY(6, 16, "  >Board\n");
			PrintXY(6, 17, "    Berfungsi untuk memilih board yang akan dimainkan(0-9)\n");
			PrintXY(6, 19, "  >My High Score\n");
			PrintXY(6, 20, "    Berisi nilai tertinggi dari ID yang sedang bermain un-\n");
			PrintXY(6, 21, "    tuk setiap boardnya beserta waktu pencapaiannya\n");
		} else if (page == 4){
			PrintXY(6, 12, "  >All High Score\n");
			PrintXY(6, 13, "    Berisi akumulasi nilai tertinggi dari setiap ID untuk\n");
			PrintXY(6, 14, "    setiap board yang ada beserta waktunya.\n");
			PrintXY(6, 16, "  >Logout\n");
			PrintXY(6, 17, "    Kembali ke menu utama.\n");
		} else if (page == 5){
			PrintXY(6, 12, "Kontrol:\n");
			PrintXY(8, 13, "             q = atas-kiri      c     = bawah-kanan\n");
			PrintXY(8, 14, "q   w   e    w = atas           r     = rotasi (90º cw)\n");
			PrintXY(8, 15, "  ↖ ↑ ↗      e = atas-kanan     f     = scroll atas\n");
			PrintXY(8, 16, "a ← s → d    a = kiri           v     = scroll bawah\n");
			PrintXY(8, 17, "  ↙ ↓ ↘      d = kanan          s     = ok/mulai/kembali\n");
			PrintXY(8, 18, "z   x   c    z = bawah-kiri     /     = kembali\n");
			PrintXY(8, 19, "             x = bawah          enter = ok\n");
		}
		GoToXY(6, 25); printf("(%d/5)\n", page);
		PrintXY(13, 25, "previous[" FontYellow "a" Reset "]\n");
		PrintXY(28, 25, "next[" FontYellow "d" Reset "]\n");
		if (page == 1){
			PrintXY(13, 25, "previous[" FontRed "a" Reset "]\n");
		} else if (page == 5){
			PrintXY(28, 25,"next[" FontRed "d" Reset "]\n");
		}
		PrintXY(29, 26, "press [" FontYellow "s" Reset "] to go back to main menu...\n");
		if (!kbhit()){ //Membaca tuts keyboard
			cc = getch();
			if (cc == 'a'){
				page--;
			} else if (cc == 'd'){
				page++;
			}
		}
	} while (cc != 's');
	resetTermios();
	Menu();
}

void About(){
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */
	/* Kamus Lokal */
	
	/* Algoritma */
	initTermios();
	Clear;
	HideCursor;
	PrintLayout();
	PrintXY(29, 10, FontBlue "Wordament-0\n" Reset);
	PrintXY(6, 12, "Permain Wordament-0 ini dibuat guna memenuhi Tugas Besar\n")
	PrintXY(6, 13, "perkuliah IF-IF2110/Algoritma dan Struktur Data.\n")
	PrintXY(6, 15, "Kontributor:\n")
	PrintXY(8, 16, "-Bayu Rasyadi Putrautama (13513046)\n")
	PrintXY(8, 17, "-Faisal Prabowo (13513094)\n")
	PrintXY(8, 18, "-Fiqie Ulya Sidiastahta (13513602)\n")
	PrintXY(8, 19, "-Muhtar Hartopo (13513068)\n")
	PrintXY(8, 20, "-Nitho Alif Ibadurrahman (13513072)\n")
	PrintXY(36, 26, "press " FontYellow "any key" Reset " to continue...\n")
	getch();
	resetTermios();
	Menu();
}

void MenuLogin(){
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */
	/* Kamus Lokal */
	char cc;
	int pilihan, board, score, i, cp;
	float avg;
	
	/* Algoritma */
	initTermios();
	pilihan = 1;
	board = 0;
	do{
		Clear;
		HideCursor;
		PrintLayout();
		if (pilihan < 1){ //Status terpilihnya menu (1-5)
			pilihan = 1;
		} else if (pilihan > 6){
			pilihan = 6;
		}
		if (board < 0){ //Status terpilihnya board (1-5)
			board = 0;
		} else if (board > 9){
			board = 9;
		}
		cp = CountPlayerBoard(ListPlayer, board);
		avg = AverageScoreBoard(ListPlayer, board);
		if (pilihan == 3){
			PrintStatistik();
			PrintXY(29, 12, FontYellow); printf("%d\n" Reset, board);
			PrintXY(5, 16, ""); printf("%d\n" Reset, cp);
			PrintXY(5, 19, ""); printf("%.2f\n" Reset, avg);
			PrintXY(5, 22, "");
			if (avg < 1000){
				printf(FontRed "Susah beet! x.x\n" Reset);
			} else{
				printf(FontGreen "Cups! :3\n" Reset);
			}
			
		} else{
			PrintGajah();
		}
		PrintXY(38, 9, "┬");
		PrintXY(38, 10, "│");
		PrintXY(38, 11, "╰─────────────────────────────┤");
		PrintXY(39, 10, "Welcome back, " FontGreen);
		for (i = 1; i <= ID.Length; i++){
			printf("%c", ID.TabKata[i]);
		}
		printf(Reset);
		PrintXY(47, 16, "PLAY\n");
		if (IDstat == 1){
			PrintXY(47, 17, Cross "DUAL MODE\n" Reset);
		} else{
			PrintXY(47, 17, "DUAL MODE\n");
		}
		PrintXY(47, 18, "BOARD   < >\n");
		GoToXY(56, 18); printf(FontYellow "%d" Reset, board);
		PrintXY(47, 19, "MY HIGH SCORE\n");
		PrintXY(47, 20, "ALL HIGH SCORE\n");
		PrintXY(47, 21, "LOGOUT\n");
		switch(pilihan){
			case 1 :
				PrintXY(47, 16, FontBlue Bold Underline "PLAY\n" Reset);
				break;
			case 2 :
				PrintXY(47, 17, FontBlue Bold Underline);
				if (IDstat == 1){
					printf(Cross "DUAL MODE\n" Reset);
				} else{
					printf("DUAL MODE\n" Reset);
				}
				break;
			case 3 :
				PrintXY(47, 18, FontBlue Bold Underline "BOARD" Reset " " FontBlue Bold "<<" Reset "   " FontBlue Bold ">>\n" Reset);
				GoToXY(56, 18); printf(Bold FontYellow "%d" Reset, board);
				break;
			case 4 :
				PrintXY(47, 19, FontBlue Bold Underline "MY HIGH SCORE\n" Reset);
				break;
			case 5 :
				PrintXY(47, 20, FontBlue Bold Underline "ALL HIGH SCORE\n" Reset);
				break;
			case 6 :
				PrintXY(47, 21, FontBlue Bold Underline "LOGOUT\n" Reset);
				break;
		}
		if (!kbhit()){ //Membaca tuts keyboard
			cc = getch();
			if (cc == 'w'){
				pilihan--;
			} else if (cc == 'x'){
				pilihan++;
			} else if((pilihan == 3) && (cc == 'a')){
				board--;
			} else if(( pilihan == 3) && (cc=='d')){
				board++;
			}
		}
	} while	((cc != 's') || (pilihan == 3) || ((IDstat == 1) && (pilihan == 2)));
	resetTermios();
	switch(pilihan){
		case 1:
			if (IDstat == 0){
				Play(board);
			} else{
				ResizeDual;
				PlayDual(board);
			}
			break;
		case 2:
			IDstat = 1;
			Login(&ID2);
			break;
		case 4:
			MyHighScore();
			break;
		case 5:
			AllHighScore();
			break;
		case 6:
			tulisSugesti(ListPlayer);
			tulisScore(ListPlayer);
			Menu();
			break;
	}
}

void MyHighScore(){
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */
	/* Kamus Lokal */
	char cc;
	int board;

	/* Algoritma */
	initTermios();
	board = 0;
	do{
		Clear;
		HideCursor;
		PrintLayout();
		if (board < 0){
			board = 0;
		} else if (board > 9){
			board = 9;
		}
		PrintXY(28, 10, FontBlue "My High Score\n" Reset);
		PrintXY(30, 11, "[Board  ]\n");
		GoToXY(37, 11); printf(FontYellow "%d" Reset, board);
		PrintXY(10, 13, "│ No │      Score      │          Waktu          │\n");
		PrintXY(10, 14, "├────┼─────────────────┼─────────────────────────┤\n");
		PrintXY(10, 15, "│  1 │                 │                         │\n");
		PrintXY(10, 16, "│  2 │                 │                         │\n");
		PrintXY(10, 17, "│  3 │                 │                         │\n");
		PrintXY(10, 18, "│  4 │                 │                         │\n");
		PrintXY(10, 19, "│  5 │                 │                         │\n");
		PrintXY(10, 20, "│  6 │                 │                         │\n");
		PrintXY(10, 21, "│  7 │                 │                         │\n");
		PrintXY(10, 22, "│  8 │                 │                         │\n");
		PrintXY(10, 23, "│  9 │                 │                         │\n");
		PrintXY(10, 24, "│ 10 │                 │                         │\n");
		PrintMyHighScore(ListPlayer, ID, board);
		PrintXY(6, 25, "(  /10)\n");
		if (board == 9){
			GoToXY(7, 25);
		} else{
			GoToXY(8, 25);
		}
		printf("%d", board + 1);
		PrintXY(15, 25, "previous[" FontYellow "a" Reset "]\n");
		PrintXY(30, 25, "next[" FontYellow "d" Reset "]\n");
		if (board == 0){
			PrintXY(15, 25, "previous[" FontRed "a" Reset "]\n");
		} else if (board == 9){
			PrintXY(30, 25,"next[" FontRed "d" Reset "]\n");
		}

		PrintXY(29, 26, "press [" FontYellow "s" Reset "] to go back to main menu...\n");
		if (!kbhit()){ //Membaca tuts keyboard
			cc = getch();
			if (cc == 'a'){
				board--;
			} else if (cc == 'd'){
				board++;
			}
		}
	} while (cc != 's');
	resetTermios();
	MenuLogin();
}

void AllHighScore(){
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */
	/* Kamus Lokal */
	char cc;
	int board;

	/* Algoritma */
	initTermios();
	board = 0;
	do{
		Clear;
		HideCursor;
		PrintLayout();
		if (board < 0){
			board = 0;
		} else if (board > 9){
			board = 9;
		}
		PrintXY(23, 10, FontBlue "All Time Top High Score\n" Reset);
		PrintXY(30, 11, "[Board  ]\n");
		GoToXY(37, 11); printf(FontYellow "%d" Reset, board);
		PrintXY(6, 13, "│ No │      User ID      │  Score  │        Waktu        │\n");
		PrintXY(6, 14, "├────┼───────────────────┼─────────┼─────────────────────┤\n");
		PrintXY(6, 15, "│  1 │                   │         │                     │\n");
		PrintXY(6, 16, "│  2 │                   │         │                     │\n");
		PrintXY(6, 17, "│  3 │                   │         │                     │\n");
		PrintXY(6, 18, "│  4 │                   │         │                     │\n");
		PrintXY(6, 19, "│  5 │                   │         │                     │\n");
		PrintXY(6, 20, "│  6 │                   │         │                     │\n");
		PrintXY(6, 21, "│  7 │                   │         │                     │\n");
		PrintXY(6, 22, "│  8 │                   │         │                     │\n");
		PrintXY(6, 23, "│  9 │                   │         │                     │\n");
		PrintXY(6, 24, "│ 10 │                   │         │                     │\n");
		PrintAllHighScore(ListPlayer, board);
		PrintXY(6, 25, "(  /10)\n");
		if (board == 9){
			GoToXY(7, 25);
		} else{
			GoToXY(8, 25);
		}
		printf("%d", board + 1);
		PrintXY(15, 25, "previous[" FontYellow "a" Reset "]\n");
		PrintXY(30, 25, "next[" FontYellow "d" Reset "]\n");
		if (board == 0){
			PrintXY(15, 25, "previous[" FontRed "a" Reset "]\n");
		} else if (board == 9){
			PrintXY(30, 25,"next[" FontRed "d" Reset "]\n");
		}
		PrintXY(29, 26, "press [" FontYellow "s" Reset "] to go back to main menu...\n");
		if (!kbhit()){ //Membaca tuts keyboard
			cc = getch();
			if (cc == 'a'){
				board--;
			} else if (cc == 'd'){
				board++;
			}
		}
	} while (cc != 's');
	resetTermios();
	MenuLogin();
}

void Play(int board){
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */
	/* Kamus Lokal */
	time_t start, end;
	Stack S, Sinverse;
	PrioQueue PQ; //MENCIPTAKAN QUEUE
	Map Map;
	MATRIKS M;
	POINT Px;
	Date Dd;
	Time Tm;
	Kata K, Max;
	addressPlayer aP;
	addressSug aS;
	addressScore aC;
	LSugesti ListSugesti;
	infotypeScore XQ;
	int tRemain, elapsed, count, score, On, A, X, i, scroll;
	char cc;
	
	/* Algoritma */
	initTermios();
	time(&start);
	CreateEmpty(&S);
	CreateEmpty(&Sinverse);
	CreateEmptyQ(&PQ,40);
	SetMap(&Map);
	SetArr(arr, board);
	SetMatriks(&M);
	aP = searchAddressPlayer(ListPlayer, ID);
	ListSugesti = PlayerLSugesti(aP, board);
	aS = FirstSug(ListSugesti);
	Px = MakePOINT(0,0);
	tRemain = WAKTU;
	On = 0;
	scroll = 1;
	score = 0;
	memset(K.TabKata, 0, sizeof(K.TabKata));
	K.Length = 0;
	TulisIsiMATRIKS(M, arr, Px);
	do{
		time(&end);
		elapsed = difftime(end, start);
		count = WAKTU - elapsed;
		if (count - tRemain == 0){
			Clear;
			HideCursor;
			PrintLayout();
			PrintMatriks();
			PrintXY(38, 9, "┬");
			PrintXY(38, 10, "│");
			PrintXY(38, 11, "╰─────────────────────────────┤")
			PrintXY(41 + (15 - ID.Length) / 2, 10, "User ID : " FontGreen);
			TulisStringKata(ID);
			printf(Reset);
			PrintXY(41, 12, FontBlue Bold "SCORE\n");
			PrintXY(55, 12, "Time Left\n");
			PrintXY(39, 15, "SUGGESTION : \n"); 
			PrintXY(39, 17, "CURRENT WORDS : \n"); 
			PrintXY(39, 19, "╔\n"); PrintXY(65, 19, "╗\n");
			PrintXY(39, 26, "╚\n"); PrintXY(65, 26, "╝\n" Reset);
			if ((aS != Nil)){
				PrintXY(55, 15, ""); TulisStringKata(InfoSug(aS));	
			}
			PrintXY(55, 17, ""); TulisStringKata(K);
			PrintXY(43, 13, ""); printf("%d\n", score);
			PrintXY(55, 13, "");
			if (elapsed >= (WAKTU - 10)){
				printf(FontRed);
			} else if (elapsed >= (WAKTU - 30)){
				printf(FontYellow);
			}
			printf("[%.02d : %.02d]\n" Reset, tRemain / 60, tRemain % 60);
			PrintXY(46, 19, "GUESSED WORDS\n");
			for (i = 1; i <= 6; i++){
				PrintXY(65, 19 + i, "░\n");
			}
							
			TulisIsiMATRIKS(M, arr, Px);
			TulisQ6(PQ, scroll, 6);
			tRemain--;
		}
		if(kbhit()){
			cc = getch();
			if ((cc == 's') && (On == 0)){ //Tombol Mulai On
				On = 1;
			}else if ((cc == 's') && (On == 1)){//Tombol Off, Menyiapkan Stack untuk d verifikasi
				On = 0;
				if (!IsMemberStack(S, X)){
					Push(&S, X);
					arr[GetElmt(M, GetOrdinat(Px), GetAbsis(Px))].status = ' ';
				}
				Sinverse = InverseStack(S);
			}	
			if (cc == 'r'){ //ROTATE BOARD
				X = GetEl(M, Px);
				PutarMATRIKS(&M);
				GetPoint(X,M, &Px);
			}
			else if(cc == 'f'){
				if(scroll > 1){
					scroll = scroll - 1;
				}
				TulisQ6(PQ, scroll, 6);
			}
			else if(cc == 'v'){
				if((scroll + 6) < Tail(PQ)){
					scroll = scroll + 1;
				}
				TulisQ6(PQ, scroll, 6);
			}else if (On == 1){//Tombol On, merekam semua jejak ke dalam stack
				X = GetEl(M, Px);
				if (!IsMemberStack(S, X)){
					Push(&S, X);
					arr[GetElmt(M, GetOrdinat(Px), GetAbsis(Px))].status = '=';
				}
				PrintXY(55, 17, ""); TulisStringKata(K);
			}else if (On == 0){
				i = 1;
				arr[GetElmt(M, GetOrdinat(Px), GetAbsis(Px))].status = ' ';
				while (Top(S) != NilS){
					arr[infotop(S)].status = ' ';
					Pop(&S, &A);
					Pop(&Sinverse, &A);
					K.TabKata[i] = arr[A].huruf;
					i++;
			}
			K.Length = i - 1;
			PrintXY(55, 17, ""); TulisStringKata(K);
			if(SearchKataT(T, K)){ //Melakukan Pencarian
				if(!IsMemberQ(PQ,K)){	
					PrintXY(55, 17, FontGreen);
					TulisStringKata(K);
					printf(Reset);
					InsertPlayerSugesti(&ListPlayer, ID, K, board);
					XQ.Score = HitungNilai(Map, K) * K.Length; //inisialisasi skor perkata
					if(K.Length > 9){
						XQ.Score += 100; //BONUS GAME
					}
					score += XQ.Score; //Memasukan Skor terbaru
					XQ.K = K; //Memasukan Kata terbaru
					AddPrioScore(&PQ, XQ); //Memasukan XQ ke Priority Queue
					memset(K.TabKata, 0, sizeof(K.TabKata));
					K.Length = 0;
				}else{
					PrintXY(55, 17, FontRed);
					TulisStringKata(K);
					printf(Reset);
				} if (aS != Nil){
					if (IsMemberQ(PQ, InfoSug(aS))){
						while ((aS != Nil) && (IsMemberQ(PQ, InfoSug(aS)))){
							aS = NextSug(aS);
						}
					}
				}
				TulisQ6(PQ, scroll, 6);
					}
				}
			PindahPOINT(&Px, cc);
				if (On == 1){
					X = GetEl(M, Px);
					if (IsMemberStack(S, X)){
						while (infotop(S) != X){
							arr[infotop(S)].status = ' ';
							Pop(&S, &A);
						}
						Pop(&S, &A);
					}
				}	
			TulisIsiMATRIKS(M, arr, Px);
		}
	} while (elapsed < WAKTU);
	MakeTime(&Tm);
	MakeDate(&Dd);
	Clear;
	PrintLayout();
	HideCursor;
	PrintXY(30, 15, FontBlue "TIME'S UP!!\n" Reset);
	PrintXY(21, 16, "╭───────────────────────────╮\n");
	PrintXY(21, 17, "│ Skor Anda :               │\n");
	PrintXY(21, 18, "│                           │\n");
	PrintXY(21, 19, "│                           │\n");
	PrintXY(21, 20, "╰───────────────────────────╯\n");
	PrintXY(35, 17, ""); printf("%d\n", score);
	PrintXY(23, 18, "Tanggal   : "); PrintDate(Dd);
	PrintXY(23, 19, "Pukul     : "); PrintTime(Tm);
	PrintXY(36, 26, "press [" FontYellow "enter" Reset "] to continue...\n");
	aC = InputScore(ID, score, Dd, Tm);
	
	InsertPlayerScore(&ListPlayer, ID, InfoScore(aC), board);
	Max.TabKata[1]='@';
	Max.TabKata[2]='@';
	Max.TabKata[3]='@';
	Max.Length=3;
	InsertPlayerScore(&ListPlayer, Max, InfoScore(aC), board);
	do{
		cc = getch();	
	} while (cc != '\n');
	resetTermios();
	MenuLogin();
}

void PlayDual(int board){
/* I.S. 			 */
/* F.S. 			 */
/* Proses: 			 */
	/* Kamus Lokal */
	time_t start, end;
	Stack S, S2, Sinverse, Sinverse2;
	PrioQueue PQ, PQ2;
	Map Map;
	MATRIKS M, M2;
	POINT Px, Px2;
	Date Dd;
	Time Tm;
	Kata K, K2, Max;
	addressPlayer aP;
	addressSug aS;
	addressScore aC;
	LSugesti ListSugesti;
	infotypeScore XQ, XQ2;
	int tRemain, elapsed, count, score, score2, On, On2, A, X, X2, i, i2, scroll, scroll2;
	char cc;
	
	/* Algoritma */
	initTermios();
	time(&start);
	CreateEmpty(&S);
	CreateEmpty(&Sinverse);
	CreateEmpty(&S2);
	CreateEmpty(&Sinverse2);
	CreateEmptyQ(&PQ,40);
	CreateEmptyQ(&PQ2,40);
	SetMap(&Map);
	SetArr(arr, board);
	SetMatriks(&M);
	SetArr(arr2, board);
	SetMatriks(&M2);
	aP = searchAddressPlayer(ListPlayer, ID);
	ListSugesti = PlayerLSugesti(aP, board);
	aS = FirstSug(ListSugesti);
	Px = MakePOINT(0,0);
	Px2 = MakePOINT(0,0);
	tRemain = WAKTU;
	On = 0;
	On2 = 0;
	scroll = 1;
	scroll2 = 1;
	score = 0;
	score2 = 0;
	memset(K.TabKata, 0, sizeof(K.TabKata));
	K.Length = 0;
	memset(K2.TabKata, 0, sizeof(K2.TabKata));
	K2.Length = 0;
	TulisIsiMATRIKSDual(M, M2, arr, arr2, Px, Px2);
	do{
		time(&end);
		elapsed = difftime(end, start);
		count = WAKTU - elapsed;
		if (count - tRemain == 0){
			Clear;
			HideCursor;
			PrintLayoutDual();
			PrintMatriksDual();
			PrintXY(38, 10, "│");
			PrintXY(38, 11, "╰────────────────────────────┤")
			PrintXY(97, 10, "│");
			PrintXY(68, 11, "├────────────────────────────╯")
			PrintXY(41 + (15 - ID.Length) / 2, 10, "User #1 : " FontGreen);
			TulisStringKata(ID);
			printf(Reset);
			PrintXY(70 + (15 - ID2.Length) / 2, 10, "User #2 : " FontGreen);
			TulisStringKata(ID2);
			printf(Reset);
			PrintXY(41, 12, FontBlue Bold "SCORE");
			PrintXY(89, 12, FontBlue Bold "SCORE");
			PrintXY(63, 12, "Time Left");
			PrintXY(39, 16, "CURRENT WORDS"); 
			PrintXY(84, 16, "CURRENT WORDS"); 
			PrintXY(39, 17, ""); TulisStringKata(K);
			PrintXY(81 + (16 - K2.Length), 17, ""); TulisStringKata(K2);
			PrintXY(43, 13, ""); printf("%d", score);
			PrintXY(91, 13, ""); printf("%d", score2);
			PrintXY(63, 13, "");
			if (elapsed >= (WAKTU - 10)){
				printf(FontRed);
			} else if (elapsed >= (WAKTU - 30)){
				printf(FontYellow);
			}
			printf("[%.02d : %.02d]" Reset, tRemain / 60, tRemain % 60);
			TulisIsiMATRIKSDual(M, M2, arr, arr2, Px, Px2);
			tRemain--;
		}
		if(kbhit()){
			cc = getch();
			if ((cc == 's') && (On == 0)){ //Tombol Mulai On
				On = 1;
			}else if ((cc == 's') && (On == 1)){//Tombol Off, Menyiapkan Stack untuk d verifikasi
				On = 0;
				if (!IsMemberStack(S, X)){
					Push(&S, X);
					arr[GetElmt(M, GetOrdinat(Px), GetAbsis(Px))].status = ' ';
				}
				Sinverse = InverseStack(S);
			}
			if ((cc == 'h') && (On2 == 0)){ //Tombol Mulai On
				On2 = 1;
			}else if ((cc == 'h') && (On2 == 1)){//Tombol Off, Menyiapkan Stack untuk d verifikasi
				On2 = 0;
				if (!IsMemberStack(S2, X2)){
					Push(&S2, X2);
					arr2[GetElmt(M2, GetOrdinat(Px2), GetAbsis(Px2))].status = ' ';
				}
				Sinverse2 = InverseStack(S2);
			}	
			if (cc == 'i'){ //ROTATE BOARD
				X2 = GetEl(M2, Px2);
				PutarMATRIKS(&M2);
				GetPoint(X2, M2, &Px2);
			}
			else if (On2 == 1){//Tombol On, merekam semua jejak ke dalam stack
				X2 = GetEl(M2, Px2);
				if (!IsMemberStack(S2, X2)){
					Push(&S2, X2);
					arr2[GetElmt(M2, GetOrdinat(Px2), GetAbsis(Px2))].status = '=';
				}
				PrintXY(81 + (16 - K2.Length), 17, ""); TulisStringKata(K2);
			}else if (On2 == 0){
				i2 = 1;
				arr2[GetElmt(M2, GetOrdinat(Px2), GetAbsis(Px2))].status = ' ';
				while (Top(S2) != NilS){
					arr2[infotop(S2)].status = ' ';
					Pop(&S2, &A);
					Pop(&Sinverse2, &A);
					K2.TabKata[i2] = arr2[A].huruf;
					i2++;
				}
				K2.Length = i2 - 1;
				PrintXY(81 + (16 - K2.Length), 17, ""); TulisStringKata(K2);
				if(SearchKataT(T, K2)){ //Melakukan Pencarian
					if(!IsMemberQ(PQ2,K2)){	
						PrintXY(81 + (16 - K2.Length), 17, FontGreen);
						TulisStringKata(K2);
						printf(Reset);
						XQ2.Score = HitungNilai(Map, K2) * K2.Length; //inisialisasi skor perkata
						if(K2.Length > 9){
							XQ2.Score += 100; //BONUS GAME
						}
						score2 += XQ2.Score; //Memasukan Skor terbaru
						XQ2.K = K2; //Memasukan Kata terbaru
						AddPrioScore(&PQ2, XQ2); //Memasukan XQ ke Priority Queue
						memset(K2.TabKata, 0, sizeof(K2.TabKata));
						K2.Length = 0;
					}else{
						PrintXY(81 + (16 - K2.Length), 17, FontRed);
						TulisStringKata(K2);
						printf(Reset);
					}
				}
			}
			if (cc == 'r'){ //ROTATE BOARD
				X = GetEl(M, Px);
				PutarMATRIKS(&M);
				GetPoint(X,M, &Px);
			}
			else if (On == 1){//Tombol On, merekam semua jejak ke dalam stack
				X = GetEl(M, Px);
				if (!IsMemberStack(S, X)){
					Push(&S, X);
					arr[GetElmt(M, GetOrdinat(Px), GetAbsis(Px))].status = '=';
				}
				PrintXY(55, 17, ""); TulisStringKata(K);
			}else if (On == 0){
				i = 1;
				arr[GetElmt(M, GetOrdinat(Px), GetAbsis(Px))].status = ' ';
				while (Top(S) != NilS){
					arr[infotop(S)].status = ' ';
					Pop(&S, &A);
					Pop(&Sinverse, &A);
					K.TabKata[i] = arr[A].huruf;
					i++;
				}
				K.Length = i - 1;
				PrintXY(39, 17, ""); TulisStringKata(K);
				if(SearchKataT(T, K)){ //Melakukan Pencarian
					if(!IsMemberQ(PQ,K)){	
						PrintXY(39, 17, FontGreen);
						TulisStringKata(K);
						printf(Reset);
						XQ.Score = HitungNilai(Map, K) * K.Length; //inisialisasi skor perkata
						if(K.Length > 9){
							XQ.Score += 100; //BONUS GAME
						}
						score += XQ.Score; //Memasukan Skor terbaru
						XQ.K = K; //Memasukan Kata terbaru
						AddPrioScore(&PQ, XQ); //Memasukan XQ ke Priority Queue
						memset(K.TabKata, 0, sizeof(K.TabKata));
						K.Length = 0;
					}else{
						PrintXY(39, 17, FontRed);
						TulisStringKata(K);
						printf(Reset);
					}
				}			
			}
			PindahPOINTDual(&Px, &Px2, cc);
			if (On == 1){
				X = GetEl(M, Px);
				if (IsMemberStack(S, X)){
					while (infotop(S) != X){
						arr[infotop(S)].status = ' ';
						Pop(&S, &A);
					}
					Pop(&S, &A);
				}
			}	
			if (On2 == 1){
				X2 = GetEl(M2, Px2);
				if (IsMemberStack(S2, X2)){
					while (infotop(S2) != X2){
						arr2[infotop(S2)].status = ' ';
						Pop(&S2, &A);
					}
					Pop(&S2, &A);
				}
			}	
			TulisIsiMATRIKSDual(M, M2, arr, arr2, Px, Px2);
		}
	} while (elapsed < WAKTU);
	MakeTime(&Tm);
	MakeDate(&Dd);
	Clear;
	HideCursor;
	
	if (score > score2){
		PrintXY(97, 15, FontBlue "CUPS!!!\n" Reset);
		PrintXY(32, 15, FontBlue "SABI!!!\n" Reset);
	} else if (score < score2){
		PrintXY(32, 15, FontBlue "CUPS!!!\n" Reset);
		PrintXY(97, 15, FontBlue "SABI!!!\n" Reset);
	} else{
		PrintXY(30, 15, FontBlue "TIME'S UP!!\n" Reset);
		PrintXY(95, 15, FontBlue "TIME'S UP!!\n" Reset);
	}
	
	PrintXY(21, 16, "╭───────────────────────────╮\n");
	PrintXY(21, 17, "│ Skor Anda :               │\n");
	PrintXY(21, 18, "│                           │\n");
	PrintXY(21, 19, "│                           │\n");
	PrintXY(21, 20, "╰───────────────────────────╯\n");
	PrintXY(35, 17, ""); printf("%d\n", score);
	PrintXY(23, 18, "Tanggal   : "); PrintDate(Dd);
	PrintXY(23, 19, "Pukul     : "); PrintTime(Tm);
	PrintXY(54, 26, "press [" FontYellow "enter" Reset "] to continue...\n");
	aC = InputScore(ID, score, Dd, Tm);
	InsertPlayerScore(&ListPlayer, ID, InfoScore(aC), board);

	Max.TabKata[1]='@';
	Max.TabKata[2]='@';
	Max.TabKata[3]='@';
	Max.Length=3;
	InsertPlayerScore(&ListPlayer, Max, InfoScore(aC), board);

	PrintXY(86, 16, "╭───────────────────────────╮\n");
	PrintXY(86, 17, "│ Skor Anda :               │\n");
	PrintXY(86, 18, "│                           │\n");
	PrintXY(86, 19, "│                           │\n");
	PrintXY(86, 20, "╰───────────────────────────╯\n");
	PrintXY(100, 17, ""); printf("%d\n", score2);
	PrintXY(88, 18, "Tanggal   : "); PrintDate(Dd);
	PrintXY(88, 19, "Pukul     : "); PrintTime(Tm);
	aC = InputScore(ID2, score2, Dd, Tm);
	InsertPlayerScore(&ListPlayer, ID2, InfoScore(aC), board);
	InsertPlayerScore(&ListPlayer, Max, InfoScore(aC), board);

	PrintLayoutDual();
	do{
		cc = getch();	
	} while (cc != '\n');
	resetTermios();
	IDstat = 0;
	ResizeTerminal;
	MenuLogin();
}