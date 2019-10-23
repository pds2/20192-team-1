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
#include <limits>

#define ACESSO_MINIMO 0
#define ACESSO_MAXIMO 5

Pessoa criarEmpregado(){

    std::string nome;
    int id;
    unsigned long long int nivel;
    Pessoa *p;

    std::cout << "Nome do Empregado: " << std::endl;
    std::cin.ignore();
    std::getline (std::cin,nome);

    std::cout << "Identificador Empregado: " << std::endl;
    std::cin >> id;

    do {
        std::cout << "Nivel de Acesso: " << std::endl;
        std::cin >> nivel;
            if (nivel < ACESSO_MINIMO || nivel > ACESSO_MAXIMO) {
                std::cout << "Nivel inválido. Tente novamente." << std::endl;
            }
        } while (nivel < ACESSO_MINIMO || nivel > ACESSO_MAXIMO);

    p = new Pessoa(nome, id, nivel);
    return(*p);
}

Distribuidor criarDistribuidor(){

    std::string nome;
    int id;
    unsigned long long int acesso;
    Distribuidor *d;

    std::cout << "Nome do Distribuidor: " << std::endl;
    std::cin.ignore();
    std::getline (std::cin,nome);

    std::cout << "Identificador Distribuidor: " << std::endl;
    std::cin >> id;

    do {
        std::cout << "Nivel de Acesso: " << std::endl;
        std::cin >> acesso;
            if (acesso < ACESSO_MINIMO || acesso > ACESSO_MAXIMO) {
                std::cout << "Nivel inválido. Tente novamente." << std::endl;
            }
        } while (acesso < ACESSO_MINIMO || acesso > ACESSO_MAXIMO);

    d = new Distribuidor(nome, id, acesso);
    return(*d);
}



int main(){
    int numero_acesso;
    // INICIO VARIAVEIS DA ANDRESSA
    int opcao = 0;
    int num_sala;
    int capacidade_sala;
    Sala * s;
    Pessoa * p;
    Filme * f;
    Distribuidor * d;
    //std::string nome_empregado;
    //unsigned long long int id_empregado;
    unsigned long long int id_distribuidor;
    //int nivel_acesso_empregado;
    std::string nome_filme;
    char opcao_yn;
    // FIM VARIAVEIS DA ANDRESSA

    //INICIO VARIAVEIS DO HENRIQUE
    
    //FIM VARIAVEIS DO HENRIQUE
    std::cout << "Digite o numero de acesso" << std::endl;
    std::cin >> numero_acesso;

    if(numero_acesso==1){
        
        std::cout << "Olá Andressa" << std::endl;
        Cinema cinema("Cineart");
        
        while (opcao != -1) {
            std::cout << std::endl;
            std::cout << "O que você deseja fazer?" << std::endl;
            std::cout << "1. Criar uma nova sala do cinema" << std::endl;
            std::cout << "2. Criar um novo empregado" << std::endl;
            std::cout << "3. Cadastrar um novo distribuidor" << std::endl;
            std::cout << "4. Cadastrar um novo filme" << std::endl;
            std::cout << "5. Cadastrar uma nova sessao" << std::endl;
            std::cout << "6. Imprimir filmes em cartaz" << std::endl;
            std::cout << "7. Imprimir próximas sessoes" << std::endl;
            std::cout << "8. Imprimir salas do cinema" << std::endl;
            std::cout << "9. Imprimir empregados" << std::endl;
            std::cout << "10. Imprimir lista Distribuidores" << std::endl;
            std::cout << "11. Imprimir todos os filmes do cinema" << std::endl;
            std::cout << "12. Vender ingressos" << std::endl;
            std::cout << "-1. Sair" << std::endl;
            std::cin >> opcao;

            if (opcao == 1) {
                // criando uma sala
                num_sala = cinema.getProximaSalaASerCriada(); // aqui eu tenho que pegar o proximo numero de sala disponivel no meu mapa de salas
                std::cout << "Sala a ser criada: " << num_sala << std::endl;
                std::cout << "Digite a capacidade da sala: ";
                std::cin >> capacidade_sala;
                s = new Sala(num_sala,capacidade_sala);
                cinema.armazenarNovaSala(*s);
            }

            if (opcao == 2) {
                cinema.armazenarNovaPessoa(criarEmpregado());
            }

            if (opcao == 3) {
                cinema.armazenarNovoDistribuidor(criarDistribuidor());

            }

            if (opcao == 4) {
                // cadastrar um novo filme
                do {
                    std::cout << "Nome do Filme: " << std::endl;
                    std::cin.ignore();
                    std::getline(std::cin,nome_filme);
                    if (cinema.isFilmeExistente(nome_filme)) {
                        std::cout << "O título já existe no sistema. Tente novamente." << std::endl;
                    }
                } while (cinema.isFilmeExistente(nome_filme));
                do {
                    std::cout << "Código Distribuidor: " << std::endl;
                    std::cin >> id_distribuidor;
                    if (!cinema.isDistribuidorExistente(id_distribuidor)) {
                        
                        std::cout << "Distribuidor não localizado. Deseja cadastrar o Distribuidor ? " << id_distribuidor << "?" << std::endl;
                        std::cout << "Digite Y para cadastrar, qualquer outra tecla para imprimir a lista de distribuidores existentes." << std::endl;
                        std::cin >> opcao_yn;
                        if (opcao_yn == 'Y') {
                            // cadastrar distribuidor pela funcao que o Henrique vai fazer
                        } else {
                            cinema.imprimirDistribuidores();
                        }
                    }
                } while (!cinema.isDistribuidorExistente(id_distribuidor));
                f = new Filme(nome_filme,*d);
                cinema.armazenarNovoFilme(*f);
            }

            if (opcao == 8) {
                cinema.imprimirSalas();
            }

            if (opcao == 9) {
                cinema.imprimirEmpregados();
            }

            if (opcao == -1) {
                // desalocar os espacos alocados
                delete s;
                delete p;
                delete f;
                delete d;
                cinema.~Cinema();
            }
        }


    }
    if(numero_acesso==2){
        std::cout << "Olá Henrique" << std::endl;
        Sala sala1(2,50), sala2(1,50); //invertendo o numero das salas para teste

        IMAX salaIMAX1(4,60);
        Premium salaPremium1(3,60);        
        TresD salaTresD1(5,60);

        /*TESTANDO OS GETTERS E SETTERS DE SALAS*/

        std::cout << "Numero sala1: "<< sala1.getNumero() <<std::endl;
        std::cout << "Numero sala2: "<< sala2.getNumero() <<std::endl;
        std::cout << "NUMEROS ERRADOS!" << std::endl <<std::endl;

        std::cout << "Corrigindo:" << std::endl;
        sala1.setNumero(1);   
        sala2.setNumero(2);
            
        std::cout << "Numero sala1: "<< sala1.getNumero() <<std::endl;
        std::cout << "Numero sala2: "<< sala2.getNumero() <<std::endl <<std::endl;
        
        
        std::cout << "Capacidade sala1: "<< sala1.getCapacidade() <<std::endl;
        sala1.setCapacidade(20);
        std::cout <<"Setando capacidade da sala1 para 20. Novo valor: " << sala1.getCapacidade() << std::endl <<std::endl;

        std::cout << "Valor por assento sala1: "<< sala1.getValorPorAssento() <<std::endl;

        sala1.setValorPorAssento(1000);
        std::cout << "Setando para 1000 valor por assento da sala1. Novo valor :" << sala1.getCapacidade() <<std::endl;
        sala1.setValorPorAssento(27.00);

        std::cout << "Valor sala1: "<< sala1.getValorPorAssento() <<std::endl <<std::endl;
        
        /*TESTANDO AS SUBCLASSES*/
        std::cout << "Taxa adicional de salaIMAX: " << salaIMAX1.getTaxaAdicional() <<std::endl;
        std::cout << "Valor por assento de salaIMAX. ESPERADO: 32.4. RESULTADO: " << salaIMAX1.getValorPorAssento() <<std::endl;


        salaIMAX1.setTaxaAdicional(1.3);
        std::cout << "Setando Taxa adicional de salaIMAX para 1.3. Novo valor: " << salaIMAX1.getTaxaAdicional() <<std::endl;   
        std::cout << "Novo valor por assento de salaIMAX. ESPERADO: 35.1 RESULTADO: " << salaIMAX1.getValorPorAssento() <<std::endl <<std::endl;
        salaIMAX1.setTaxaAdicional(1.2);

        std::cout << "Taxa adicional de salaPremium: " << salaPremium1.getTaxaAdicional() <<std::endl;
        std::cout << "Valor por assento de salaPremium. ESPERADO: 55.08. RESULTADO: " << salaPremium1.getValorPorAssento() <<std::endl;


        salaPremium1.setTaxaAdicional(1.8);
        std::cout << "Setando Taxa adicional de salaPremium para 1.8. Novo valor: " << salaPremium1.getTaxaAdicional() <<std::endl;   
        std::cout << "Novo valor por assento de salaPremium. ESPERADO: 58.32 RESULTADO: " << salaPremium1.getValorPorAssento() <<std::endl<<std::endl;
        salaPremium1.setTaxaAdicional(1.7);

        std::cout << "Taxa adicional de salaTresD: " << salaTresD1.getTaxaAdicional() <<std::endl;
        std::cout << "Valor por assento de salaTresD. ESPERADO: 40.4. RESULTADO: " << salaTresD1.getValorPorAssento() <<std::endl;


        salaTresD1.setTaxaAdicional(10);
        std::cout << "Setando Taxa adicional de salaTresD para 10. Novo valor: " << salaTresD1.getTaxaAdicional() <<std::endl;   
        std::cout << "Novo valor por assento de salaTresD. ESPERADO: 42.4 RESULTADO: " << salaTresD1.getValorPorAssento() <<std::endl;
        salaTresD1.setTaxaAdicional(8);
    }
    if(numero_acesso==3){
        std::cout << "Olá Matheus, isso é um teste" << std::endl;
    }
    return 0;
}