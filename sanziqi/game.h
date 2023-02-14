#pragma once
//关于游戏相关的函数声明，符号声明，头文件的包含

//头文件的包含
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//符号声明
#define ROW 3
#define COLUMN 3

//函数声明
void Initialboard(char board[ROW][COLUMN], int row, int column) ;

void Printboard(char board[ROW][COLUMN], int row, int column);

void Playermove(char board[][COLUMN], int row, int column);

void Computermove(char board[][COLUMN], int row, int column);

char Iswin(char board[][COLUMN], int row, int column);
/*
  Iswin的返回值代表：
	return '*'是玩家赢
	return '#'是电脑赢
	return 'Q'是平局（满了）
	return 'c'是游戏继续
*/