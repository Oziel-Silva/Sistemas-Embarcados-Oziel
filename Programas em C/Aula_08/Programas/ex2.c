#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TAM 50000


void valor_maximo(long int *vetor)
{
	long int i,aux = 0;

	for (i = 0; i < TAM; i++)
	{
		if (vetor[i] > aux)
		{
			aux = vetor[i];
		}
	}
	printf("%ld \n",aux );
}






int main(int argc, char const *argv[])
{
	long int *v = malloc(TAM*(sizeof(long int)));
	long int aux = 0;
	int i;

		

	for (int i = 0; i < TAM; i++)
	{
		v[i] = rand();
	}
	
	valor_maximo(v);
	
	return 0;
}	