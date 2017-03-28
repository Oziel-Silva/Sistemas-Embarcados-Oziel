#include<stdio.h>
#include<stdlib.h>

void main()
{
	char name_file[] = "ola_mundo.txt";
	FILE *filepointer;

	filepointer = fopen(name_file,"w");

	

	if (filepointer == NULL)
		{
			printf("Impossível abrir o Arquivo %s\n",name_file);
		}
	else
		{
			fprintf(filepointer, "Olá Mundo!!\n");
			printf("Arquivo %s criado com sucesso\n",name_file);
		}
	fclose(filepointer);

}
