#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	pid_t pid_filho1 = fork();

	
	if (pid_filho1 == 0)
	{
		

		pid_t pid_filho2 = fork();

		if (pid_filho2 == 0)
		{
			printf("Eu sou o filho 2 \n");
		}
		else
			printf("Eu sou o filho 1 \n");
			


	}
	else
		printf("Eu sou o pai!\n");

return 0;
}