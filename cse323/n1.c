#include<string.h>

char* encoder(char message[],char src[],char dest[])
{
	i=0;
	char encmsg[100];
	strcat(encmsg,src)
	strcat(encmsg,dest)
	while(message[i]!='\0')
	{
		switch(message[i])
		{
		case 'a':strcat(encmsg,'000');break;
		case 'b':strcat(encmsg,'001');break;
		case 'c':strcat(encmsg,'010');break;
		case 'd':strcat(encmsg,'011');break;
		case 'e':strcat(encmsg,'100');break;
		case 'f':strcat(encmsg,'101');break;
		case 'g':strcat(encmsg,'110');break;
		case '\0':strcat(encmsg,'111');break;
		default:printf('Error\n')
		}
	}
}

void main()
{
	char srcmac[12]
}
