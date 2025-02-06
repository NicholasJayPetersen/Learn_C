// Nicholas Petersen

#include <stdio.h>

int main() 
{
	int month, day, year;
	
	printf("		______Leap Year Calculator______\n\n");
	printf("	Enter your birthday (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &month, &day, &year);
		
	printf("\n	Your birthday");
		
	switch (month)
	{
		case 1:
			 printf(", January");
			break;
		case 2:
			 printf(", February");
			break;	
		case 3:
			 printf(", March");
			break;	
		case 4:
			 printf(", April");
			break;	
		case 5:
			 printf(", May");
			break;	
		case 6:
			 printf(", June");
			break;
		case 7:
			 printf(", July");
			break;	
		case 8:
			 printf(", August");
			break;	
		case 9:
			 printf(", September");
			break;	
		case 10:
			 printf(", October");
			break;	
		case 11:
			 printf(", November");
			break;	
		case 12:
			 printf(", December");
			break;	
		default:
			printf(" is invalid. Please try again.\n");
			return 0;
	}
	
	printf(" %d, %d ", day, year);
		
	if (year % 4 == 0 && (year % 100 !=0 || year % 400 == 0))
		printf("is a leap year.\n");
	
	else
		printf("is not a leap year.\n", day, year);
	
	
	return 0;
}
