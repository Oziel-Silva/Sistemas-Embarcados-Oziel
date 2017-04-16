#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "bib_arqs.h"

int tam_arq_texto(char *nome_arquivo)
{
 	int arquivo;
    long  int nBytes = 0; // tamanho em bytes do arquivo
    
    arquivo = open(nome_arquivo,O_RDWR | O_CREAT | S_IRWXU); // PADRÃO POSIX
 	
 	if (arquivo == -1)
 	{
 		printf("Erro ao abrir/criar arquivo!!\n");
 	}
 	else
 	{
 		printf("O  arquivo foi criado com sucesso!!\n");
 	}
    return 0;
}