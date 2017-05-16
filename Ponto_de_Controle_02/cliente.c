#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <unistd.h>

	void chama_opcao(void);
	void print_exemplo(void);
	void sensores(void);
	void menu(void);
	void quarto(char *parametro);
	void sala(char *parametro);
	void opcao_1(void);
	int conect(void);
	void menu_principal(void);
	void temperatura(char* parametro);

	char IP_Servidor[] = "192.168.43.196";
	int socket_id;
	struct sockaddr_in servidorAddr;
	int length;
	unsigned short servidorPorta = 9000;
	char* text;
	
	

int main (int argc, char* const argv[])
{
	menu_principal();
	return 0;
}

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

void menu_principal(void)
{ 
	
	
	char parametro;
	char *param_envio;

	
	

	 do
    {
        
        printf("\n\tEscolha um cômodo ou a funcionalidade\n\n");
        printf("1. quarto \n");
        printf("2. sala\n");
        printf("3. camera externa \n");
        printf("0. sair\n");

        scanf(" %c", &parametro);
        system("clear");  
        
        
        switch(parametro)
        {
            case '1' :
            	param_envio = "1";
            	quarto(param_envio);
                break;

            case '2' :
           		param_envio = "2";
            	sala(param_envio);
                
                break;

            case '3' :
            	//sala();                
                break;

            case '0' :
                exit(1);
                break;

            default:
                printf("Digite uma opcao valida\n");
        }
    } while(parametro);
}

void quarto(char *parametro)
{
	
	 
	 char* param_envio;
	 char escolha;

	sleep(1);
	
	
  do
    {
        printf("\n\tEscolha uma funcionalidade\n\n");
        printf("1. Tomadas\n");
        printf("2. Temperatura do recinto\n");
        printf("0. Voltar ao menu anterior\n");

        scanf(" %c", &escolha);

        system("clear");

        switch(escolha)
        {
            case '1':
            	//param_envio = "1";
            	//tomadas();
           		
            	break;
            case '2':
            	param_envio = "1";
            	temperatura(param_envio);
            	break; 
            case '0':
            	//param_envio = "1";
            	menu_principal();             

            default:
                printf("Digite uma opcao valida\n");
        }
    } while(param_envio);
}

void sala(char *parametro)
{
	
	 
	 char* param_envio;
	 char escolha;

	sleep(1);
	
	
  do
    {
        printf("\n\tEscolha uma funcionalidade\n\n");
        printf("1. Tomadas\n");
        printf("2. Temperatura do recinto\n");
        printf("0. Voltar ao menu anterior\n");

        scanf(" %c", &escolha);

        system("clear");

        switch(escolha)
        {
            case '1':
            	//param_envio = "1";
            	//tomadas();
           		
            	break;
            case '2':
            	param_envio = "2";
            	temperatura(param_envio);
            	break; 
            case '0':
            	//param_envio = "1";
            	menu_principal();             

            default:
                printf("Digite uma opcao valida\n");
        }
    } while(param_envio);
}


int conect(void)
{
    socket_id = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(socket_id < 0)
	{
		fprintf(stderr, "Erro na criacao do socket!\n");
		exit(0);
	}
	 
	memset(&servidorAddr, 0, sizeof(servidorAddr)); // Zerando a estrutura de dados
	servidorAddr.sin_family = AF_INET;
	servidorAddr.sin_addr.s_addr = inet_addr(IP_Servidor);
	servidorAddr.sin_port = htons(servidorPorta);
	if(connect(socket_id, (struct sockaddr *) &servidorAddr,sizeof(servidorAddr)) < 0)
	{
		fprintf(stderr, "Erro na conexao!\n");
		exit(0);
	}

	return socket_id;
}

void temperatura(char* parametro)
{	char* text;
	int length_rx;
	int temp ;
	int rx_temp;
	int socket = conect();


    length = strlen(parametro);
	write(socket, &length, sizeof(length));
	write(socket, parametro, length);

	read(socket, &length_rx, sizeof (length_rx));
	text = (char*) malloc (length_rx);
 	read(socket, text, length_rx);

 	rx_temp = atoi(text);

 	temp = (100 * rx_temp)/1024;

	fprintf(stderr,"\n\n   Temperatura do ambiente é de: %d °C\n\n", temp);
	free (text);
	sleep(2);
	system("clear");
	menu_principal();

}