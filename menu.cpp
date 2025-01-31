#include "..\include\menu.hpp"
#include <iostream>

using namespace std;

/**
 * @file menu.cpp
 * @brief Implementação da classe Menu, responsável por exibir e controlar o menu do jogo.
 */

/**
 * @brief Construtor da classe Menu.
 *
 * Exibe a tela inicial do jogo com as opções do menu principal.
 */
    Menu::Menu(){
    cout << "===================================" << endl;
    cout << "       Bem-vindo ao Jogo!          " << endl;
    cout << "===================================" << endl;
    cout << "1. Jogar" << endl;
    cout << "2. Objetivo" << endl;
    cout << "3. Sair do jogo"<<endl;
    }

/**
 * @brief Inicia o jogo.
 *
 * Cria uma nova instância da classe `Jogo` e inicia a partida chamando `iniciarJogo()`.
 */
    void Menu::iniciarJogo(){
        jogo = new Jogo(); ///< Aloca dinamicamente um novo objeto do jogo.
        jogo->iniciarJogo();
    }

/**
 * @brief Exibe as regras e objetivos do jogo.
 *
 * Explica as regras básicas do jogo para o jogador antes da partida.
 * Após a explicação, o jogo é iniciado automaticamente.
 */
    void Menu::objetivos() {
        cout << "   Objetivo do jogo:" << endl;
        cout << "   Afundar os navios inimigos antes que ele afunde os seus." << endl;
        cout << "   Cada jogador tem um Tabuleiro 10x10." << endl;
        cout << "   O tabuleiro de baixo é o seu território, onde você posiciona os navios." << endl;
        cout << "   O tabuleiro de cima é o território inimigo, onde suas jogadas acontecem." << endl;
        cout << endl;
        cout << "Pressione 'QUALQUER TECLA' para jogar. Divirta-se!" << endl;

        cin.ignore(); ///< Ignora qualquer caractere pendente no buffer de entrada.
        cin.get(); ///< Aguarda o jogador pressionar uma tecla para continuar.

        jogo->iniciarJogo();
    }

/**
 * @brief Destrutor da classe Menu.
 *
 * Libera a memória alocada para o objeto `Jogo`.
 */
    Menu::~Menu() {
        delete jogo; ///< Deleta a instância do jogo para evitar vazamento de memória.
    }
    
