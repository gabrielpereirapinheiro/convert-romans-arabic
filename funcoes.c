/*TRABALHO DE METODOS DE PROGRAMACAO
*
* ALUNO : GABRIEL PEREIRA PINHEIRO
* MATRICULA: 14/0020764
* UNIVERSIDADE DE BRASILIA
* DEPARTAMENTO DE CIENCIA DA COMPUTACAO
* PROFESSOR: JAN MENDONCA
*/

#include "bibliotecas.h"

int converte_valor(char letra)
{

	int valor_retornado;

	switch(letra)
	{
		case 'I':
			valor_retornado = 1;
			break;

		case 'V':
			valor_retornado = 5;
			break;
				
		case 'X':
			valor_retornado = 10;
			break;

		case 'L':
			valor_retornado = 50;
			break;	

		case 'C':
			valor_retornado = 100;
			break;	

		case 'D':
			valor_retornado = 500;
			break;		

		case 'M':
			valor_retornado = 1000;
			break;

		default :
			valor_retornado=-1;	
	}

	return valor_retornado;
}
void transfere_string_int(char *string,int *vetor,int size)
{
	int i;

	for (int i = 0; i <  size; ++i)
    {
    	vetor[i] = converte_valor(string[i]);
    }
}

int valor_total(int *vetor,int tamanho)
{
	int i,total=0,invalido=0,passado=0,repetido=0;

    for (int i = 0; i < tamanho; ++i)
    {
    	if(vetor[i]<vetor[i+1] && i+1<tamanho)
    	{
    		if(vetor[i] == passado)
    		{
    			printf(" S %d \n",repetido+1 );
    			repetido++;
    		}
    		total = (vetor[i+1] - vetor[i]) + total;
    		i = i + 1;
    	}
    	else
    	{    		
    		total = total + vetor[i] ;
    	}
    	if (passado == vetor[i])
    	{
    		repetido++;
    		printf("A%d\n", repetido);
    	}
    	
    	if(repetido!=0 && repetido!=3)
    	{
    		if (vetor[i]!=passado)
    		{
    			repetido=0;
    		}
    	}
    	printf(" ree %dn",repetido);

    	if(vetor[i]==-1 || repetido==3)
    	{
    		invalido=1;
    	}
    	passado = vetor[i];
    	
    }
    if(invalido!=0)
    {
    	total=-1;
    }

    return total;
}

void mostra_resultados(int total, char *string,int tamanho )
{
	if(total!=-1)
	{
		printf("O numero romano %s convertido é igual a %d \n",string,total );
	}
	else
	{
		printf("Numero inválido !\n");
	}
}
