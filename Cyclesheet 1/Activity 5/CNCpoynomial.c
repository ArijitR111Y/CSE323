#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

char data[100],pattern[100];
int datalength,patternLength;
char rem[10];
int i,j,count=0,num;


void xor()
{
	
	for(i=1;i<patternLength;i++)
	{
		rem[i]=((rem[i]==pattern[i])?'0':'1');
	}
}

void crc()
{
	for(num=0;num<patternLength;num++)
		rem[num]=data[num];
	do
	{
		if(rem[0]=='1')
		xor();
		for(i=0;i<patternLength-1;i++)
		{
			rem[i]=rem[i+1];
		}
		rem[i]=data[num++];
} while (num<=datalength+patternLength-1);	
}

int main()
{
	printf("Enter the data :");
	scanf("%s",data);
	printf("-------------------------------------------------------------------\n");
	datalength = strlen(data);
	printf("Enter the generating Pattern:");
	scanf("%s",pattern);
	printf("-------------------------------------------------------------------\n");
	patternLength = strlen(pattern);
	for (i = datalength; i < datalength+patternLength-1; i++)
	{
		data[i]='0';
	}
	printf("-------------------------------------------------------------------\n");
	
	printf("\nModifying the data\n");
	Sleep(1000);
	printf("-------------------------------------------------------------------\n");
	crc();
	printf("\nData Modified\n");
	printf("-------------------------------------------------------------------\n");
	printf("\nModified Data:");
	for (i = datalength,j=0; i < datalength+patternLength-1; i++,j++)
	{
		data[i]=rem[j];
	}
	printf("%s\n",data);
	Sleep(1000);
	printf("-------------------------------------------------------------------\n");
	printf("\nSending the modified data\n");
	Sleep(2000);
	printf("\nData Sent\n");
	printf("-------------------------------------------------------------------\n");
	printf("-------------------------------------------------------------------\n");
	Sleep(2000);
	printf("\nRecieving the Data\n");
	Sleep(1000);
	printf("-------------------------------------------------------------------\n");
	printf("\nChecking for error bits\n");
	crc();
	printf("-------------------------------------------------------------------\n");
	for(i=0;i<strlen(rem);i++)
	{
		if(rem[i]=='0')
		count++;
	}
	Sleep(2000);
	if(count==strlen(rem))
	{
		printf("\nData Received Successfully");
	}
	else
	{
		printf("Parity Error");
	}
}





