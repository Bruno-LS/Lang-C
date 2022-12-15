//importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//defini��o de constantes
#define TRUE 1
#define FALSE 0

//defini��o de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//declara��o dos prot�tipos das fun��es
int inserir (TLista *L, int numero);
int remover (TLista *L, int numero);
int alterar (TLista L, int velho, int novo);
int buscar (TLista L, int numero);
void exibir (TLista L);

int menu ();

//main 
void main ()
{
	//declara��o de vari�veis
	TLista L = NULL;
	int num1, num2, op, quant, resp;
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usu�rio
		op = menu ();
		
		//verificando a op��o escolhida
		switch (op)
		{
			//Inser��o
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a fun��o
			        if (inserir (&L, num1) == TRUE)
			        {
			        	printf ("\n\tInsercao realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Remo��o
			case 2: printf ("\nEntre com o valor a ser removido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a fun��o
			        quant = remover (&L, num1);
			        
					if (quant > 0)
			        {
			        	printf ("\n\t%d remocoes realizadas!", quant);
					}
					else
					{
						printf ("\n\tERRO: remocao nao realizada!");
					}
					break;

			//Altera��o
			case 3: printf ("\nEntre com o valor a ser alterado: ");
			        scanf ("%d", &num1);
			        
			        printf ("\nEntre com o novo valor: ");
			        scanf ("%d", &num2);
			        
			        //chamando a fun��o
			        quant = alterar (L, num1, num2);
			        
			        if (quant > 0)
			        {
			        	printf ("\n\t%d alteracoes realizadas!", quant);
					}
					else
					{
						printf ("\n\tERRO: alteracao nao realizada!");
					}
					break;

			//Busca
			case 4: printf ("\nEntre com o valor a ser buscado: ");
			        scanf ("%d", &num1);
			        
			        //chamando a fun��o
			        resp = buscar (L, num1);
			        
					if (resp == TRUE)
			        {
			        	printf ("\n\tO valor %d foi encontrado na lista!", num1);
					}
					else
					{
						printf ("\n\tO valor %d NAO foi encontrado na lista!", num1);
					}
					break;

			//Exibir
			case 5: exibir (L);
					break;
					
			//Sa�da
			case 6: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 6);
}

//implementa��o das fun��es
int inserir (TLista *L, int numero)
{
	//declara��o de vari�veis;
	TLista aux;
	
	//verificando se o elemento n�o existe na lista
	if (buscar (*L, numero) == FALSE)
	{	
		//1� passo: alocar mem�ria para o novo n�	
		aux = (TLista) malloc (sizeof(TNo));
		
		//verificando se houve erro na aloca��o de mem�ria
		if (aux == NULL)
		{
			return FALSE;
		}
		else
		{
			//2� passo: armazenar 'numero' na mem�ria rec�m-alocada
			aux->valor = numero;
			
			//3� passo: mandar o campo 'prox' do novo n� apontar para o 
			//"at� ent�o" primeiro elemento	da lista
			aux->prox = *L;
			
			//4� passo: fazer com que L aponte para o novo n� da lista		
			*L = aux;
			
			return TRUE;
		}
	}
	else
	{
		return FALSE;
	}
}

int remover (TLista *L, int numero)
{
	//declara��o de vari�veis
	TLista aux1, aux2;
	
	//verificando se o primeiro elemento da lista � o n�mero que deseja-se remover
	if ((*L) && ((*L)->valor == numero))
	{
		//fazendo o aux1 apontar para o primeiro elemento da lista
		aux1 = *L;
		
		//fazer o L apontar para o "segundo" elemento da l�ista
		*L = aux1->prox;     //*L = (*L)->prox;
		
		//liberando a mem�ria do n� apontado por 'aux1'
		free (aux1);
		
		//retornando TRUE, pois a remo��o foi realizada
		return TRUE;		
	}
	
	//verificando se ainda h� elementos na lista
	if (*L)
	{
		//colocando os auxiliares 'aux2' e 'aux1' no primeiro e segundo n�s, respectivamente
		aux2 = *L;
		aux1 = (*L)->prox;	
		
		//percorrendo a lista com 'aux1'
		while (aux1)
		{
			//verificando se o 'aux1' est� apontando para 'numero'
			if (aux1->valor == numero)
			{
				//removendo o valor apontado por 'aux1'
				aux2->prox = aux1->prox;
				
				//removendo o n� que guarda o 'numero'
				free (aux1);
								
				//retornando TRUE, pois o elemento foi removido
				return TRUE;
			}
			else
			{
				//andando com os dois auxiliares
				aux2 = aux1;
				aux1 = aux1->prox;
			}
		}
	}
	
	//retornando FALSE, pois o elemento n�o pertence � lista
	return FALSE;
}

int alterar (TLista L, int velho, int novo)
{
	//declara��o de vari�veis
	TLista aux = L;
	int respVelho, respNovo;
	
	//verificando se o 'velho' existe
	respVelho = buscar (L, velho);
	
	//verificando se o 'novo' existe
	respNovo = buscar (L, novo);
	
	if (respVelho && !respNovo)
	{
		//percorrendo toda a lista
		while (aux != NULL)
		{
			//verificando se o elemento 'velho' foi encontrado
			if (aux->valor == velho)
			{
				//alterando o 'velho' pelo 'novo'
				aux->valor = novo;
				
				//retornando TRUE
				return TRUE;
			}
			
			//fazendo o aux apontar para o pr�ximo n� da lista
			aux = aux->prox;		
		}
	}
	
	//retornando FALSE, pois a opera��o n�o foi realizada
	return FALSE;
}

int buscar (TLista L, int numero)
{
	//declara��o de vari�veis
	TLista aux = L;
	
	//percorrendo a lista at� o seu final
	while (aux != NULL)
	{
		//testando se � o valor sendo buscado
		if (aux->valor == numero)
		{
			return TRUE;
		}
			
		//atualizando o 'aux' para apontar para o pr�ximo n�
		aux = aux->prox;
	}
	
	//se chegou a este ponto, o n�mero buscado n�o existe
	return FALSE;	
}

void exibir (TLista L)
{
	//declara��o de vari�veis
	TLista aux = L;
	
	//testando se a lista est� vazia
	if (L == NULL)
	{
		printf ("\nLista vazia!");
	}
	else
	{
		printf ("\nElementos da lista: ");
		
		//percorrendo a lista at� o seu final
		while (aux != NULL)
		{
			//exibindo o valor apontado pelo 'aux'
			printf ("%d ", aux->valor);
			
			//atualizando o 'aux' para apontar para o pr�ximo n�
			aux = aux->prox;
		}
	}
}

int menu ()
{
	//declara��o de vari�veis
	int opcao;
	
	//exibindo o meu ao usu�rio
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Remover\n");
	printf ("(3) Alterar\n");
	printf ("(4) Buscar\n");
	printf ("(5) Exibir\n");
	printf ("(6) Sair\n\n");
	
	//lendo a op��o do usu�rio
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a op��o escolhida
	return opcao;
}
