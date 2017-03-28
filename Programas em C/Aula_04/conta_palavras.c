#include <stdio.h>
#include <string.h>
//#include"conta_palavras.h"

void main(void)
{
	char string[]="palmeiras minha vida e palmeiras";
	char palavra[]="palmeiras";
	char *str1[100];
	char str [50];
	int i = 0, j;
	int conta = 0;
	int x = 0;
	FILE *arquivo;

			



	arquivo = fopen("ola.txt","r");

	if(arquivo == NULL)
		printf("Não foi posssivel abrir o arquivo\n");
	else
		while (fgets(str,10, arquivo)!= NULL)
			{
				str1[i] = strdup(str);
				i++;
			}
	
	printf("%s \n",str1[0]);
	printf("%d\n",i );
	fclose(arquivo);
}