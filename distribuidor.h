#include <iostream>
#include "pessoa.h"
#include <string>

class Distribuidor: public Pessoa {
    private:
        unsigned long long int ValorTotalArrecadado;
        unsigned long long int ValorDisponivelParaSaque;
    public:
        Distribuidor(std::string,unsigned long long int, int);
        ~Distribuidor();
        void setValorTOtalArrecadado(unsigned long long int);
        void setValorDisponivelParaSaque(unsigned long long int);
        unsigned long long int getValorTotalArrecadado();
        unsigned long long int getValorDisponivelParaSaque();
};