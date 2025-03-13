//Nicholas Petersen

#include <stdio.h>
#include <stdbool.h>

void displayTotals(int cones, int vanilla, int chocolate, int fudge, float total);
char getFlavor();
int main ()
{
	char favoriteFlavor;
	int numScoops = 0;
	float conePrice = .75;
	float scoopPrice = 1.25;
	float total;
	float totalSales = 0;
	int totalCones = 0;
	int vScoops = 0;
	int cScoops = 0;
	int fScoops = 0;
		

	//check if user wants to quit
	while (favoriteFlavor != 'q' && favoriteFlavor != 'Q')
	{
		favoriteFlavor = getFlavor();
		//if user wants to quit break out of loop and retest
		if (favoriteFlavor == 'q' || favoriteFlavor == 'Q')
			break;
		
		//check for valid number of scoops
		while (numScoops < 1 || numScoops > 4)
		{
			printf("\nHow many scoops would you like? ");
			scanf("%d", &numScoops);
			
			if (numScoops < 1 || numScoops > 4)
			{
				printf("\nThat is an invalid number of scoops!\nYou many only choose between 1 and 4.\n\nPlease try agian!\n");
			}
		}
		
		//add to accumulators
		total = scoopPrice * numScoops + conePrice;
		printf("Your ice cream cone cost $%5.2f\n\n", total);
		
		totalCones++;
		totalSales += total;
		
		switch(favoriteFlavor)
		{
			case 'v':
			case 'V':
				vScoops += numScoops;
				break;
			case 'c':
			case 'C':
				cScoops += numScoops;
				break;
			case 'f':
			case 'F':
				fScoops += numScoops;
				break;
		}
		
		//reset scoops for next iteration
		numScoops = 0;
	}
	
	//show totals after quitting
	displayTotals(totalCones, vScoops, cScoops, fScoops, totalSales);
	
	return 0;
}

char getFlavor()
{
	char choice;
	bool valid = false;
	
	//runs until a valid option is chosen
	while (valid == false)
	{
		printf("Please choose your favorite flavor!");
		printf("\nV - Vanilla");
		printf("\nC - Chocolate");
		printf("\nF - Fudge");
		printf("\nQ - Quit\n\n");
		scanf("\n%c", &choice);
		
		//check if the input was one of the acceptable options
		switch (choice)
		{
			case 'V':
			case 'v':
			case 'C':
			case 'c':
			case 'F':
			case 'f':
			case 'Q':
			case 'q':
				valid = true;	//end the loop if a valid option was chosen
				break;
			default:
				printf("\n\nYou have entered an invalid flavor. Try Again!\n\n");
				break;
		}		
	}
	
	return choice;
}

void displayTotals(int cones, int vanilla, int chocolate, int fudge, float total)
{
	printf("\n\nTotal number of cones sold:		%d", cones);
	printf("\nTotal scoops of vanilla sold: 		%d", vanilla);
	printf("\nTotal scoops of chocolate sold:		%d", chocolate);
	printf("\nTotal scoops of fudge sold:		%d", fudge);
	printf("\nTotal amount collected:			$%.2f", total);
}
