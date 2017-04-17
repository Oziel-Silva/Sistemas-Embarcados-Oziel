#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int v_global = 0; // Variavel global para este exemplo
int id_atual;	  
	void Incrementa_Variavel_Global( pid_t id_atual)
	{
		v_global++;
		printf("ID do processo que executou esta funcao = %d\n", id_atual);
		printf("v_global = %d\n", v_global);
	}

int main(int argc, const char *argv[])
{
	
	pid_t pid_pai = getpid();

	printf("O pid desse  processo é %d\n",pid_pai );
	//printf("O  valor da variavel global é %d\n",v_global );
	//printf("chamando a função que incrementa a variavel...\n");

	pid_t pid_filho1 = fork();

	if (pid_filho1 != 0)
	{
		Incrementa_Variavel_Global(pid_filho1);
		pid_t pid_filho2 = fork();

		if (pid_filho2 != 0)
		{
			Incrementa_Variavel_Global(pid_filho2);
			pid_t pid_filho3 = fork();

			if (pid_filho3 != 0)
			{
				Incrementa_Variavel_Global(pid_filho3);
			}
		}
	}
	

return 0;
}