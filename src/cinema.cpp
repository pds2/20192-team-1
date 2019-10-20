#include <iostream>
#include "cinema.h"

// implementada ok!
Cinema::Cinema (std::string nome) {
    this->nomeDoCinema = nome;
    std::cout << "Bem-vindo ao " << this->nomeDoCinema << "!" << std::endl;
}

Cinema::~Cinema () {
    
}

std::map<int, Sala> Cinema::getSalas() {
    return this->listaSalas;
}

std::map<unsigned long long int, Pessoa> Cinema::getEmpregados() {
    return this->listaEmpregados;
}

std::map<std::string, Filme> Cinema::getFilmes() {
    return this->listaFilmes;
}

std::map<std::string, Sessao> Cinema::getSessoes() {
    return this->listaSessoes;
}

std::map<unsigned long long int, Distribuidor> Cinema::getDistribuidores() {
    return this->listaDistribuidores;
}

bool Cinema::isListaSalaVazia() {
    if ((this->getSalas()).empty()) {
        return true;
    } else {
        return false;
    }
}

// a sala sempre eh criada em sequencia a funcao pega o tamanho da lista e retorna +1 do tamanho
int Cinema::getProximaSalaASerCriada() {
    return (this->getSalas()).size()+1;
}

void Cinema::armazenarNovaSala(Sala sala) {
    (this->listaSalas).insert(std::pair<int, Sala>(sala.getNumero(),sala));
    std::cout << "Sala " << sala.getNumero() << " armazenada com sucesso!" << std::endl;
}

std::string Cinema::getNomeDoCinema() {
    return this->nomeDoCinema;
}

void Cinema::imprimirSalas() {
    std::map<int, Sala>::iterator it;
    it = this->listaSalas.begin();
    if (this->listaSalas.empty()) {
        std::cout << "Não há salas Cadastradas ainda no " << this->getNomeDoCinema() << std::endl;
    } else {
        std::cout << "Sala\t| Capacidade\t|" << std::endl;
        while (it != this->listaSalas.end()) {
            std::cout << it->first << "\t| " << it->second.getCapacidade() << "\t\t|";
            std::cout << std::endl;
            ++it;
        }
    }
}