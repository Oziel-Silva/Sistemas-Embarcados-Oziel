#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <unistd.h>
#include "mainmenu.h"
#include "quarto.h"
#include "sala.h"
#include "conect.h"
#include "temperatura.h"
#include "request_camera.h"
void quarto(char *parametro)
{
	
	 
	 char* param_envio;
	 char escolha;
    
	
  do
    {
        printf("\n\tEscolha uma funcionalidade\n\n");
        printf("1. Tomadas\n");
        printf("2. Temperatura do recinto\n");
        printf("3. camera quarto\n");
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
            case '3':
                param_envio = "3";
                request_camera(param_envio); 
            case '0':
            	//param_envio = "1";
            	menu_principal();             

            default:
                printf("Digite uma opcao valida\n");
        }
    } while(param_envio);
}

