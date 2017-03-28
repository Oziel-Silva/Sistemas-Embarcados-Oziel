#include<stdio.h>
#include<stdlib.h>
#include"bib_arqus.h"

void main(void){

	char arq [100];
	printf("Insira o nome do arquivo com a extensão\n");
	scanf("%s",arq);

	tam_arq_textonom(arq);
	
}