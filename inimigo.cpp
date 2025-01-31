#include "..\include\inimigo.hpp"


Inimigo::Inimigo() { // construtor que inicia o tabuleiro aleatório do inimigo
    srand(time(nullptr));// inicia aleatoriamente com srand
    Iaposicionar();
}

void Inimigo:: Iaposicionar(){ // inicia o tabuleiro com posição aleatória gerando coordenadas aleatóriaa, e como subclasse de jogador utiliza os métodos do próprio
    vector<char> tipos = {'C', 'T', 'T', 'D', 'D', 'S', 'S', 'S', 'S', 'S'};
    for(char tipo : tipos){
        bool posicionado = false;

        while (!posicionado){
            int linha = rand() % 10;
            char coluna = 'A' + (rand() % 10);
            char direcao = (rand() % 2 == 0) ? 'H' : 'V';

            posicionado = Posicionar(tipo,linha,coluna,direcao);
        }
    }
}
// disparar por sobrecarga, levando como parametro somente o jogador que ele vai atacar
bool Inimigo::disparar(Jogador & Jogador){
    int linha;
    char coluna;
    bool valido = false;

    while(!valido){
        linha = rand() % 10;
        coluna = 'A' + (rand() % 10);

        if(getTabuleiroatk().getPosicao(linha, coluna) == ' '){
            valido = true;
        }
    }
    cout << "Inimigo ataca " << linha << coluna << endl;
    return Jogador::disparar(Jogador, linha, coluna);
}