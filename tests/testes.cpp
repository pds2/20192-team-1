#include "doctest.h"

#include "assento.h"
#include "cinema.h"
#include "distribuidor.h"
#include "filme.h"
#include "pessoa.h"
#include "sala.h"

#include <string.h>
#include <iostream>

TEST_CASE("01 - Testando o construtor com parâmetros corretos de peso e custo por quilo") {
    CHECK_NOTHROW(Package(2,5, "Carlos", "Alfeneiros")); //construtor com formato (peso, custo_por_quilo, nome, endereço)
}

TEST_CASE("02 - Testando construtor com valores inválidos -> deve gerar uma exceção") {
    Package p(-1,5, "Carlos", "Alfeneiros");
    CHECK(p.get_peso() > 1000); //atribuir um número negativo a um unsigned int vai gerar um valor absurdo como resposta
}

TEST_CASE("03 - Testando a função para cálculo do custo de envio") {
    Package pacote(2,3, "Carlos", "Bahia");
    CHECK(pacote.calculate_cost() == 6);
}

TEST_CASE("04 - Testando construtor da classe derivada (TwoDayPackage)") {
    TwoDayPackage pacote = TwoDayPackage(2, 7, 3, "Josias", "Manaus"); //construtor do tipo: (peso, custo_por_quilo, taxa_de_envio, nome, endereço)
    CHECK(pacote.calculate_cost() == 17);
}

TEST_CASE("05 - Testando herança e reescrita do método para cálculo de custo (TwoDayPackage)") {
    Package *pacote = new TwoDayPackage(2, 7, 7, "Josias", "Sampa");
    CHECK(pacote->calculate_cost() == 21);
    delete pacote;
}

TEST_CASE("06 - Testando construtor da classe derivada (OverNightPackage)") {
    OverNightPackage pacote = OverNightPackage(2, 5, 2, "Maria", "Rio"); //construtor do tipo: (peso, custo_por_quilo, taxa_adicional_por_quilo, nome, endereço)
    CHECK(pacote.calculate_cost() == 14);
}

TEST_CASE("07 - Testando herança e reescrita do método para cálculo de custo (OverNightPackage)") {
    Package *pacote = new OverNightPackage(2, 5, 2, "Maria", "Rio"); //construtor do tipo: (peso, custo_por_quilo, taxa_adicional_por_quilo, nome, endereço)
    CHECK(pacote->calculate_cost() == 14);
    delete pacote;
}

TEST_CASE("08 - Checando o acesso aos atributos da classe base pela classe derivada") {
    Package *pacoteON = new OverNightPackage(2, 5, 7, "Maria", "Rio");
    CHECK(pacoteON->get_peso() == 2);
    CHECK(pacoteON->get_custo_por_quilo() == 5);

    Package *pacoteTD = new TwoDayPackage(12, 4, 2, "Paulo", "Juazeiro");
    CHECK(pacoteTD->get_peso() == 12);
    CHECK(pacoteTD->get_custo_por_quilo() == 4);
    
    delete pacoteON;
    delete pacoteTD;
}