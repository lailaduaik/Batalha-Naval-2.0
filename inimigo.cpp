#include "..\include\inimigo.hpp"

/**
 * @file inimigo.cpp
 * @brief Implementação da classe Inimigo, que representa o inimigo no jogo.
 */

/**
 * @brief Construtor da classe Inimigo.
 *
 * Inicializa o tabuleiro do inimigo aleatoriamente usando `srand` e chama `Iaposicionar()`
 * para posicionar os navios no tabuleiro de forma aleatória.
 */
Inimigo::Inimigo() {
    srand(time(nullptr)); ///< Garante que o tabuleiro seja aleatório a cada execução
    Iaposicionar();
}

/**
 * @brief Posiciona automaticamente os navios do inimigo no tabuleiro.
 *
 * Utiliza um vetor de tipos de navios e tenta posicioná-los aleatoriamente no tabuleiro
 * até que todos estejam corretamente alocados.
 */
void Inimigo:: Iaposicionar(){
    /**
     * @brief Lista dos tipos de navios do inimigo.
     * 
     * O vetor contém diferentes tipos de navios que serão posicionados no tabuleiro
     * de forma aleatória.
     */
    vector<char> tipos = {'C', 'T', 'T', 'D', 'D', 'S', 'S', 'S', 'S', 'S'};
    for(char tipo : tipos){
        bool posicionado = false;

        while (!posicionado){
            int linha = rand() % 10;                       ///< Gera uma linha aleatória (0-9)
            char coluna = 'A' + (rand() % 10);             ///< Gera uma coluna aleatória ('A'-'J')
            char direcao = (rand() % 2 == 0) ? 'H' : 'V';  ///< Define a direção aleatoriamente


            posicionado = Posicionar(tipo,linha,coluna,direcao);
        }
    }
}

/**
 * @brief Realiza um disparo contra o jogador, escolhendo aleatoriamente um alvo válido.
 * 
 * O inimigo tenta atacar uma posição aleatória no tabuleiro do jogador. 
 * Ele continua escolhendo até encontrar uma posição válida que ainda não tenha sido atacada.
 *
 * @param Jogador Referência para o jogador que receberá o ataque.
 * @return true se o ataque acertou um navio, false caso contrário.
 */
bool Inimigo::disparar(Jogador & Jogador){
     /**
     * @brief Variáveis para armazenar a posição do ataque.
     * 
     * - `linha`: Linha escolhida aleatoriamente para o ataque.
     * - `coluna`: Coluna escolhida aleatoriamente para o ataque.
     * - `valido`: Flag para verificar se a posição escolhida é válida.
     */
    int linha;
    char coluna;
    bool valido = false;

    /**
     * @brief Escolhe uma posição aleatória para atacar.
     * 
     * O loop continua até encontrar uma posição que ainda não tenha sido atacada.
     */
    while(!valido){
        linha = rand() % 10;
        coluna = 'A' + (rand() % 10);

        /**
         * @brief Verifica se a posição ainda não foi atacada.
         * 
         * O ataque só será realizado se a posição estiver vazia (' ').
         */
        if(getTabuleiroatk().getPosicao(linha, coluna) == ' '){
            valido = true;
        }
    }
    
    /**
     * @brief Exibe o ataque do inimigo na tela.
     */
    cout << "Inimigo ataca " << linha << coluna << endl;
      
    /**
     * @brief Realiza o ataque chamando o método da classe Jogador.
     * 
     * A função `disparar()` da classe `Jogador` processa o ataque e retorna `true` se um navio foi atingido.
     */
    return Jogador::disparar(Jogador, linha, coluna);
}
