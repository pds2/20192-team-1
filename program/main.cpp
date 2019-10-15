#include "assento.h"
#include "cinema.h"
#include "distribuidor.h"
#include "filme.h"
#include "pessoa.h"
#include "sala.h"

#include <string.h>
#include <iostream>

int main(){
    int numero_acesso;
    std::cout << "Digite o numero de acesso" << std::endl;
    std::cin >> numero_acesso;

    if(numero_acesso==1){
        std::cout << "Olá Andressa" << std::endl;
    }
    if(numero_acesso==2){
        std::cout << "Olá Henrique" << std::endl;
    }
    if(numero_acesso==3){
        std::cout << "Olá Matheus" << std::endl;
    }
    return 0;
}