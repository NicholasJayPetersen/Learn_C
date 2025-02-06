//Nicholas Petersen

#include <stdio.h>
#include <limits.h>
float getScore();
float findMin(float score1, float score2, float score3, float score4);
float findMax(float score1, float score2, float score3, float score4);
float calculateScore(float min, float max, float score1, float score2, float score3, float score4);
int main()
{	
	float score1, score2, score3, score4, min, max;
	
	printf("____Aggregate Score Calculator____");
	printf("\n\n	Enter four scores...\n");
	score1 = getScore();
	score2 = getScore();
	score3 = getScore();
	score4 = getScore();
	
	min = findMin(score1, score2, score3, score4);
	max = findMax(score1, score2, score3, score4);
	
	//calculate score and output
	printf("\nAggregate Score: %.2f", calculateScore(min, max, score1, score2, score3, score4));
		
	return 0;
}

float getScore()
{
	float score;
	printf("	Score: ");
	scanf("%f", &score);
	return score;
}

float findMin(float score1, float score2, float score3, float score4)
{
	//set a placeholder for the min, then compare to each number and replace it with the smallest.
	float smallest = score1;
	if (smallest > score2)
		smallest = score2;
		
	if (smallest > score3)
		smallest = score3;
		
	if (smallest > score4)
		smallest = score4;
		
	return smallest;
}

float findMax(float score1, float score2, float score3, float score4)
{
	//set a placeholder for the max, then compare to each number and replace it with the largest.
	float largest = score1;
	if (largest < score2)
		largest = score2;
		
	if (largest < score3)
		largest = score3;
		
	if (largest < score4)
		largest = score4;
		
	return largest;
}

float calculateScore(float min, float max, float score1, float score2, float score3, float score4)
{
	float aggregate;
	
	//printf("\nMin: %f", min);
	//printf("\nMax: %f", max);
	//printf("\nscore: %f", score1);
	//printf("\nscore: %f", score2);
	//printf("\nscore: %f", score3);
	//printf("\nscore: %f", score4);
	
	//look for minimum and maximum, then set those scores to zero to discard from average
	if (score1 == min || score1 == max)
		score1 = 0;
	if (score2 == min || score2 == max)
		score2 = 0;
	if (score3 == min || score3 == max)
		score3 = 0;
	if (score4 == min || score4 == max)
		score4 = 0;
	
	//add all scores: (min and max already converted to 0), then divide by two to find the average for the middle two scores
	aggregate = (score1 + score2 + score3 + score4) / 2.0;
	
	return aggregate;
}
