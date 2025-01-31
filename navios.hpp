#ifndef NAVIOS_HPP
#define NAVIOS_HPP

#include <string>

// classe navios e suas subclasses que armazenam cada tipo de navio o Tanker, destroyer, carrier e Submarine.

class Navios{
private:
int altura, largura, quantidade;
char comando_direcao;
char tipo;
public:
Navios(int altura, int largura, char tipo, int quantidade);
int get_altura() const;
int get_largura() const;
char get_tipo() const;
int getquantidade() const;
void setdirecao(char direcao);
char getdirecao() const;
void setquantidade(int _quantidade);
};

class Tanker : public Navios{
public:
Tanker();
};

class Destroyer : public Navios{
public:
Destroyer();
};

class Carrier : public Navios{
public:
Carrier();
};

class Submarine : public Navios{
public:
Submarine();
};

#endif