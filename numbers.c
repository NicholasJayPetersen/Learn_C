//Nicholas Petersen

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void playLevel(int level, int *guessPtr);
int spinWheel(int *winningNumberPtr);
int determineLevelUp(int winningNumber, int *level, int guess, int *hp);

int main()
{
	int guess, winningNumber, level = 1, hp = 50;
	srand(time(NULL));
	
	printf("Number Guessing Game");
	printf("\n\nStarting Health: %d", hp);
	
	while(level < 4)
	{
		playLevel(level, &guess);
		spinWheel(&winningNumber);
		determineLevelUp(winningNumber, &level, guess, &hp);
		printf("\nThe number was: %d", winningNumber);
		printf("\nRemaining Health: %d", hp);
		if(hp < 1)
			break;
	}
	
	if(level == 4)
		printf("\nYou win! Thanks for playing!");
	else
		printf("\nGame Over! Try again...");
		
	return 0;
}

void playLevel(int level, int *guessPtr)
{	
	if(level == 1)
	{
		printf("\nLevel 1:  Choose odd(1) or even(2): ");
		scanf("%d", guessPtr);
		
		while(*guessPtr != 1 && *guessPtr != 2)
		{
			printf("\nINVALID CHOICE: Please enter 1 or 2...");
			printf("\nLevel 1:  Choose odd(1) or even(2): ");
			scanf("%d", guessPtr);
		}
	}
	else if(level == 2)
	{
		printf("\nFind the dozen (1st, 2nd or 3rd) ->(1-12) or (13-24) or (25-36) Zero does not count and results in a loss: ");
		scanf("%d", guessPtr);	
		
		while(*guessPtr != 1 && *guessPtr != 2 && *guessPtr != 3)
		{
			printf("\nINVALID CHOICE: Please enter 1, 2, or 3...");
			printf("\nFind the dozen (1st, 2nd or 3rd) ->(1-12) or (13-24) or (25-36) Zero does not count and results in a loss: ");
			scanf("%d", guessPtr);
		}
	}	
	else
	{
		printf("\nChoose the number (0-36): ");
		scanf("%d", guessPtr);
		
		while(*guessPtr < 0 || *guessPtr > 36)
		{
			printf("\nINVALID CHOICE: Please enter a number between 0 and 36...");
			printf("\nChoose the number (0-36): ");
			scanf("%d", guessPtr);
		}
	}
}

int spinWheel(int *winningNumberPtr)
{
	*winningNumberPtr = rand() % 37;
}

int determineLevelUp(int winningNumber, int *levelPtr, int guess, int *hpPtr)
{
	if(*levelPtr == 1)
	{
		if((guess == 1 && winningNumber % 2 == 0) || (guess == 2 && winningNumber % 2 != 0))
			{
				printf("\nYou got it!");
				*levelPtr = 2;
			}	
		else
		{
			printf("\nWrong! You took 2 damage!\n");
			*hpPtr -= 2;
		}	
	}
	else if (*levelPtr == 2)
	{
		if((guess == 1 && winningNumber <= 12) ||
		   (guess == 2 && (winningNumber > 12 && winningNumber < 25)) ||
		   (guess == 3 && (winningNumber >= 5 && winningNumber < 37)))
			{
				printf("\nYou got it!");
				*levelPtr = 3;
			}
		else
		{
			printf("\nWrong! You took 5 damage!\n");
			*hpPtr -= 5;
			*levelPtr = 1;
		}
	}
	else if (*levelPtr ==3)
	{
		if(guess == winningNumber)
			{
				printf("\nYou got it!");
				*levelPtr = 4;
			}
		else
		{
			if(abs(guess - winningNumber) <= 5)
			{
				printf("\nWrong! You took 3 damage!\n");
				*hpPtr -= 3;
			}
			else if(abs(guess - winningNumber) <= 10)
			{
				printf("\nWrong! You took 6 damage!\n");
				*hpPtr -= 6;	
			}
			else
			{
				printf("\nWrong! You took 9 damage!\n");
				*levelPtr = 2;
				*hpPtr -= 9;
			}
		}
	}
}
