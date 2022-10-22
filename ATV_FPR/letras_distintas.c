#include<stdio.h>
#include<string.h>

int todos_distintos(char s[]);

void main()
{
	char s[]={"abcde"};

	todos_distintos(s);

int todos_distintos(char s[])
{
	int l, i, j;
	
	l = strlen(s);

	for(i=0;i<l;i++)
	{
		for(j=i+1;j<l;j++)
		{
			if(s[i]==s[j])
			{
				return 0;
			}
		}
	}
	return 1;

}
