#ifndef distribuidor_h
#define distribuidor_h
#include <iostream>
#include "pessoa.h"
#include <string>


class Distribuidor: public Pessoa {
    private:
        unsigned long long int ValorTotalArrecadado;
        unsigned long long int ValorDisponivelParaSaque;
    public:
        Distribuidor(std::string nome,unsigned long long int identificacao);
        ~Distribuidor();
        Distribuidor();
        void setValorTOtalArrecadado(unsigned long long int valor);
        void setValorDisponivelParaSaque(unsigned long long int valor);
        unsigned long long int getValorTotalArrecadado();
        unsigned long long int getValorDisponivelParaSaque();
};
#endif