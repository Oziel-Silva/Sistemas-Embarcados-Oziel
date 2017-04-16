#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "bib_arqs.h"



void main(void)
{
	char arq[20];

	printf("Insira o nome do aquivo com a extensão!!\nEx: livros.txt\n");
	scanf("%s",arq);
	tam_arq_texto(arq);
	//printf("%s\n",arq);
	
}