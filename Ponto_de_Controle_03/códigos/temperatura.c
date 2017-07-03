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

void temperatura(char* parametro)
{	char* text;
	int length_rx, length;
	float temp ;
	float rx_temp;
	int socket = conect();


    length = strlen(parametro);
	write(socket, &length, sizeof(length));
	write(socket, parametro, length);

	read(socket, &length_rx, sizeof (length_rx));
	text = (char*) malloc (length_rx);
 	read(socket, text, length_rx);

 	rx_temp = atoi(text);

 	temp = (rx_temp*3.3/1023)/0.1;

	fprintf(stderr,"\n\n   Temperatura do ambiente é de: %2f °C\n\n", temp);
	free (text);
	sleep(2);
	system("clear");
	menu_principal();

}
