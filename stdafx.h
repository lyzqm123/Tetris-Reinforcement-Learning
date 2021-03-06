// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once
#include <cstdio>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include <random>
#include <functional>
#include "Tetris.h"
using namespace std;

#define LIMIT_SCORE 5000
#define GAME_VELOCITY 0.33355555
#define DIFFICULTY_WEIGHT 0.02
#define PLUS_SCORE 100
#define BLINK_VELOCITY 100

#define LEFT 75 
#define RIGHT 77 
#define UP 72
#define DOWN 80 
#define SPACE 32 
const int dy[] = { 0,0,1 };
const int dx[] = { -1,1,0 };
inline void goCursor(int y, int x) {
	COORD pos = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
inline int GetRandomData(int l, int r) {
	random_device rd;
	mt19937 engine(rd());
	uniform_int_distribution<int> distribution(l, r);
	auto getdata = bind(distribution, engine);
	return getdata();
}