#include "filme.h"
#include <string>

Filme::Filme(std::string titulo, Distribuidor &distribuidor) {
    this->titulo = titulo;
    this->distribuidor = &distribuidor;
}

Filme::~Filme() {

}

Filme::Filme() {
    
}

std::string Filme::getTitulo(){
    return(this->titulo);
}