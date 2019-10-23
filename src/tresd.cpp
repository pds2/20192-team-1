#include "tresd.h"

float TresD::taxaAdicionalTresD = 8.00; //valor dos oculos

TresD::TresD(int numero, int capacidade) : IMAX(numero,capacidade){
    this->capacidade = capacidade;
    this->numero = numero;
}

TresD::~TresD(){}

void TresD::setTaxaAdicional(float taxa){
    this->taxaAdicionalTresD = taxa;
}

float TresD::getTaxaAdicional(){
    return(taxaAdicionalTresD);
}


float TresD::getValorPorAssento(){
    return((Sala::valorPorAssento * IMAX::taxaAdicionalIMAX) + TresD::taxaAdicionalTresD);
}