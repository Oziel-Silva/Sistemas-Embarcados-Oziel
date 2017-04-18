#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TAM 50000


void* valor_maximo(void *vetor)
{
	long int *v = (long int*) vetor;
	long int i,aux = 0;

	for (i = 0; i < TAM; i++)
	{
		if (v[i] > aux)
		{
			aux = v[i];
		}
	}
	return (void*) aux;
}






int main(int argc, char const *argv[])
{
	long int v[TAM];

	long int A[TAM/4];
	long int B[TAM/4];
	long int C[TAM/4];
	long int D[TAM/4];

	long int i,aux = 0;
	void *status1;
	void *status2;
	void *status3;
	void *status4;

	pthread_t thread1_id;
	pthread_t thread2_id;
	pthread_t thread3_id;
	pthread_t thread4_id;	


	for (i = 0; i < TAM; i++)
	{
		v[i] = rand();
	}

	for (i = 0; i < (TAM/4) - 1; i++)
	{
		A[i] = v[i];
	}
	
	for (i = (TAM/4); i < (TAM/2) - 1; i++)
	{
		B[i] = v[i];
	}

	for (i = (TAM/2); i < ((3*TAM)/4) - 1; i++)
	{
		C[i] = v[i];
	}

	for (i = ((3*TAM)/4); i < (TAM); i++)
	{
		D[i] = v[i];
	}
	pthread_create (&thread1_id, NULL, &valor_maximo, &A);
	pthread_create (&thread2_id, NULL, &valor_maximo, &B);
	pthread_create (&thread3_id, NULL, &valor_maximo, &C);
	pthread_create (&thread4_id, NULL, &valor_maximo, &D);

	//valor_maximo(v);
	pthread_join (thread1_id, &status1);
	pthread_join (thread2_id, &status2);
	pthread_join (thread3_id, &status3);
	pthread_join (thread4_id, &status4);

	
		if ((long int) status1 > aux)
		{
			aux = (long int)status1;
		}

		if ((long int) status2 > aux)
		{
			aux = (long int)status2;
		}

		if ((long int) status3 > aux)
		{
			aux = (long int)status3;
		}

		if ((long int) status4 > aux)
		{
			aux = (long int)status4;
		}	

	printf("%ld\n",aux);


	return 0;
}	