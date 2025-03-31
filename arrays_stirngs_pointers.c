//Nicholas Petersen

#include <stdio.h>

void update(int numbers[], int value);
void print(int *numbers);

int main()
{
	int numbers[5] = {10, 20, 30, 40, 50};
	int value = 55;
	
	update(numbers, value);
	
	print(numbers);
	printf("\nValue is %d", value);
	
	return 0;
}

void update(int numbers[], int value)
{
	numbers[0] = 15;
	numbers[1] = 25;
	numbers[2] = 35;
	numbers[3] = 45;
	numbers[4] = 55;
	
	value = 88;
}

void print(int *numbers)
{
	for(int x=0; x<5; x++)
	{
		//printf("%d  ", numbers[x]);		subscript notation
		//printf("%d  ", *(numbers+x));		pointer notation
		printf("%d  ", *numbers++);			//pointer arithmetic
	}
}
