//Nicholas Petersen

#include <stdio.h>

int main()
{
	
	short int initMiles = 27920;
	short int flTrip = 2490;
	short int coTrip = 2780;
	short int dailyDrives = 6213;
	
	short int tripAvg = (flTrip + coTrip) / 2;
	unsigned short int totalMiles = initMiles + flTrip + coTrip + dailyDrives;
	
	printf("___Odometer Tracker___");
	printf("\n\nStarting Miles:	  %5d", initMiles);
	printf("\nFlorida Trip:     %5d", flTrip);
	printf("\nColorado Trip:    %5d", coTrip);
	printf("\nDaily Drives:     %5d", dailyDrives);
	printf("\n\nRoad Trip Average:	%5d", tripAvg);
	printf("\nCurrent Odometer:    	%5d", totalMiles);
	
	return 0;
}
