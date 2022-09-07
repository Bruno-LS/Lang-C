#include<stdio.h>


/*QUESTÃO 02:
Desenvolver uma função que, dada uma matriz
M15×20, determine se um número X se encontra
na linha L da matriz.*/


int funcao(int ma[15][20], int x, int l);


int main()
{
	int lin, col, matriz[15][20], l, x, pos;

	srand (time(NULL));

	for(lin=0;lin<15;lin++)
	{
		for(col=0;col<20;col++)
		{
			matriz[lin][col] = rand ()%10;;
			printf("|%d|", matriz[lin][col]);
		}
		printf("\n");		
	}
	
	
	printf("\n\nDigite o X: ");
	scanf("%d", &x);
	
	printf("\nDigite o L: ");
	scanf("%d", &l);
	
	
	
	printf("\n\n\n");
	pos = funcao(matriz, x, l);

	if(pos == 1)
	{
		printf("SIM");
		
	}
	else
	{
		printf("NAO");
	}
		
	
}

int funcao(int ma[][20], int x, int l)
{
	int col;
	
	//sleep(2);	
	for(col=0;col<20;col++)
	{
		if(ma[l][col] == x)
		{
			return 1;
		} 
		
	}
			
	
	
}
