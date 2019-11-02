#include <iostream>
#include "cinema.h"

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

// verifica se titulo do filme ja existe na lista
bool Cinema::isFilmeExistente(std::string nome_filme) {
    std::map<std::string,Filme>::iterator it;
    it = this->listaFilmes.find(nome_filme); // estou pegando certo?
    if (it != this->listaFilmes.end()) { // estou pegando certo?
        return true;
    } else {
        return false;
    }
}

// verifica se o id do distribuidor ja existe na lista
bool Cinema::isDistribuidorExistente(unsigned long long int id_distribuidor) {
    std::map<unsigned long long int,Distribuidor>::iterator it;
    it = this->listaDistribuidores.find(id_distribuidor); 
    if (it != this->listaDistribuidores.end()) {
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
    
    if (isEmpregadoExistente(pessoa.getIdentificacao())) {
            std::cout << "O identificador já existe no sistema. Tente novamente." << std::endl;
    }

    else {
    this->listaEmpregados.insert(std::pair<unsigned long long int, Pessoa>(pessoa.getIdentificacao(),pessoa));
    std::cout << "Empregado " << pessoa.getNome() << " armazenado com sucesso!" << std::endl;
    }
}

void Cinema::armazenarNovoDistribuidor(Distribuidor distribuidor) {
    
    if (isDistribuidorExistente(distribuidor.getIdentificacao())) {
            std::cout << "O identificador já existe no sistema. Tente novamente." << std::endl;
    }

    else {
    this->listaDistribuidores.insert(std::pair<unsigned long long int, Distribuidor>(distribuidor.getIdentificacao(),distribuidor));
    std::cout << "Distribuidor " << distribuidor.getNome() << " armazenado com sucesso!" << std::endl;
    }
}
void Cinema::armazenarNovoFilme(Filme filme) {
    if (isFilmeExistente(filme.getTitulo())) {
                std::cout << "O título já existe no sistema. Tente novamente." << std::endl;
            }
    else {
    this->listaFilmes.insert(std::pair<std::string,Filme>(filme.getTitulo(),filme));
    std::cout << "Filme " << filme.getTitulo() << " armazenado com sucesso!" << std::endl;
    }
}

std::string Cinema::getNomeDoCinema() {
    return this->nomeDoCinema;
}

// imprime a lista de salas cadastradas no cinema
void Cinema::imprimirSalas() {
    std::map<int, Sala>::iterator it;
    it = this->listaSalas.begin(); // estou pegando certo?
    if (this->listaSalas.empty()) { // estou pegando certo?
        std::cout << "Não há salas Cadastradas ainda no " << this->getNomeDoCinema() << std::endl;
    } else {
        std::cout << "Sala\t| Capacidade\t| Tipo\t\t|" << std::endl;
        while (it != this->listaSalas.end()) { // estou pegando certo?
            std::cout << it->first << "\t| " << it->second.getCapacidade() << "\t\t|" << it->second.getTipo() << "\t\t|";
            std::cout << std::endl;
            ++it;
        }
    }
}

// imprime a lista de empregados cadastrados no cinema
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

void Cinema::imprimirDistribuidores() {
    std::map<unsigned long long int, Distribuidor>::iterator it;
    it = this->listaDistribuidores.begin(); // estou pegando certo?
    if (this->listaDistribuidores.empty()) { // estou pegando certo?
        std::cout << "Não há distribuidores cadastrados no " << this->getNomeDoCinema() << std::endl;
    } else {
        std::cout << "ID\t| Nome\t\t\t| Valor Arrecadado" << std::endl;
        while (it != this->listaDistribuidores.end()) { // estou pegando certo?
            std::cout << it->first << "\t| " << it->second.getNome() << "\t| " << it->second.getValorTotalArrecadado() << "\t\t|";
            std::cout << std::endl;
            ++it;
        }
    }
}

void Cinema::imprimirFilmesCadastrados(){
    std::map<std::string, Filme>::iterator it;
    it = this->listaFilmes.begin(); 
    if (this->listaFilmes.empty()) { 
        std::cout << "Não há filmes cadastrados no " << this->getNomeDoCinema() << std::endl;
    } else {
        std::cout << "Nome\t\t| Distribuidor" << std::endl;
        while (it != this->listaFilmes.end()) { 
            std::cout << it->first << "\t\t| " << this->listaDistribuidores.find(it->second.getDistribuidor())->second.getNome();
            std::cout << std::endl;
            ++it;
        }
    }
}
