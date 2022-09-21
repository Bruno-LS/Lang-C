#include<stdio.h>
#define TAM 20

//Ano
typedef struct{
	int modelo;
	int fabricacao;
}T_ano;

//Veiculo
typedef struct {
	char placa[9];
	char modelo[20];
	char  marca[20];
	char cor[20];	   
	float km;
	float valor;
	char tipo[6];
	T_ano ano;
	
}T_carro;



void buscar_carro(T_carro agencia[TAM], int quant, char m[], int a1, int a2, float x);
void exibir_dados_carro(T_carro carro);
void reajustar_valor(T_carro agencia[],int quant);

void  main()
{
	int a1, a2;
	float x;
	char modelo[20]; 
	
	T_carro agencia[TAM];
	
	buscar_carro(agencia, TAM, modelo, a1, a2, x);
	reajustar_valor(agencia,TAM);
		

	
}


void buscar_carro(T_carro agencia[TAM], int quant, char m[], int a1, int a2, float x)
{
	int i, cont=0;
	
	for(i=0;i<quant;i++)
	{
		if( (strcmp(m, agencia[i].modelo)==0) && (agencia[i].ano.fabricacao >=a1) && (agencia[i].ano.fabricacao <=a2) && (agencia[i].valor<=x) )
		{
			exibir_dados_carro(agencia[i]);
			cont++;
		}
	}
	if(cont==0)
	{
		printf("Nenhum carro encontrado");
	}	
}

void exibir_dados_carro(T_carro carro)
{
	printf("Placa: %s\n", carro.placa);
	
	printf("Marca/Modelo: %s/%s\n", carro.marca, carro.modelo);
	
	printf("Cor: %s\n", carro.cor);
	
	printf("quilometragem: %.1f\n", carro.km);
	
	printf("ANO: d%\n", carro.ano.fabricacao, carro.ano.modelo);	
	
	printf("Valor:R$ %.1f\n", carro.valor);
	
	printf("Tipo: s%\n\n", carro.tipo);
		
	
}
void reajustar_valor(T_carro agencia[],int quant)
{
	int i;
	
	for(i=0;i<quant;i++)
	{
		if(agencia[i].km == 0)
		{
			agencia[i].valor *=1.025;
		}
	}
}





