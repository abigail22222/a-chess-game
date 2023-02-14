//游戏相关函数的实现
#include "game.h"  //因为有宏,还有许多头文件可以打包放里面


void Initialboard(char board[ROW][COLUMN], int row, int column)
{
	int i = 0,j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COLUMN; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void Printboard(char board[ROW][COLUMN], int row, int column)
{
	int i,j;
	for (i = 0; i < column; i++)
	{
		printf("---");
		if (i < column - 1)
		{
			printf("|");
		}
	}
	printf("\n");
	
	for (i = 0; i < row; i++)
	{
		//棋盘的内容和竖分割线
		for (j = 0; j < column; j++)//在第i行的第j个
		{
			printf(" %c ", board[i][j]);
			if (j < column - 1)
			{
				printf("|");
			}	  
		}
		printf("\n");
		//棋盘的横分界线和竖分界线
		for (j = 0; j < column; j++)//在第i行的第j个
		{
			printf("---");
			if (j < column - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		
	}
	
}

void Playermove(char board[][COLUMN], int row, int column)
{
	

	//判断是否是合法的坐标，用循环
	//如果是合法坐标，还要判断坐标是否被占用了
	while (1)
	{
		int x, y;
		printf("玩家请下棋：");
		scanf_s("%d %d", &x, &y);
		if (x >= column - 2 && x <= column && y >= row - 2 && y <= row)
		{
			//坐标合法
			if (board[y-1][x-1] == ' ')
			{
				//坐标未被占用
				board[y-1][x-1] = '*';
				Printboard(board, row, column);//Playmove已经把row和column的值传进来了
				break;
			}
			else
			{
				//坐标被占用
				printf("你已经下过这里了，换一个格子吧。\n");
			}

		}
		else 
		{
			//坐标不合法
			printf("不在棋盘范围内，请重新输入。\n");
		}
	}
}

void Computermove(char board[][COLUMN], int row, int column)
{
	//规定下棋范围
	//判断坐标是否被占用
	printf("电脑下棋：\n");
	
	while (1)
	{
		int x = rand() % 3;
		int y = rand() % 3;
		if (board[y][x] == ' ')
		{
			board[y][x] = '#';
			Printboard(board, row, column);
			break;
		}
		else
		{
			//坐标被占用
		}
	}
	
}

char Iswin(char board[][COLUMN], int row, int column)
{
	int i, j;//i是第i行，j是第i行的第j个
	int rencnt = 0;
	int jicnt = 0;
	//检查行
	for (i = 0; i < row; i++)
	{
		rencnt = jicnt = 0;  //在这里防止因为换行了才继续加到column的值
		for (j = 0; j < column; j++)
		{
			if (board[i][j] == '*')
			{
				rencnt++;
				if (rencnt == column)  
				{
					return '*';
				}				
			}
			else if (board[i][j] == '#')
			{
				jicnt++;
				if (jicnt == column)
				{
					return '#';
				}
			}
		}
	}

	//检查列
	for (j = 0; j < column; j++)
	{
		rencnt=jicnt= 0;  //在这里防止因为换行了才继续加到column的值
		for (i = 0; i < row; i++)
		{
			if (board[i][j] == '*')
			{
				rencnt++;
				if (rencnt == row)
				{
					return '*';
				}
			}
			else if (board[i][j] == '#')
			{
				jicnt++;
				if (jicnt == row)
				{
					return '#';
				}
			}
		}
	}

	//检查对角线 正方形才会有对角线，row=column
	rencnt = jicnt = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][i] == '*')
		{
			rencnt++;
		}
		else if(board[i][i]=='#')
		{
			jicnt++;
		}

		if (rencnt == row)
		{
			return '*';
		}
		else if (jicnt == row)
		{
			return '#';
		}
	}

	rencnt = jicnt = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][column - 1 - i] == '*')
		{
			rencnt++;
		}
		else if (board[i][column - 1 - i] == '#')
		{
			jicnt++;
		}


		if (rencnt == row)
		{
			return '*';
		}
		else if (jicnt == row)
		{
			return '#';
		}
	}

	//检查是否满了
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			if (board[i][j] == ' ')
			{
				return 'c'; //没有满
			}
		}
	}

	return 'Q';//满了



}