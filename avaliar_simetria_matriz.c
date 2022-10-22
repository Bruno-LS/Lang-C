#include<stdio.h>


/*Fazer uma função que, dada uma matriz M6×6,
determine se ela é simétrica.*/


int avaliar(int ma[][6]);
void transposta(int ma[][6]);

int main()
{
	int lin, col, matriz[6][6], sim;

	srand (time(NULL));

	printf("\nMatriz Normal:\n\n");
	for(lin=0;lin<6;lin++)
	{
		for(col=0;col<6;col++)
		{
			matriz[lin][col] = lin + col + 1;	//FORMA SIMÉTRICA
//			matriz[lin][col] = rand ()%10;		//FORMA N SIMÉTRICA
			printf(" |%d| ", matriz[lin][col]);
		}
		printf("\n");		
	}
	
	printf("\n\n\n");
	transposta(matriz);
	printf("\n\n\n");
	
	sim = avaliar(matriz);
	
	if(sim==1)
	{
		printf("Sim, e' simetrica.");
	}
	else
	{
		printf("Nao e' simetrica.");
	}
}

int avaliar(int ma[][6])
{
	int lin, col, transposta[6][6];
	
	for(lin=0;lin<6;lin++)
	{
		for(col=0;col<6;col++)
		{
			transposta[lin][col] = ma[col][lin];
			
			if(ma[lin][col] != transposta[lin][col])
			{
				return 0;
			}
		}		
	}
	return 1;
}

void transposta(int ma[][6])
{
	int transposta[6][6], lin, col;
	
	printf("\nMatriz Transposta:\n\n");
	for(lin=0;lin<6;lin++)
	{
		for(col=0;col<6;col++)
		{
			transposta[lin][col] = ma[col][lin];
			printf(" |%d| ", transposta[lin][col]);
		}
		printf("\n");		
	}
	
}
