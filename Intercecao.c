void Intersecao(int vetA[], int tamA, int vetB[], int tamB, int vetC[], int *tamC)
{
	//declaração de variáveis
	int i = 0, j;
	
	//percorrendo o vetor A para criar o vetor de interseção
	for (j=0;j<tamA;j++)
	{
		//verificando se o elemento vetA[j] existe no vetor vetB
		if (buscar (vetB, tamB, vetA[j]) != -1)
		{
			//inserindo o elemento vetA[j] no vetor vetC
			vetC[i] = vetA[j];
			i++;
		}
	}
	
	//'retornando' o tamanho do vetor intersecao
	*tamC = i;
}

