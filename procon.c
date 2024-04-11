#include <stdio.h>
#include <stdlib.h>

int full,empty,mutex,n,x;

int wait(int s);
int signal(int s);

void producer();
void consumer();

int main()
{
	printf("\n1.Producer\n2.Consumer\n3.Exit");
	empty = 3;
	full = 0;
	mutex = 1;
	
	while(1)
	{
		printf("\nEnter choice:");
		scanf("%d",&n);
		
		switch(n)
		{
			case 1:if(mutex==1 && empty!=0)
					{
						producer();
					}
					else
					{
						printf("buffer is full");
					}
					break;
					
			case 2:if(mutex==1 && full!=0)
					{
						consumer();
					}
					else
					{
						printf("buffer is empty");
					}
					break;
			case 3: exit(0);
					break;
			
		}
	}
	

	return 0;
}


int wait(s)
{
	return (--s);
}

int signal(s)
{
	return (++s);
}

void producer()
{
	mutex = wait(mutex);
	full = signal(full);
	empty = wait(empty);
	x++;
	printf("Producer produces item %d",x);
	mutex = signal(mutex);
}

void consumer()
{
	mutex = wait(mutex);
	full = wait(full);
	empty = signal(empty);
	printf("Consumer consumes item %d",x);
	x--;
	mutex = signal(mutex);
}
