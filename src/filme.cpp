#include "filme.h"
#include <string>

Filme::Filme(std::string titulo, unsigned long long int id_distribuidor,int duracao_minutos) {
    this->titulo = titulo;
    this->distribuidor = id_distribuidor;
    this->duracao_minutos = duracao_minutos;
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

int Filme::getDuracaoMinutos() {
    return this->duracao_minutos;
}

int Filme::getDuracaoSegundos() {
    return this->duracao_minutos*60;
}