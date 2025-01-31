#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <iostream>


// classe matriz que vai inicializar e ter funções para ajudar a se situar na matriz
class Matriz{
private:
static const int tamanho = 22;
char matriz[tamanho][tamanho];


void inicializarMatriz();

public:
Matriz();

void printar() const;
void setPosicao(int linha, char coluna, char simbolo);
char getPosicao(int linha, char coluna) const;


};

#endif // MATRIZ_HPP