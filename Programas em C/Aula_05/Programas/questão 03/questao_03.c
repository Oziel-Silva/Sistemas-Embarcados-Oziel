#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char nome[10];
	strcpy(nome,argv[1]);
	int arq;
	strcat(nome,".txt");
	arq = open(nome,O_RDWR | O_CREAT | S_IRWXU);
	
	if(arq == -1)
		printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
		write(arq,"nome :",strlen("nome: "));	
		write(arq,argv[1],strlen(argv[1]));
		write(arq,"\n",strlen("\n"));
		write(arq,"Idade: ",strlen("Idade: "));
		write(arq,argv[2],strlen(argv[2]));
		write(arq,"\n",strlen("\n"));
		
		}
	
close(arq);
	
}