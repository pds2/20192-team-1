#include "filme.h"
#include <string>

Filme::Filme(std::string titulo, Distribuidor &distribuidor) {
    this->titulo = titulo;
    this->distribuidor = &distribuidor;
}

Filme::~Filme() {

}