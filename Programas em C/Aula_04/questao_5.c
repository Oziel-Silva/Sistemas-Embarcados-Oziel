#include<stdio.h>
#include"arq_texto.h"

void main(void)
{
	char string[]= "nome_id.txt" ;
	char conteudo_principal [100];
	le_arq_texto(string,conteudo_principal);
}