#include<stdio.h>
#include<string.h>
#include<conio.h>
int main()
{
	char dle[]="*",stx[]="#",etx[]="$",data[20],result[30];
	int i,j,len;
	printf("\nDLE=%s\nSTX=%s\nETX=%s",dle,stx,etx);
	printf("\n\nEnter the data\n");
	gets(data);
	len=strlen(data);
	strcpy(result,dle);
	strcat(result,stx);
	for(i=0;i<len;i++)
	{
		if(data[i]=='*')
		{
			strcat(result,"**");
		}
		else
		{
			int temp=strlen(result);
			result[temp]=data[i];
		}
	}
	strcat(result,dle);
	strcat(result,etx);
	printf("\n\nData Transmitted\n");
	puts(result);
	getch();
	return 0;