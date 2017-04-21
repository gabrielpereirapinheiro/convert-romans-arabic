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
		/*Sessao de testes que ira testar numeros corretor*/
	
		REQUIRE(converte("DCCCXC")==890);
		REQUIRE(converte("XI")==11);
		REQUIRE(converte("LXI")==61);
		REQUIRE(converte("DCCLXXVIII")==778);
		REQUIRE(converte("DCLXXII")==672);
		REQUIRE(converte("XL")==40);
		REQUIRE(converte("XC")==90);
		REQUIRE(converte("LXXX")==80);
		REQUIRE(converte("CML")==950);
		REQUIRE(converte("MX")==1010);
		REQUIRE(converte("MDXLI")==1541);
		REQUIRE(converte("MMXXXIII")==2033);
		REQUIRE(converte("MMCMXCIX")==2999);
		REQUIRE(converte("XXI")==21);
		REQUIRE(converte("XXX")==30);
	}

	SECTION("SESSAOO TESTE NUMEROS INVALIDOS")
	{
		/*Sessao de testes que ira testar numeros invalidos*/
		REQUIRE(converte("XXXXL")==-1);
		REQUIRE(converte("XxL")==-1);
		REQUIRE(converte("XD")==-1);
		REQUIRE(converte("XM")==-1);
		REQUIRE(converte("VX")==-1);
		REQUIRE(converte("VV")==-1);
		REQUIRE(converte("VX")==-1);
		REQUIRE(converte("IIX")==-1);
		REQUIRE(converte("VV")==-1);
		REQUIRE(converte("VX")==-1);
		REQUIRE(converte("LC")==-1);
		REQUIRE(converte("CCCCC")==-1);
		REQUIRE(converte("LLLLL")==-1);
		REQUIRE(converte("DDDDD")==-1);
		REQUIRE(converte("IIIII")==-1);
		REQUIRE(converte("MMMMM")==-1);
		REQUIRE(converte("XMXMX")==-1);
		REQUIRE(converte("XXIO")==-1);

	}
}

