#include <stdlib.h>
#include <stdio.h>
#include "ref.h"
#include <time.h>

/*
 * TOURNAMENT SELECTION
 * returns the index of one parent
 * Run the function N times to generate N parents
 * */
int tournamentSelection(double * fitness, int tournamentSize, int length)
{
	int randPos = 0;
	int bestPos = 0;
	int i = 0;

	//if tournamentSize is less than 1, throw an error
	if(tournamentSize<1)
	{
		printf("Tournament Size can't be less than one\n");
		exit(1);
	}
	
    //Get a random position
    randPos = rand()%length;
	bestPos = randPos;
	//printf("%d ", randPos);
	
	//Do tournaments
	for(i=1; i<tournamentSize; i++)
	{
		randPos = rand()%length;
		//printf("%d ", randPos);
		if(fitness[randPos] < fitness[bestPos])
		{
			bestPos = randPos;
		}
	}
	
	//Return
	return bestPos;
	
}
