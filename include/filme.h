#ifndef filme_h
#define filme_h
#include "distribuidor.h"
#include <iostream>
#include <string>


class Filme {
    private:
        std::string titulo;
        unsigned long long int verbaArrecadada;
        unsigned long long int publicoTotal;
        float ticketMedio;
        Distribuidor *distribuidor;
    public:
        Filme(std::string,*Distribuidor); // nao tenho certeza da passagem do distribuidor como ponteiro (mas tem que ser ponteiro)
        ~Filme();
        float getTicketMedio(); 
        unsigned long long int getPublicoTotal();
        unsigned long long int getVerbaArrecadada();
        void setTicketMedio(float);
        void setPublicoTotal(unsigned long long int);
        void setVerbaArrecadada(unsigned long long int);
};
#endif