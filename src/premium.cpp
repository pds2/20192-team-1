#include "premium.h"
#include "imax.h"

float Premium::taxaAdicionalPremium = 1.7; //é aplicada à taxa IMAX

Premium::Premium(int numero, int capacidade) : IMAX(numero,capacidade,"Premium"){
    this->capacidade = capacidade;
    this->numero = numero;
}

Premium::~Premium(){}

void Premium::setTaxaAdicional(float taxa){
    this->taxaAdicionalPremium = taxa;
}

float Premium::getTaxaAdicional(){
    return(taxaAdicionalPremium);
}

float Premium::getValorPorAssento(){
    return(Sala::valorPorAssento * IMAX::taxaAdicionalIMAX * Premium::taxaAdicionalPremium);
}