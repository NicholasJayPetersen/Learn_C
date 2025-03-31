//Nicholas Petersen

#include <stdio.h>
#include <string.h>

//strings are an array of characters terminated by the null character '\0'

int main()
{
	char greeting[10] = "Hello!";
	char name[10];
	char message[10];
	
	printf("\nEnter your name: ");
	//scanf("%s", name);	stops reagin input at white space
	//gets(name);			means "get string" and does not stop at white space. Is dangerous!!
	
	fgets(name, 10, stdin);
	printf("\nGreeting is %s", greeting);
	printf("\nName is: %s", name);
	
	
	//how to copy a string
	int x = 0;
	while(greeting[x] != '\0') // or while(greeting[x])
	//or while(message[x] = greeting[x]) x++; will assign and then check all in one line
	{
		message[x] = greeting [x];
		printf("%c ", greeting[x]);
		x++;
	}
	message[x] = '\0';
	
	printf("\n%s %s", message, name);
	
	
	strcpy(message, greeting); //string copy
	
	//compares a sgring
	if(strcmp(message, greeting) == 0)
		printf("\nThe stirngs are the same");
	if(strcmp(message, greeting) > 0)
		printf("\nmessage is larger than greeting");
	if(strcmp(message, greeting) < 0)
		printf("\nmessage is smaller than greeting");
	
	
	return 0;
}
