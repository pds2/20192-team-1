#include "assento.h"

Assento::Assento() {
    this->estaLivre = true; //ao ser criado, o assento esta livre
}

Assento::~Assento() {  
}

bool Assento::getAssentoEstaLivre() {  /*implementando o getter:
                                        retorna FALSE se o assento está ocupado, retorna TRUE se o assento esta livre*/
    return(this->estaLivre);
}

bool Assento::setOcuparAssento() { /*implementando o setter:
                                    retorna FALSE se o assento já esta ocupado, retorna TRUE se estava livre e agora esta ocupado*/
    if(!this->estaLivre) {
        return false;
    }
    else {
        this->estaLivre = false;
        return true;
    }
}


