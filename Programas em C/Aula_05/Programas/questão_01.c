#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>	// Para a funcao open()
#include <unistd.h>	// Para a funcao close()


void main()
{
	char name_file[] = "ola_mundo.txt";
	int filepointer;
	char string[]= "Olá Mundo!!\n";

	filepointer = open(name_file, O_RDWR | O_CREAT);

	

	if (filepointer == -1)
		{
			printf("Impossível abrir o Arquivo %s\n",name_file);
		}
	else
		{

			write(filepointer, &string, sizeof(string));
			printf("Arquivo %s criado com sucesso\n",name_file);
		}
	close(filepointer);

}
