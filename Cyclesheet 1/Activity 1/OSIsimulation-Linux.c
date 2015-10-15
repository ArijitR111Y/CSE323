#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

struct Layer
{
	char data[50];
	struct Layer *next;
}*top=0,*p;

		void insert(char level[50])
		{
			struct Layer *node;
			node = (struct Layer*)malloc(sizeof(struct Layer));
			strcpy(node->data,level);
			node->next = 0;
			if(top==0)
			{
				top=node;
			}
			else
			{
				node->next=top;
				top=node;
				
			}
		}
		
		void receive()
		{
			top=top->next;
		}
		void display()
		{
			//cout<<top->data;
			for(p=top;p!=0;p=p->next)
			{
				printf("-> %s",p->data);
			}
			printf("\n\n");
		}
		
		
main()
{
	char ab[50];
	int i;
	printf("\nEnter a data to be sent\n");
	gets(ab);
	insert(ab);
	printf("\nChecking Connection\n\n");
	sleep(1000);
	printf("\nPassing through all layers\n");
	sleep(1000);
	char abc[20][20] ={"a","s","p","t","n","d","py"};
	for(i=0;i<7;i++) 
	{
		insert(abc[i]);
		display();
		sleep(1000);
	}
	printf("\nNo obstruction found\n");
	sleep(1000);
	printf("\nData Sent Successfully\n\n");
	sleep(2000);
	printf("\nReceiving.....\n\n");
	sleep(1000);
	for(i=0;i<7;i++) 
	{
		receive();
		display();
		sleep(1000);
	}
	printf("\nVerified\n");
	sleep(1000);
	printf("\nData received successfully\n");
}
