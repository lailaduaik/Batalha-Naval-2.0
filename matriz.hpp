#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <iostream>

/**
 * @file matriz.hpp
 * @brief Declaração da classe Matriz, responsável por gerenciar a estrutura da matriz do jogo.
 */

/**
 * @class Matriz
 * @brief Representa a matriz do tabuleiro do jogo.
 *
 * A classe Matriz inicializa e gerencia a estrutura do tabuleiro, 
 * fornecendo métodos para manipulação de posições e exibição da matriz.
 */
class Matriz{
private:
static const int tamanho = 22; ///< Tamanho fixo da matriz.
char matriz[tamanho][tamanho]; ///< Matriz que armazena os elementos do tabuleiro.

    /**
     * @brief Inicializa a matriz preenchendo-a com os caracteres padrão.
     *
     * Este método é chamado no construtor para configurar a matriz antes do uso.
     */
void inicializarMatriz();

public:

    /**
     * @brief Construtor da classe Matriz.
     *
     * Inicializa a matriz chamando o método `inicializarMatriz()`.
     */
Matriz();

    /**
     * @brief Exibe a matriz na saída padrão.
     *
     * Método utilizado para visualizar o estado atual do tabuleiro.
     */
void printar() const;

    /**
     * @brief Define um símbolo em uma posição específica da matriz.
     * 
     * @param linha Índice da linha na matriz.
     * @param coluna Índice da coluna na matriz representado por um caractere ('A' - 'J').
     * @param simbolo Caractere a ser inserido na posição especificada.
     */
void setPosicao(int linha, char coluna, char simbolo);

    /**
     * @brief Retorna o símbolo presente em uma posição específica da matriz.
     * 
     * @param linha Índice da linha na matriz.
     * @param coluna Índice da coluna na matriz representado por um caractere ('A' - 'J').
     * @return O caractere armazenado na posição especificada.
     */
char getPosicao(int linha, char coluna) const;

};

#endif // MATRIZ_HPP
