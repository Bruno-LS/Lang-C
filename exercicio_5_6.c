#include<stdio.h>
#include<stdlib.h>
#define L 3
#define C 3


/*Considere uma loja que mantém em uma
matriz o resposta vendido por cada funcionário
pelos diversos meses do ano. Ou seja, uma
matriz de 12 linhas (uma por mês) e 10 colunas
(10 funcionários). Pede-se o desenvolvimento
de uma função para cada item abaixo:

a. Calcular o total vendido durante o ano;
b. Dado um mês fornecido pelo usuário,
determinar o total vendido nesse mês;
c. Dado um funcionário fornecido pelo
usuário, determinar o total vendido por ele
durante o ano;
d. Determinar o mês com maior índice de
vendas;
e. Determinar o funcionário que menos
vendeu durante o ano.*/



int funcao(int matriz[][C], char op, int p);

void main()
{
	int matriz[L][C], lin, col, resposta, p;	
	char op;
	
	
	srand(time(NULL));
	
	for(lin=0;lin<L;lin++)
	{
		for(col=0;col<C;col++)
		{
			matriz[lin][col] = rand() % 20;
			printf("|%d\t|   ", matriz[lin][col]);
		}
		printf("\n");
	}
	
	printf("\n\n\n");
	
	printf("digite a opcao: ");
	
	scanf("%c", &op);
	op = toupper(op);
	
	switch (op)
	{
		case 'A':
		resposta = funcao(matriz, op, p);
		printf("o total e': %d", resposta);
		break;
		
		case 'B':
		printf("Diga o mes: ");
		scanf("%d", &p);
		p-=1;
		resposta = funcao(matriz, op, p);
		printf("o total e': %d", resposta);
		break;
		
		case 'C':
		printf("Diga o numero do funcionario: ");
		scanf("%d", &p);
		p-=1;
		resposta = funcao(matriz, op, p);
		printf("o total e': %d", resposta);
		break;
		
		case 'D':
		resposta = funcao(matriz, op, p);
		printf("O mes com mais indice de vendas e': %d", resposta);
		break;
		
		case 'E':
		resposta = funcao(matriz, op, p);
		break;	
	}
	
	
}


int funcao(int matriz[][C], char op, int p)
{
	int lin, col, total, maisV=-1, funcionarios[C], mes[L];

	
	if(op == 'A')
	{
		for(lin=0;lin<L;lin++)
		{
			for(col=0;col<C;col++)
			{
				total += matriz[lin][col];
			}	
		}
		return total;	
	}
	
	else if(op == 'B')
	{
		for(col=0;col<C;col++)
		{
			total += matriz[p][col];
		}
		return total;
	}
	
	else if(op == 'C')
	{
		for(lin=0;lin<L;lin++)
		{
			total += matriz[lin][p];
		}
		return total;	
	}
	
	else if(op == 'D')
	{
		//pegando o Total de cada mes
		for(lin=0;lin<L;lin++)
		{
			for(col=0;col<C;col++)
			{
				mes[lin] += matriz[lin][col];				
			}

		}
		
		//verificando qual mes tem mais vendas
		for(lin=0;lin<L;lin++)
		{
			if(maisV < mes[lin])
			{
				maisV = mes[lin];
				total = lin;
			}
		}
		return total+1;
	}
	/*else if(op == 'E')
	{
		
	}*/
	
}

