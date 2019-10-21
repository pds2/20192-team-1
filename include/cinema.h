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
        void armazenarNovaSala(Sala sala); 
        void armazenarNovaPessoa(Pessoa pessoa); 
        void armazenarNovoDistribuidor(Distribuidor novoDistribuidor);
        void armazenarNovoFilme(Filme novoFilme,Distribuidor distribuidorNovoFilme);
        void armazenarSessao(Sessao novaSessao);
        void imprimirFilmesEmCartaz();
        void imprimirSessoesFuturas(Filme filme);
        void imprimirEmpregados();
        void imprimirDistribuidores();
        void imprimirSalas();
        void adicionarVerbaArrecadada(unsigned int valorParaAdicionar);
        unsigned long long int getVerbaArrecadada();
        void setNomeDoCinema(std::string novoNome);
        int getProximaSalaASerCriada();
        bool isListaSalaVazia(); // testa se nao ha nenhum elemento na lista de salas
        bool isEmpregadoExistente(unsigned long long int id_empregado);
        std::map<std::string, Filme> getFilmes();
        std::map<unsigned long long int, Pessoa> getEmpregados();
        std::map<int, Sala> getSalas();
        std::map<std::string, Sessao> getSessoes();
        std::map<unsigned long long int, Distribuidor> getDistribuidores();
        std::string getNomeDoCinema();
};
#endif