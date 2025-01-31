#include "../include/matriz.hpp"
#include <iostream>

using namespace std;

/**
 * @file matriz.cpp
 * @brief Implementação da classe Matriz, responsável por gerenciar a estrutura do tabuleiro do jogo.
 */

/**
 * @brief Construtor da classe Matriz.
 *
 * Inicializa a matriz chamando `inicializarMatriz()` para criar a estrutura do tabuleiro.
 */
Matriz::Matriz(){
    inicializarMatriz();
}

/**
 * @brief Inicializa a matriz do jogo com a estrutura padrão.
 *
 * A matriz tem um tamanho fixo de 22x22, contendo coordenadas de referência e espaços para os navios e disparos.
 */
void Matriz::inicializarMatriz(){
     /**
     * @brief Estrutura inicial da matriz do tabuleiro.
     *
     * Essa matriz contém as coordenadas de referência ('A' - 'J' e '0' - '9'),
     * além das divisões para os espaços onde os navios serão posicionados.
     */
        char estrutura[22][22] = {
        {' ', ' ', 'A', ' ', 'B', ' ', 'C', ' ', 'D', ' ', 'E', ' ', 'F', ' ', 'G', ' ', 'H', ' ', 'I', ' ', 'J', ' '},
        {' ', ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' '},
        {'0', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {' ', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|'},
        {'1', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {' ', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|'},
        {'2', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {' ', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|'},
        {'3', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {' ', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|'},
        {'4', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {' ', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|'},
        {'5', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {' ', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|'},
        {'6', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {' ', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|'},
        {'7', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {' ', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|'},
        {'8', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {' ', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|'},
        {'9', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', ' '},
    };
    
    //loop que coloca cada char dessa matriz igual a matriz que vai inicializar
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            matriz[i][j] = estrutura[i][j];
        }
    }
}


/**
 * @brief Exibe a matriz na tela.
 *
 * Essa função imprime o tabuleiro, sendo utilizada em outras partes do jogo.
 */
void Matriz::printar() const{
    for(int i=0; i < tamanho; i++){
        for(int j=0; j < tamanho; j++){
        cout << matriz[i][j]<<" ";
        }
    cout << endl; ///< Quebra de linha após cada linha da matriz.
    }
}

/**
 * @brief Define um símbolo em uma posição específica da matriz.
 * 
 * @param linha Índice da linha na matriz.
 * @param coluna Índice da coluna na matriz representado por um caractere ('A' - 'J').
 * @param simbolo Caractere a ser inserido na posição especificada.
 */
void Matriz::setPosicao(int linha, char coluna, char simbolo){
    int coluna_real = 0;
    int linha_real = linha * 2 + 2; ///< Converte a linha para o índice correto na matriz.
    int coluna_real = (coluna - 'A') * 2 + 2; ///< Converte a coluna ('A' - 'J') para um índice numérico.

    if(linha_real >= 2 && linha_real <= 20 && coluna_real >= 2 && coluna_real <= 20){
        matriz[linha_real][coluna_real] = simbolo;
    }
}

/**
 * @brief Retorna o símbolo presente em uma posição específica da matriz.
 * 
 * @param linha Índice da linha na matriz.
 * @param coluna Índice da coluna na matriz representado por um caractere ('A' - 'J').
 * @return O caractere armazenado na posição especificada.
 */
char Matriz::getPosicao(int linha, char coluna) const {
    int colunaIndex = (coluna - 'A') * 2 + 2; ///< Converte a coluna ('A' - 'J') para um índice numérico.

    if (linha >= 0 && linha <= 9 && colunaIndex >= 2 && colunaIndex <= 20) {
        return matriz[2 + linha * 2][colunaIndex]; ///< Retorna o símbolo presente na posição especificada.
    }

    return ' '; ///< Retorna espaço em branco caso a posição seja inválida.
}
