#include "premium.h"

float Premium::taxaAdicionalPremium = 1.7;

Premium::Premium(int numero, int capacidade) : IMAX(numero,capacidade){
    this->capacidade = capacidade;
    this->numero = numero;
}

Premium::~Premium(){}

void Premium::setTaxaAdicional(float taxa){
    this->taxaAdicionalPremium = taxa;
}

float Premium::getValorPorAssento(){
    return(Sala::valorPorAssento * Premium::taxaAdicionalPremium);
}