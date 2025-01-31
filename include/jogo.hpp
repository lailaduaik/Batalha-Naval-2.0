#ifndef JOGO_HPP
#define JOGO_HPP

#include "..\include\jogador.hpp"
#include "..\include\inimigo.hpp"

/**
 * @file jogo.hpp
 * @brief Declaração da classe Jogo, responsável por controlar o fluxo do jogo.
 */

/**
 * @class Jogo
 * @brief Controla o resultado e os acontecimentos do jogo.
 *
 * A classe Jogo gerencia o jogador, o inimigo e o loop principal da partida.
 */
class Jogo {
private:
    Jogador jogador;  ///< O jogador humano
    Inimigo inimigo;  ///< O inimigo controlado pelo computador

    /**
     * @brief Loop principal do jogo.
     *
     * Controla as rodadas e a interação entre o jogador e o inimigo
     * até que o jogo tenha um vencedor.
     */
    void loopJogo();

public:
     /**
     * @brief Construtor da classe Jogo.
     *
     * Inicializa o jogo criando os jogadores e preparando o ambiente.
     */
    Jogo();

    /**
     * @brief Inicia o jogo, incluindo o posicionamento dos navios.
     *
     * Essa função dá início à partida, chamando os métodos necessários
     * para configurar os tabuleiros e iniciar o loop do jogo.
     */
    void iniciarJogo();
};

#endif // JOGO_HPP
