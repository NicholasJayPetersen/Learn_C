//Nicholas Petersen

#include <stdio.h>

float askRent(float rentPrices[4]);

int main()
{
	//rentPrices is name, 4 is the size
	float rentPrices[4] = {800.75, 950.50, 1100.25, 1250.00};
	float totalRent;
	
	totalRent = askRent(rentPrices);
	printf("\nYour rent will be: $%.2f", totalRent);
	
	return 0;
}

float askRent(float rentPrices[4])
{
	int bedrooms;
	for (int x = 0; x < 4; x++)
	{	
		printf("\n%d bedroom $%.2f", x+1, rentPrices[x]);
	}
	printf("\nHow many bedrooms: ");
	scanf("%d", &bedrooms);
	
	/*
	switch(bedrooms)
	{
		case 1:
			return rentPrices[0];
		case 2:
			return rentPrices[1];
		case 3:
			return rentPrices[2];
		case 4:
			return rentPrices[3];
	}*/
	
	 return rentPrices[bedrooms - 1];
}
