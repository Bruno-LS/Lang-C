#include<stdio.h>
#include<string.h>

/*
 a a b a b c b a b a  3  

*/
int funcao(char vetor[]);

void main()
{
	int quant;
	char vetor[30];
	
	fflush(stdin);
	printf("digite: ");
	gets(vetor);
	
	quant = funcao(vetor);
	
	printf("%d", quant);
}


int funcao(char vetor[])
{
	int i,j, quant=0, cont;
	char copy[30];

	strcpy(copy,vetor);
	cont = strlen(vetor);

    for(i=0;vetor[i];i++)
    {
    	if(copy[i]!=0)
    	{
	    	for(j=i+1;vetor[j];j++)
	    	{
	    		if(vetor[i]==copy[j])
	    		{
	    			quant++;
	    			copy[j] = 0;
				}
				
			}
		}
    }
    
    
    cont -= quant; 
	return cont;
}

