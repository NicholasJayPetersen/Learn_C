//Nicholas Petersen

#include <stdio.h>
int addNumbers(int num1, int num2);
void printSum(int sum);
int getNum();
int main()
{
	int num1, num2, sum;
	
	printf("Gives the sum of two numbers")
	//printf("Enter two numbers separated by a space: ");
	//scanf("%d %d", &num1, &num2);
	num1 = getNum();
	num2 = getNum();
	//sum = num1 + num2;
	sum = addNumbers(num1, num2); //function call
	
	//printf("\nThe sum of the two numbers is: %d", sum);
	printSum(sum);
	
	return 0;
}

//basic function to add two numbers
//returns an integer
//entire head and body is function definition
int addNumbers(int num1, int num2)  //function header
{ //function body
	int sum = num1 + num2;
	return sum;
}

void printSum(int sum)
{
	printf("\nThe sum of the two numbers is: %d", sum);
}

int getNum()
{
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	return num;
}

/*

function terminology
defintion
header
body
function name - addNumbers
parameters - num1, num2 in the definition
return data type - int
function call
arguements - num1, num2 in the function call
prototype - declatarion before main and has ;

*/
