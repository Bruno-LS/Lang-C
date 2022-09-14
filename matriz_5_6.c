#include<stdio.h>
#include<stdlib.h>
#define L 3
#define C 3


/*Considere uma loja que mantam em uma
matriz o resposta vendido por cada funcionario
pelos diversos meses do ano. Ou seja, uma
matriz de 12 linhas (uma por mes) e 10 colunas
(10 funcionarios). Pede-se o desenvolvimento
de uma funçao para cada item abaixo:
a. Calcular o total vendido durante o ano;
b. Dado um mes fornecido pelo usuario,
determinar o total vendido nesse mes;
c. Dado um funcionario fornecido pelo
usuario, determinar o total vendido por ele
durante o ano;
d. Determinar o mes com maior indice de
vendas;
e. Determinar o funcionario que menos
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
		scanf("%d", &p);	//PEGAR A POSIÇAO A PARTIR DO 1, JA QUE N EXISTE MES OU FUNCIONARIO "0"
		p-=1;			//PEGAR A POSIÇAO CERTA
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
		printf("O funcionario com menor indice de vendas e': %d", resposta);
		break;	
	}
	
	
}


int funcao(int matriz[][C], char op, int p)
{
	int lin, col, total, maisV=-1, func_com_menosV=999999, funcionarios[C], mes[L];

	//pegando o Total de cada mes
		for(lin=0;lin<L;lin++)
		{
			for(col=0;col<C;col++)
			{
				//total de cada mes pegando linha por linha 
				mes[lin] += matriz[lin][col];
				//total de cada funcionario pegando coluna por coluna correspondente
				funcionarios[col] += matriz[lin][col];				
			}
		}
		
	//TOTAL ANUAL	
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
	
	//TOTAL POR MES SELECIONADO
	else if(op == 'B')
	{
		for(col=0;col<C;col++)
		{
			total += matriz[p][col];
		}
		return total;
	}
	
	//TOTAL POR FUNCIONARIO SELECIONADO
	else if(op == 'C')
	{
		for(lin=0;lin<L;lin++)
		{
			total += matriz[lin][p];
		}
		return total;	
	}
	
	//MES COM MAIS VENDAS
	else if(op == 'D')
	{		
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
	
	//FUNCIONARIO COM MENOS VENDAS
	else if(op == 'E')
	{
		for(col=0;col<C;col++)
		{
			if(func_com_menosV > funcionarios[col])
			{
				func_com_menosV = funcionarios[col];
				total = col;
			}
		}
		return total+1;
	}
}
Footer
© 2022 GitHub, In
