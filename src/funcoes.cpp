/*TRABALHO DE METODOS DE PROGRAMACAO
*
* ALUNO : GABRIEL PEREIRA PINHEIRO
* MATRICULA: 14/0020764
* UNIVERSIDADE DE BRASILIA
* DEPARTAMENTO DE CIENCIA DA COMPUTACAO
* PROFESSOR: JAN MENDONCA
*/

#include <ctype.h>
#include "bibliotecas.hpp"

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
void transfere_string_int(char const *string,int *vetor,int size)
{
	int i;

	for (int i = 0; i <  size; ++i)
    {
    	vetor[i] = converte_valor(string[i]);
    }
}

int converte(char const *string)
{
    int vetor[30];
    int valor;
    int tamanho;
    int total;

 	
    tamanho = strlen (string);

    transfere_string_int(string,vetor,tamanho);

    total = valor_total(vetor,tamanho);
    
    return total;
}

int valor_total(int *vetor,int tamanho)
{
	int i,total=0,invalido=0,passado=0,repetido=0;

    for (int i = 0; i < tamanho; ++i)
    {
    	
    	if(vetor[i]==1)/*Ve se é I e ira ser os proximos se sao validos*/
    	{
       		if ((vetor[i+1]!=5 && vetor[i+1]!=10 && vetor[i+1]!=1) && i+1<tamanho ) /*Se o proximo não for I,V,X ja da erro*/
    		{
    			invalido=1;
    			break;
    		}
    	}
    	if(vetor[i]==10) /*Ve se e X e ira ver se os proximos sao validos*/
    	{
    		if(vetor[i+1]!=50 && vetor[i+1]!=100 && vetor[i+1]!=10 && vetor[i+1]!=5 && vetor[i+1]!=1&& i+1<tamanho)
    		{
    			invalido=1;
    			break;
    		}
    	}
        if(vetor[i]==50)/*Ve se e C e ira ver se os proximos sao validos*/
        {
            if ((vetor[i+1]==1000 || vetor[i+1]==500 ) && i+1<tamanho  )
            {
                invalido=1;
                break;
            }
        }

    	if(vetor[i]<vetor[i+1] && i+1<tamanho && vetor[i] != -1)
    	{
    		if(vetor[i] == passado)
    		{
    			repetido++;
    		}
            else
            {
                if(repetido!=0 && repetido!=4)
                {
                    if (vetor[i]!=passado)
                    {
                        repetido=0;
                    }
                }
            }
    		total = (vetor[i+1] - vetor[i]) + total;
    		i = i + 1;
    	}
    	else
    	{    		
    		total = total + vetor[i] ;
    	}
    	if (passado == vetor[i]) /*Acrescenta repetido*/
    	{
            //printf("RE = %d e v %d em %d\n", repetido+1,vetor[i],i );
    		repetido++;
    	}

    	if(repetido!=0 && repetido!=3) /*Zera o repetido */
    	{
            //printf("oi %d %d em %d\n",vetor[i],passado,i );
    		if (vetor[i]!=passado)
    		{
                //printf("zerou %d\n",i );
    			repetido=0;
    		}
    	}

    	if(vetor[i]==-1 || repetido==3) /*Caso tenha retornado um valor invalido da funcao converte ou seja 3 vezes repetido*/
    	{
    		invalido=1;
            break;
    	}
    	passado = vetor[i];
    	
    }
    if(invalido!=0)
    {
    	total=-1;
    }

    return total;
}
