#ifndef tresd_h
#define tresd_h
#include "imax.h"
#include <iostream>


class TresD : public IMAX {
    private:
        static float taxaAdicionalTresD;

    public:
        TresD(int numero,int capacidade);
        ~TresD();
        void setTaxaAdicional(float) override;
        float getValorPorAssento() override;
};
#endif