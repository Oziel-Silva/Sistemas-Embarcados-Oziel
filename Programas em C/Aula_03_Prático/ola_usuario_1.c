#include<stdio.h>
#include<stdlib.h>

main()
{
	char nome[10];
	printf("Digite seu nome:");
	gets(nome);
	printf("Ola %s \n",&nome);
	return 0;
}
