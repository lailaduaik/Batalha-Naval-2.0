#include "..\include\menu.hpp"
#include <iostream>

using namespace std;

    Menu::Menu(){
    cout << "===================================" << endl;
    cout << "       Bem-vindo ao Jogo!          " << endl;
    cout << "===================================" << endl;
    cout << "1. Jogar" << endl;
    cout << "2. Objetivo" << endl;
    cout << "3. Sair do jogo"<<endl;
    }

    void Menu::iniciarJogo(){
        jogo = new Jogo();

        jogo->iniciarJogo();
    }

    void Menu::objetivos() {
        cout << "   Objetivo do jogo:" << endl;
        cout << "   Afundar os navios inimigos antes que ele afunde os seus." << endl;
        cout << "   Cada jogador tem um Tabuleiro 10x10." << endl;
        cout << "   O tabuleiro de baixo é o seu território, onde você posiciona os navios." << endl;
        cout << "   O tabuleiro de cima é o território inimigo, onde suas jogadas acontecem." << endl;
        cout << endl;
        cout << "Pressione 'QUALQUER TECLA' para jogar. Divirta-se!" << endl;

        cin.ignore();
        cin.get();

        jogo->iniciarJogo();
    }

    Menu::~Menu() {
        delete jogo;
    }
    