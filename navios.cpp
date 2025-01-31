

#include "..\include\navios.hpp"


//construtor padrão da classe navios, que recebe a altura, largura, tipo e quantidade por tipo, como a direção é para cada navio foi preferível alterar depois.
Navios :: Navios(int _altura, int _largura, char _tipo, int _quantidade):altura(_altura), largura(_largura), tipo(_tipo), quantidade(_quantidade){} 

//pega a altura e retorna ela
int Navios :: get_altura() const{
    return altura;
}

// pega a largura e retorna ela
int Navios :: get_largura() const{
    return largura;
}

//pega o tipo e retorna ele
char Navios :: get_tipo() const{ 
    return tipo;
}

//pega a quantidade e retorna ele
int Navios :: getquantidade() const{
    return quantidade;
}

// seta a direção do navio
void Navios :: setdirecao(char _direcao){
    comando_direcao = _direcao;
}

// devolve a direção do navio H ou V
char Navios :: getdirecao() const{
    return comando_direcao;
}

//set a quantidade
void Navios ::setquantidade(int _quantidade){
    quantidade = _quantidade;
}

//inicializa 1 carrier
Carrier::Carrier():Navios(4,1,'C',1) {}

//inicializa os 2 tankers
Tanker::Tanker(): Navios(3,1,'T',2){}

//inicializa os 2 destroyers
Destroyer::Destroyer(): Navios(3,2,'D', 2){}

//inicializa os 5 submarinos
Submarine::Submarine():  Navios(1,1,'S', 5){}

