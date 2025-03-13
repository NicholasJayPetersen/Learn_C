//Nicholas Petersen

#include <stdio.h>

int askHospitalDays(int medID, char firstInitial, char lastInitial);
int askSurgeryLevel(int medID, char firstInitial, char lastInitial);
int askMedication(int medID, char firstInitial, char lastInitial, float medPrices[10]);
void calcAndPrintHospitalBill(int level, char firstInitial, char lastInitial, int medID, int days, float medPrices[10], 
							  int numOfMeds, float surgicalPrices[5], float labFees[5]);
int main()
{
	int medID;
	char firstInitial, lastInitial;
	
	float surgicalPrices[] = {1500.00, 3250.00, 6579.99, 12999.99, 25450.00};
	float labFees[] = {500.00, 1025.00, 2500.99, 5290.00, 9875.99};
	float medPrices[10];
	
	printf("WHat is the patients medical ID: ");
	scanf("%d", &medID);
	printf("What is the patients last initial: ");
	scanf("\n%c", &lastInitial);
	printf("What is the patients first initial: ");
	scanf("\n%c", &firstInitial);
	
	int days = askHospitalDays(medID, firstInitial, lastInitial);
	int surgeryLevel = askSurgeryLevel(medID, firstInitial, lastInitial);
	int numOfMeds = askMedication(medID, firstInitial, lastInitial, medPrices);
	
	calcAndPrintHospitalBill(surgeryLevel, firstInitial, lastInitial, medID, days, medPrices, numOfMeds, surgicalPrices, labFees);
	
	return 0;
}

int askHospitalDays(int medID, char firstInitial, char lastInitial)
{
	int days = 0;
	
	while(days < 1 || days > 21)
	{
		printf("How many days did patient %c.%c. #%d stay in the hospital: ", firstInitial, lastInitial, medID);
		scanf("%d", &days);	
		
		if(days < 1 || days > 21)
			printf("ERROR: Invalid number of days. Must be between 1 and 21...\n");
	}
	
	return days;
}

int askSurgeryLevel(int medID, char firstInitial, char lastInitial)
{
	int surgeryLevel = 0;
	
	while(surgeryLevel < 1 || surgeryLevel > 5)
	{
		printf("What level of surgery did patient %c.%c. #%d have: ", firstInitial, lastInitial, medID);
		scanf("%d", &surgeryLevel);
		
		if(surgeryLevel < 1 || surgeryLevel > 5)
			printf("ERROR: Surgery level must be betrween 1 and 5. Please try again...\n");
	}
	
	return surgeryLevel;
}

int askMedication(int medID, char firstInitial, char lastInitial, float medPrices[10])
{
	int numOfMeds = 0;
	
	while(numOfMeds < 1 || numOfMeds > 10)
	{
		printf("How many medications were used for patient %c.%c. #%d (up to 10): ", firstInitial, lastInitial, medID);
		scanf("%d", &numOfMeds);	
		
		if(numOfMeds < 1 || numOfMeds > 10)
			printf("ERROR: Number of medications must be between 1 and 10. Please try again...\n");	
	}

	for(int x = 0;  x < numOfMeds; x++)
	{
		printf("\nEnter medication #%d --> ", x+1);
		scanf("%f", &medPrices[x]);
	}
	
	return numOfMeds;
}

void calcAndPrintHospitalBill(int level, char firstInitial, char lastInitial, int medID, int days, float medPrices[10], 
							  int numOfMeds, float surgicalPrices[5], float labFees[5])
{
	float totalMedCost = 0;
	float dailyCharge = days * 350.00;
	float surgicalCharge = surgicalPrices[level-1]; 
	float labCharge = labFees[level-1];
	
	for(int x = 0; x< numOfMeds; x++)
	{
		totalMedCost += medPrices[x];
	}
	
	float total = totalMedCost + dailyCharge + surgicalCharge + labCharge;
	
	printf("\nBilling Statment for Level %d Surgical Procedure", level);
	printf("\nPatient:			%c.%c. #%d", firstInitial, lastInitial, medID);
	printf("\nDaily Charge: 			$%9.2f", dailyCharge);
	printf("\nMedication Charge:		$%9.2f", totalMedCost);
	printf("\nSurgical Charge:		$%9.2f", surgicalCharge);
	printf("\nLab Charge:			$%9.2f", labCharge);
	printf("\nTotal:				$%9.2f", total);
}
