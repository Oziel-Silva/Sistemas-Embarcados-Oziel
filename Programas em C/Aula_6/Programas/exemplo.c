#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
      execl("/bin/ls","ls","exemplo.c",NULL) ;
      printf ("Eu ainda nao estou morto\n") ;
      exit(0);
}