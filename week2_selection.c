// Nicholas Petersen

#include <stdio.h>

int main()
{
	//relational operators < > <= >= == !=
	
	int age = 19;
	
	if (age >= 18)
		printf("Adult\n");
		
	else 
		printf("Child\n");
		
	
	if (age > 18)
	{
	
		printf("You may enter");
		if (age > 21)
			printf(" and you may drink");

	}
	else
		printf("Go home!");
		
	printf("\n");
		
	int grade = 52;
	
	if (grade >= 90)
		printf("A");
	else if (grade >= 80)
		printf("B");
	else if (grade >= 70)
		printf("C");
	else if (grade >= 60)
		printf("D");
	else
		printf("E");
		
	
	return 0;
}
