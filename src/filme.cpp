#include "filme.h"
#include <string>

Filme::Filme(std::string titulo, unsigned long long int id_distribuidor) {
    this->titulo = titulo;
    this->distribuidor = id_distribuidor;
}

Filme::~Filme() {

}

Filme::Filme() {
    
}

std::string Filme::getTitulo(){
    return(this->titulo);
}

unsigned long long int Filme::getDistribuidor(){
    return(this->distribuidor);
}