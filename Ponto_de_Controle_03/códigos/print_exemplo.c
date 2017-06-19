#include <stdio.h>
#include <stdlib.h>

void print_exemplo()
{
		puts("   Este programa cria um cliente que se comunica");
		puts("   a um servidor TCP/IP na porta especificada");
		puts("   pelo usuario. Para permitir que o cliente comunique-se");
		puts("   com este servidor, o servidor deve ser");
		puts("   executado inicialmente com uma porta definida,");
		puts("   e o cliente devera ser executado em outra");
		puts("   janela ou em outra aba do terminal, utilizando");
		puts("   a mesma porta. O servidor escreve na tela");
		puts("   todo texto enviado pelo cliente. Se o cliente");
		puts(" f  transmitir o texto \"sair\", o servidor se");
		puts("   encerra. Se o usuario pressionar CTRL-C para");
		puts("   o servidor, ele tambem se encerra.");
		puts("   encerra.");
		puts("   Modo de Uso:");
		printf("       <IP do Servidor> <Porta do servidor> <Mensagem>\n");
		printf("   Exemplo: 127.0.0.1 8000 \"Ola socket\"\n");
		exit(1);
}
