#include <iostream>
#include <string>

class Pessoa {
    private:
        std::string nome;
        unsigned long long int identificacao; // CPF ou CNPJ
        int nivelDeAcesso;
    public:
        Pessoa(std::string,unsigned long long int, int);
        ~Pessoa();
        std::string getNome();
        long long int getIdentificacao();
        int getNivelDeAcesso();
        void setNome(std::string);
        void setIdentificacao(unsigned long long int);
        void setNivelDeAcesso(int);
};