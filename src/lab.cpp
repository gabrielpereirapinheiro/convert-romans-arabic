/*TRABALHO DE METODOS DE PROGRAMACAO
*
* ALUNO : GABRIEL PEREIRA PINHEIRO
* MATRICULA: 14/0020764
* UNIVERSIDADE DE BRASILIA
* DEPARTAMENTO DE CIENCIA DA COMPUTACAO
* PROFESSOR: JAN MENDONCA
*/

#include "bibliotecas.hpp"
#include "../include/catch.hpp"

TEST_CASE("TESTE","teste")
{
	SECTION("SESSAO TESTE")
	{
		REQUIRE(converte("XL")==40);
		REQUIRE(converte("DXXVII")==527);
		REQUIRE(converte("xx")==-1);
		REQUIRE(converte("XXXX")==-1);
		REQUIRE(converte("CXXXVII")==137);
		REQUIRE(converte("CCM")==-1);
	}
}

