#ifndef cinema_h
#define cinema_h
#include <iostream>
#include <vector>
#include "filme.h"
#include "pessoa.h"
#include "sessao.h"
#include "sala.h"

class Cinema {
    private:
        std::vector<Filme> listaFilmes;
        std::vector<Pessoa> listaEmpregados;
        std::vector<Sala> listaSalas;
        std::vector<Sessao> listaSessoes;
        std::vector<Distribuidor> listaDistribuidores;
        unsigned long long int verbaArrecadada;

    public:
        Cinema();
        ~Cinema();
        void criarNovaSala(int); // int:capacidade
        void criarNovaPessoa(int); // int:nivel de acesso
        void cadastrarNovoDistribuidor(Distribuidor);
        void cadastrarNovoFilme(Filme,Distribuidor);
        void cadastrarSessao(Sessao);
        void imprimirFilmesEmCartaz();
        void imprimirSessoesFuturas(Filme); // imprimir as sessoes futuras daquele filme
        void imprimirEmpregados();
        void imprimirDistribuidores();
        void adicionarVerbaArrecadada(unsigned int);
        unsigned long long int getVerbaArrecadada();
};
#endif