#include <iostream>
#include "cinema.h"

Cinema::Cinema (std::string nome) {
    this->nomeDoCinema = nome;
    std::cout << "Bem-vindo ao " << this->nomeDoCinema << "!" << std::endl;
}

Cinema::~Cinema () {
    
}