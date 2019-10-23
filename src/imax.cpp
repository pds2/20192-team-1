#include "imax.h"

float IMAX::taxaAdicionalIMAX = 1.2;

IMAX::IMAX(int numero, int capacidade) : Sala(numero,capacidade){
    this->capacidade = capacidade;
    this->numero = numero;
}

IMAX::~IMAX(){}

void IMAX::setTaxaAdicional(float taxa){
    this->taxaAdicionalIMAX = taxa;
}

float IMAX::getTaxaAdicional(){
    return(IMAX::taxaAdicionalIMAX);
}

float IMAX::getValorPorAssento(){
    return(Sala::valorPorAssento * IMAX::taxaAdicionalIMAX);
}