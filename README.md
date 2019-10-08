# Projeto de gerenciamento de uma exibidora de cinema

Este projeto consiste em um sistema de gerenciamento para uma exibidora de cinema. 
O sistema deve ser capaz de gerenciar as salas do cinema, suas respectivas sessões, 
bem como a venda de ingressos de acordo com o tipo da sala (IMAX,3D,COMUM) e a disponibilidade dos assentos, 
incluindo informações sobre a bilheteria total e a verba arrecadada.

## Autores

* **Andressa Nowasyk** - @andressanowasyk
* **Henrique Lisboa** - @hlisboasousa
* **Matheus Akira** - @matheysakira

## User Stories


* Como um vendedor, eu quero ver todos os assentos disponíveis e seus respectivos preços das sessões abertas para a venda para que eu possa mostrar ao cliente.

* Como um vendedor, eu quero conseguir vender ingressos de assentos disponíveis as sessões futuras.

* Como um gerente, eu quero ser capaz de adicionar um novo filme para exibição, a porcentagem de bilheteria do distribuidor e do exibidor, o horário, a quantidade e o tipo de sala das sessões de cada novo filme.

* Como gerente, eu quero ser capaz de ver a renda de cada filme, sala e sessão para que eu possa decidir ou não continuar com determinado filme em cartaz.

* Como gerente, eu quero ser capaz de adicionar e deletar sessões.

* Como gerente, eu quero ser capaz de definir valores para cada assento de acordo com o tipo de sala, horário da sessão e combo de pipoca.

* Como diretor do cinema, eu quero poder criar novas salas ou deletar as salas existentes.

## Cartões CRC

//Podia ter um texto que explicasse de uma forma mais geral a distribuição das classes//

*CRC:

| Classe: Cinema                            |                       |
|-------------------------------------------|-----------------------|
| Responsabilidades:                        | Colaborações:         |
|   *Ser capaz de adicionar salas*;         |                       |
|   *Ser capaz de adicionar filmes*;        |                       |
|   *Ser capaz adicionar sessões*;          |                       |
|   *Ser capaz de adicionar distribuidor*;  |                       |
|   *Saber filmes em cartaz*;               |                       |
|   *Saber valor total já arrecadado*;      |                       |


| Classe: Sala                      |               |
|-----------------------------------|---------------|
| Responsabilidades:                | Colaborações: |
|   *Saber sua capacidade*;         |
|   *Saber seu valor por assento*;  | 


| Classe: Assento                     |               | 
|-------------------------------------|---------------|
| Responsabilidades:                  | Colaborações: |
|   *Saber se está ocupado ou livre*; |               |
|   *Ser capaz de setar seu estado*;  |               |


| CLasse: Filmes                                            |                 |
|-----------------------------------------------------------|-----------------|
| Responsabilidades:                                        | Colaborações:   |
|   *Saber sua duração*;                                    | *Distribuidor*; |
|   *Saber seu título*;                                     |                 |
|   *Saber sua verba arrecadada*;                           |                 |
|   *Saber o distribuidor que negociou*;                    |                 |
|   *Saber sua bilheteria total*;                           |                 |
|   *Saber seu público total*;                              |                 |
|   *Saber seu tícket médio*;                               |                 |
|   *Ser capaz de adicionar valor na sua verba arrecadada*; |                 |

| Classe: Sessão                                                                  |                 |
|---------------------------------------------------------------------------------|-----------------|
| Responsabilidades:                                                              | Colaborações:   |
|   *Saber sua data/hora*;                                                        |  *Sala*         |
|   *Saber seu filme*;                                                            |  *FIlme*        |
|   *Ser capaz de criar seu mapa de assentos de acordo com a capacidade da sala*; |  *Assento*      |
|   *Ser capaz de ver assentos*;
|   *Ser capaz de imprimir o mapa de assentos (livres/ocupados)*;


| Classe: IMAX                                                                    | Superclasse: Sala |
|---------------------------------------------------------------------------------|-------------------|
| Responsabilidades:                                                              | Colaborações:     |
|   *Ser capaz de adicionar uma taxa no valor do ingresso*;                                           |                 
|   *Saber sua taxa adicional*;                                                                       |    


| Classe: Premium                                                                 | Superclasse: Sala |
|---------------------------------------------------------------------------------|-------------------|
| Responsabilidades:                                                              | Colaborações:     |
|   *Ser capaz de adicionar uma taxa no valor do ingresso*;                                           |                 
|   *Saber sua taxa*;                                                                                 |   
  



Acho que aqui a gente pode inserir as tabelas, usando um gerador de tabelas: https://www.tablesgenerator.com/markdown_tables

