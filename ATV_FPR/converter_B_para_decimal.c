#include<stdio.h>
#include<string.h>

#define T 10

int validar(char s[]);
int converter(char s[]);

void main()
{
	char string[T]={"100"};
	
	converter(string);
}

int converter(char s[])
{
	int i, l, j, con=0, dois;
	
	l = strlen(s);
	
	if(validar(s)==0)
	{
		return -1;
	}
	else
	{
		for(i=l-1;i>=0;i--)
		{
			
			dois=1;
			if(i==l-1)
			{
				if(s[i]=='1')
				{
					con+=1;
				}
			}
			else
			{
				if(s[i]=='1')
				{
					for(j=1;j<(l-i);j++)
					{
						dois=dois*2;
					}
					con+=dois;
				}
			}
		}
		return con;	
	}
	
}


int validar(char s[])
{
	int i;
	
	for(i=0;s[i];i++)
	{
		if( (s[i]<'0') || (s[i]>'1') )
		{
			return 0;
		}
	}
	return 1;
	
}
