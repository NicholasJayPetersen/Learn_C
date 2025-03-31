//Nicholas Petersen

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void displayBoard(char *board[][3]);
void selectLocation(char *choice, int turn, int players, char *board[][3]);
void setTurn(char *board[][3], char *choice, int *turn, int *turnCount);
void checkForWin(char *board[][3], bool *gameOver, int *turnCount);

int main()
{
	
	char *board[3][3] = {{"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"}};
	char choice[3], playAgain = 'y';
	int turn = 1, turnCount = 0, players;
	printf("Tic Tac Toe!");
	
	bool gameOver = false;
	while(playAgain == 'y' || playAgain == 'Y')
	{
		printf("One or two players?(1/2): ");
		scanf("%d", &players);
		while(!gameOver)
		{	
			displayBoard(board);
			selectLocation(choice, turn, players, board);
			setTurn(board, choice, &turn, &turnCount);
			checkForWin(board, &gameOver, &turnCount);	
		}
		
		printf("\nWould you like to play agian?(y/n): ");
		scanf("\n%c", &playAgain);
	}
	
	return 0;
}

void displayBoard(char *board[][3])
{
	for(int x=0; x<3; x++)
	{
		printf("\n\n");
		for(int y=0; y<3; y++)
			printf("%s	", board[x][y]);
	}	
}

void selectLocation(char *choice, int turn, int players, char *board[][3])
{
	char index[3][3][3] = {{"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"}};
	
	printf("\n\nPlayer %d's turn!\nWhere would you like to place your mark?: ", turn);
	if(turn == 1)
	{
		scanf("\n%s", choice);	
	}
	else if (players == 1 && turn == 2)
	{
		
		srand(time(NULL));
		int random = (rand() % 10) + 1;
		sprintf(choice, "%d", random);
		printf("\nThinking.....");
		sleep(2);
		
		while(true)
			for(int x=0; x<3; x++)
				for(int y=0; y<3; y++)
					if(strcmp(index[x][y], choice) == 0)
					{
						if(strcmp(board[x][y], "X") == 0 || strcmp(board[x][y], "O") == 0 )
						{
							random = (rand() % 10) + 1;
							sprintf(choice, "%d", random);
						}
						else
							return;
					}
	}
	
}

void setTurn(char *board[][3], char *choice, int *turn, int *turnCount)
{
	for(int x=0; x<3; x++)
		for(int y=0; y<3; y++)
			if(strcmp(board[x][y], choice) == 0)
			{
				switch(*turn)
				{
					case 1: board[x][y] = "X"; *turn = 2; break;
					case 2: board[x][y] = "O"; *turn = 1; break;
				}
			}
	(*turnCount)++;
}

void checkForWin(char *board[][3], bool *gameOver, int *turnCount)
{
	
	if(*turnCount >= 9)
	{
		*gameOver = true;
		printf("\n Its a draw!");
		return;
	}
	
	char winningCombos[8][3][2] = {{{0,0}, {1,0}, {2,0}},
								{{0,1}, {1,1}, {2,1}},
								{{0,2}, {1,2}, {2,2}},
								{{0,0}, {0,1}, {0,2}},
								{{1,0}, {1,1}, {1,2}},
								{{2,0}, {2,1}, {2,2}},
								{{0,0}, {1,1}, {2,2}},
								{{0,2}, {1,1}, {2,0}}};
									

	for(int a=0; a<8; a++)
	{
		int xCount = 0;	
		int oCount = 0;
		
		for(int b=0; b<3; b++)
		{
			
			if((strcmp(board[winningCombos[a][b][0]][winningCombos[a][b][1]], "X") == 0))
				xCount++;
				
			if((strcmp(board[winningCombos[a][b][0]][winningCombos[a][b][1]], "O") == 0))
				oCount++;
				
			if(xCount == 3)
			{
				*gameOver = true;
				printf("\nPlayer 1 wins!");
				return;
			}
			if(oCount == 3)
				{
					*gameOver = true;
					printf("\nPlayer 2 wins!");
					return;
				}
		}
	}
}
