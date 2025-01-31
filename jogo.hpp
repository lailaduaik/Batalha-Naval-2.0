#ifndef JOGO_HPP
#define JOGO_HPP

#include "..\include\jogador.hpp"
#include "..\include\inimigo.hpp"
// classe jogo controla o resultado e os acontecimentos
class Jogo {
private:
    Jogador jogador;  // O jogador humano
    Inimigo inimigo;  // O inimigo controlado pelo computador

    // Loop principal do jogo
    void loopJogo();

public:
    // Construtor
    Jogo();

    // Inicia o jogo, incluindo o posicionamento dos navios
    void iniciarJogo();
};

#endif // JOGO_HPP