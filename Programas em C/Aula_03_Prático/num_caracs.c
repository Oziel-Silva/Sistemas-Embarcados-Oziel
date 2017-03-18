#include <stdio.h>
#include "num_caracs.h"

int Num_Caracs(char *string)
{
	int contador_str = 0;
	int temp1 = 0;

	while(string[contador_str]!= '\0')
	{
		
		printf("%s\n",&string[contador_str] );
		contador_str = contador_str + 1;
		
	}
	printf("Números de caracteres = %d\n",contador_str);
	return 0;
}