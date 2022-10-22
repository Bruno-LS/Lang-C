#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define L 6

typedef struct{
	char nome[20];
	char genero[1];
	int idade;
	float altura;	
	
}Grupo;

void preencher(Grupo pessoa[]);
int busca (Grupo pessoa[], char g, int ida_min, int ida_max, float altu_min, float altu_max);


void main()
{
	Grupo pessoa[L];
	char g;
	int idade_min, idade_max;
	float altura_max, altura_min;
	
	//PREENCHER PESSOAS
	preencher(pessoa);
	
	printf("Digite o Genero: ");
	fflush(stdin);
	scanf("%c", &g);
	
	printf("Digite a Idade Minima: ");
	scanf("%d", &idade_min);
	
	printf("Digite a Idade Maxima: ");
	scanf("%d", &idade_max);
	
	printf("Digite Altura Minima: ");
	scanf("%f", &altura_min);
	
	printf("Digite Altura Maxima: ");
	scanf("%f", &altura_max);
	
	//BUSCAR POR PARAMETRO
	busca(pessoa, toupper(g), idade_min, idade_max, altura_min, altura_max);
	
	
}

int busca (Grupo pessoa[], char g, int ida_min, int ida_max, float altu_min, float altu_max)
{
	int i, j, cont=0;
	

		//VERIFICAR QUANDO N OBTIVER O GENERO
		if( (g!='M') && (g!='F'))
		{
			for(i=0;i<L;i++)
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
		else
		{
			for(j=0;j<L;j++)
			{
				//VERIFICAR GENERO
				if (pessoa[j].genero[0] == g)
				{	
					//VERIFICAR IDADE
					if( (pessoa[j].idade>=ida_min) && (pessoa[j].idade<=ida_max) )
					{
						if( (pessoa[j].altura>=altu_min) && (pessoa[j].altura<=altu_max) )
						{
							cont++;	
						}		
					}					
				}
			}
		}
		
	printf("cont = %d", cont);
}


void preencher(Grupo pessoa[])
{
	//Pessoa 1
	strcpy (pessoa[0].nome, "JOAO");
	strcpy (pessoa[0].genero, "M");
	pessoa[0].idade = 11;
	pessoa[0].altura = 1.3;

	//Pessoa 2
	strcpy (pessoa[1].nome, "MARIA");
	strcpy (pessoa[1].genero, "F");
	pessoa[1].idade = 12;
	pessoa[1].altura = 1.4;
	
	//Pessoa 3
	strcpy (pessoa[2].nome, "ANA");
	strcpy (pessoa[2].genero, "F");
	pessoa[2].idade = 13;
	pessoa[2].altura = 1.5;
	
	//Pessoa 4
	strcpy (pessoa[3].nome, "PAULA");
	strcpy (pessoa[3].genero, "F");
	pessoa[3].idade = 15;
	pessoa[3].altura = 1.6;
	
	//Pessoa 5
	strcpy (pessoa[4].nome, "BRUNO");
	strcpy (pessoa[4].genero, "M");
	pessoa[4].idade = 17;
	pessoa[4].altura = 1.7;
	
	//Pessoa 6
	strcpy (pessoa[5].nome, "PEDRO");
	strcpy (pessoa[5].genero, "M");
	pessoa[5].idade = 30;
	pessoa[5].altura = 1.8;	
	
	
}


void exibir (Grupo pessoa[])
{
	int i;
	
	
	for(i=0;i<6;i++)
	{
		printf("\nnome:%s \n", pessoa[i].nome);
		printf("genero:%s \n", pessoa[i].genero);
		printf("idade:%d \n", pessoa[i].idade);
		printf("altura:%.1f \n\n", pessoa[i].altura);
	}
}
