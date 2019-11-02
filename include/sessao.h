#ifndef sessao_h
#define sessao_h
#include <iostream>
#include <map>
#include <iterator>
#include <string>
#include "sala.h"
#include "filme.h"
#include "assento.h"


class Sessao {
    private:
        std::string datahora;
        std::string filme;
        int capacidade;
        std::map <std::string,Assento> mapa_assentos;
    public:
        Sessao(int capacidade, std::string filme, std::string datahora);
        ~Sessao();
        void imprimir_mapa_assentos();

};
#endif