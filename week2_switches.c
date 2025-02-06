// Nicholas Petersen

#include <stdio.h>
#include <ctype.h>

int main()
{
	char initial = 'A';
	printf("\n%c", initial); //displays character form
	printf("\n%d", initial); //displays as ASCII value
	initial = initial + 3; //changed ASCII values of character
	printf("\n%c", initial);// character is now D
	
	char status = 'd';
	if (status >= 97) 
		status = status - 32;
	//status = toupper(status); //converts char to upper case
	switch (status)
	{
		case 'M': case 'm': //stacking cases simulates an or operator
			printf("\nMarried"); //if break is omitted it will run the next case as well
			//break;
		case 'S':
			printf("\nSingle");
			break;
		case 'D':
			printf("\nDivorced");
			break;
		default:
			printf("\nInvalid");
			break;
	}
	
	int grade = 72;
	switch (grade)
	{
		case 90: case 91: case 92 //.....etc.. does not make sense versus if statement
			printf("\nA")
	}
	
	return 0;
}
