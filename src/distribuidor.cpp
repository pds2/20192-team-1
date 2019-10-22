#include "distribuidor.h"
#include "pessoa.h"
#include <string>

Distribuidor::Distribuidor(std::string nome,unsigned long long int identificacao, int acesso) : Pessoa(nome, identificacao, acesso) {
    //Pessoa(nome,identificacao,acesso);
    this->ValorTotalArrecadado = 0;
}

Distribuidor::~Distribuidor() {

}

unsigned long long int Distribuidor::getValorTotalArrecadado() {
    return this->ValorTotalArrecadado;
}