#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
struct char_print_parms
{
	char character;
	int count;
};
void  *char_print (void* parameters)
	{
		struct char_print_parms *p = (struct char_print_parms*) parameters;
		int i;
		for (i = 0; i < 10; i++)
		{
			printf("%d\n", p -> count +i);
			sleep(1);
		}
			
		return NULL;
	}
int main ()
{
	pthread_t thread1_id;
	
	struct char_print_parms thread1_args;	
	thread1_args.character = '1';
	thread1_args.count = 1;

	pthread_create (&thread1_id, NULL, &char_print, &thread1_args);
	

	pthread_join (thread1_id, NULL);
	
	
return 0;
}