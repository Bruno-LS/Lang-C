#include<stdio.h>


/*Faça uma função que, dada uma matriz M8×5 de
reais, gere a matriz Mt, sua transposta.
*/
#define L 8
#define C 5

void funcao(int ma[][C], int transposta[][L]);


int main()
{
	int lin, col, matriz[L][C], transposta[C][L];

	for(lin=0;lin<L;lin++)
	{
		for(col=0;col<C;col++)
		{
			matriz[lin][col] = lin + col;
			printf(" |%d| ", matriz[lin][col]);
		}
		printf("\n");		
	}
	
	printf("\n\n\n\n\n");
	funcao(matriz, transposta);
	
}

void funcao(int ma[][C], int transposta[][L])
{
	int , lin, col;
	
	for(lin=0;lin<C;lin++)
	{
		for(col=0;col<L;col++)
		{
			transposta[lin][col] = ma[col][lin];
			printf(" |%d| ", transposta[lin][col]);
		}
		printf("\n");		
	}
	
}




