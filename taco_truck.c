//Nicholas Petersen

#include <stdio.h>
#include <stdbool.h>

int startNewOrder();
char getMenuCategory();
float getTacoChoice();
float getBurritoChoice();
float getQuesadillaChoice();
float getNachoChoice();
void showTotals(int tacos, int burritos, int quesadillas, int nachos, float total);
bool keepGoing();

int main ()
{	
	//accumulators
	int tacos  = 0, burritos = 0, quesadillas = 0, nachos = 0;
	float total = 0;
	
	//If user says no exit the program. If yes, start an order.
	int order = startNewOrder();
	for(order; order > 0; order--)
	{
		//loop to add multiple items
		bool notFinished = true;
		while(notFinished == true)
		{
			char menuCat = getMenuCategory();
			switch(menuCat)
			{
				case 'T':
				case 't':
					total += getTacoChoice();	//add taco price to running total
					tacos++;					//increment taco counter
					break;
				case 'B':
				case 'b':
					total += getBurritoChoice(); 	//add burrito price to running total
					burritos++;						//incrememnt burrito counter
					break;
				case 'Q':
				case 'q':
					total += getQuesadillaChoice(); //add quesadilla price to running total
					quesadillas++;					//increment quesadilla counter
					break;
				case 'N':
				case 'n':
					total += getNachoChoice();		//add nacho price to running total
					nachos++;						//increment nacho counter
					break;				
			}
					
			notFinished = keepGoing();		//check if user wants to add more items. If not exit the switch loop
		}
		
		showTotals(tacos, burritos, quesadillas, nachos, total);
	}
	
	printf("\n\nThank you for choosing Tomas Taco Truck!");
	
	return 0;
}

int startNewOrder()
{
	//check to see if user would like to start an order
	char startOrder;
	printf("Welcome to Tomas Taco Truck!");
	printf("\n\nWould you like to place an order? (Y/N) ");
	scanf(" %c", &startOrder);
	
	while(startOrder != 'Y' && startOrder != 'y' && startOrder != 'N' && startOrder != 'n')
	{
		printf("ERROR: Invlid option. Please choose Y or N.");
		printf("\n\nWould you like to place an order? (Y/N) ");
		scanf(" %c", &startOrder);
	}
	
	//if not, return 0 and the main for loop will never run
	if(startOrder == 'n' || startOrder == 'N')
		return 0;
	
	//otherwise starts the order process
	return 1;
}

char getMenuCategory()
{
	//user picks a menu category
	char cat;
	printf("Please choose from the following menu categories");
	printf("\nT - Tacos");
	printf("\nB - Burritos");
	printf("\nQ - Quesadillas");
	printf("\nN - Nachos");
	printf("\n---> ");
	scanf("\n%c", &cat);
	
	//validate data and repeat as needed
	while(cat != 'T' && cat != 'B' && cat != 'Q' && cat != 'N' && +
		  cat != 't' && cat != 'b' && cat != 'q' && cat != 'n')
	{
		printf("\nERROR: You chose an incorrect option. Please select a number:");
		printf("\nT - Tacos");
		printf("\nB - Burritos");
		printf("\nQ - Quesadillas");
		printf("\nN - Nachos");
		printf("\n---> ");
		scanf("\n%c", &cat);	
	}
	
	return cat;
}

float getTacoChoice()
{
	int choice;
	float cost;
	
	//user picks a taco option
	printf("\n1 - Regular Taco $1.99");
	printf("\n2 - Super Taco $2.99");
	printf("\n3 - Veggie Taco $1.99");
	printf("\nChoose a taco: ");
	scanf("%d", &choice);
	
	//validate data and repeat as needed
	while(choice != 1 && choice != 2 && choice != 3)
	{
		printf("\nERROR: You chose an incorrect option. Please select a valid number:");
		printf("\n1 - Regular Taco $1.99");
		printf("\n2 - Super Taco $2.99");
		printf("\n3 - Veggie Taco $1.99");
		printf("\nChoose a taco: ");
		scanf("%d", &choice);	
	}

	//assign cost based on chosen option
	switch(choice)
	{
		case 1:
		case 3:
			cost = 1.99;
			break;
		case 2:
			cost = 2.99;
			break;
	}
	
	return cost;
	
}

float getBurritoChoice()
{
	int choice;
	float cost;
	
	//user picks a burrito option
	printf("\n1 - Regular Burrito $2.99");
	printf("\n2 - Super Burrito $3.99");
	printf("\n3 - Veggie Burrito $2.99");
	printf("\n4 - Bean & Rice Burrito $1.99");
	printf("\n5 - Bean, Rice, & Cheese Burrito $1.99");
	printf("\n6 - Burrito Bowl $4.99");
	printf("\nChoose a burrrito: ");
	scanf("%d", &choice);
	
	//validate data and repeat as needed
	while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6)
	{
		printf("\nERROR: You chose an incorrect option. Please select a valid number:");
		printf("\n1 - Regular Burrito $2.99");
		printf("\n2 - Super Burrito $3.99");
		printf("\n3 - Veggie Burrito $2.99");
		printf("\n4 - Bean & Rice Burrito $1.99");
		printf("\n5 - Bean, Rice, & Cheese Burrito $1.99");
		printf("\n6 - Burrito Bowl $4.99");
		printf("\nChoose a burrrito: ");
		scanf("%d", &choice);
	}
	
	//assign cost based on chosen option
	switch(choice)
	{
		case 1:
		case 3:
			cost = 2.99;
			break;
		case 2:
			cost = 3.99;
			break;
		case 4:
		case 5:
			cost = 1.99;
			break;
		case 6:
			cost = 4.99;
			break;
	}
	
	return cost;
	
}

float getQuesadillaChoice()
{
	int choice;
	float cost;
	
	//user picks a quesadilla option
	printf("\n1 - Regular Quesadilla $1.99");
	printf("\n2 - Meat Quesadilla $2.99");
	printf("\n3 - Beef Quesadilla $3.99");
	printf("\n4 - Super Quesadilla $4.99");
	printf("\nChoose a quesadilla: ");
	scanf("%d", &choice);
	
	//validate data and repeat as needed
	while(choice != 1 && choice != 2 && choice != 3 && choice != 4)
	{
		printf("\nERROR: You chose an incorrect option. Please select a valid number:");
		printf("\n1 - Regular Quesadilla $1.99");
		printf("\n2 - Meat Quesadilla $2.99");
		printf("\n3 - Beef Quesadilla $3.99");
		printf("\n4 - Super Quesadilla $4.99");
		printf("\nChoose a quesadilla: ");
		scanf("%d", &choice);
	}
	
	//assign cost based on chosen option
	switch(choice)
	{
		case 1:
			cost = 1.99;
			break;
		case 2:
			cost = 2.99;
			break;
		case 3:
			cost = 3.99;
			break;
		case 4:
			cost = 4.99;
			break;
	}
	
	return cost;
	
}

float getNachoChoice()
{
	int choice;
	char extraCheese;
	float cost;
	
	//user picks a nacho option
	printf("\n1 - Regular Nacho $3.99");
	printf("\n2 - Super Nacho $5.99");
	printf("\nChoose a Nacho: ");
	scanf("%d", &choice);
	
	//validate data and repeat as needed
	while(choice != 1 && choice != 2)
	{
		printf("\nERROR: You chose an incorrect option. Please select a valid number:");
		printf("\n1 - Regular Taco $3.99");
		printf("\n2 - Super Taco $5.99");
		printf("\nChoose a Nacho: ");
		scanf("%d", &choice);	
	}
	
	printf("Would you like extra cheese for $1.00? Y/N: ");
	scanf(" %c", &extraCheese);
	
	//validate data and repeat as needed
	while(extraCheese != 'Y' && extraCheese != 'y' && extraCheese != 'N' && extraCheese != 'n')
	{
		printf("\nERROR: You chose an incorrect option. Please select Y or N.");
		printf("Would you like extra cheese for $1.00? Y/N: ");
		scanf(" %c", &extraCheese);	
	}
	
	//assign cost based on chosen option
	switch(choice)
	{
		case 1:
			cost = 3.99;
			break;
		case 2:
			cost = 5.99;
			break;
	}
	
	if(extraCheese == 'Y' || extraCheese == 'y')
		cost += 1;
	
	return cost;
	
}

void showTotals(int tacos, int burritos, int quesadillas, int nachos, float total)
{
	//only prints the menu category if something was added
	printf("\n\nYour order consists of");
	if(tacos > 0)
		printf("\nTotal Tacos: %d", tacos);
	if( burritos > 0)
		printf("\nTotal Burritos: %d", burritos);
	if(quesadillas > 0)
		printf("\nTotal Quesadillas: %d", quesadillas);
	if(nachos > 0)
		printf("\nTotal Nachos: %d", nachos);
	
	printf("\n\nTotal Due: $%.2f", total);
}

bool keepGoing()
{
	char keepGoing;
	
	//User has the option to add another item or finish the order
	printf("\n\nWould you like to add another item (Y/N): ");
	scanf("\n%c", &keepGoing);
	
	//validate data and repeat as needed
	while(keepGoing != 'Y' && keepGoing != 'y' && keepGoing != 'N' && keepGoing != 'n')
	{
		printf("\nERROR: Your entry was invalid. Please enter either Y or N.");
		printf("\n\nWould you like to add another item (Y/N): ");
		scanf("\n%c", &keepGoing);
	}
	
	//repeats loop
	if(keepGoing == 'Y' || keepGoing == 'y')
		return true;
		
	//ends the ordering loop	
	else if(keepGoing == 'N' || keepGoing == 'n')
		return false;
}
