#include "doctest.h"

#include "assento.h"
#include "cinema.h"
#include "distribuidor.h"
#include "filme.h"
#include "pessoa.h"
#include "sala.h"
#include "imax.h"
#include "tresd.h"
#include "premium.h"

#include <string.h>
#include <iostream>

/*-----------------------------TESTE SALAS-----------------------------

                CONSTRUTOR COM FORMATO: Tipo(numero, capacidade)------*/

TEST_CASE("01 - Testando o construtor de salas") {
    CHECK_NOTHROW(Sala salaComum(1,50));
    CHECK_NOTHROW(IMAX salaIMAX(2,50));
    CHECK_NOTHROW(Premium salaPremium(3,50));
    CHECK_NOTHROW(TresD salaTresD(4,50));
}

TEST_CASE("02 - Testando os valores por assento de cada tipo") {
    Sala salaComum(1,50);
    IMAX salaIMAX(2,50);
    Premium salaPremium(3,50);
    TresD salaTresD(4,50);

    CHECK(salaComum.getValorPorAssento()==27.00);
    CHECK(salaIMAX.getValorPorAssento()-32.40 < 0.01);
    CHECK(salaPremium.getValorPorAssento()-55.08 < 0.01);
    CHECK(salaTresD.getValorPorAssento()-40.40 < 0.01);
    
}

//TEST_CASE("03 - ")