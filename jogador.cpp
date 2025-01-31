#include "..\include\jogador.hpp"
#include <iostream>

using namespace std;
//inicializa a classe jogador com 0 acertos e inicializa o vetor dos navios pelo push_back
Jogador :: Jogador(): acertos(0){
    navios.push_back(Carrier());   
    navios.push_back(Tanker());    
    navios.push_back(Destroyer()); 
    navios.push_back(Submarine()); 

}



// função posicionar responsável por posicionar um navio de acordo com a entrada do jogador, essa função vai ser usada na classe jogo.
bool Jogador::Posicionar(int linha, char coluna, char tipo, char _direcao) {
    try {
        // Verifica se as coordenadas estão dentro dos limites tratamento de exceção
        if (coluna < 'A' || coluna > 'J' || linha < 0 || linha > 9) {
            throw out_of_range("Coordenadas inválidas! As coordenadas devem estar entre A-J e 0-9.");
        }

        for (auto& navio : navios) {
            //if que define a direcao de posicionamento do barco
            if (navio.get_tipo() == tipo && navio.getquantidade() > 0) {
                int largura = (_direcao == 'H') ? navio.get_altura() : navio.get_largura();
                int altura = (_direcao == 'V') ? navio.get_altura() : navio.get_largura();
                //coluna index que vai ser o valor númerico da coluna para verificação 
                int colunaIndex = coluna - 'A'; // Converte 'A'-'J' para índice 0-9

                // Verifica se o navio cabe no tabuleiro
                if (linha + altura - 1 >= 10 || colunaIndex + largura - 1 >= 10) {
                    throw out_of_range("O navio não cabe no tabuleiro!");
                }

                // Verifica se o espaço está livre
                for (int i = 0; i < altura; i++) {
                    for (int j = 0; j < largura; j++) {
                        if (tabuleiro.getPosicao(linha + i, 'A' + colunaIndex + j) != ' ') {
                            throw logic_error("A posição já está ocupada!");
                        }
                    }
                }

                // Posiciona o navio na matriz
                for (int i = 0; i < altura; i++) {
                    for (int j = 0; j < largura; j++) {
                        tabuleiro.setPosicao(linha + i, 'A' + colunaIndex + j, tipo);
                    }
                }

                // Atualiza a quantidade disponível desse tipo de navio
                navio.setquantidade(navio.getquantidade() - 1);
                return true;
            }
        }
        
        // Se o tipo de navio não for encontrado ou não houver unidades disponíveis
        throw logic_error("Navio não encontrado ou quantidade esgotada!");

    } catch (const out_of_range& e) {
        cout << "Erro: " << e.what() << "\n";
        return false;
    } catch (const logic_error& e) {
        cout << "Erro: " << e.what() << "\n";
        return false;
    } catch (const exception& e) {
        cout << "Erro inesperado: " << e.what() << "\n";
        return false;
    }
}


bool Jogador::disparar(Jogador& inimigo, int linha, char coluna) {
    try {
        // Verifica se a linha está dentro do intervalo permitido
        if (linha < 0 || linha > 9) {
            throw out_of_range("Linha inválida! Deve estar entre 0 e 9.");
        }

        // Verifica se a coluna está dentro do intervalo permitido
        if (coluna < 'A' || coluna > 'J') {
            throw out_of_range("Coluna inválida! Deve estar entre A e J.");
        }

        // Acessa a posição do inimigo no tabuleiro
        char alvo = inimigo.getTabuleiro().getPosicao(linha, coluna);

        // Se acertar, marca 'X' no tabuleiro de ataque e no tabuleiro do inimigo
        if (alvo != ' ') {
            matriz_ataque.setPosicao(linha, coluna, 'X');
            inimigo.getTabuleiro().setPosicao(linha, coluna, 'X');
            acertos++;
            return true;
        } else {
            matriz_ataque.setPosicao(linha, coluna, 'O');
            return false;
        }
    } catch (const out_of_range& e) {
        cout << "Erro: " << e.what() << "\n";
        return false;
    } catch (const exception& e) {
        cout << "Erro inesperado: " << e.what() << "\n";
        return false;
    }
}

// exibi os tabuleiros a cada turno
void Jogador :: exibirtabuleiros() const{
    cout << "\n Seu tabuleiro de ataque após essa rodada: " << endl;
    matriz_ataque.printar();
    cout<< "\n Seu tabuleiro de embarcações após essa rodada: " << endl;
    tabuleiro.printar();
}

// função para alterarmos o tabuleiro
Matriz& Jogador :: getTabuleiro(){
    return tabuleiro;
}
// função para alterarmos o tabuleiro
Matriz& Jogador :: getTabuleiroatk(){
    return matriz_ataque;
}
bool Jogador::ganhou() const{
    return acertos >= 11;
}