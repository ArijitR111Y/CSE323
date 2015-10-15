#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
main()
{
int i=0,j=0,n,pos;
char a[100],copy[100],b[50],ch;

printf("  Enter string : ");
gets(a);
strcpy(copy,a);
n=strlen(a);
printf("  Enter position : ");
scanf("%d",&pos);
if(pos>n)
{
printf("  Invalid position!!Enter again :" );
scanf("%d",&pos);
}
printf("  Enter the character : ");
ch=getche();
 
b[0]='d';
b[1]='l';
b[2]='e';
b[3]='s';
b[4]='t';
b[5]='x';
j=6;
while(i<n)
{
if(i==pos-1)
{
b[j]='d';
b[j+1]='l';
b[j+2]='e';
b[j+3]=ch;
b[j+4]='d';
b[j+5]='l';
b[j+6]='e';
j=j+7;
}
if(a[i]=='d' && a[i+1]=='l' && a[i+2]=='e')
{
b[j]='d';
b[j+1]='l';
b[j+2]='e';
j=j+3;
}
 
b[j]=a[i];
i++;
j++;
}
b[j]='d';
b[j+1]='l';
b[j+2]='e';
b[j+3]='e';
b[j+4]='t';
b[j+5]='x';
b[j+6]='\0';
printf("\n  Frame after stuffing:\n");
printf("  %s",b);
printf("\n  Frame after destuffing : \n");
printf("  %s",copy);
getch();
}
