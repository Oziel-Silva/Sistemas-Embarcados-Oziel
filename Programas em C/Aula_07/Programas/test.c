#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int pid;	// PID do processo filho
	int fd[2];	// Descritores do pipe
	int i;

	char mensagem[10] = "123456789";
	for(i = 0; i < strlen(mensagem); i++)
	printf(" %c\n",mensagem[i] );
	return 0;
}