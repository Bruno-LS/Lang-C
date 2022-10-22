#include<stdio.h>

#define Q 10

typedef struct{
	int valor;
	int posicao;
	int ocorrencia;

}estru;

int Buscar(int vetor[], int tam, int num);
int preencher(int v[], estru v2[]);
void exibir (estru v2[], int quant);

void main()
{
	int v1[Q]={4, 9, 5, 1, 1, 2, 4, 8, 5, 4}, quant;
	estru v2[Q];
	
	quant = preencher(v1, v2);
	exibir (v2, quant);
}


int preencher(int v[], estru v2[])
{
	int i, j, p, cont, quant=0;

	for(i=0;i<Q;i++)
	{	
		cont = 1;
		
		//SEMPRE PEGA PRIMEIRA OCORRENCIA
		p = Buscar(v, Q, v[i]);
		
		//SE FOR PRIMEIRA OCORRENCIA
		if(i==p)
		{		//VARIANDO SO A QUANTIDADE DE V2
			v2[quant].posicao = p; 
			v2[quant].valor = v[i];	
					
			//BUSCANDO NUMERO DE OCORRENCIAS				
			for(j=i+1;j<Q;j++)
			{
				if(v[j] == v[i]) 
				{
					cont++;	
				}
			}
			v2[quant].ocorrencia = cont;
			
			quant++;//AUMENTANDO QUANTIDADE DE V2
		}	
	}
	
	
	return quant;
}

int Buscar(int vetor[], int tam, int num)
{
	int i;
	
	//percorrendo vetor
	for(i=0;i<tam;i++)
	{
		if(vetor[i] == num)
		{
			return i;
		}
	}
	
}


void exibir (estru v2[], int quant)
{
	int i;
	
	for(i=0;i<quant;i++)
	{
		printf("\nvalor: %d\t", v2[i].valor);
		printf("ocorrencia: %d\t", v2[i].ocorrencia);
		printf("posicao: %d \n", v2[i].posicao);
	}
}




