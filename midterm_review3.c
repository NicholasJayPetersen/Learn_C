//Nicholas Petersen

#include <stdio.h>

int makeReservation(int train[10]);
float calculatePrice(int numPeople, char time);
void displayFinalTotals(float cost, int numPeople, int morningPeople, int afternoonPeople, int morningTrain[10], int afternoonTrain[10]);

int main()
{
	int morningTrain[10] = {20,20,20,20,20,20,20,20,20,20}, afternoonTrain[10] = {20,20,20,20,20,20,20,20,20,20};
	char time, goAgain = 'y';
	int numPeople, morningPeople = 0, afternoonPeople = 0, totalPeople = 0;
	float cost, totalCost = 0;
	
	printf("Welcome to Train Trippers Day Excursions!");
	
	while(goAgain == 'y' || goAgain == 'Y')
	{
		printf("\nWould you like a (M)orning trip or an (A)fternoon trip? ");
		scanf("\n%c", &time);
		
		if(time == 'm' || time =='M')
		{
			numPeople = makeReservation(morningTrain);
			morningPeople += numPeople;
			totalPeople += numPeople;
		}
		else if(time == 'a' || time == 'A')
		{
			numPeople = makeReservation(afternoonTrain);
			afternoonPeople += numPeople;
			totalPeople += numPeople;
		}	
		else
			printf("\nInvalid choice.");
			
			
		cost = calculatePrice(numPeople, time);
		printf("\nYour total cost is $ %.2f", cost);
		totalCost += cost;
		
		printf("\nIs there another reservation? ");
		scanf("\n%c", &goAgain);
	}

	displayFinalTotals(totalCost, totalPeople, morningPeople, afternoonPeople, morningTrain, afternoonTrain);
	
	return 0;
}

int makeReservation(int train[10])
{
	int numPeople = 0, carNumber;
	
	printf("\nHow many people would you like to make a reservation for ? (1-20) ");
	scanf("%d", &numPeople);
	while(numPeople < 1 || numPeople > 20)
	{
		printf("\n\nERROR: Number of poeple must be between 1 and 20.");
		printf("\nHow many people would you like to make a reservation for ? (1-20)");
		scanf("%d", &numPeople);
	}
	
	printf("\nHere are the available train cars and their current capacity:");
	printf("\nTrain Car# - Available Seats");
	
	for(int x=0; x<10; x++)
	{
		printf("\n#%d 	-	%d", x+1, train[x]);
	}
	
	printf("\nWhich train car would you like to be on? ");
	scanf("%d", &carNumber);
	
	train[carNumber-1] -= numPeople;
	
	printf("\nYou are reserved on train car #%d for %d people.", carNumber, numPeople);
	
	return numPeople;
}

float calculatePrice(int numPeople, char time)
{
	float totalCost, morningPrice = 18.50, afternoonPrice = 23.75;
	
	switch(time)
	{
		case 'm':
		case 'M':
			totalCost = morningPrice * numPeople;
			break;
		case 'a':
		case 'A':
			totalCost = afternoonPrice * numPeople;
	}
	
	if(numPeople >= 10)
		totalCost *= .8;
		
	return totalCost;
}

void displayFinalTotals(float cost, int numPeople, int morningPeople, int afternoonPeople, int morningTrain[10], int afternoonTrain[10])
{
	printf("\nTotal amount collected:              $  %6.2f", cost);
	printf("\nTotal seats reserved for Morning:           %6d", morningPeople);
	printf("\nTotal seats reserved for Afternoon:         %6d", afternoonPeople);
	printf("\nTotal seats reserved for the day:           %6d", numPeople);
	
	printf("\n\nCurrent Capacity for Morning Train:\n\n");
	for(int x=0; x<10; x++)
		printf("\n#%d 	-	%d", x+1, morningTrain[x]);
		
	printf("\n\nCurrent Capacity for Afternoon Train:\n\n");
	for(int x=0; x<10; x++)
		printf("\n#%d 	-	%d", x+1, afternoonTrain[x]);
}
