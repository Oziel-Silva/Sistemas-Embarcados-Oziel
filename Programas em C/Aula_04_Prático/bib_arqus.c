#include <stdio.h>
 #include "bib_arqus.h"

int tam_arq_texto(char *nome_arquivo)
{
 
    //char nomeArquivo[100]; // nome do arquivo
    FILE *arquivo; // ponteiro para o arquivo
    long  int nBytes = 0; // tamanho em bytes do arquivo
     
    //printf("Digite o nome do arquivo: ");
    //scanf("%s", nomeArquivo);
 
    // abre o arquivo para leitura
    arquivo = fopen(nome_arquivo, "r");
 
    // verifica se o arquivo foi aberto com sucesso
    if (arquivo != NULL) {
        // movimenta a posição corrente de leitura no arquivo 
        // para o seu fim
        fseek(arquivo, 0, SEEK_END);
 
        // pega a posição corrente de leitura no arquivo
        nBytes = ftell(arquivo);
 
        // imprime o tamanho do arquivo
        printf("O arquivo %s possui %ld bytes\n",nome_arquivo, nBytes);
     
    } else {
        printf("Arquivo inexistente");
    }
 
    return 0;
 
}