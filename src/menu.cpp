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
    std::cout << "===================================" << std::endl;
    std::cout << "       Bem-vindo ao Jogo!          " << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "1. Jogar" << std::endl;
    std::cout << "2. Objetivo" << std::endl;
    std::cout << "3. Sair do jogo"<< std::endl;
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
        std::cout << "   Objetivo do jogo:" << std::endl;
        std::cout << "   Afundar os navios inimigos antes que ele afunde os seus." << std::endl;
        std::cout << "   Cada jogador tem um Tabuleiro 10x10." << std::endl;
        std::cout << "   O tabuleiro de baixo é o seu território, onde você posiciona os navios." << std::endl;
        std::cout << "   O tabuleiro de cima é o território inimigo, onde suas jogadas acontecem." << std::endl;
        std::cout << std::endl;
        std::cout << "Pressione 'QUALQUER TECLA' para jogar. Divirta-se!" << std::endl;

        std::cin.ignore(); ///< Ignora qualquer caractere pendente no buffer de entrada.
        std::cin.get(); ///< Aguarda o jogador pressionar uma tecla para continuar.

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
    
