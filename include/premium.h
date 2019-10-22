#ifndef premium_h
#define premium_h
#include "imax.h"
#include <iostream>


class Premium : public IMAX {
    private:
        static float taxaAdicionalPremium;

    public:
        Premium(int numero,int capacidade);
        ~Premium();
        void setTaxaAdicional(float) override;
        float getValorPorAssento() override;
};
#endif