#ifndef MENU_HPP
#define MENU_HPP

#include "..\include\jogo.hpp"
#include <iostream>

using namespace std;
// classe menu que instancia o jogo e define os loops
class Menu {
private:
    Jogo* jogo;
public:
    Menu();
    ~Menu();

    void iniciarJogo();
    void objetivos();
};

#endif