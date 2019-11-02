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
        int fileiras;
        int assentosPorFileiras;
        std::string datahora;
        std::string filme;
        std::multimap <std::string,Assento> mapa_assentos;
    public:
        Sessao(int fileiras, int assentosPorFileiras, std::string filme, std::string datahora);
        ~Sessao();
        void imprimirMapaAssentos();

};
#endif