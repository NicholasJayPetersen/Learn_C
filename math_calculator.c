//Nicholas Petersen

#include <stdio.h>

int main()
{
	double num1, num2, result;
	char operand;
	
	printf("____A simple math operations calculator____\n");
	
	printf("\nPlease enter a number:		");
	scanf("%lf", &num1);
	printf("\nPlease enter an operator \n(+, -, *, /):			");
	scanf("\n%c", &operand);
	printf("\nPlease enter another number:	");
	scanf("%lf", &num2);
	
	if (operand == '/' && num2 == 0)
	{
		printf("\nYou cannot divide by zero! Please try again");
		return 1;
	}
	
	switch (operand)
	{
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		case '*':
			result = num1 * num2;
			break;
		case '/':
			result = num1 / num2;
			break;
		default:
			printf("\nInvalid operator entered. Please try agian.");
			return 2;
	}
	
	
	//format output based on if a decimal or integer was entered using cast
	//if all integer numbers, dont show decimal places
	if(num1 == (int)num1 && num2 == (int)num2 && result == (int)result)
	{
		printf("\n%d %c %d = %d", (int)num1, operand, (int)num2, (int)result);
	}
	//format integer divison output to be a decimal only if there is a remainder.
	else if (num1 == (int)num1 && num2 == (int)num2 && ((int)num1 % (int)num2 != 0))
	{
		printf("\n%d %c %d = %lf", (int)num1, operand, (int)num2, result);
	}
	//if user enters a decimal number ouput formatted to default
	else
	{
		printf("\n%lf %c %lf = %lf", num1, operand, num2, result);
	}
	
	return 0;
}
