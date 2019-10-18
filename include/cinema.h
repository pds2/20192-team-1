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
        // os maps terao como chave respectivamente:
        // filme: titulo do filme
        // empregados: numero identificador
        // sala: numero da sala
        // sessao: string representando data/hora
        // lista distribuidores: numero identificador
        std::map<std::string, Filme> listaFilmes;
        std::map<unsigned long long int, Pessoa> listaEmpregados;
        std::map<int, Sala> listaSalas;
        std::map<std::string, Sessao> listaSessoes;
        std::map<unsigned long long int, Distribuidor> listaDistribuidores;
        unsigned long long int verbaArrecadada;
        std::string nomeDoCinema;

    public:
        Cinema(std::string nome);
        ~Cinema();
        void criarNovaSala(int capacidade); // int:capacidade
        void criarNovaPessoa(int nivelAcesso); // int:nivel de acesso
        void armazenarNovoDistribuidor(Distribuidor novoDistribuidor);
        void armazenarNovoFilme(Filme novoFilme,Distribuidor distribuidorNovoFilme);
        void armazenarSessao(Sessao novaSessao);
        void imprimirFilmesEmCartaz();
        void imprimirSessoesFuturas(Filme filme); // imprimir as sessoes futuras daquele filme
        void imprimirEmpregados();
        void imprimirDistribuidores();
        void adicionarVerbaArrecadada(unsigned int valorParaAdicionar);
        unsigned long long int getVerbaArrecadada();
        void setNomeDoCinema(std::string novoNome);
        std::string getNomeDoCinema();
};
#endif