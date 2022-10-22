#include<stdio.h>


/*Implementar uma função que, dada uma matriz
M10×8, gere um vetor V de tamanho 8, onde
cada elemento do vetor consiste na soma dos
elementos de uma coluna de M. Ou seja, o
elemento V[0] consiste na soma dos elementos
da primeira coluna de M, o elemento V[1]
consiste na soma dos elementos da segunda
coluna de M, e assim por diante.*/

#define COL 8
#define LIN 10
void funcao(int ma[][COL]);


int main()
{
	int lin, col, matriz[LIN][COL];

	for(lin=0;lin<LIN;lin++)
	{
		for(col=0;col<COL;col++)
		{
			matriz[lin][col] = lin + col;
			printf(" |%d| ", matriz[lin][col]);
		}
		printf("\n");		
	}
	
	printf("\n\n\n");
	funcao(matriz);
	
}

void funcao(int ma[][COL])
{
	int lin, col, cont, vet[COL];
	
	
	for(col=0;col<COL;col++)
	{
		for(lin=0, cont=0;lin<LIN;lin++)
		{
			cont += ma[lin][col];
		}
		vet[col] = cont;
		printf("%d\n", vet[col]);		
	}
	
}
