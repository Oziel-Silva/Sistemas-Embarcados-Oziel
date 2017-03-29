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
	
	pid_t pid_filho1 = fork();

	
	if (pid_filho1 == 0)
		{
			pid_t pid_filho2 = fork();

			if (pid_filho2 == 0)
			{
				id_atual = getpid();
			
				Incrementa_Variavel_Global( id_atual);
			}
				else
				{
			  		id_atual = getpid();
			
					Incrementa_Variavel_Global( id_atual);
				}	
		}
	
	else
		{
			id_atual = getpid();		
			Incrementa_Variavel_Global( id_atual);
		}
		
return 0;
}