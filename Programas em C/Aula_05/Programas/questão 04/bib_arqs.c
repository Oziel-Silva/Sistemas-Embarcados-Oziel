#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "bib_arqs.h"

int tam_arq_texto(char *nome_arquivo)
{
 	int arquivo;
    int nBytes = 0; // tamanho em bytes do arquivo
    
    arquivo = open(nome_arquivo,O_RDONLY); // PADRÃO POSIX

	lseek(arquivo,0,SEEK_END);
 	nBytes = ftell(arquivo);
 }