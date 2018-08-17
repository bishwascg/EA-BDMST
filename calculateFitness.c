#include "ref.h"
#include <math.h>


//Find distance btw two points
double findDistance(double x1, double x2, double y1, double y2)
{
	double d = (double) sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));
	return d;
}


double calulateFitness(int * arr, int numOfPoints, double * x, double * y, int D)
{
	//Initialize Variables
	int * depth;
	int i = 0;
	int c = 0;
	double dist = 0;
	double mdist = 0;
	int pos = 0;
	double obj = 0.00;
	
	
	//Allocate Memory
	depth =  (int *) calloc (numOfPoints, sizeof(int));
	
	//Initialize
	for(i=0; i<numOfPoints; i++)
		depth[i] = -1;
	
	//Center Node
	depth[arr[c]] = 0;
	c++;
	
	//D is ODD
	if(D%2!=0)
	{
		depth[arr[c]] = 0;
		c++;
		obj = obj + findDistance(x[arr[c-1]], x[arr[c-2]], y[arr[c-1]] ,y[arr[c-2]]);
	}
	
	//Generate Tree
	while(c<numOfPoints)
	{
		mdist = (double) INT_MAX;
		pos = -1;
		for(i=0;i<c;i++)
		{
			dist = findDistance(x[arr[i]], x[arr[c]], y[arr[i]], y[arr[c]]);
			if(dist < mdist)
			{
				if(depth[i] + 1 < (int)D/2)
				{
					pos = i;
					mdist = dist;
				}
			}
			else
				continue;
		}
		depth[c] = depth[pos] + 1;
		obj = obj + mdist;
		c++;
	}
	
	//Free
	free(depth);
	
	//printf("obj %lf", obj);
	
	return obj;
}