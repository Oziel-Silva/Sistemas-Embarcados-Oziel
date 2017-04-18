#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>	// Para a funcao open()
	// Para a funcao close()


int main(int argc, char const *argv[])
{
	long int A[60][60];
	long int B[60][60];
	long int C[60][60];
	int i, j;

	long int c_aux;

	for (i = 0; i < 60; i++)
	{
		for (j = 0; j < 60; j++)
		{
			A[i][j] = rand();
			B[i][j] = rand();
		}
	}

	for (i = 0; i < 60; i++)
	{
		for (j = 0; j < 60; j++)
		{
			C[i][j] = A[i][j] + B[i][j] ;
		}
	}

	int filepointer = open("matrix.txt", O_RDWR | O_CREAT);

	for (i = 0; i < 60; i++)
	{
		for (j = 0; j < 60; j++)
		{	
			c_aux = C[i][j];
			printf("%ld ",c_aux );
		}
		printf("\n");
	}


close(filepointer);

	return 0;
}