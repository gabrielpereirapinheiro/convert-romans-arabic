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

/*Funcao que ira converter o valor da letra e retornar um numero*/
int converte_valor(char letra)
{
    /*Variavel que ira receber o valor da letra*/
	int valor_retornado;

	switch(letra)
	{
        /*Caso seja I*/
		case 'I':
			valor_retornado = 1;
			break;
        /*Caso seja V*/
		case 'V':
			valor_retornado = 5;
			break;
		/*Caso seja X*/		
		case 'X':
			valor_retornado = 10;
			break;
        /*Caso seja L*/
		case 'L':
			valor_retornado = 50;
			break;	
        /*Caso seja C*/
		case 'C':
			valor_retornado = 100;
			break;	
        /*Caso seja D*/
		case 'D':
			valor_retornado = 500;
			break;		
        /*Caso seja M*/
		case 'M':
			valor_retornado = 1000;
			break;
        /*Caso nao seja nenhuma dessas letras*/
		default :
			valor_retornado=-1;	
	}

	return valor_retornado;
}
/*Funcao que recebe a string passada na funcao princial e ira converter para um vetor de inteiro*/
void transfere_string_int(char const *string,int *vetor,int size)
{
	int i;

	for (int i = 0; i <  size; ++i)
    { 
        /*Vetor i ira receber o valor da letra romana*/
    	vetor[i] = converte_valor(string[i]);
    }
}
/*Funcao principal, ira chamar as outras funcoes e retornar o valor do numero romano caso seja valido*/
int converte(char const *string)
{
    int vetor[30];
    //Vetor de no maximo 30 caracteres
    int valor;
    //valor retornador
    int tamanho;
    //tamanho da string
    int total;
    //total do numero romano
    int valor_analisa=0;
    //caso seja valido
 	
    tamanho = strlen (string);

    transfere_string_int(string,vetor,tamanho);

    valor_analisa = analisa(vetor,tamanho);
    if(valor_analisa==1)
    {
        total = -1;
    }
    else
    {
        total = valor_total(vetor,tamanho);
    }
   
    
    return total;
}
/*Funcao que ira analisar o vetor e verificar se e um numero valido*/
int analisa(int *vetor,int tamanho)
{
    int invalido=0;

    for (int i = 0; i < tamanho; ++i)
    {
      
        if(vetor[i]==1)/*Ve se é I e ira ser os proximos se sao validos*/
        {
            if ((vetor[i+1]!=5 && vetor[i+1]!=10 && vetor[i+1]!=1) && i+1<tamanho ) /*Se o proximo não for I,V,X ja da erro*/
            {
           
                invalido=1;
                break;
            }
            if(vetor[i+1]==1)
            {   
                for (int j = i; j < tamanho; ++j)
                {
                    if(vetor[j]!=1)
                    {
                        invalido=1;
                        break;
                    }
                }
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
        if (vetor[i]==5)
        {
            if (vetor[i+1]!=1  && i+1<tamanho )
            {
           
                invalido=1;
                break;
            }
        }
        if(vetor[i]==50)/*Ve se e C e ira ver se os proximos sao validos*/
        {
            if ((vetor[i+1]!=1000 && vetor[i+1]!=500 && vetor[i+1]!=10) && i+1<tamanho  )
            {
              
                invalido=1;
                break;
            }
        }

    }

    return invalido;
}
/*Funcao que ira receber um vetor e ira calcular o valor desse numero romano e retornar o valor caso seja valido*/
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
