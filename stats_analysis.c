//Nicholas Petersen

#include <stdio.h>
#include <stdbool.h>
#define MAX 10

int* getData();
int getChoice();
void displayData(int statsArray[]);
int displayLargest(int statsArray[]);
int displaySmallest(int statsArray[]);
float displayAverage(int statsArray[]);
int displayRange(int statsArray[]);
float displayMedian(int statsArray[]);
int displayMode(int statsArray[]);
int displayMode(int statsArray[]);

int main()
{
	printf("Statistics Calculator");
	int* statsArray = getData();
	
	bool quit = false;
	while(!quit)
		switch (getChoice())
		{
			case 0:
				displayData(statsArray);
				break;
			case 1:
				printf("The Max is: %d\n", displayLargest(statsArray));
				break;
			case 2:
				printf("The Min is: %d\n", displaySmallest(statsArray));
				break;
			case 3:
				printf("The average is: %.2f", displayAverage(statsArray));
				break;
			case 4:
				printf("The Range is: %d", displayRange(statsArray));
				break;
			case 5:
				printf("The Median is: %.2f", displayMedian(statsArray));
			case 6:
				displayMode(statsArray);
				break;
			default:
				printf("\n\nThank you for using the Statistics Calculator!");
				quit = true;
		}
	 
	return 0;
}

int* getData()
{
	static int statsArray[MAX]; //static allows the array to persist after the function finishes
	printf("\nPlease enter 10 numbers.\n");
	
	for(int x=0; x<MAX; x++)
	{
		printf("Number %d: ", x+1);
		scanf("%d", &statsArray[x]);
	}
	
	return statsArray; //returns only the pointer because of int*
}

int getChoice()
{
	int choice;
	printf("\n\nChoose an option:"
			"\n0 - Show Numbers"
			"\n1 - Find Max"
			"\n2 - Find Min"
			"\n3 - Find Average"
			"\n4 - Find Range"
			"\n5 - Find Median"
			"\n6 - Find Mode(s)"
			"\nChoose any other key to exit."
			"\n\nChoice: ");
	scanf("%d", &choice);
	
	return choice;
}

void displayData(int statsArray[])
{
	printf("\nCurrent array values:");
	for(int x=0; x<MAX; x++)
		printf("\nNumber %d: %d", x+1, statsArray[x]);
}

int displayLargest(int statsArray[])
{
	int largest = statsArray[0];
	
	//compares each number in the array
	for(int x =0; x<MAX-1; x++)
	{
		//compares this number to the next number and stores the larger one
		if(largest > statsArray[x+1])
			largest = statsArray[x];
		else
			largest = statsArray[x+1];
	}
	
	return largest;
}

int displaySmallest(int statsArray[])
{
	int smallest = statsArray[0];
	
	//compares each number in the array
	for(int x=0; x<MAX-1; x++)
	{
		//compares this number to the next number and stores the smaller one
		if(smallest < statsArray[x+1])
			continue;
		else
			smallest = statsArray[x+1];
	}
	
	return smallest;
}

float displayAverage(int statsArray[])
{
	float average;
	int sum = 0;
	
	//adds each number in the array
	for(int x=0; x<MAX; x++)
		sum += statsArray[x];
	
	return sum/MAX; //divides by number of elements in array and sends it back.
}

int displayRange(int statsArray[])
{
	int max = displayLargest(statsArray); //gets max number
	int min = displaySmallest(statsArray); //gets min number
	
	return max-min; //range is difference between the two
}

float displayMedian(int statsArray[])
{	
	//finds median depending on odd or even amount of numbers
	if(MAX % 2 != 0)
		return statsArray[(MAX/2)-1]; //when numbers are odd, return middle number
	else
		return (statsArray[(MAX/2)] + statsArray[(MAX/2)]-1) / 2.0; //when numbers are even return average of the two middles.
}

int displayMode(int statsArray[])
{
	int count = 0;
	int dupes[MAX];
	int mode[MAX];
	
	//This nested loop will find any duplicates in the array using a counter
	for(int x=0; x<MAX-1; x++)
	{
		for(int y=0; y<MAX-1; y++)
		{
			if(statsArray[x] == statsArray[y])
			count++;    //if a duplicate is found add to the count
		}
		
		if(count > 1)  //greater than one to make up for it counting itself
		{
			dupes[x] = statsArray[x]; //adds to the dupes array if 2 or more occurences
		}
		else
			dupes[x] = 0;
		
		count = 0;
	}

	//stores multiple occurences modes[] while ignoring the zeros in dupes[]
	for(int x=0; x<MAX-1; x++)
	{
		if(dupes[x] != 0 && dupes[x])
		{
			mode[count] = dupes[x];
			count++;	
		}		
	}
	
	//iterates through modes[] and prints each unique number once
	printf("\nModes: ");
	for(int x=0; x<count; x++)
	{
		//checks to see if a number has already been printed. If not it prints the number.
		int checkIfPrinted = false;
		for(int y=0; y<x; y++)
		{
			if(mode[x] == mode[y])
			{
				checkIfPrinted = true;
				break;	
			}
		}
		
		if(!checkIfPrinted)
			printf("%d  ", mode[x]);
	}
}
