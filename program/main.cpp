#include "assento.h"
#include "cinema.h"
#include "distribuidor.h"
#include "filme.h"
#include "pessoa.h"
#include "sala.h"

#include <string.h>
#include <iostream>
#include <limits>

#define ACESSO_MINIMO 0
#define ACESSO_MAXIMO 5
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
    std::string nome_empregado;
    unsigned long long int id_empregado;
    unsigned long long int id_distribuidor;
    int nivel_acesso_empregado;
    std::string nome_filme;
    char opcao_yn;
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
                num_sala = cinema.getProximaSalaASerCriada(); // aqui eu tenho que pegar o proximo numero de sala disponivel no meu mapa de salas
                std::cout << "Sala a ser criada: " << num_sala << std::endl;
                std::cout << "Digite a capacidade da sala: ";
                std::cin >> capacidade_sala;
                s = new Sala(num_sala,capacidade_sala);
                cinema.armazenarNovaSala(*s);
            }

            if (opcao == 2) {
                // criando um empregado

                // início transformar em funcao
                std::cout << "Nome do Empregado: " << std::endl;
                std::cin.ignore();
                std::getline (std::cin,nome_empregado);
                do {
                    std::cout << "Identificador Empregado: " << std::endl;
                    std::cin >> id_empregado;
                    if (cinema.isEmpregadoExistente(id_empregado)) {
                        std::cout << "O identificador já existe no sistema. Tente novamente." << std::endl;
                    }
                } while (cinema.isEmpregadoExistente(id_empregado));

                do {
                    std::cout << "Nivel de Acesso: " << std::endl;
                    std::cin >> nivel_acesso_empregado;
                    if (nivel_acesso_empregado < ACESSO_MINIMO || nivel_acesso_empregado > ACESSO_MAXIMO) {
                        std::cout << "Nivel inválido. Tente novamente." << std::endl;
                    }
                } while (nivel_acesso_empregado < ACESSO_MINIMO || nivel_acesso_empregado > ACESSO_MAXIMO);
                // fim transformar em funcao

                p = new Pessoa(nome_empregado,id_empregado,nivel_acesso_empregado);
                cinema.armazenarNovaPessoa(*p);
            }

            if (opcao == 3) {

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
    }
    if(numero_acesso==3){
        std::cout << "Olá Matheus, isso é um teste" << std::endl;
    }
    return 0;
}