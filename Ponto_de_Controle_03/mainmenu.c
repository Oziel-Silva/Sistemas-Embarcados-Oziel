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

void menu_principal(void)
{ 
	
	
	char parametro;
	char *param_envio;

	
	

	 do
    {
        
        printf("\n\tEscolha um cômodo\n\n");
        printf("1. quarto \n");
        printf("2. sala\n");
        printf("3. área externa\n");
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
