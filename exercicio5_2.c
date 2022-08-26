/*Questão 02:
Implementar uma função que, dadas duas
strings s1 e s2, crie uma nova string – s3 –
contendo todos os caracteres de s1 que não
estejam em s2.
Nota: em s3, não devem existir caracteres
repetidos.*/

#include<stdio.h>
#include<string.h>


/*
s1	a b c d e f
s2	a s i g e j
s3	b c d f
*/

void funcao(char s1[], char s2[], char s3[]);
int Buscar(char vetor[], char let);


void main()
{
	char s1[20], s2[20], s3[40];
	
	printf("digite S1: ");
	gets(s1);
	
	printf("\ndigite S2: ");
	fflush(stdin);
	gets(s2);
	
	printf("\n\nS1 e' : %s", s1);
	printf("\n\nS2 e' : %s", s2);
	
	funcao(s1, s2, s3);
	
	printf("\n\nS3 e' : %s", s3);
	
}


void funcao(char s1[], char s2[], char s3[])
{
	int i=0, c, r=0, j;
	
	
	c = strcmp(s1, s2);
	
	//testando se sao iguais
	if(c != 0)
	{							
		//percorrendo s2 para ver repetiçao
		while(s1[r])
		{
			j = Buscar(s2,s1[r]);
			if(j==-1)
			{
				s3[i] = s1[r];
				r++;
				i++;	
			}
			else
			{
				r++;
			}		
		}		
	}	
}

int Buscar(char vetor[], char let)
{
	int i;
	
	//percorrendo vetor
	for(i=0;vetor[i];i++)
	{
		if(vetor[i] == let)
		{
			return i;
		}								
	}
	return -1;
}

