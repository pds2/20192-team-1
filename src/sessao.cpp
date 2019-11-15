#include "sessao.h"
#include "sala.h"
#include "filme.h"
#include "assento.h"
#include <string>

#define PRIMEIROASCII 65
#define PRIMEIROASSENTO 1

Sessao::Sessao(Sala sala, std::string filme, std::string dataHora) {
    this->qtde_assentosLivres = sala.getFileiras()*sala.getAssentosPorFileiras();
    this->qtde_assentosOcupados = 0;
    int aux_fileira = PRIMEIROASCII;
    int aux_coluna = PRIMEIROASSENTO;
    int i, j;
    std::string nome_assento;   
    this->filme = filme;
    this->dataHora = dataHora;
    this->sala = sala;
    // agora preciso criar meu map de assentos com todos livres
    // preciso rodar o alfabeto ate a quantidade de fileiras e depois os numeros ate a quantidade de assentos por fileiras
    for (i=aux_fileira;i<=sala.getFileiras()+aux_fileira;i++) {
        for (j=aux_coluna;j<=sala.getAssentosPorFileiras();j++) {
            nome_assento = char(i) + std::to_string(j);
            this->mapa_assentos.insert(std::pair<std::string,Assento>(nome_assento,*new Assento()));
        }
    }
}

Sessao::~Sessao() {

}

Sessao::Sessao() {
    this->qtde_assentosLivres = this->sala.getCapacidade();
    this->qtde_assentosOcupados = 0;
}

std::string Sessao::getChaveSessao() {
    if (this->sala.getNumero() < 10) {
        return this->dataHora + "0" + std::to_string(this->sala.getNumero());
    } else {
        return this->dataHora + std::to_string(this->sala.getNumero());
    }
}

void Sessao::imprimirMapaAssentos() {
    std::multimap<std::string, Assento>::iterator it;
    int count = 0;
    for (it = this->mapa_assentos.begin();it!=this->mapa_assentos.end();++it) {
        std::cout << it->first << " ";
        it->second.imprimirAssento();
        std::cout << "|\t";
        count++;
        if (count == this->sala.getAssentosPorFileiras()) {
            count = 0;
            std::cout << std::endl;
        }
    }
}

std::string Sessao::getDataHora() {
    return this->dataHora;
}

std::string Sessao::getFilme() {
    return this->filme;
}

Sala Sessao::getSala() {
    return this->sala;
}

int Sessao::getQtdeAssentosLivres() {
    return this->qtde_assentosLivres;
}

int Sessao::getQtdeAssentosOcupados() {
    return this->qtde_assentosOcupados;
}

bool Sessao::isAssentoLivre(std::string assento) {    
    try{        
        std::multimap <std::string,Assento>::iterator it =this->mapa_assentos.find(assento);
        if(it==mapa_assentos.end()){
            throw("Assento inexistente");
        }else{

    return it->second.getAssentoEstaLivre();
        }
    }
    catch(char const* ex){
        std::cout << "exceção lançada" << std::endl;
    }
}

void Sessao::setAssentoOcupado(std::string assento) {
    this->mapa_assentos.find(assento)->second.setOcuparAssento();
    this->qtde_assentosOcupados++;
    this->qtde_assentosLivres--;
}

