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
    unsigned long long int id;
    int nivel;
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

Distribuidor criarDistribuidor() {

    std::string nome;
    unsigned long long int id;
    Distribuidor *d;

    std::cout << "Nome do Distribuidor: " << std::endl;
    std::cin.ignore();
    std::getline (std::cin,nome);

    std::cout << "Identificador Distribuidor: " << std::endl;
    std::cin >> id;

    d = new Distribuidor(nome, id);
    return(*d);
}

Filme criarFilme(std::map<unsigned long long int, Distribuidor> listaDistribuidores) {
    int id_distribuidor;
    std::map<unsigned long long int, Distribuidor>::iterator distribuidor_it;
    Distribuidor * d = new Distribuidor();
    char opcao_yn;
    std::string nome_filme;
    Filme * f = new Filme();
    // cadastrar um novo filme
    std::cout << "Código Distribuidor: " << std::endl;
    std::cin >> id_distribuidor;

    distribuidor_it = listaDistribuidores.find(id_distribuidor);
    if (distribuidor_it == listaDistribuidores.end()) { 
        
        std::cout << "Distribuidor não localizado"<< std::endl;
        std::cout << "Digite qualquer tecla para retornar ao Menu Inicial" << std::endl;
        std::cin >> opcao_yn; // precisamos trocar pra nao precisar dar enter
        return *f;          

    } else {
        // quer dizer que o distribuidor já existe
        *d = distribuidor_it->second;
        std::cout << "Nome do Filme: " << std::endl;
        std::cin.ignore();
        std::getline(std::cin,nome_filme);        
        f = new Filme(nome_filme,*d);
        return *f;
    }
}

Sala cadastrarNovaSala (int num_sala) {
    Sala *s = new Sala();
    int capacidade_sala;
    int tipo_de_sala;
    std::cout << "Sala a ser criada: " << num_sala << std::endl;
    std::cout << "Digite a capacidade da sala: ";
    std::cin >> capacidade_sala;
    do {
    std::cout << "Escolha o tipo de sala:" << std::endl;
    std::cout << "1. Comum" << std::endl;
    std::cout << "2. IMAX" << std::endl;
    std::cout << "3. IMAX Premium" << std::endl;
    std::cout << "4. IMAX 3D" << std::endl;
    std::cin >> tipo_de_sala;

    if (tipo_de_sala < 1 || tipo_de_sala > 4) {
    std::cout << "Tipo de sala inválido." << std::endl;
    }
    } while (tipo_de_sala < 1 || tipo_de_sala > 4);

    // de acordo com a opcao de sala, preciso criar uma sala aqui
    if (tipo_de_sala == 1) {
    // sala comum
    s = new Sala(num_sala,capacidade_sala);
    }

    if (tipo_de_sala == 2) {
    // sala IMAX
    s = new IMAX(num_sala,capacidade_sala);

    }

    if (tipo_de_sala == 3) {
    // sala IMAX Premium
    s = new Premium(num_sala,capacidade_sala);


    } 

    if (tipo_de_sala == 4) {
    // IMAX 3D
    s = new TresD(num_sala,capacidade_sala);
    }

    return *s;
}


int main() {
    int numero_acesso;
    // INICIO VARIAVEIS DA ANDRESSA
    int opcao = 0;
    int num_sala;
    int capacidade_sala;
    int tipo_de_sala = 0;
    Sala * s = new Sala();
    Pessoa * p = new Pessoa();
    Filme * f = new Filme();
    Distribuidor * d = new Distribuidor();
    std::map<unsigned long long int, Distribuidor>::iterator distribuidor_it;
    std::string nome_filme;
    // FIM VARIAVEIS DA ANDRESSA

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
                cinema.armazenarNovaSala(cadastrarNovaSala(cinema.getProximaSalaASerCriada()));
            }

            if (opcao == 2) {
                cinema.armazenarNovaPessoa(criarEmpregado());
            }

            if (opcao == 3) {
                // cadastrar um novo distribuidor
                cinema.armazenarNovoDistribuidor(criarDistribuidor());
            }

            if (opcao == 4) {
                    // PRECISAMOS FAZER TRATAMENTO DE EXCESSAO AQUI
                    // SE NAO HOUVE DISTRIBUIDOR VAI RETORNAR UM FILME DE QUALQUER JEITO
                    // TEMOS QUE FAZER UM THROW COM CATCH
                    cinema.armazenarNovoFilme(criarFilme(cinema.getDistribuidores()));
            }

            if (opcao == 8) {
                cinema.imprimirSalas();
            }

            if (opcao == 9) {
                cinema.imprimirEmpregados();
            }

            if(opcao == 10){
                cinema.imprimirDistribuidores();
            }              
            
            if(opcao == 11){
                cinema.imprimirFilmesCadastrados();
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
        std::cout << "Setando para 1000 valor por assento da sala1. Novo valor :" << sala1.getValorPorAssento() <<std::endl;
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
                do {
                    std::cout << "Escolha o tipo de sala:" << std::endl;
                    std::cout << "1. Comum" << std::endl;
                    std::cout << "2. IMAX" << std::endl;
                    std::cout << "3. IMAX Premium" << std::endl;
                    std::cout << "4. IMAX 3D" << std::endl;
                    std::cin >> tipo_de_sala;

                    if (tipo_de_sala < 1 || tipo_de_sala > 4) {
                        std::cout << "Tipo de sala inválido." << std::endl;
                    }
                } while (tipo_de_sala < 1 || tipo_de_sala > 4);

                // de acordo com a opcao de sala, preciso criar uma sala aqui
                if (tipo_de_sala == 1) {
                    // sala comum

                }

                if (tipo_de_sala == 2) {
                    // sala IMAX

                }

                if (tipo_de_sala == 3) {
                    // sala IMAX Premium


                } else {
                    // tipo de sala == 4
                    // IMAX 3D

                }

                s = new Sala(num_sala,capacidade_sala);
                cinema.armazenarNovaSala(*s);
            }

            if (opcao == 2) {
                cinema.armazenarNovaPessoa(criarEmpregado());
            }

            if (opcao == 3) {
                // cadastrar um novo distribuidor
                cinema.armazenarNovoDistribuidor(criarDistribuidor());
            }

            if (opcao == 4) {
                    // PRECISAMOS FAZER TRATAMENTO DE EXCESSAO AQUI
                    // SE NAO HOUVE DISTRIBUIDOR VAI RETORNAR UM FILME DE QUALQUER JEITO
                    // TEMOS QUE FAZER UM THROW COM CATCH
                    cinema.armazenarNovoFilme(criarFilme(cinema.getDistribuidores()));
            }

            if (opcao == 8) {
                cinema.imprimirSalas();
            }

            if (opcao == 9) {
                cinema.imprimirEmpregados();
            }

            if(opcao == 10){
                cinema.imprimirDistribuidores();
            }

            if(opcao == 11){
                cinema.imprimirFilmesCadastrados();
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
    if(numero_acesso==3){
        std::cout << "Olá Matheus, isso é um teste" << std::endl;
    }
    return 0;
}