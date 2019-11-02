#include "sessao.h"
#include "sala.h"
#include "filme.h"
#include "assento.h"
#include <string>

#define PRIMEIROASCII 65
#define PRIMEIROASSENTO 1

Sessao::Sessao(int fileiras, int assentosPorFileiras, std::string filme, std::string datahora) {
    int aux_fileira = PRIMEIROASCII;
    int aux_coluna = PRIMEIROASSENTO;
    int i, j;
    std::string nome_assento;
    Assento * cadeira;
    
    this->fileiras = fileiras;
    this->assentosPorFileiras = assentosPorFileiras;
    this->filme = filme;
    this->datahora = datahora;
    // agora preciso criar meu map de assentos com todos livres
    // preciso rodar o alfabeto ate a quantidade de fileiras e depois os numeros ate a quantidade de assentos por fileiras
    for (i=aux_fileira;i<=fileiras+aux_fileira;i++) {
        for (j=aux_coluna;j<=assentosPorFileiras;j++) {
            nome_assento = char(i) + std::to_string(j);
            this->mapa_assentos.insert(std::pair<std::string,Assento>(nome_assento,*new Assento()));
        }
    }
}

Sessao::~Sessao() {

}

void Sessao::imprimirMapaAssentos() {
    std::multimap<std::string, Assento>::iterator it;
    int count = 0;
    for (it = this->mapa_assentos.begin();it!=this->mapa_assentos.end();++it) {
        std::cout << it->first << " ";
        it->second.imprimirAssento();
        std::cout << "|\t";
        count++;
        if (count == this->assentosPorFileiras) {
            count = 0;
            std::cout << std::endl;
        }
    }
}
