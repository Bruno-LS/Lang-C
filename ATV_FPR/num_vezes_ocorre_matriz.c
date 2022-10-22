#include<stdio.h>
#include<stdlib.h>

#define ROW 5
#define COL 5

int aparecem(int matriz[ROW][COL], int vet[], int L);

void main()
{
	int vet[COL]={0,0,0,0,0}, lin=1;

	int matriz[ROW][COL] ={	
	{1, 5, 7, 1, 6},
	{6, 2, 1, 4, 7,},
	{3, 6, 9, 7, 1},
	{2, 4, 5, 7, 4},
	{2, 4, 8, 9, 2} };
	
	aparecem(matriz, vet, lin);
	
}

int aparecem(int matriz[ROW][COL], int vet[], int L)
{
	int p, i, j, o;
		
	//percorrer somente as colunas da linha L
	for(o=0;o<COL;o++)
	{
		//percorrer as linhas da matriz
		for(i=0;i<ROW;i++)
		{
			//verificar se é a linha L da matriz e pular 
			if(i!=L)
			{
				//percorrer as colunas da matriz 
				for(j=0;j<COL;j++)
				{
					//verificar se quantos elementos tem de cada numero na linha L
					if(matriz[L][o]==matriz[i][j])
					{
						vet[o]++;
					}
				}
			}
		}
	}
	
}
