#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include "..\include\jogador.hpp"
#include <cstdlib>
#include <ctime>

/**
 * @file inimigo.hpp
 * @brief Declaração da classe Inimigo, uma subclasse de Jogador.
 */

/**
 * @class Inimigo
 * @brief Representa um inimigo no jogo, herdando da classe Jogador.
 *
 * A classe Inimigo possui métodos para posicionar navios e disparar contra o jogador.
 */
class Inimigo : public Jogador {
    public:
         /**
         * @brief Construtor da classe Inimigo.
         *
         * Inicializa um inimigo no jogo.
         */
    Inimigo();
        /**
         * @brief Posiciona automaticamente os navios do inimigo no tabuleiro.
         *
         * Utiliza um algoritmo aleatório para distribuir os navios.
         */
        void Iaposicionar();
        /**
         * @brief Realiza um disparo contra o jogador.
         * 
         * Escolhe aleatoriamente uma posição para atacar no tabuleiro do jogador.
         * @param Jogador Referência para o jogador que será atacado.
         * @return true se o disparo acertou um navio, false caso contrário.
         */
        bool disparar(Jogador &Jogador);
};

#endif
