#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char nome_id[] = "nome.txt";
	int arq;

	arq = open(nome_id,O_RDWR | O_CREAT );
	
	if(arq == -1)
		printf("Erro, nao foi possivel abrir o arquivo\n");
	else{

		//write(arq,argv[1],sizeof(argv[1]));
		write(arq,&argv[2],5);
	}
close(arq);
	
}