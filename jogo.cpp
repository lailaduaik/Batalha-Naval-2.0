#include "..\include\jogo.hpp"
#include <iostream>

using namespace std;

#include <iostream>
#include "jogo.hpp"

using namespace std;

/**
 * @file jogo.cpp
 * @brief Implementação da classe Jogo, responsável por controlar o fluxo do jogo.
 */

/**
 * @brief Construtor da classe Jogo.
 *
 * Inicializa o jogo. O inimigo já posiciona seus navios automaticamente no construtor.
 */
Jogo::Jogo() {
}

/**
 * @brief Inicia o jogo, permitindo que o jogador posicione seus navios e iniciando o loop da partida.
 *
 * O jogador posiciona manualmente seus navios no tabuleiro, enquanto os navios do inimigo
 * já são posicionados automaticamente. Após o posicionamento, o jogo entra no loop de rodadas.
 */
void Jogo::iniciarJogo() {
    cout << "Bem-vindo ao Batalha Naval!\n\n";
    cout << "Antes de começar, você deve posicionar seus navios no tabuleiro.\n";

     /**
     * @brief Lista dos tipos de navios do jogador.
     *
     * O vetor contém os navios que o jogador deve posicionar no tabuleiro.
     */
    vector<char> tipos = {'C', 'T', 'T', 'D', 'D', 'S', 'S', 'S', 'S', 'S'};

    for (char tipo : tipos) {
        bool posicionado = false; ///< Indica se o navio foi posicionado corretamente.
        while (!posicionado) {
            int linha; ///< Linha escolhida pelo jogador.
            char coluna; ///< Coluna escolhida pelo jogador.
            char direcao; ///< Direção escolhida pelo jogador ('H' para horizontal, 'V' para vertical).

            cout << "Posicionando navio do tipo '" << tipo << "'.\n";
            cout << "Digite a linha (0-9): ";
            cin >> linha;
            cout << "Digite a coluna (A-J): ";
            cin >> coluna;
            cout << "Digite a direção (H para horizontal, V para vertical): ";
            cin >> direcao;

            /**
             * @brief Chama a função `Posicionar()` da classe `Jogador` para inserir o navio no tabuleiro.
             *
             * Se a posição for inválida, o jogador será solicitado a tentar novamente.
             */
            posicionado = jogador.Posicionar(linha, coluna, tipo, direcao);

            if (!posicionado) {
                cout << "Tente novamente.\n";
            }
        }
    }

    cout << "\nTodos os navios foram posicionados!\n";
    cout << "O jogo começará agora.\n";

    /**
     * @brief Inicia o loop do jogo, onde as rodadas de ataques serão executadas.
     */
    loopJogo();
}

/**
 * @brief Loop principal do jogo, onde os jogadores realizam turnos alternados de ataque.
 *
 * O jogador e o inimigo alternam turnos de ataque até que um deles alcance a vitória.
 */
void Jogo::loopJogo() {
    bool jogoAtivo = true; ///< Indica se o jogo ainda está em andamento.

    while (jogoAtivo) {
        int linha;     ///< Linha escolhida para o ataque do jogador.
        char coluna;   ///< Coluna escolhida para o ataque do jogador.

        cout << "\nSua vez de atacar!\n";
        cout << "Digite a linha (0-9): ";
        cin >> linha;
        cout << "Digite a coluna (A-J): ";
        cin >> coluna;

        /**
         * @brief O jogador realiza um disparo contra o inimigo.
         * 
         * Se o ataque for bem-sucedido, um 'X' será marcado no tabuleiro do inimigo.
         */
        bool acerto = jogador.disparar(inimigo, linha, coluna);
        if (acerto) {
            cout << "Você acertou um navio inimigo!\n";
        } else {
            cout << "Você errou.\n";
        }

        /**
         * @brief O inimigo realiza um disparo contra o jogador.
         * 
         * O inimigo escolhe aleatoriamente um local para atacar.
         */        
        cout << "\nTurno do inimigo...\n";
        bool inimigoAcertou = inimigo.disparar(jogador);
        if (inimigoAcertou) {
            cout << "O inimigo acertou seu navio!\n";
        } else {
            cout << "O inimigo errou.\n";
        }

        /**
         * @brief Exibe os tabuleiros do jogador após a rodada.
         */        
        jogador.exibirtabuleiros();

        /**
         * @brief Verifica se algum jogador atingiu a condição de vitória.
         */
        if (jogador.ganhou()) {
            cout << "Parabéns! Você venceu a batalha naval!\n";
            jogoAtivo = false;
        } else if (inimigo.ganhou()) {
            cout << "O inimigo venceu. Melhor sorte na próxima vez!\n";
            jogoAtivo = false;
        }
    }
}
