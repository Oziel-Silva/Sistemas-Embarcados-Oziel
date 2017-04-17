#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	pid_t pid_filho1;
	printf("Eu sou o processo pai com ID de %d \n",getpid() );

	pid_filho1 = fork();

	if(pid_filho1 != 0)
	{
		pid_t pid_filho2;
		printf("Eu sou o filho 1 com ID de %d \n",pid_filho1);

		pid_filho2 = fork();

		if (pid_filho2 != 0)
		{
			printf("Eu sou o filho 2 com ID de %d \n",pid_filho2 );

			pid_t pid_filho3 = fork();

			if (pid_filho3 != 0 )
			{
				printf("Eu sou o filho 3 com ID de %d \n",pid_filho3 );
			}
			else
			{
				
			}
		}
		else
		{

		}
	}

	else
	{

	}
}