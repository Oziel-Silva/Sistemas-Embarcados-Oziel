#include<stdio.h>
#include"arq_texto.h"

int main(int argc, char *argv[])
{
	
	char conteudo_principal [100];
	le_arq_texto(argv[1],conteudo_principal);
	return 0;
}