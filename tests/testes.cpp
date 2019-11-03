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
#include "sessao.h"

#include <string.h>
#include <iostream>

/*TESTES UNITÁRIOS:

1) Salas e valores de ingresso;
2) Pessoas e níveis de acesso; 
3) Filmes;
4) Sessões;
5) Cinema;
5) Funções complexas (valor total arrecadado, publico total etc)


---------------------------TESTES UNITÁRIOS----------------------------

-------------------TESTE SALAS E VALORES POR ASSENTO----------------------------

                CONSTRUTOR SALA COM FORMATO: Tipo(numero, capacidade)------*/

TEST_CASE("01 - Testando o construtor de salas") {
    CHECK_NOTHROW(Sala salaComum(1,5,10));
    CHECK_NOTHROW(IMAX salaIMAX(2,5,10));
    CHECK_NOTHROW(Premium salaPremium(3,5,10));
    CHECK_NOTHROW(TresD salaTresD(4,5,10));
}


TEST_CASE("02 - Testando os valores por assento de cada tipo") {

    //CONSTRUINDO UMA SALA DE CADA TIPO COM CAPACIDADE 50 (5X10)
    Sala *salaComum = new Sala(1,5,10);
    IMAX *salaIMAX = new IMAX(2,5,10);
    Premium *salaPremium = new Premium(3,5,10);
    TresD *salaTresD = new TresD(4,5,10);

    //CONFERINDO OS VALORES POR ASSENTO
    CHECK(salaComum->getValorPorAssento()==27.00);
    CHECK(salaIMAX->getValorPorAssento()-32.40 < 0.01);
    CHECK(salaPremium->getValorPorAssento()-55.08 < 0.01);
    CHECK(salaTresD->getValorPorAssento()-40.40 < 0.01);

    //DESALOCANDO MEMÓRIA
    delete salaComum;
    delete salaIMAX;
    delete salaPremium;
    delete salaTresD;
}

TEST_CASE("03 - Testando o cadastro de salas"){
    Cinema Cineart("Cineart");

    Sala *salaComum = new Sala(1,5,10);
    IMAX *salaIMAX = new IMAX(2,5,10);
    Premium *salaPremium = new Premium(3,5,10);
    TresD *salaTresD = new TresD(4,5,10);

    //*******************O SISTEMA CONSEGUE CADASTRAR DUAS SALAS COM O MESMO NUMERO DE SALA
    CHECK_NOTHROW(Cineart.armazenarNovaSala(*salaComum));
    CHECK_NOTHROW(Cineart.armazenarNovaSala(*salaIMAX));
    CHECK_NOTHROW(Cineart.armazenarNovaSala(*salaPremium));
    CHECK_NOTHROW(Cineart.armazenarNovaSala(*salaTresD));

    //DESALOCANDO MEMÓRIA
    delete salaComum;
    delete salaIMAX;
    delete salaPremium;
    delete salaTresD;
}

/*---------------------------TESTE PESSOAS E NIVEIS-----------------------------
    NÍVEIS:
        0)Distribuidor
        1)Proprietário do cinema
        2)Gerente
        3)Vendedor

        EMPREGADOS - CONSTRUTOR COM FORMATO: Pessoa("nome", cpf ou cnpj, nível de acesso )------
        DISTRIBUIDOR - CONSTRUTOR COM FORMATO: Distribuidor("nome", id_distribuidor)-----------*/

TEST_CASE("04 - Testando o construtor de pessoas"){

    CHECK_NOTHROW(Pessoa("Proprietário", 12345678900,1));
    CHECK_NOTHROW(Pessoa("Gerente", 12345678901, 2));
    CHECK_NOTHROW(Pessoa("Vendedor", 12345678902, 3));
    CHECK_NOTHROW(Distribuidor("Distribuidor", 1));
}

TEST_CASE("05 - Testando os níveis de cada pessoa"){
    //CONSTRUINDO UM PROPRIETARIO, UM GERENTE, UM VENDEDOR E UM DISTRIBUIDOR
    Pessoa *proprietario = new Pessoa("Proprietário", 12345678900,1);
    Pessoa *gerente = new Pessoa("Gerente", 12345678901, 2);
    Pessoa *vendedor = new Pessoa("Vendedor", 12345678902, 3);
    Distribuidor *distribuidor = new Distribuidor("Distribuidor", 1);

    //VERIFICANDO O NÍVEL DE CADA PESSOA
    CHECK(proprietario->getNivelDeAcesso()==1);
    CHECK(gerente->getNivelDeAcesso()==2);
    CHECK(vendedor->getNivelDeAcesso()==3);
    CHECK(distribuidor->getNivelDeAcesso()==0);

    //DESALOCANDO MEMÓRIA
    delete proprietario;
    delete gerente;
    delete vendedor;
    delete distribuidor;
}

TEST_CASE("06 - Testando o cadastro de pessoas"){
    Cinema Cineart("Cineart");

    Pessoa *proprietario = new Pessoa("Proprietário", 12345678900,1);
    Pessoa *gerente = new Pessoa("Gerente", 12345678901, 2);
    Pessoa *vendedor = new Pessoa("Vendedor", 12345678902, 3);
    Distribuidor *distribuidor = new Distribuidor("Distribuidor", 1);


    CHECK_NOTHROW(Cineart.armazenarNovaPessoa(*proprietario));
    CHECK_NOTHROW(Cineart.armazenarNovaPessoa(*gerente));
    CHECK_NOTHROW(Cineart.armazenarNovaPessoa(*vendedor));
    CHECK_NOTHROW(Cineart.armazenarNovoDistribuidor(*distribuidor));

    //DESALOCANDO MEMÓRIA
    delete proprietario;
    delete gerente;
    delete vendedor;
    delete distribuidor;
}

/*-----------------------------TESTE FILMES-----------------------------

                CONSTRUTOR FILME COM FORMATO: Filme("nome", id_distribuidor, duração em minutos)------*/
TEST_CASE("07 - Testando o construtor de filmes"){
    CHECK_NOTHROW(Filme("Rei Leão",1,90));
    CHECK_NOTHROW(Filme("Titanic",1,195));
}

TEST_CASE("08 - Testando o cadastro de filmes"){
    Cinema Cineart("Cineart");

    //definição e cadastro de distribuidor
    Distribuidor *distribuidor = new Distribuidor("distribuidor", 1);
    Cineart.armazenarNovoDistribuidor(*distribuidor);

    //definição de filmes
    Filme *ReiLeao = new Filme("Rei Leão",distribuidor->getIdentificacao(),90);
    Filme *Titanic = new Filme("Titanic",distribuidor->getIdentificacao(),195);
    Filme *MagicoDeOz = new Filme("Mágico de Oz",13,195); 


    //*******************O SISTEMA CONSEGUE CADASTRAR UM FILME COM UM ID DE DISTRIBUIDOR NÃO CADASTRADO

    CHECK_NOTHROW(Cineart.armazenarNovoFilme(*ReiLeao));
    CHECK_NOTHROW(Cineart.armazenarNovoFilme(*Titanic));
    CHECK_NOTHROW(Cineart.armazenarNovoFilme(*MagicoDeOz)); // NÃO DEVERIA SER ARMAZENADO COM SUCESSO, POIS DISTRIBUIDOR NÃO ESTÁ CADASTRADO

    delete ReiLeao;
    delete Titanic;
    delete MagicoDeOz;
}


/*-----------------------------TESTE SESSÕES-----------------------------

                CONSTRUTOR SESSAO COM FORMATO: Sessao(Sala, "nome_do_filme", string data)------*/

TEST_CASE("07 - Testando o contrutor de sessões "){

    //definição de salas
    Sala *salaComum = new Sala(1,5,10);
    Sala *salaIMAX = new IMAX(2,5,10);

    //definição de filmes
    Filme *ReiLeao = new Filme("Rei Leão",1,90);
    Filme *Titanic = new Filme("Titanic",1,195);

    //A SESSÃO NÃO DEVERIA RECEBER UM FILME INTEIRO AO INVÉS DE SÓ RECEBER O NOME ?
    CHECK_NOTHROW(Sessao(*salaComum,"Rei Leão", std::to_string(20191101)));
    CHECK_NOTHROW(Sessao(*salaIMAX,"Titanic", std::to_string(20191101)));

    //DESALOCANDO MEMÓRIA
    delete salaComum;
    delete salaIMAX;
    delete ReiLeao;
    delete Titanic;
}

TEST_CASE("08 - Testando o cadastro de Sessões"){

    Cinema Cineart("Cineart");

    //Definição e cadastro de salas
    Sala *salaComum = new Sala(1,5,10);
    Sala *salaIMAX = new Sala(2,5,10);
    Cineart.armazenarNovaSala(*salaComum);
    Cineart.armazenarNovaSala(*salaIMAX);

    //Definição e cadastro de distribuidores
    Distribuidor *distribuidor = new Distribuidor("distribuidor", 1);
    Cineart.armazenarNovoDistribuidor(*distribuidor);

    //Definição e cadastro de filmes
    Filme *ReiLeao = new Filme("Rei Leão",1,90);
    Filme *Titanic = new Filme("Titanic",1,195);
    Cineart.armazenarNovoFilme(*ReiLeao);
    Cineart.armazenarNovoFilme(*Titanic);

    //Definição de Sessões
    Sessao *sessao1 = new Sessao(*salaComum,"Rei Leão", std::to_string(20191101));
    Sessao *sessao2 = new Sessao(*salaIMAX,"Titanic", std::to_string(20191102));

    CHECK_NOTHROW(Cineart.armazenarSessao(salaComum->getNumero(),*sessao1));
    CHECK_NOTHROW(Cineart.armazenarSessao(salaIMAX->getNumero(),*sessao2));

    //DESALOCANDO MEMÓRIA
    delete salaComum;
    delete salaIMAX;
    delete distribuidor;
    delete ReiLeao;
    delete Titanic;
    delete sessao1;
    delete sessao2;
}