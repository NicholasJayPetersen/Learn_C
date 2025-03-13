//Nicholas Petersen

#include <stdio.h>

char determineBanquetRoom(int numGuests);
float determineRoomPrice(char banquetRoom);
float determineFoodPrice(int numGuests);
float determineEquipmentPrice();
void displayPrices(char banquetRoom, int numGuest, float prices[5]);


int main()
{
	float prices[4] = {0, 0, 0, 0};
	int numGuests, numTables;
	char banquetRoom, addtlEquipment;
	
	printf("Welcome to Holiday Banquet Center!");
	printf("\n\nHow many guests do you expect: ");
	scanf("%d", &numGuests);
	
	while(numGuests < 15 || numGuests > 250)
	{
		printf("\nYou have entered an invalid number of guests.");
		printf("\nHow many guests do you expect: ");
		scanf("%d", &numGuests);
	}
	
	banquetRoom = determineBanquetRoom(numGuests);
	prices[0] = determineRoomPrice(banquetRoom);
	
	numTables = numGuests/10.0 +2;
	prices[1] = numTables * 15.00;
	
	prices[2] = determineFoodPrice(numGuests);
	
	printf("Do you need additional equipment?(Y/N): ");
	scanf("\n%c", &addtlEquipment);
	
	if (addtlEquipment == 'y' || addtlEquipment == 'Y')
		prices[3] = determineEquipmentPrice();
		
	displayPrices(banquetRoom, numGuests, prices);
	
	return 0;
}

char determineBanquetRoom(int numGuests)
{
	char banquetRoom;
	
	printf("Based on the number of guests, you have the choice of the following rooms:");
	if(numGuests >= 15 && numGuests <= 25)
		printf("\nC - Cozy Cabin");
	if(numGuests >= 15 && numGuests <= 75)
		printf("\nP - Purple Parlor");
	if(numGuests >= 50 && numGuests <= 125)
		printf("\nD - Deluxe Dining");
	if(numGuests >= 50 && numGuests <= 150)
		printf("\nB - Big Ballroom");
	if(numGuests >= 100 && numGuests <= 250)
		printf("\nG - Grand Guestroom");
		
	printf("\n\nPlease choose from the available rooms above: --> ");
	scanf("\n%c", &banquetRoom);
	
	return banquetRoom;
}

float determineRoomPrice(char banquetRoom)
{
	switch(banquetRoom)
	{
		case 'c':
		case 'C':
			return 250.00;
		case 'p':
		case 'P':
			return 250.00;
		case 'd':
		case 'D':
			return 500.00;
		case 'b':
		case 'B':
			return 500.00;
		case 'g':
		case 'G':
			return 750.00;
	}
}

float determineFoodPrice(int numGuests)
{
	float oneEntree = 17.00;
	float twoEntree = 19.50;
	float desert = 2.00;
	float cost;
	int entreeChoice;
	char desertChoice;
	
	printf("Would you like one main entree or two? ");
	scanf("%d", &entreeChoice);
	while(entreeChoice != 1 && entreeChoice !=2)
	{
		printf("\nInvalid!  Try again!");
		printf("\nWould you like one main entree or two? ");
		scanf("%d", &entreeChoice);	
		
	}
	
	printf("Would you like desert (Y/N)? ");
	scanf("\n%c", &desertChoice);
	while(desertChoice != 'y' && desertChoice !='Y' && desertChoice != 'n' && desertChoice != 'N')
	{
		printf("\nInvalid!  Try again!");
		printf("\nWould you like desert (Y/N)? ");
		scanf("%d", &desertChoice);
	}

	
	if(entreeChoice == 1)
		cost = oneEntree * numGuests;
	if(entreeChoice == 2)
		cost = twoEntree * numGuests;
		
	if(desertChoice == 'y' || desertChoice == 'Y')
		cost += numGuests * desert;
	
	return cost;
}

float determineEquipmentPrice()
{
	float equipmentPrices[5] = {100.00, 25.00, 50.00, 10.00, 5.00};
	int choice = 1;
	float cost = 0;
	
	while(choice != 0)
	{
		printf("\n1 - Projector	 	%.2f", equipmentPrices[0]);
		printf("\n2 - Screen	 	%.2f", equipmentPrices[1]);
		printf("\n3 - Sound Box	 	%.2f", equipmentPrices[2]);
		printf("\n4 - 8-Foot Table 	%.2f", equipmentPrices[3]);
		printf("\n5 - Easel		 	%.2f", equipmentPrices[4]);
		
		printf("\n\nEnter a choice or 0 to quit: ");
		scanf("%d", &choice);
		
		if(choice == 0)
			continue;
			
		cost += equipmentPrices[choice-1];
		
		printf("\n\nYour equipment cost is currently: %.2f\n\n", cost);
	}
	
	return cost;
}

void displayPrices(char banquetRoom, int numGuests, float prices[4])
{
	printf("\nYour quote to rent the ");
	switch(banquetRoom)
	{
		case 'c':
		case 'C':
			printf("Cozy Cabin ");
			break;
		case 'p':
		case 'P':
			printf("Purple Parlor ");
			break;
		case 'd':
		case 'D':
			printf("Deluxe Dining ");
			break;
		case 'b':
		case 'B':
			printf("Big Ballroom ");
			break;
		case 'g':
		case 'G':
			printf("Grand Guestroom ");
			break;
	}
	printf("for %d guests will be:\n", numGuests);
	
	printf("\nRoom Price: 	 	$%7.2f", prices[0]);
	printf("\nTable Price:	 	$%7.2f", prices[1]);
	printf("\nFood Price: 	 	$%7.2f", prices[2]);
	printf("\nEquipment Price: 	$%7.2f", prices[3]);
	
	float subtotal = 0;
	for(int x=0; x<4; x++)
	{
		subtotal += prices[x];
	}
	
	printf("\nSerice Fee:		$%7.2f", subtotal*0.21);
	printf("\nTotal: 			$%7.2f", subtotal+subtotal*0.21);

	
}


