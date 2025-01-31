#include <iostream>
#include "..\include\menu.hpp"

using namespace std;
// main simples
int main() {
    Menu menu;

    int escolha;
    do {
        cin >> escolha;
        switch (escolha) {
            case 1:
                menu.iniciarJogo();
                break;
            case 2:
                menu.objetivos();
                break;
            case 3:
                cout <<"Saindo da batalha naval"<<endl;
                break;
            default:
                cout << "Opção inválida! Tente novamente." << endl;
                break;
        }
    } while (escolha != 3);

    cout << "FIM DE JOGO";
    return 0;
}