#include<stdio.h>
# define T 10

void Ordenar(int vetor[], int tam);

void main()
{
	int vetor[T], num;
	
	
	Ordenar(vetor, T);
	
}

void Ordenar(int vetor[], int tam)
{
	int i, j, aux;
	
	//varrendo o vetor
	for (i=0;i<tam;)
	{
		for(j=i+1;j<tam;j++)
		{
			//comparando os elementos das posições 'i' e 'j'
			if (vetor[i] > vetor[j])
			{
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
		i++;
		
	}
}

