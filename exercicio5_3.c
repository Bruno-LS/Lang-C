#include<stdio.h>
#include<string.h>

/*Desenvolver uma fun��o, em C, que, dada uma
string s e dada uma posi��o p desta string, crie duas
novas strings: s1 com os caracteres de s das
posi��es 0 a p-1; e s2 com os caracteres de s da
posi��o p � �ltima.
Nota: Caso p seja uma posi��o inv�lida, a fun��o
dever� retornar o valor 0; caso contr�rio,
proceder� com a cria��o das duas strings e
retornar� o valor 1.*/


int funcao(char vetor[], char vet1[], char vet2[], int p);

void main()
{
	int p;
	char s[20], s1[20], s2[20];
	
	fflush(stdin);
	printf("digite S: ");
	gets(s);
	
	printf("digite P: ");
	scanf("%d", &p);
	
	funcao(s, s1, s2, p);
	
	printf("s e': %s\n", s);
	
	printf("s1 e': %s\n", s1);
	
	printf("s2 e': %s\n", s2);
	
}


int funcao(char vetor[], char vet1[], char vet2[], int p)
{
	int i, l, j;
	
	l = strlen(vetor);

	if( (p<0) || (p>=l) )
	{
		return 0;
	}
	else
	{
		for(i=0, j=i;vetor[i];i++)
		{
			if(i<p)
			{
				vet1[i] = vetor[i];	
			}
			else
			{
				vet2[j] = vetor[i];
				j++;	
			}	
		}	
		
	}
	return 1;
	


}

