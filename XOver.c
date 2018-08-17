#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "ref.h"

/*
 * This is an implementation of the Partially Mapped Crossover due Goldberg and Lingle (1985)
 * for the Travelling Salesman Problem (TSP)
 * @author: Bishwas C Gupta
 * All rights reserved
 * Assume - numbering of cities start at index 0
 * */
void PMX(int * father, int * mother, int * child1, int * child2, int length)
{
    //Initialize variables
    int cut1 = 0;
    int cut2 = 0;
    int * mapping1, * mapping2;
    int temp = 0;
    int i = 0;
    int n1, n2, m1, m2;

    //Dynamic Memory Allocation
    mapping1 = (int *) calloc (length, sizeof(int));
    mapping2 = (int *) calloc (length, sizeof(int));
    
    //Get two cut points
    cut1 = rand()%length;
    cut2 = rand()%length;
    //The two cut points should be unequal
    while(cut1 == cut2)
        cut2 = rand()%length;
    //cut1 should be smaller than cut2
    if(cut1 > cut2)
    {
        //Swap
        temp = cut1;
        cut1 = cut2;
        cut2 = temp;
    }
    
    //Initialize mappings
    for(i=0; i<length; i++)
    {
        mapping1[i] = -1;
        mapping2[i] = -1;
    }
    
    //Create Mapping and populate fixed Locations
    for(i=cut1; i<=cut2; i++)
    {
        child1[i] = mother[i];
        child2[i] = father[i];
        
        mapping1[mother[i]] = father[i];
        mapping2[father[i]] = mother[i];
    }
    
    //Repair
    for(i=0; i<length; i++)
    {
        //No change if fixed location
        if((i >= cut1) && (i <= cut2))
            continue;
        
        n1 = father[i];
        n2 = mother[i];
        
        m1 = mapping1[n1];
        m2 = mapping2[n2];
        
        while (m1 != -1) 
        {
            n1 = m1 ;
            m1 = mapping1[m1] ;
        } 
        while (m2 != -1)
        {
            n2 = m2 ;
            m2 = mapping2[m2] ;
        } 
        
        child1[i] = n1 ;
        child2[i] = n2 ;
    }
    
	
    //Free Dynamically Allocated Memory
    free(mapping1);
    free(mapping2);
}
