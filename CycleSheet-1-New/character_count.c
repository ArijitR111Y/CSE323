#include<iostream>
#include<string.h>
using namespace std;
char input[10][20];
int get_input();
void make_frames(int);
int count_chars(int s);
int main()
{
	int no_of_words=get_input();
	make_frames(no_of_words);
	return 0;
}
int get_input()
{
	int answer;
	int i=0;
	do
	{
		cout<<"\nEnter the word";
		cin>>input[i];
		cout<<"\ndo you want to continue: (yes:1 | no:0)";
		cin>>answer;
		i++; 
	}
	while(answer!=0);
	return i;
}
void make_frames(int num_words)
{
	int i=0;
	cout<<"The transmitted data is:\n\t";
	for(i;i<num_words;i++)
	{
		cout<<count_chars(i)+1<<input[i];
	}
	cout<<"\n\n";
}
int count_chars(int index)
{
	int i=0;
	while(input [index][i]!='\0')
		i++;
	return i;
}