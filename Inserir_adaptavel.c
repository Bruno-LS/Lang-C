#include<stdio.h>
#define T 10

void Inserir(int vetor[], int tam, int num, int quant);

void main()
{
	int vetor[T], num;
	
	
	Inserir(vetor[], T, num, quant);
	
}


void Inserir(int vetor[], int tam, int num, int quant)//FEITO
{
	int i, exis;
	
	//verificar existencia
	exis = Buscar(vetor, tam, num);
	
	//verificando se o vetor est� n�o cheio e existencia do n�mero
	if( (quant!=tam) && (exis==-1) )
	{
		vetor[quant] = num;
			
	}

	//Ordenando
	Ordenar( vetor, tam);
}

