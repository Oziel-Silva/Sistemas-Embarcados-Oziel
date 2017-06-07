#include <stdio.h>
#include <stdlib.h>

int main() {
  
  
 char buffer[12];
int i = 20;
snprintf(buffer, 12,"%d",i);

printf("%s",buffer);

  return 0;
}

