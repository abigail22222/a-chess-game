#pragma once
//������Ϸ��صĺ�������������������ͷ�ļ��İ���

//ͷ�ļ��İ���
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//��������
#define ROW 3
#define COLUMN 3

//��������
void Initialboard(char board[ROW][COLUMN], int row, int column) ;

void Printboard(char board[ROW][COLUMN], int row, int column);

void Playermove(char board[][COLUMN], int row, int column);

void Computermove(char board[][COLUMN], int row, int column);

char Iswin(char board[][COLUMN], int row, int column);
/*
  Iswin�ķ���ֵ����
	return '*'�����Ӯ
	return '#'�ǵ���Ӯ
	return 'Q'��ƽ�֣����ˣ�
	return 'c'����Ϸ����
*/