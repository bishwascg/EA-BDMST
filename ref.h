#ifndef functions_h
#define functions_h
#include <stdio.h>
#include <stdlib.h>

/*
 * This header file contains the function signatures used to perform various functions and
 * the various structures used in the code
 * @author: Bishwas C Gupta
 * */
 
/*
 * FUNCTIONS FOR THE BDMST PROBLEM
 * */
void readBDMST(char *, double **, double **, int *, int);
double calulateFitness(int *, int, double *, double *, int);


/*
 * UTILTY FUNCTIONS
 * */
double random(); //random number btw 0 and 1
void findWorstTwo(double * , int , int * , int * );
double findBest(double * , int );
void randomize (int *, int);
size_t FindIndex( const int *, size_t, int);
void reverse(int *, int);

/*
 * MUTATION OPERATORS FOR ORDERED CHROMOSOMES
 * */
void swapMutate(int *, int); //Swap Mutation

/*
 * CROSSOVER OPERATORS FOR ORDERED CHROMOSOMES
 * */
void PMX(int *, int *, int *, int *, int); //Partially Mapped Crossover

/*
 * SELECTION OPERATORS
 * */
int tournamentSelection (double *, int, int);

#endif