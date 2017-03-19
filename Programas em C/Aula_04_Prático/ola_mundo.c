#include<stdio.h>
#include<stdlib.h>

void main()
{
	char url[] = "ola_mundo.txt";
	FILE *fp;

	fp = fopen(url,"w");

	fprintf(fp, "Olá Mundo!!");

	if (fp == NULL)
	{
		printf("Impossível abrir o Arquivo %s\n",url);
	}
	else
	{
		printf("Arquivo %s criado com sucesso\n",url );
		fclose(fp);
	}

}
