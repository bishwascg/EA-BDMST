#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ref.h"


void main(int argc, char **argv)
{
	
	//Variable Initialization
	char * fileName = "E:/BDMST/TestDatatoUse/estein50.txt";
	int D = 5;
	int numOfPoints = 0;
	int POP_SIZE = 400;
	float XOver_Prob = 0.60;
	float mut_Prob = 1.00;
	int noImprovement = 100000;
	double * x;
	double * y;
	double fitChild1, fitChild2;
	double best;
	double sumbest = 0.0;
	double bestIter = 0.0;
	int worstPos1, worstPos2;
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	int ** population;
	double * fitness;
	int * temp;
	int * father;
	int * mother;
	int * child1;
	int * child2;
	int tournamentSize = 3;
	int count = 0;
	int iter = 0;
	int sumiter = 0;
	int looper = 0;
	double randomNumber = 0.0;
	time_t t;
	
	//Set Random Seed
	srand((unsigned) time(&t));
	
	//Run for the First five instances
	for(i=0; i<1; i++)
	{
		
		//Read the BDMST File
		readBDMST(fileName, &x, &y, &numOfPoints, i);
		
		//Re-initialize
		sumbest = 0.0;
		sumiter = 0;
		bestIter = (double) INT_MAX;
		
		//Allocate Memory
		population = (int **) malloc (POP_SIZE * sizeof(int *));
		for (j=0; j<POP_SIZE; j++)
         population[j] = (int *)malloc(numOfPoints * sizeof(int));
		fitness = (double *) malloc (POP_SIZE * sizeof(double));
		temp = (int *) calloc (numOfPoints, sizeof(int));
		father = (int *) calloc (numOfPoints, sizeof(int));
		mother = (int *) calloc (numOfPoints, sizeof(int));
		child1 = (int *) calloc (numOfPoints, sizeof(int));
		child2 = (int *) calloc (numOfPoints, sizeof(int));
		
		for(looper = 0; looper<50; looper++)
		{
			//Re-initialize
			count = 0;
			randomNumber = 0.0;
			iter = 0;
		
			//Random Population Initialization
			for(j=0; j<numOfPoints; j++)
				temp[j] = j;
			for(j=0; j<POP_SIZE; j++)
			{
				randomize(temp, numOfPoints);
				for(k=0; k<numOfPoints; k++)
					population[j][k] = temp[k];
			}
			
			//Calculate Fitness of Population
			for(j=0; j<POP_SIZE; j++)
			{
				for(k=0; k<numOfPoints; k++)
				{
					temp[k] = population[j][k];
				}
				fitness[j] = calulateFitness(temp, numOfPoints, x, y, D);
			}
			
			//Find Best
			best = findBest(fitness, POP_SIZE);
			
			while(count<noImprovement)
			{
				
				//Parent Selection Using 3-way tournaments
				l = tournamentSelection(fitness, tournamentSize, POP_SIZE);
				for(j=0; j<numOfPoints; j++)
					father[j] = population[l][j];
				l = tournamentSelection(fitness, tournamentSize, POP_SIZE);
				for(j=0; j<numOfPoints; j++)
					mother[j] = population[l][j];

				//PMX Crossover
				randomNumber = (double)rand() / (double)((unsigned)RAND_MAX + 1);
				if(randomNumber <= XOver_Prob)
				{
					PMX(father, mother, child1, child2, numOfPoints);
				}
				else
				{
					//printf("skipping crossover\n");
					for(j=0; j<numOfPoints; j++)
					{
						child1[j] = father[j];
						child2[j] = mother[j];
					}
				}
				
				//Swap Mutation
				randomNumber = (double)rand() / (double)((unsigned)RAND_MAX + 1);
				if(randomNumber <= mut_Prob)
				{
					swapMutate(child1, numOfPoints);
					swapMutate(child2, numOfPoints);
				}
				
				//Find Fitness of Children & Parents
				fitChild1 = calulateFitness(child1, numOfPoints, x, y, D);
				fitChild2 = calulateFitness(child2, numOfPoints, x, y, D);
				
				//Find 2 worst positions in the population
				findWorstTwo(fitness, POP_SIZE, &worstPos1, &worstPos2);
				

				//Replace Individuals 
				for(j=0; j<numOfPoints; j++)
				{
					population[worstPos1][j] = child1[j];
					population[worstPos2][j] = child2[j];
				}
				fitness[worstPos1] = fitChild1;
				fitness[worstPos2] = fitChild2;

				
				//Find Best
				if(fitChild1 < best)
				{
					best = fitChild1;
					count = 0;
					printf("%d best %.2lf\n", iter, best);
				}
				else if(fitChild2 < best)
				{
					best = fitChild2;
					count = 0;
					printf("%d best %.2lf\n", iter, best);
				}
				else
				{
					count++;
				}
				
				iter++;
			}
			
			printf("**************************************************\n");
			printf("Objective -- %lf\n", best);
			printf("Iterations -- %d\n", iter-noImprovement);
			printf("**************************************************\n");
			
			sumbest += best;
			sumiter += (iter-noImprovement);
			if(best < bestIter)
				bestIter = best;
			
		}
		
		printf("**************************************************\n");
		printf("**************************************************\n");
		printf("Objective -- %lf\n", sumbest/(double)50);
		printf("Iterations -- %d\n", sumiter/50);
		printf("Best -- %lf\n", bestIter);
		printf("**************************************************\n");
		printf("**************************************************\n");
		
		//Free Memory
		free(x);
		free(y);
		for (j=0; j<POP_SIZE; j++)
         free(population[j]);
		free(population);
		free(fitness);
		free(temp);
		free(father);
		free(mother);
		free(child1);
		free(child2);
	}

}
