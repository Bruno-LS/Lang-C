#include<stdio.h>


/*Faça uma função que, dada uma matriz M8×5 de
reais, gere a matriz Mt, sua transposta.
*/


void funcao(int ma[][5], int transposta[][8]);


int main()
{
	int lin, col, matriz[8][5], transposta[5][8];

	for(lin=0;lin<8;lin++)
	{
		for(col=0;col<5;col++)
		{
			matriz[lin][col] = lin + col;
			printf(" |%d| ", matriz[lin][col]);
		}
		printf("\n");		
	}
	
	printf("\n\n\n\n\n");
	funcao(matriz, transposta);
	
}

void funcao(int ma[][5], int transposta[][8])
{
	int , lin, col;
	
	for(lin=0;lin<5;lin++)
	{
		for(col=0;col<8;col++)
		{
			transposta[lin][col] = ma[col][lin];
			printf(" |%d| ", transposta[lin][col]);
		}
		printf("\n");		
	}
	
}




