#include "sala.h"

float Sala::valorPorAssento = 10.00;

Sala::Sala(int numero,int capacidade) {
    this->capacidade = capacidade;
    this->numero = numero;
}

Sala::~Sala() {
    
}

int Sala::getNumero() {
    return this->numero;
}

int Sala::getCapacidade() {
    return this->capacidade;
}