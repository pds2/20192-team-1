#include "sala.h"

float Sala::valorPorAssento = 27.00;

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

float Sala::getValorPorAssento() {
    return Sala::valorPorAssento;
}

void Sala::setCapacidade(int capacidade) {
    this->capacidade = capacidade;
}

void Sala::setValorPorAssento(float valor) {
    this->valorPorAssento = valor;
}

void Sala::setNumero(int numero) {
    this->numero = numero;
}

