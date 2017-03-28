#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	char nome_id[] = "nome_id.txt";
	FILE *arq;

	arq = fopen(nome_id,"w");
	
	if(arq == NULL)
		printf("Erro, nao foi possivel abrir o arquivo\n");
	else{

		fprintf(arq,"Nome: %s. \nIdade: %s\n",argv[1],argv[2]);
	}
fclose(arq);
	
}