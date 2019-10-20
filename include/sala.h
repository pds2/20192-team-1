#ifndef sala_h
#define sala_h
#include "assento.h"
#include <iostream>


class Sala {
    private:
        int numero;
        int capacidade;
        static float valorPorAssento; // valor por assento precisa ser estático para que todas as salas do mesmo tipo tenham o mesmo valor por assento
    public:
        Sala(int numero,int capacidade);
        ~Sala();
        void alterarValorPorAssento(int);
        int getNumero();
        int getCapacidade();
        float getValorPorAssento();
        void setCapacidade(int);
        void setValorPorAssento(float);
        void setNumero(int);
};
#endif