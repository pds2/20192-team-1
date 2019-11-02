#include "sessao.h"
#include "sala.h"
#include "filme.h"
#include "assento.h"
#include <string>

Sessao::Sessao(int capacidade, std::string filme, std::string datahora) {
    this->capacidade = capacidade;
    this->filme = filme;
    this->datahora = datahora;
    // agora preciso criar meu map de assentos com todos livres
    
}

Sessao::~Sessao() {

}