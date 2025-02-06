// Nicholas Petersen
// Programming Languages Assignment

#include <stdio.h>

int main()
{
	int html,
		java,
		cpp,
		cSharp,
		js,
		php,
		swift,
		kotlin,
		python,
		
		numStudents,
		webLangs,
		mobileLangs,
		oopLangs;
		
		
		//output introduction to screen
		printf("Welcome to the Calumet High School Programming Survey\n\n");
		printf("Please enter the total number of students who know:\n\n");
		
		
		//have user put stuff in cups
		printf("\tHTML:\t\t");
		scanf("%d", &html);
		numStudents += html;
		
		printf("\tJava:\t\t");
		scanf("%d", &java);
		numStudents += java;
		
		printf("\tC++:\t\t");
		scanf("%d", &cpp);
		numStudents += cpp;
		
		printf("\tC#:\t\t");
		scanf("%d", &cSharp);
		numStudents += cSharp;
		
		printf("\tJavaScript:\t");
		scanf("%d", &js);
		numStudents += js;
		
		printf("\tPhP:\t\t");
		scanf("%d", &php);
		numStudents += php;
		
		printf("\tSwift:\t\t");
		scanf("%d", &swift);
		numStudents += swift;
		
		printf("\tKotlin:\t\t");
		scanf("%d", &kotlin);
		numStudents += kotlin;
		
		printf("\tPython:\t\t");
		scanf("%d", &python);
		numStudents += python;
		
		
		//do math with cups full of stuff
		webLangs = html + js + php;
		mobileLangs = swift + kotlin;
		oopLangs = java + cpp + cSharp + python;
		
		//output groupings
		printf("\nTotal Students:                           %4d\n", numStudents);
		printf("Total who know Web languages:             %4d\n", webLangs);
		printf("Total who know Mobile App Dev languages:  %4d\n", mobileLangs);
		printf("Total who know Object Oriented languages: %4d\n", oopLangs);
	
	return 0;
}
