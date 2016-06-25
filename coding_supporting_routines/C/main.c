#include "main.h"


int askUserForInt (char *whatToAsk)
{
	char input[80];
	printf ("%s\n", whatToAsk);
	
	scanf ("%s", input);
	int value = atoi(input);
	if (value == 0)
	{
		printf("wrong value!\n");
		return 0;
	}
	else
	{
		printf("you have said %d\n", value);
		return value;
	}
}


int askUserYesNoQuestion (char *whatToAsk)
{
	char input[80];
	printf ("%s\n", whatToAsk);
	
	scanf ("%s", input);
	if (input[0] == 'Y' || input[0] == 'y')
	{
		return 1;
	}
	else
	{
		return 0;	
	}
}


int compareTwoFloats(float a, float b)
{
	if (fabs(a - b)/b < 0.01)
		return 0;
	else
		return 1;
}

float generateRandomFloat()
{
	return (float)rand()/(float)(RAND_MAX);
}

void printOutAMatrix(int M, int N, float *matrix)
{
	int i, j;
	for (i = 0; i < M; i++)
	{
		printf ("\n");
		for (j = 0; j < N; j++)
		{
			printf ("%0.3f, ", matrix[i * N + j]);
		}
	}
	printf("\n\n");
}


void zeroMatrixOfFloats (float *matrix, int numberOfElements)
{
	for (int i = 0; i < numberOfElements; i++)
	{
		matrix[i] = (float)0.0;
	}
}
