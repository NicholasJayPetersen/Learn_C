//Nicholas Petersen

#include <stdio.h>


//pointers are variables that can only include an address
//the asterisk tells the computer its a pointer and basically says go to here

void calculate(float length, float width, float *areaPtr, float *perimeterPtr);
void getData(float *lengthPtr, float *widthPtr);

int main()
{
	float length, width, area, perimeter;
	
	getData(&length, &width);
	calculate(length, width, &area, &perimeter);
	
	printf("\n area %.1f and perimeter %.1f", area, perimeter);
	
	return 0;
}

void calculate(float length, float width, float *areaPtr, float *perimeterPtr)
{
	float area, perimeter;
	
	area = length * width;
	perimeter = (length * 2) + (width * 2);
	
	*areaPtr = area;
	*perimeterPtr = perimeter;
}

void getData(float *lengthPtr, float *widthPtr)
{
	printf("Enter the length: ");
	scanf("%f", lengthPtr);
	
	printf("\nEnter the width: ");
	scanf("%f", widthPtr);
}


