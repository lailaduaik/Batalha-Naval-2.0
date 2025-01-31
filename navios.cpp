#include "..\include\navios.hpp"
#include <iostream>

using namespace std;

/**
 * @file navios.cpp
 * @brief Implementação das classes que representam os navios do jogo.
 */

/**
 * @brief Construtor da classe Navios.
 *
 * Inicializa um navio com altura, largura, tipo e quantidade.
 * A direção (`comando_direcao`) deve ser definida posteriormente.
 *
 * @param _altura Altura do navio.
 * @param _largura Largura do navio.
 * @param _tipo Tipo do navio ('C' para Carrier, 'T' para Tanker, etc.).
 * @param _quantidade Quantidade de navios desse tipo disponíveis.
 */
Navios::Navios(int _altura, int _largura, char _tipo, int _quantidade)
    : altura(_altura), largura(_largura), tipo(_tipo), quantidade(_quantidade) {}

/**
 * @brief Obtém a altura do navio.
 * 
 * @return A altura do navio.
 */
int Navios::get_altura() const {
    return altura;
}

/**
 * @brief Obtém a largura do navio.
 * 
 * @return A largura do navio.
 */
int Navios::get_largura() const {
    return largura;
}

/**
 * @brief Obtém o tipo do navio.
 * 
 * @return O caractere representando o tipo do navio.
 */
char Navios::get_tipo() const {
    return tipo;
}

/**
 * @brief Obtém a quantidade de navios disponíveis desse tipo.
 * 
 * @return O número de navios disponíveis.
 */
int Navios::getquantidade() const {
    return quantidade;
}

/**
 * @brief Define a direção do navio ('H' para horizontal, 'V' para vertical).
 * 
 * @param _direcao Direção do navio.
 */
void Navios::setdirecao(char _direcao) {
    comando_direcao = _direcao;
}

/**
 * @brief Obtém a direção do navio ('H' para horizontal, 'V' para vertical).
 * 
 * @return O caractere representando a direção do navio.
 */
char Navios::getdirecao() const {
    return comando_direcao;
}

/**
 * @brief Define a quantidade de navios disponíveis desse tipo.
 * 
 * @param _quantidade Novo valor para a quantidade de navios disponíveis.
 */
void Navios::setquantidade(int _quantidade) {
    quantidade = _quantidade;
}

/**
 * @brief Construtor da classe Carrier.
 *
 * Inicializa um porta-aviões com altura 4, largura 1 e quantidade 1.
 */
Carrier::Carrier() : Navios(4, 1, 'C', 1) {}

/**
 * @brief Construtor da classe Tanker.
 *
 * Inicializa dois navios do tipo Tanker, cada um com altura 3 e largura 1.
 */
Tanker::Tanker() : Navios(3, 1, 'T', 2) {}

/**
 * @brief Construtor da classe Destroyer.
 *
 * Inicializa dois navios do tipo Destroyer, cada um com altura 3 e largura 2.
 */
Destroyer::Destroyer() : Navios(3, 2, 'D', 2) {}

/**
 * @brief Construtor da classe Submarine.
 *
 * Inicializa cinco submarinos, cada um com altura 1 e largura 1.
 */
Submarine::Submarine() : Navios(1, 1, 'S', 5) {}
