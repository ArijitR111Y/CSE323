#include <stdio.h> 
#include <conio.h> 

void main() 
{ 
char num[11], i, j, k, cnt=0; 

printf("Enter the sequence of 10 digit binary numbers: "); 
for(i=0;i<10;i++) 
scanf("%c", &num[i]); 
printf("The 10 digit binary number you have entered is: "); 
for(i=0;i<10;i++) 
printf("%c", num[i]); 
printf("\nAfter stuffing: "); 
i=0; 
while (i<10) 
{ 
if(num[i]=='1') 
{ 
i++; 
cnt++; 
if(cnt==5) 
{ 
for(k=11;k>i;k--) 
num[k]=num[k-1]; 
num[i]=0; 
num[i]='0'; 
} 
} 
else 
{ 
i++; 
cnt=0; 
} 
} 
for(i=0;i<11;i++) 
printf("%c", num[i]); 
printf("\nAfter destuffing: "); 
i=0; 
while (i<10) 
{ 
if(num[i]=='1') 
{ 
i++; 
cnt++; 
if(cnt==5) 
{ 
for(k=i;k<11;k++) 
num[k]=num[k+1]; 
} 
} 
else 
{ 
i++; 
cnt=0; 
} 
} 
for(i=0;i<10;i++) 
printf("%d", num[i]-48); 
getch(); 
}
