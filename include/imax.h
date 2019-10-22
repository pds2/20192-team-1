#ifndef imax_h
#define imax_h
#include "sala.h"
#include <iostream>


class IMAX : public Sala {
    private:
        static float taxaAdicionalIMAX;

    public:
        IMAX(int,int);
        ~IMAX();
        virtual void setTaxaAdicional(float);
        float getValorPorAssento() override;
};
#endif