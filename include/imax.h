#ifndef imax_h
#define imax_h
#include "sala.h"
#include <string>
#include <iostream>



class IMAX : public Sala {
    protected:
        static float taxaAdicionalIMAX;

    public:
        IMAX(int numero,int capacidade,std::string tipo);
        IMAX(int numero,int capacidade);
        ~IMAX();
        virtual void setTaxaAdicional(float taxa_adicional);
        virtual float getTaxaAdicional(); // é virtual para cada tipo de sala retornar sua proŕia taxa
        float getValorPorAssento() override;
        
};
#endif