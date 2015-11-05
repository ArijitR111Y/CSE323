#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
int main()
{
  int i,j;
  char str[100],msg[100];
  printf("\nenter the message to be transmitted\n");
 // for(i=0;msg[i]!='\0';i++)
    scanf("%s",&msg);
  printf("\n\n...............transmitter...............");
  Sleep(2000);
  for(i=0;i<=7;i++)
  {
      switch(i)
       {
                 case 1:strcpy(str,"AH");
                        strcat(str,msg);
                        strcpy(msg,str);
                        printf("\napplication layer : %s\n",msg);
                        Sleep(2000);
                        break;
                 case 2:strcpy(str,"PH");
                        strcat(str,msg);
                        strcpy(msg,str);
                        printf("\npresentation layer : %s\n",msg);
                        Sleep(2000);
                        break;
                 case 3:strcpy(str,"SH");
                        strcat(str,msg);
                        strcpy(msg,str);
                        printf("\nsession layer : %s\n",msg);
                        Sleep(2000);
                        break;     
                 case 4:strcpy(str,"TH");
                        strcat(str,msg);
                        strcpy(msg,str);
                        printf("\ntransport layer : %s\n",msg);

                         Sleep(2000);         
                                        break;
                 case 5:strcpy(str,"NH");
                        strcat(str,msg);
                        strcpy(msg,str);
                        printf("\nnetwork layer : %s\n",msg);
                        Sleep(2000);
                        break;
                 case 6:strcpy(str,"DH");
                        strcat(str,msg);
                        strcpy(msg,str);
                        printf("\ndata link layer : %s\n",msg);
                        Sleep(2000);
                        break; 
                 case 7:printf("\nmessage entered into physical layer and was transmitted");
                 Sleep(2000);
                        break;
       }}
       printf("\n\n..................receiver....................\n");
       for(i=7;i>=1;i--)
       {
         switch(i)
         {
          
             case 1:printf("application layer : %s\n",msg);
                    strcpy(msg,msg+2);
                    Sleep(2000);
                    break;
             case 2:printf("presentation layer : %s\n",msg);
                    strcpy(msg,msg+2);
                    Sleep(2000);
                    break;
             case 3:printf("session layer : %s\n",msg);
                    strcpy(msg,msg+2);
                    Sleep(2000);
                    break;
             case 4:printf("transport layer : %s\n",msg);
                    strcpy(msg,msg+2);
                    Sleep(2000);
                    break;
             case 5:printf("network layer : %s\n",msg);
                    strcpy(msg,msg+2);
                    Sleep(2000);
                    break;
             case 6:printf("datalink layer : %s\n",msg);
                    strcpy(msg,msg+2);
                    Sleep(2000);
                    break;
             case 7:printf("message entered into physical layer and was received\n");
                    break;
         }
       }
       getch();
       return 0;
       
  }
 