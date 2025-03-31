//Nicholas Petersen

#include <stdio.h>
#include <string.h>

int main()
{
	char birthMonth[10];
	printf("Enter your birth month: ");
	fgets(birthMonth, 10, stdin);
	printf("Your birth month is %s", birthMonth);
	
	//char month1[10] = "January";
	//char month2[10] = "February";
	//char month3[10] = "March";
	
	char *months[12]= {"January","February","March", "April", "May","June", "July", "August", "September", "October", "November", "December"};
	
	for(int x=0; x<12; x++)
	{
		printf("%s  ", months[x]);
	}
	
	
	char messsage[10] = "Hello!";	//C stirng
	char *greeting;					//string pointer
	//message = "bye";				not allowed
	greeting = "Bye!";				//allowed
	printf("\n%s", greeting);
	
	greeting="Almost!";
	printf("\n%s", greeting);


	return 0;
}
