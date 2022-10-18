#include<stdio.h>
#include<string.h>

typedef struct{
	int idade;
	float altura;	
	char nome[20];
	char genero[1];
	
}Grupo;

int busca (Grupo pessoa[], char g[], int ida_min, int ida_max, float altu_min, float altu_max);
void preencher(Grupo pessoa[]);

void main()
{
	Grupo pessoa[6];
	char g[1];
	int idade_min, idade_max;
	float altura_max, altura_min;
	
	//PREENCHER PESSOAS
	preencher(pessoa);
	
/*	printf("nome:%s \n", pessoa[1].nome);
	printf("genero:%s \n", pessoa[1].genero);
	printf("idade:%d \n", pessoa[1].idade);
	printf("altura:%.1f \n", pessoa[1].altura);*/
	
	//ESCOLHER PARAMETROS
	printf("Digite o Genero: ");
	fflush(stdin);
//	scanf("%s", &g);
	gets(g);
		
	printf("Digite a Idade Minima: ");
	scanf("%d", &idade_min);
	
	printf("Digite a Idade Maxima: ");
	scanf("%d", &idade_max);
	
	printf("Digite Altura Minima: ");
	scanf("%f", &altura_min);
	
	printf("Digite Altura Maxima: ");
	scanf("%f", &altura_max);
	
	//BUSCAR POR PARAMETRO
	busca(pessoa, g, idade_min, idade_max, altura_min, altura_max);
	
}

int busca (Grupo pessoa[], char g[], int ida_min, int ida_max, float altu_min, float altu_max)
{
	int i, b, cont=0;
	
	//mudar o 6
	for(i=0;i<6;i++)
	{
		b = strcmp(pessoa[i].genero, g);
		//VERIFICAR GENERO
		if(b==0)
		{
			//VERIFICAR IDADE
			if( (pessoa[i].idade>=ida_min) && (pessoa[i].idade<=ida_max) )
			{
				if( (pessoa[i].altura>=altu_min) && (pessoa[i].altura<=altu_max) )
				{
					cont++;	
				}		
			}					
		}
		
	}
	printf("%d", cont);
}


void preencher(Grupo pessoa[])
{
	//Pessoa 1
	strcpy (pessoa[0].nome, "JOAO");
	strcpy(pessoa[0].genero, "M");
	pessoa[0].idade = 11;
	pessoa[0].altura = 1.4;

	//Pessoa 2
	strcpy (pessoa[1].nome, "MARIA");
	strcpy (pessoa[1].genero, "F");
	pessoa[1].idade = 25;
	pessoa[1].altura = 1.7;
	
	//Pessoa 3
	strcpy (pessoa[2].nome, "ANA");
	strcpy (pessoa[2].genero, "F");
	pessoa[2].idade = 25;
	pessoa[2].altura = 1.5;
	
	//Pessoa 4
	strcpy (pessoa[3].nome, "PAULA");
	strcpy (pessoa[3].genero, "F");
	pessoa[3].idade = 29;
	pessoa[3].altura = 1.8;
	
	//Pessoa 5
	strcpy (pessoa[4].nome, "CLARA");
	strcpy (pessoa[4].genero, "F");
	pessoa[4].idade = 17;
	pessoa[4].altura = 1.6;
	
	//Pessoa 6
	strcpy (pessoa[5].nome, "PEDRO");
	strcpy (pessoa[5].genero, "M");
	pessoa[5].idade = 15;
	pessoa[5].altura = 1.7;	
	
	
}

