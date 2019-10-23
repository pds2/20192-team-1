#ifndef imax_h
#define imax_h
#include "sala.h"
#include <iostream>



class IMAX : public Sala {
    protected:
        static float taxaAdicionalIMAX;

    public:
        IMAX(int,int);
        ~IMAX();
        virtual void setTaxaAdicional(float);
        virtual float getTaxaAdicional(); // é virtual para cada tipo de sala retornar sua proŕia taxa
        float getValorPorAssento() override;
        
};
#endif