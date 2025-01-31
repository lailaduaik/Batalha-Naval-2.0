#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "..\include\matriz.hpp"
#include "..\include\navios.hpp"

#include <vector>
#include <stdexcept>

using namespace std;
/**
 * @file jogador.hpp
 * @brief Declaração da classe Jogador, responsável pelas ações do jogador no jogo.
 */

/**
 * @class Jogador
 * @brief Representa um jogador no jogo, controlando suas ações e tabuleiros.
 *
 * A classe Jogador gerencia o posicionamento de navios, ataques contra o inimigo e 
 * o estado do jogo para determinar se o jogador venceu.
 */
class Jogador{

private:
Matriz matriz_ataque;  ///< Matriz que representa os ataques realizados pelo jogador.
Matriz tabuleiro;      ///< Matriz que representa o tabuleiro do jogador com seus navios.
vector<Navios> navios; ///< Vetor contendo os navios do jogador.
int acertos;           ///< Contador de acertos do jogador durante a partida.

public:
    /**
     * @brief Construtor da classe Jogador.
     *
     * Inicializa o jogador, seus tabuleiros e seus navios.
     */
  Jogador();

    /**
     * @brief Posiciona um navio no tabuleiro do jogador.
     * 
     * @param linha Linha onde o navio será posicionado.
     * @param coluna Coluna onde o navio será posicionado.
     * @param tipo Tipo do navio a ser posicionado.
     * @param _direcao Direção do navio ('H' para horizontal, 'V' para vertical).
     * @return true se o navio foi posicionado com sucesso, false caso contrário.
     */
  bool Posicionar(int linha, char coluna, char tipo, char _direcao);

    /**
     * @brief Obtém a referência para o tabuleiro do jogador.
     * 
     * @return Referência para a matriz do tabuleiro do jogador.
     */
  Matriz& getTabuleiro();

    /**
     * @brief Obtém a referência para a matriz de ataque do jogador.
     * 
     * @return Referência para a matriz de ataque.
     */
  Matriz& getTabuleiroatk();

    /**
     * @brief Exibe os tabuleiros do jogador na tela.
     */
  void exibirtabuleiros() const;

    /**
     * @brief Realiza um disparo contra um inimigo.
     * 
     * @param inimigo Referência para o jogador inimigo que receberá o ataque.
     * @param linha Linha onde o disparo será realizado.
     * @param coluna Coluna onde o disparo será realizado.
     * @return true se o disparo acertou um navio, false caso contrário.
     */
  bool disparar(Jogador&inimigo, int linha, char coluna);

    /**
     * @brief Verifica se o jogador venceu a partida.
     * 
     * @return true se o jogador acertou todos os navios do inimigo, false caso contrário.
     */
  bool ganhou()const;

};
#endif 
