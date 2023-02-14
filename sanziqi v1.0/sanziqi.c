//��Ϸ��غ�����ʵ��
#include "game.h"  //��Ϊ�к�,�������ͷ�ļ����Դ��������


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
		//���̵����ݺ����ָ���
		for (j = 0; j < column; j++)//�ڵ�i�еĵ�j��
		{
			printf(" %c ", board[i][j]);
			if (j < column - 1)
			{
				printf("|");
			}	  
		}
		printf("\n");
		//���̵ĺ�ֽ��ߺ����ֽ���
		for (j = 0; j < column; j++)//�ڵ�i�еĵ�j��
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
	

	//�ж��Ƿ��ǺϷ������꣬��ѭ��
	//����ǺϷ����꣬��Ҫ�ж������Ƿ�ռ����
	while (1)
	{
		int x, y;
		printf("��������壺");
		scanf_s("%d %d", &x, &y);
		if (x >= column - 2 && x <= column && y >= row - 2 && y <= row)
		{
			//����Ϸ�
			if (board[y-1][x-1] == ' ')
			{
				//����δ��ռ��
				board[y-1][x-1] = '*';
				Printboard(board, row, column);//Playmove�Ѿ���row��column��ֵ��������
				break;
			}
			else
			{
				//���걻ռ��
				printf("���Ѿ��¹������ˣ���һ�����Ӱɡ�\n");
			}

		}
		else 
		{
			//���겻�Ϸ�
			printf("�������̷�Χ�ڣ����������롣\n");
		}
	}
}

void Computermove(char board[][COLUMN], int row, int column)
{
	//�涨���巶Χ
	//�ж������Ƿ�ռ��
	printf("�������壺\n");
	
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
			//���걻ռ��
		}
	}
	
}

char Iswin(char board[][COLUMN], int row, int column)
{
	int i, j;//i�ǵ�i�У�j�ǵ�i�еĵ�j��
	int rencnt = 0;
	int jicnt = 0;
	//�����
	for (i = 0; i < row; i++)
	{
		rencnt = jicnt = 0;  //�������ֹ��Ϊ�����˲ż����ӵ�column��ֵ
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

	//�����
	for (j = 0; j < column; j++)
	{
		rencnt=jicnt= 0;  //�������ֹ��Ϊ�����˲ż����ӵ�column��ֵ
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

	//���Խ��� �����βŻ��жԽ��ߣ�row=column
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

	//����Ƿ�����
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			if (board[i][j] == ' ')
			{
				return 'c'; //û����
			}
		}
	}

	return 'Q';//����



}