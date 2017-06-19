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

void request_camera(char* parametro)
{	char* text;
	int length_rx, length;
	int temp ;
	int rx_temp;
	int socket = conect();


    length = strlen(parametro);
	write(socket, &length, sizeof(length));
	write(socket, parametro, length);

	
	menu_principal();

}
