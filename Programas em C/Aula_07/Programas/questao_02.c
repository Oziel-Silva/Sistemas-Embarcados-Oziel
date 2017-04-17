#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER 256
int i = 0;

int main(void)

{
	int pip1[2],pip2[2],pip3[2],pip4[2]; //criando File Descriptors pro pipe
	pid_t pid; // varaiável para armazenar o pid

	//Criando o pipe//
	if(pipe(pip1) < 0)
	{
		perror("pipe");
		return -1;
	}
	if(pipe(pip2) < 0)
	{
		perror("pipe");
		return -1;
	}
	if(pipe(pip3) < 0)
	{
		perror("pipe");
		return -1;
	}
	if(pipe(pip4) < 0)
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
		

		char str1_enviada_pai[BUFFER] = "Não façais nada violento, praticai somente aquilo que é justo e equilibrado.";
		char str2_enviada_pai[BUFFER] = "Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...";
		char str_buffer_pai[BUFFER];
		
			close(pip1[1]);// fechando para escrita 
			//lendo o pipe
			read(pip1[0], str_buffer_pai, sizeof(str_buffer_pai));
			sleep(1);
			printf("FILHO: %s\n",str_buffer_pai);

			close(pip2[0]);//fechando para leitura
			write(pip2[1], str1_enviada_pai, sizeof(str1_enviada_pai)+1);
			sleep(2);

			close(pip3[1]);
			read(pip3[0],str_buffer_pai,sizeof(str_buffer_pai));
			sleep(1);
			printf("FILHO: %s\n",str_buffer_pai);

			close(pip4[0]);
			write(pip4[1], str2_enviada_pai,sizeof(str2_enviada_pai) + 1);
			sleep(1);
		
		
		exit(0);
	}

	else
	{
		char str1_enviada_filho[BUFFER]= "Pai, qual é a verdadeira essência da sabedoria?";
		char str2_enviada_filho[BUFFER] = "Mas até uma criança de três anos sabe disso!";
		char str_buffer_filho[BUFFER];

		// Para esse exemplo o filho vai escrever e ler//
		// Para escrever fechamos o pipe para leitura //

		close(pip1[0]);//fechando para leitura
		write(pip1[1], str1_enviada_filho, sizeof(str1_enviada_filho)+1);
		sleep(1);
		
		close(pip2[1]); //fechando para escrita
		read(pip2[0],str_buffer_filho,sizeof(str_buffer_filho));
		sleep(1);
		printf("PAI: %s\n",str_buffer_filho);

		close(pip3[0]);
		write(pip3[1],str2_enviada_filho,sizeof(str2_enviada_filho) +1);
		sleep(1);
		
		close(pip4[1]);
		read(pip4[0],str_buffer_filho,sizeof(str_buffer_filho));
		sleep(1);
		printf("PAI: %s\n",str_buffer_filho);
		sleep(1);
	
		
		exit(0);

	}

	return 0;

	}
