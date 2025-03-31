//Nicholas Petersen

#include <stdio.h>
#include <string.h>

void findVowels(char *phrasePtr, int *aCountPtr, int *eCountPtr, int *iCountPtr, int *oCountPtr, int *uCountPtr);

int main()
{
	char phrase[160];
	int aCount = 0, eCount = 0, iCount = 0, oCount = 0, uCount = 0;
	
	printf("Enter a phrase: ");
	fgets(phrase, 255, stdin);
	findVowels(phrase, &aCount, &eCount, &iCount, &oCount, &uCount);
	
	printf("\nTotal A's:	%d", aCount);
	printf("\n      E's:	%d", eCount);
	printf("\n      I's:	%d", iCount);
	printf("\n      O's:	%d", oCount);
	printf("\n      U's:	%d", uCount);
	
	return 0;
}

void findVowels(char *phrasePtr, int *aCountPtr, int *eCountPtr, int *iCountPtr, int *oCountPtr, int *uCountPtr)
{
	for (int x = 0; phrasePtr[x] != '\0'; x++)
    {
        switch (phrasePtr[x]) 
		{
            case 'A':
			case 'a':
				(*aCountPtr)++; 
				break;
			case 'E':
            case 'e': 
				(*eCountPtr)++; 
				break;
			case 'I':
            case 'i': 
				(*iCountPtr)++; 
				break;
			case 'O':
            case 'o': 
				(*oCountPtr)++; 
				break;
			case 'U':
            case 'u': 
				(*uCountPtr)++; 
				break;
        }
	}
}
