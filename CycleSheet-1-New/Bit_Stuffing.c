#include<stdio.h>
#include<string.h>
#include<conio.h>
int main()
{
	char flag[]="01111110",data[100],result[100];
	int count=0,i;
	printf("\nEnter the binary data\n");
	gets(data);
	strcpy(result,flag);
	int len=strlen(data);
	printf("\nlength of data is %d",len);
//stuffing of data
	for(i=0;i<len;i++)
	{
		if(data[i]=='1')
		{
			count++;
			if(count==5)
			{
				strcat(result,"1");
				strcat(result,"0");
				count=0;
			}
			else
				strcat(result,"1");
			
		}
		else
		{
			count=0;
			strcat(result,"0");
		}
	}
	strcat(result,flag);
	printf("Data received by receiver.......\n");
	puts(result);
	strcpy(result,"");
	//destuffing of data
		for(i=0;i<len;i++)
	{
		if(data[i]=='1')
		{
			count++;
			if(count==5)
			{
				strcat(result,"1");
				strcat(result,"0");
				count=0;
			}
			else
				strcat(result,"1");
		}
		else
		{
			count=0;
			strcat(result,"0");
		}
	}
	printf("\nreceiver's network layer.......\n");
	puts(result);
	getch();
	return 0;