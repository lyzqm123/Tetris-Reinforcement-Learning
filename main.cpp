// Tetris Reinforcement Learning.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
int main(){
	//커서 깜빡임 없앰
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo); 
	FILE *tetris_log = fopen("tetris_log.txt", "w");
	int test = 1;
	while (1) {
		goCursor(0, 46); printf("<Test Count> : %d", test);
		Tetris *tetris = new Tetris();
		int score = tetris->start();
		fprintf(tetris_log, "<%d> - score : %d\n", test++, score);
		delete tetris;
	}
    return 0;
}

