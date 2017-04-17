#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void funcao_para_control_c()
{
	printf("\nProcesso terminado!\n");
	
	exit(1);
}

void tratamento_alarme(int sig)
{
	system("ps aux --sort=-pcpu");
	// system("date +%s%3N");
	alarm(1);
}

int main()
{
	signal(SIGALRM, tratamento_alarme);
	signal(SIGINT, funcao_para_control_c);
	alarm(1);
	printf("Aperte CTRL+C para acabar:\n");
	while(1);
	return 0;
}