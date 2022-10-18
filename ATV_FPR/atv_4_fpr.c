#include<stdio.h>
#include<string.h>

int aux(char s[]);
int num_final(char s[], int l, int i);

void main()
{ 
	char s[]={"ab123b"};
	
	aux(s);
}

int aux(char s[])
{
	int l;
	
	l = strlen(s);
	
	return num_final(s, l-1, 0);
	
}

//RECURSIVO
int num_final(char s[], int l, int i)
{
	if(i<l)
	{
		//SE FOR CARACTER
		if( (s[i]<'0') || (s[i]>'9') )
		{
			return num_final(s, l, i+1);
		}
		//SE FOR NUMERO E O PROXIMO CARACTER
		else if( (s[i+1]<'0') || (s[i+1]>'9') )
		{
			return 0;
		}
		// SE O PROXIMO FOR NUMERO MESMO
		else
		{
			return num_final(s, l, i+1);
		}
	}
	//SE NAO DER CARAC. DEPOIS DE NUM.
	return 1;	
}
