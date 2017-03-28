#include<stdio.h>
#include"arq_texto.h"

void le_arq_texto(char *nome_arquivo, char *conteudo)
{
	
	char str;
	char str1[100];
	FILE *arquivo;

	arquivo = fopen(nome_arquivo,"r");
	if(arquivo == NULL)
		printf("Não foi posssivel abrir o arquivo\n");
	else
		while(fgets(conteudo, sizeof(str1), arquivo) != NULL)
			printf("%s",conteudo);

	fclose(arquivo);


}