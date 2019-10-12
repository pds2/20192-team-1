#include "assento.h"
#include <iostream>

class Sala {
    private:
        int numero;
        int capacidade;
        float valorPorAssento;
    public:
        Sala(int,int,float); // numero, capacidade, valorPorAssento
        ~Sala();
        void alterarValorPorAssento(int);
        int getNumero();
        int getCapacidade();
        float getValorPorAssento();
        void setCapacidade(int);
        void setValorPorAssento(float);
        void setNumero(int);
};