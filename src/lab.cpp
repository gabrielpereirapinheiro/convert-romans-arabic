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
	SECTION("SESSAO TESTE NUMEROS CORRETOS")
	{
	
		REQUIRE(converte("DCCCXC")==890);
		REQUIRE(converte("XI")==11);
		REQUIRE(converte("LXI")==61);
		REQUIRE(converte("DCCLXXVIII")==778);
		REQUIRE(converte("DCLXXII")==672);
		REQUIRE(converte("XL")==40);
		REQUIRE(converte("XC")==90);
		REQUIRE(converte("LXXX")==80);
		REQUIRE(converte("CML")==950);

	}
	SECTION("SESSAO TESTE NUMEROS INVALIDOS")
	{
		REQUIRE(converte("XXXXL")==-1);
		REQUIRE(converte("XxL")==-1);
		REQUIRE(converte("XD")==-1);
		REQUIRE(converte("XM")==-1);
		REQUIRE(converte("MMMMM")==-1);
		REQUIRE(converte("LM")==-1);
		REQUIRE(converte("ID")==-1);
	}
}

