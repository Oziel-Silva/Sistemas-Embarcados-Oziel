#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	printf("ola %s\n",argv[1]);
	printf("numero de entradas : %d\n",(argc-1));
	return 0;
}
