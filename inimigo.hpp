#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include "..\include\jogador.hpp"
#include <cstdlib>
#include <ctime>

//classe inimigo subclasse de jogador
class Inimigo : public Jogador {
    public:
    Inimigo();
    void Iaposicionar();
    bool disparar(Jogador &Jogador);
};


#endif