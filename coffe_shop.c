//Nicholas Petersen

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void orderCoffee(char *orders, int *itemCountPtr);
void displayOrder(char orders[99][4][10], int itemCount);

int main()
{
	char orders[99][4][10];
	int itemCount = 0;
	
	orderCoffee(orders, &itemCount);
	displayOrder(orders, itemCount);

	return 0;
}

void orderCoffee(char *orders, int *itemCountPtr)
{
	char flavors[5][10] = {"House", "Iced", "Vanilla", "Hazelnut", "Mocha"};
	char sizes[3][8] = {"Small", "Medium", "Large"};
	
	printf("Welcome to the coffe shop!");
	printf("\n\nChoose your coffee(s)");
	int x=0;
	while(true && *itemCountPtr < 100)
	{
		char choice = 'y';
		bool valid = false;
		while(valid == false)
		{
			valid = false;
			printf("\nAvailable Sizes: |");
			for(int i=0; i<3; i++)
				printf("| %s |", sizes[i]);
				
			printf("|\nSize?: ");
			fgets(*(orders[x][0]), 10, stdin);

			//find the new line and replace it with a null for comparison purpsoses
			//calculates the position of the new line in the string
			int newLine = strcspn(*orders[x][0], "\n");
			//replaces it with a null
			*orders[x][0][newLine] = '\0';
			
			for(int y=0; y<3; y++)
			{
				if(strcasecmp(*orders[x][0], sizes[y]) == 0)
				{
					valid = true;
					break;
				}
				
			}
			if(!valid)
				printf("\nInvalid size. Please try again...");
		}
			
		valid = false;
		while(valid==false)
		{
			printf("\nAvailable Flavors: |");
			
			for(int i=0; i<5; i++)
				printf("| %s |", flavors[i]);
				
			printf("|\nFlavor?: ");
			fgets(*orders[x][1], 10, stdin);
			
			//find the new line and replace it with a null for comparison purpsoses
			//calculates the position of the new line in the string
			int newLine = strcspn(*orders[x][1], "\n");
			//replaces it with a null
			*orders[x][1][newLine] = '\0';
			
			for(int y=0; y<5; y++)
			{
				if(strcasecmp(*orders[x][1], flavors[y]) == 0)
				{
					valid = true;
					break;	
				}
			}
			if(!valid)
				printf("\nInvalid flavor. Please try again...");
		}
		
		printf("\nSugar?(y/n): ");
		fgets(*orders[x][2], 2, stdin);
		while(strcasecmp(*orders[x][2], "y") != 0 && strcasecmp(*orders[x][2], "n"))
		{
			while(getchar() != '\n'); //clears the input buffer in case more than one character was entered
			printf("\nInvalid sugar option. Please try again...");
			printf("\nSugar?(y/n): ");
			fgets(*orders[x][2], 2, stdin);
		}

		getchar(); //removes leftover \n form the buffer before starting the next fgets
		
		printf("\nCream?(y/n): ");
		fgets(*orders[x][3], 2, stdin);
		while(strcasecmp(*orders[x][3], "y") != 0 && strcasecmp(*orders[x][3], "n"))
		{
			while(getchar() != '\n'); //clears the input buffer in case more than one character was entered
			printf("\nInvalid cream option. Please try again...");
			printf("\nCream?(y/n): ");
			fgets(*orders[x][3], 2, stdin);
		}
		
		printf("\nAdd another?(y/n): ");
		scanf("\n%c", &choice);
		while(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
		{
			while(getchar() != '\n'); //clears the input buffer in case more than one character was entered
			printf("\nInvalid choice. Please try again...");
			printf("\nAdd another?(y/n): ");
			scanf("\n%c", &choice);
		}
		
		x++;

		while(getchar() != '\n'); //clear the buffer before starting the loop over
		if(choice == 'n' || choice =='N')
			break;
	}
	*itemCountPtr = x;
}

void displayOrder(char orders[99][4][10], int itemCount)
{
	
	float total = 0;
	int smallCount = 0, mediumCount = 0, largeCount = 0;
	
	//convert first letter of size to uppercase
	for(int x=0; x < itemCount; x++)
		orders[x][0][0] = toupper(orders[x][0][0]);		
	
	//convert flavor to lowercase
	for(int x=0; x < itemCount; x++)
		for(int y=0; orders[x][1][y]; y++)
			orders[x][1][y] = tolower(orders[x][1][y]);
			
	//add up the sizes to calculate the total
	for(int x=0; x < itemCount; x++)
	{
		if(strcmp(orders[x][0], "Small") == 0)
        	smallCount++;
		else if(strcmp(orders[x][0], "Medium") == 0)
        	mediumCount++;
    	else if(strcmp(orders[x][0], "Large") == 0) 
        	largeCount++;
	}
	
	total = (smallCount * 3.00) + (mediumCount * 4.50) + (largeCount* 6.00);
	
	printf("\n\nYour coffee order:");
	for(int x=0; x<itemCount; x++)
	{
		printf("\n%s %s coffee ", &orders[x][0], orders[x][1]);
		if(strcasecmp(orders[x][3], "y") == 0 && strcasecmp(orders[x][2], "n") == 0)
			printf("with cream");
		
		else if(strcasecmp(orders[x][3], "n") == 0 && strcasecmp(orders[x][2], "y") == 0)
			printf("with sugar");
		
		else if(strcasecmp(orders[x][3], "y") == 0 && strcasecmp(orders[x][2], "y") == 0)
			printf("with cream and sugar");
	}
	
	printf("\n\nTotal due: $ %.2f", total);
}
