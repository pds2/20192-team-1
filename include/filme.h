#ifndef filme_h
#define filme_h
#include "distribuidor.h"
#include <iostream>
#include <string>


class Filme {
    private:
        std::string titulo;
        int duracao_minutos;
        unsigned long long int distribuidor;
        unsigned long long int verbaArrecadada;
        unsigned long long int publicoTotal;
        float ticketMedio;
    public:
        Filme(std::string titulo, unsigned long long int distribuidor,int duracao_minutos);
        Filme();
        ~Filme();
        int getDuracaoMinutos();
        int getDuracaoSegundos();
        float getTicketMedio(); 
        std::string getTitulo();
        unsigned long long int getPublicoTotal();
        unsigned long long int getVerbaArrecadada();
        void setTicketMedio(float);
        void setPublicoTotal(unsigned long long int);
        void setVerbaArrecadada(unsigned long long int);
        unsigned long long int getDistribuidor();
};
#endif