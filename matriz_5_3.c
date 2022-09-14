#include<stdio.h>


/*Desenvolver uma fun??o que gere a seguinte
matriz M5?5:
1 2 3 4 5
2 3 4 5 6
3 4 5 6 7
4 5 6 7 8
5 6 7 8 9
*/

void funcao(int ma[][5]);


int main()
{
	int matriz[5][5];

	funcao(matriz);
	
}

void funcao(int ma[][5])
{
	int lin, col;
	
	
	for(lin=0;lin<5;lin++)
	{
		for(col=0;col<5;col++)
		{
			ma[lin][col] = lin + col + 1;
			printf(" |%d| ", ma[lin][col]);
		}
		printf("\n\n");		
	}
	
}
