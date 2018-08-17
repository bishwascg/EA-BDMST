#include "ref.h"

/*
 * This Function Reads the BDMST FILE 
 * */
 
void readBDMST(char * filePath, double ** x, double ** y, int * numOfPoints, int i)
{
	int numLinesSkip = 0;
	int loop = 0;
	char temp[35];
	FILE * BDMST;
	
	//Open File
	BDMST = fopen(filePath, "r");
	
	//If file does not exist, exit the program
    if(BDMST == NULL)
    {
        perror("Error while opening the file.\n");
        exit(1);
    }
	
	//Skip First Line
    fscanf(BDMST,"%*[^\n]\n",temp);
	
	//Read Number of Instances
	fscanf(BDMST,"%d\n", numOfPoints);
	
	//Find number of lines to skip
	numLinesSkip = i * (* numOfPoints);
	if(i!=0)
		numLinesSkip = numLinesSkip + i;
	
	//Skip those lines
	for(loop=0; loop<numLinesSkip;loop++)
		fscanf(BDMST,"%*[^\n]\n",temp);
	
	//Allocate Dynamic Memory
	* x = (double *) calloc (* numOfPoints, sizeof(double));
	* y = (double *) calloc (* numOfPoints, sizeof(double));
	
	//Fill the x and y coordinates
	for(loop=0; loop< *numOfPoints; loop++)
	{
		fscanf(BDMST,"%lf %lf\n",(*x+loop),(*y+loop));
	}

}

