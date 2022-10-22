//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes
#define L 8
#define C 4

//prot�tipos das fun��es
void somarLinhas(int matriz[L][C], int linhas[]);
int somarRecursivo(int matriz[L][C], int linhas[], int cont[], int i, int c);
void exibirMatriz (int M[L][C]);

//main
void main ()
{
	int matriz[L][C] = {{1, 5, 9, 2},
	                    {0, 3, 4, 8},//l1
	                    {1, 1, 3, 7},
	                    {7, 9, 6, 5},//l2
	                    {1, 3, 2, 4},
	                    {8, 6, 8, 7},
	                    {9, 7, 2, 1},//l3  =>  7 12 10 13
	                    {4, 6, 7, 8}};
	           // l1 l2 l3      
	int linhas[]={1, 3, 6};                    

	//exibindo a matriz antes da chamada � fun��o
	exibirMatriz (matriz);
	
	//chamandao a fun��o   
	somarLinhas(matriz, linhas);
	
	//exibindo a matriz ap�s a chamada � fun��o
	exibirMatriz (matriz);
}
	
//implementa��o das fun��es
void somarLinhas(int matriz[L][C], int linhas[])
{
	int i=0, c=0;
	int cont[]={0,0,0,0};
	
	somarRecursivo(matriz, linhas, cont, i, c);
}


int somarRecursivo(int matriz[L][C], int linhas[], int cont[], int i, int c)
{
	int j;
	
	if(i<L)
	{
		//ACHANDO A LINHA COMECANDO POR c
		if(i==linhas[c])
		{
			for(j=0;j<C;j++)
			{
				if(c<2)		//GARANTINDO QUE SOME APENAS L1 E L2
				{
					cont[j]+=matriz[i][j];
				}
				else if(c==2)	//ATRIBUINDO � L3
				{
					matriz[i][j] = cont[j];
				}
			}
			somarRecursivo(matriz, linhas, cont, i, c+1);	//PEGANDO A PROXIMA LINHA
		}
		else	//CASO N ACHE A LINHA PULA PRA PROXIMA
		{
			somarRecursivo(matriz, linhas, cont, i+1, c);
		}		
	}
	
}

void exibirMatriz (int M[L][C])
{
	//declara��o de vari�veis
	int i, j;
	
	printf ("Elementos da matriz:\n\n");
	
	for (i=0;i<L;i++)
	{
		for (j=0;j<C;j++)
		{
			printf ("%3d ", M[i][j]);
		}
		
		printf ("\n");
	}
	
	printf ("\n\n");
}
