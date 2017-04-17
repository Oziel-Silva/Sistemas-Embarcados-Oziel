#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int i =0;

	for (i = 1 ; i < argc ; ++i)
		system(argv[i]);

	printf("%d \n",argc );

	return 0;
}