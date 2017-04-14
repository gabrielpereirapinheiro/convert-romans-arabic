/*TRABALHO DE METODOS DE PROGRAMACAO
*
* ALUNO : GABRIEL PEREIRA PINHEIRO
* MATRICULA: 14/0020764
* UNIVERSIDADE DE BRASILIA
* DEPARTAMENTO DE CIENCIA DA COMPUTACAO
* PROFESSOR: JAN MENDONCA
*/

#include "bibliotecas.h"

int main()
{
    char string[30];
    int vetor[30];
    int valor;
    int tamanho;
    int total;

    printf("DIGITE A STRING A SER CONVERTIDA ->");
    scanf("%s",string);

    tamanho = strlen (string);

    transfere_string_int(string,vetor,tamanho);

    total = valor_total(vetor,tamanho);

    mostra_resultados(total,string,tamanho);

    return 0;
}