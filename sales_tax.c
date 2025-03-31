//Nicholas Petersen

#include <stdio.h>

void inputTotalSales(float *totalSalesPtr);
void calculateTaxes(float *totalSalesPtr);
void displayTaxes(float *totalSalesPtr);

float countyTax, stateTax, totalTax;

int main ()
{
	float totalSales;
	
	printf("Monthly Sales Tax Calculator");
	inputTotalSales(&totalSales);
	calculateTaxes(&totalSales);
	displayTaxes(&totalSales);
	return 0;
}

void inputTotalSales(float *totalSalesPtr)
{
	printf("\nPlease enter the total monthly sales: ");
	scanf("%f", totalSalesPtr);
}

void calculateTaxes(float *totalSalesPtr)
{
	countyTax = *totalSalesPtr * 0.04;
	stateTax = *totalSalesPtr * 0.06;	
	totalTax = countyTax + stateTax;
}

void displayTaxes(float *totalSalesPtr)
{
	printf("\n__Tax totals__");
	printf("\nTotal Sales: $%.2f", *totalSalesPtr);
	printf("\nTotal County Tax: $%.2f", countyTax);
	printf("\nTotal State Tax: $%.2f", stateTax);
}
