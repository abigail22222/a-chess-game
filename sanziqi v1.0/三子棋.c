//≤‚ ‘”Œœ∑µƒ¬ﬂº≠
#include "game.h"

void menu()
{
	printf("***********************************\n");
	printf("***********************************\n");
	printf("***********************************\n");
	printf("***********   1.play    ***********\n");
	printf("***********   »˝◊”∆Â    ***********\n");
	printf("***********   0.exit    ***********\n");
	printf("***********************************\n");
	printf("***********************************\n");
	printf("***********************************\n");
}

void game()
{
	char board[ROW][COLUMN];
	//≥ı ºªØ∆Â≈Ã
	Initialboard(board, ROW, COLUMN);
	//¥Ú”°∆Â≈Ã
    Printboard(board,ROW,COLUMN);

	char ret;
	while(1)
	{
		//ÕÊº“œ¬∆Â
		Playermove(board, ROW, COLUMN);
		//≈–∂œ ‰”Æ
		ret=Iswin(board, ROW, COLUMN);
		if (ret != 'c')
		{
			break;
		}

		//µÁƒ‘œ¬∆Â
		Computermove(board, ROW, COLUMN);
		//≈–∂œ ‰”Æ
		ret = Iswin(board, ROW, COLUMN);
		if (ret != 'c')
		{
			break;
		}

	}
	if (ret == '*')
	{
		printf("πßœ≤ƒ„”Æ¿≤£°£°\n");
	}else if (ret == '#')
	{
		printf("Ã´≤Àø©ƒ„ ‰ø©\n");
	}else if (ret == 'Q')
	{
		printf("∆Â∑Í∂‘ ÷¥Ú∆Ω¡À\n");
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
		printf("«Î—°‘Ò£∫");
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

	} while (input); //1 0¬ﬂº≠
	return 0;
}