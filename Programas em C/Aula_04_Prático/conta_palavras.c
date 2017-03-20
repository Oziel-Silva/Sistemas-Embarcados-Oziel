#include<stdio.h>
#include"conta_palavras.h"

void le_arq_texto(char *palavra, char *nome_arquivo, char *conteudo)
{
	
	int i,j;
	for(i=0; palavra[i] != '\0'; i++);

	char str1[100];
	FILE *arquivo;

	arquivo = fopen(nome_arquivo,"r");
	if(arquivo == NULL)
		printf("Não foi posssivel abrir o arquivo\n");
	else
		while((srt1 = fgetc(arquivo)) != EOF)
		{
			for (j= 0;str1[i]==conteudo[i]; ++i)
			{	if (j == i)
				{
					break;
				}
				/* code */
			}
		}

	fclose(arquivo);


}