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

// verifica se o id do empregado já existe na lista do cinema
bool Cinema::isEmpregadoExistente(unsigned long long int id_empregado) {
    std::map<unsigned long long int, Pessoa>::iterator it;
    it = this->listaEmpregados.find(id_empregado); // estou pegando certo?
    if (it != this->listaEmpregados.end()) { // estou pegando certo?
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
    (this->listaSalas).insert(std::pair<int, Sala>(sala.getNumero(),sala)); // estou pegando certo?
    std::cout << "Sala " << sala.getNumero() << " armazenada com sucesso!" << std::endl;
}

void Cinema::armazenarNovaPessoa(Pessoa pessoa) {
    this->listaEmpregados.insert(std::pair<unsigned long long int, Pessoa>(pessoa.getIdentificacao(),pessoa));
    std::cout << "Empregado " << pessoa.getNome() << " armazenado com sucesso!" << std::endl;
}

std::string Cinema::getNomeDoCinema() {
    return this->nomeDoCinema;
}

void Cinema::imprimirSalas() {
    std::map<int, Sala>::iterator it;
    it = this->listaSalas.begin(); // estou pegando certo?
    if (this->listaSalas.empty()) { // estou pegando certo?
        std::cout << "Não há salas Cadastradas ainda no " << this->getNomeDoCinema() << std::endl;
    } else {
        std::cout << "Sala\t| Capacidade\t|" << std::endl;
        while (it != this->listaSalas.end()) { // estou pegando certo?
            std::cout << it->first << "\t| " << it->second.getCapacidade() << "\t\t|";
            std::cout << std::endl;
            ++it;
        }
    }
}

void Cinema::imprimirEmpregados() {
    std::map<unsigned long long int, Pessoa>::iterator it;
    it = this->listaEmpregados.begin(); // estou pegando certo?
    if (this->listaEmpregados.empty()) { // estou pegando certo?
        std::cout << "Não há funcionários cadastrados no " << this->getNomeDoCinema() << std::endl;
    } else {
        std::cout << "ID\t\t| Nome\t\t\t| Nível|" << std::endl;
        while (it!= this->listaEmpregados.end()) { // estou pegando certo?
            std::cout << it->first << "\t| " << it->second.getNome() << "\t| " << it->second.getNivelDeAcesso() << "\t\t|";
            std::cout << std::endl;
            ++it;
        }
    }
}