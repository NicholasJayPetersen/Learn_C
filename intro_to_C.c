// Nicholas Petersen

//input output header
#include <stdio.h>

//main driver
int main()
{
	int birthYear;
	int currentYear, age;
	
	printf("What year were you born? ");
	scanf("%d", &birthYear);
	
	printf("What is the current year? ");
	scanf("%d", &currentYear);
	
	//Lvalue assignment operator Rvalue
	age = currentYear - birthYear;
	
	//%d is data type to be inserted into string followed by variablees in order
	printf("In %d you will be %d years old", currentYear, age);
	
	return 0;
}
