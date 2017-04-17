#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER 256
int i = 0;

int main(void)

{
	int fd[2]; //criando File Descriptors pro pipe
	pid_t pid; // varaiável para armazenar o pid

	//Criando o pipe//
	if(pipe(fd) < 0)
	{
		perror("pipe");
		return -1;
	}

	//criando processo filho//
	if((pid = fork()) < 0)
	{
		perror("fork");
		exit(1);
	}

	// Processo Pai //
	if(pid > 0)
	{
		// No processo pai vamos escrever, então fechamos o pipe para leitura //
		close(fd[0]);

		char str[BUFFER] = "12345678910";
		printf("String enviada pelo pai no pipe: %s \n",str );

		// Escrevendo no pipe //
		for(i = 0 ;  i < sizeof(str); i++)
		{
			write(fd[1], str+i, 1);
			sleep(1);
		}
		
		exit(0);
	}

	else
	{
		char str_recebida[BUFFER];

		// No filho vamos ler, então fechamos o pipe para escrita.//
		close(fd[1]);

		// Lendo o que foi escrito no pipe.//

		for(i = 0 ;  i < 10; i++)
		{
		read(fd[0], str_recebida, 1);
		sleep(1);
		printf("String lida pelo filho no pipe: %s\n\n",str_recebida );
		}
		
		exit(0);

	}

	return 0;

	}

