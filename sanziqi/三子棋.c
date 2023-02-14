//������Ϸ���߼�
#include "game.h"

void menu()
{
	printf("***********************************\n");
	printf("***********************************\n");
	printf("***********************************\n");
	printf("***********   1.play    ***********\n");
	printf("***********   ������    ***********\n");
	printf("***********   0.exit    ***********\n");
	printf("***********************************\n");
	printf("***********************************\n");
	printf("***********************************\n");
}

void game()
{
	char board[ROW][COLUMN];
	//��ʼ������
	Initialboard(board, ROW, COLUMN);
	//��ӡ����
    Printboard(board,ROW,COLUMN);

	char ret;
	while(1)
	{
		//�������
		Playermove(board, ROW, COLUMN);
		//�ж���Ӯ
		ret=Iswin(board, ROW, COLUMN);
		if (ret != 'c')
		{
			break;
		}

		//��������
		Computermove(board, ROW, COLUMN);
		//�ж���Ӯ
		ret = Iswin(board, ROW, COLUMN);
		if (ret != 'c')
		{
			break;
		}

	}
	if (ret == '*')
	{
		printf("��ϲ��Ӯ������\n");
	}else if (ret == '#')
	{
		printf("̫�˿����俩\n");
	}else if (ret == 'Q')
	{
		printf("�����ִ�ƽ��\n");
	}
	Printboard(board, ROW, COLUMN);

}

int main()
{
	srand((unsigned int)time(NULL));
	int input=0;
	
	do
	{
		menu();
		printf("��ѡ��");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("play\n");
			game();
			break;
		case 0:
			printf("exit the game\n");
			break;
		default:
			printf("error,please choose the number again\n");
			break;
		}

	} while (input); //1 0�߼�
	return 0;
}