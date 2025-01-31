#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "..\include\matriz.hpp"
#include "..\include\navios.hpp"

#include <vector>
#include <stdexcept>

using namespace std;
//classe jogador responsável por tudo que o jogador faz

class Jogador{

private:
Matriz matriz_ataque;
Matriz tabuleiro;
vector <Navios> navios;
int acertos;

public:
Jogador();
bool Posicionar(int linha, char coluna, char tipo, char _direcao);
Matriz& getTabuleiro();
Matriz& getTabuleiroatk();
void exibirtabuleiros() const;
bool disparar(Jogador&inimigo, int linha, char coluna);
bool ganhou()const;

};
#endif 