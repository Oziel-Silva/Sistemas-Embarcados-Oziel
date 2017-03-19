#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char nome_id[] = "nome_id.txt";
	FILE *arq;

	char nome[100];
	int id;

	arq = fopen(nome_id,"w");
	
	if(arq == NULL)
		printf("Erro, nao foi possivel abrir o arquivo\n");
	else{

		printf("Insira o seu nome: ");
		scanf("%s",nome);
		
		printf ("Insira a sua idade: ");
		scanf ("%d",&id);

		fprintf(arq,"Nome: %s. \nIdade: %d\n",nome,id);
	}
fclose(arq);
	
}
