//Nicholas Petersen

#include <stdio.h>

int main()
{
					//Array items are each given a reserved space in memory
					//another location in memory will point to that area and be temp
	int temp[7]; 	//7 is the array size
	for(int x=0; x<7; x++)
	{
		printf("Enter a temperature: ");
		scanf("%d", &temp[x]);
	}
	
	for(int x=0; x<20; x++)
	{
		printf("\nThe temp is %d", temp[x]);
	}
	
	
	return 0;
}
