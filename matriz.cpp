#include "../include/matriz.hpp"

using namespace std;

//Construtor da Matriz, puxa a função inicializar matriz
Matriz::Matriz(){
    inicializarMatriz();
}
//função inicializar matriz, faz a matriz ter a estrutura definida 22 por 22;
void Matriz::inicializarMatriz(){
        char estrutura[22][22] = {
        {' ', ' ', 'A', ' ', 'B', ' ', 'C', ' ', 'D', ' ', 'E', ' ', 'F', ' ', 'G', ' ', 'H', ' ', 'I', ' ', 'J', ' '},
        {' ', ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' '},
        {'0', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {' ', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|'},
        {'1', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {' ', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|'},
        {'2', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {' ', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|'},
        {'3', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {' ', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|'},
        {'4', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {' ', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|'},
        {'5', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {' ', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|'},
        {'6', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {' ', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|'},
        {'7', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {' ', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|'},
        {'8', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {' ', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|', '-', '|'},
        {'9', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', ' '},
    };
    
    //loop que coloca cada char dessa matriz igual a matriz que vai inicializar
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            matriz[i][j] = estrutura[i][j];
        }
    }
}

//exibe a matriz na tela, vai ser utilizada em outras funções
void Matriz::printar() const{
    for(int i=0; i < tamanho; i++){
        for(int j=0; j < tamanho; j++){
        cout << matriz[i][j]<<" ";
    }
}
}

// como o jogador terá de 0 a 9 e A a J, e a matriz não segue esses valores, essa função set converte as coordenadas dadas para alterar na matriz
void Matriz::setPosicao(int linha, char coluna, char simbolo){
    int coluna_real = 0;
    int linha_real = linha*2 + 2;

    coluna_real = (coluna - 'A') * 2 + 2;

    if(linha_real >= 2 && linha_real <= 20 && coluna_real >= 2 && coluna_real <= 20){
        matriz[linha_real][coluna_real] = simbolo;
    }
}

// com o mesmo funcionamento que a set, só para get para compararmos em funções como disparo e no posicionamento
char Matriz::getPosicao(int linha, char coluna) const {
    int colunaIndex = (coluna - 'A') * 2 + 2;

    if (linha >= 0 && linha <= 9 && colunaIndex >= 2 && colunaIndex <= 20) {
        return matriz[2 + linha * 2][colunaIndex];
    }

    return ' ';}