#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "ref.h"

/*
 * A utility function to reverse an integer array of given length
 * @author: Bishwas C Gupta
 * All Rights Reserved
 * */
void reverse(int * array, int length)
{
    int i, temp, end;
    end = length - 1;
    for (i = 0; i < length/2; i++) 
    {
        temp = array[i];
        array[i] = array[end];
        array[end] = temp;
        end--;
  }
}

// A utility function to swap to integers
//@author: GeeksforGeeks.org
void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
// A utility function to print an array
//@author: GeeksforGeeks.org
void printArray (int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 

// A function to generate a random permutation of arr[]
//@author: GeeksforGeeks.org
void randomize (int * arr, int n )
{
 
    // Start from the last element and swap one by one. We don't
    // need to run for the first element that's why i > 0
    for (int i = n-1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i+1);
 
        // Swap arr[i] with the element at random index
        swap(&arr[i], &arr[j]);
    }
}

//A utility function to find array index if given value
//Source: http://stackoverflow.com/questions/25003961/find-array-index-if-given-value
size_t FindIndex( const int * a, size_t size, int value )
{
    size_t index = 0;

    while ( index < size && a[index] != value ) ++index;

    return ( index == size ? -1 : index );
}

//Find Worst Two in a given array of double
void findWorstTwo(double * arr, int arr_size, int * p1, int * p2)
{
    int i = 0;
	int pos1 = 0;
	int pos2 = 0;
	double first = -99999.0;
	double second = -99999.0;
		
    /* There should be atleast two elements */
    if (arr_size < 2)
    {
        printf(" Invalid Input in findWorstTwo function");
        exit(1);
    }

    for (i = 0; i < arr_size ; i ++)
    {
        /* If current element is greater than first 
           then update both first and second */
        if (arr[i] > first)
        {
			 second = first;
			 pos2 = pos1;
			 first = arr[i];
			 pos1 = i;
        }

        /* If arr[i] is in between first and second 
           then update second  */
        else if (arr[i] > second && arr[i] != first)
		{
            second = arr[i];
			 pos2 = i;
		}
    }
	
	*p1 = pos1;
	*p2 = pos2;

}


//Find Best
double findBest(double * arr, int length)
{
	double best = 0.0;
	int i = 0;

	best = arr[0];
	for(i=0;i<length;i++)
	{
		if(arr[i]<best)
		{
			best = arr[i];
		}
	}
	return best;
}