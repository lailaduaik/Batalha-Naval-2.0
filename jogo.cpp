#include "..\include\jogo.hpp"
#include <iostream>

using namespace std;

#include <iostream>
#include "jogo.hpp"

using namespace std;

Jogo::Jogo() {
    // O inimigo já posiciona seus navios automaticamente no construtor
}

//inicia o jogo posicionando todos os navios do jogador, os do inimigo são automaticamente posicionados
void Jogo::iniciarJogo() {
    cout << "Bem-vindo ao Batalha Naval!\n\n";
    cout << "Antes de começar, você deve posicionar seus navios no tabuleiro.\n";

    vector<char> tipos = {'C', 'T', 'T', 'D', 'D', 'S', 'S', 'S', 'S', 'S'};

    for (char tipo : tipos) {
        bool posicionado = false;
        while (!posicionado) {
            int linha;
            char coluna, direcao;

            cout << "Posicionando navio do tipo '" << tipo << "'.\n";
            cout << "Digite a linha (0-9): ";
            cin >> linha;
            cout << "Digite a coluna (A-J): ";
            cin >> coluna;
            cout << "Digite a direção (H para horizontal, V para vertical): ";
            cin >> direcao;

            // Chama a função Posicionar da classe Jogador
            posicionado = jogador.Posicionar(linha, coluna, tipo, direcao);

            if (!posicionado) {
                cout << "Tente novamente.\n";
            }
        }
    }

    cout << "\nTodos os navios foram posicionados!\n";
    cout << "O jogo começará agora.\n";

    loopJogo();
}

void Jogo::loopJogo() {
    bool jogoAtivo = true;

    while (jogoAtivo) {
        int linha;
        char coluna;

        cout << "\nSua vez de atacar!\n";
        cout << "Digite a linha (0-9): ";
        cin >> linha;
        cout << "Digite a coluna (A-J): ";
        cin >> coluna;

        bool acerto = jogador.disparar(inimigo, linha, coluna);
        if (acerto) {
            cout << "Você acertou um navio inimigo!\n";
        } else {
            cout << "Você errou.\n";
        }

        // O inimigo joga
        cout << "\nTurno do inimigo...\n";
        bool inimigoAcertou = inimigo.disparar(jogador);
        if (inimigoAcertou) {
            cout << "O inimigo acertou seu navio!\n";
        } else {
            cout << "O inimigo errou.\n";
        }

        // Exibir tabuleiros
        jogador.exibirtabuleiros();

        // Verificar se alguém ganhou
        if (jogador.ganhou()) {
            cout << "Parabéns! Você venceu a batalha naval!\n";
            jogoAtivo = false;
        } else if (inimigo.ganhou()) {
            cout << "O inimigo venceu. Melhor sorte na próxima vez!\n";
            jogoAtivo = false;
        }
    }
}