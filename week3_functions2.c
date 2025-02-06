//Nicholas Petersen

#include <stdio.h>
float CalculateArea(float l, float w);
float CalculatePerimeter(float l, float w);
int main()
{
	float length, width, area, perimeter;
	char answer;
	
	printf("Enter length: ");
	scanf("%f", &length);
	
	printf("Enter width:  ");
	scanf("%f", &width);
	
	printf("\nLength %.2f and width %.2f", length, width);
	
	printf("\nWould you like to calculate area or perimiter (type A or P)? ");
	scanf("\n%c", &answer);
	printf("\nHey %c is your answer!", answer);
	
	if (answer == 'A' || answer == 'a')
	{
		area = CalculateArea(length, width);
		printf("\nArea is %.2f", area);
	}
	else if (answer == 'P' || answer == 'p')
	{
		perimeter = CalculatePerimeter(length, width);
		printf("\nPerimeter is %.2f", perimeter);
	}
	else
	{
		printf("\nYou chose an invalid option. Please try again.");
	}
	
	return 0;
}

float CalculateArea(float l, float w)
{
	float a = l * w;
	return a;
}

float CalculatePerimeter(float l, float w)
{
	float p = (2 * l) + (2 * w);
	return p;
}
