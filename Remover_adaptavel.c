#include<stdio.h>
# define T 10

void Remover(int vetor[], int num, int quant);

void main()
{
	int vetor[T]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, num;
	
	printf("Digite o numero a Remover: ");
	scanf("%d", &num);
	
	Remover(vetor, num, T);
	
}

void Remover(int vetor[], int num, int quant)
{
	int i, j;
		
		
	//percorrendo vetor
	for(i=0;i<=quant;i++)
	{
		//verificar existencia e se o vetor não está vazio
		if( (quant!=0) && (vetor[i] == num) )
		{
			//deslocando os demais elementos uma posição para a esquerda
				for (j=i+1;j<=quant;j++)
				{
					vetor[j-1] = vetor[j];
				}			
		}
			else
			{
				i++;
			}			
	}

}

