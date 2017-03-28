#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
	char nome_id[] = "nome_id.txt";
	int arquivo;
	char string_nome[10];
	char string_idade[2];

	arquivo = open(nome_id, O_RDWR | O_CREAT);
	
	if(arquivo == -1)
		printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
		printf("Digite o seu nome:\n");
		scanf("%s",string_nome);
		printf("Digite sua idade:\n");
		scanf("%s",string_idade);

		write(arquivo,"Nome:",sizeof("Nome\n"));

		write(arquivo,&string_nome,sizeof(string_nome));
		write(arquivo,"\nIdade:",sizeof("\nIdade"));
		write(arquivo,&string_idade,sizeof(string_idade));
		write(arquivo,"\n:",sizeof("\n"));
	}
close(arquivo);
	
}