#ifndef sessao_h
#define sessao_h
#include <iostream>
#include <map>
#include <iterator>
#include "sala.h"
#include "filme.h"


class Sessao {
    private:
    std::string datahora;
    Filme filme;
    Sala sala;

    public:
    Sessao(Sala sala, Filme filme, std::string datahora):sala(sala), filme(filme), datahora(datahora){  
        std::multimap <char,Assento> mapa_assentos;
    }
    ~Sessao();
    void imprimir_mapa_assentos();

};
#endif