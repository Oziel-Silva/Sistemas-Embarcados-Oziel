#include<stdio.h>
#include"conta_palavras.h"

int main(int argc, char *argv[])
{
	
	char conteudo_principal [100];
	le_arq_texto(argv[1],argv[2],conteudo_principal);
	return 0;
}