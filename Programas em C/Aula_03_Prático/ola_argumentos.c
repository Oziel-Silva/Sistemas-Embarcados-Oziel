#include <stdlib.h>
#include <stdio.h>

main(int argc, char **argv)
{
	printf("argumentos:");
int i=0;
for ( i=0; i<argc; i++){
	printf("%s ",argv[i]);
}
printf("\n");
return 0;
}
