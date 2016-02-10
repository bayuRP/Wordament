#!/bin/bash
_script="$(readlink -f ${BASH_SOURCE[0]})"
_base="$(dirname $_script)"
cd $_base

gcc main.c function.c graphic.c ADT/Matriks/Matriks.c ADT/MesinKata/mesinkata.c\
	ADT/MesinKarakterBoard/mesinkarboard.c ADT/Waktu/adtwaktu.c ADT/Point/point.c\
	ADT/Stack/stack.c ADT/ADTPriorityQueue/queue.c ADT/MapNilai/mapnilai.c\
	ADT/Tree/tree.c ADT/ListPlayer/listplayer.c ADT/ListPlayer/listscore.c\
	ADT/ListPlayer/listsugesti.c ADT/FileIO/BTeksternal.c\
	-o Wordament

if gcc main.c function.c graphic.c ADT/Matriks/Matriks.c ADT/MesinKata/mesinkata.c\
	ADT/MesinKarakterBoard/mesinkarboard.c ADT/Waktu/adtwaktu.c ADT/Point/point.c\
	ADT/Stack/stack.c ADT/ADTPriorityQueue/queue.c ADT/MapNilai/mapnilai.c\
	ADT/Tree/tree.c ADT/ListPlayer/listplayer.c ADT/ListPlayer/listscore.c\
	ADT/ListPlayer/listsugesti.c ADT/FileIO/BTeksternal.c\
	-o Wordament; then 
./Wordament
fi
