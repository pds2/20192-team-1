#ifndef sessao_h
#define sessao_h
#include <iostream>
#include <map>
#include <iterator>
#include <string>
#include "sala.h"
#include "filme.h"


class Sessao {
    private:
        std::string datahora;
        Filme *filme;
        Sala *sala;

    public:
        Sessao(Sala sala, Filme filme, std::string datahora);
        ~Sessao();
        void imprimir_mapa_assentos();

};
#endif