<<<<<<< HEAD:src/jogador.cpp
#include "..\include\jogador.hpp"
#include <iostream>

using namespace std;

/**
 * @file jogador.cpp
 * @brief Implementação da classe Jogador, responsável por gerenciar as ações do jogador no jogo.
 */

/**
 * @brief Construtor da classe Jogador.
 *
 * Inicializa o jogador com 0 acertos e adiciona os navios disponíveis ao vetor de navios.
 */
Jogador :: Jogador(): acertos(0){
    navios.push_back(Carrier());   ///< Adiciona um porta-aviões ao vetor de navios.
    navios.push_back(Tanker());    ///< Adiciona um navio-tanque ao vetor de navios.
    navios.push_back(Destroyer()); ///< Adiciona um contratorpedeiro ao vetor de navios.
    navios.push_back(Submarine()); ///< Adiciona um submarino ao vetor de navios.
}

/**
 * @brief Posiciona um navio no tabuleiro do jogador.
 * 
 * O jogador insere a linha, coluna, tipo de navio e a direção de posicionamento.
 * A função verifica a validade da entrada e posiciona o navio caso o espaço esteja livre.
 * 
 * @param linha Linha onde o navio será posicionado.
 * @param coluna Coluna onde o navio será posicionado.
 * @param tipo Tipo do navio a ser posicionado.
 * @param _direcao Direção do navio ('H' para horizontal, 'V' para vertical).
 * @return `true` se o navio foi posicionado com sucesso, `false` caso contrário.
 */
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

/**
 * @brief Realiza um disparo contra o inimigo.
 * 
 * O jogador escolhe uma linha e uma coluna para atacar. Se acertar um navio inimigo,
 * a posição será marcada com 'X', caso contrário, será marcada com 'O'.
 * 
 * @param inimigo Referência para o jogador inimigo que receberá o ataque.
 * @param linha Linha onde o disparo será realizado.
 * @param coluna Coluna onde o disparo será realizado.
 * @return `true` se o disparo acertou um navio, `false` caso contrário.
 */
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

/**
 * @brief Exibe os tabuleiros do jogador.
 *
 * Mostra o tabuleiro de ataque e o tabuleiro de embarcações após cada rodada.
 */
void Jogador :: exibirtabuleiros() const{
    cout << "\n Seu tabuleiro de ataque após essa rodada: " << endl;
    matriz_ataque.printar();
    cout<< "\n Seu tabuleiro de embarcações após essa rodada: " << endl;
    tabuleiro.printar();
}

/**
 * @brief Retorna a referência para o tabuleiro do jogador.
 * 
 * @return Referência para o tabuleiro onde os navios estão posicionados.
 */
Matriz& Jogador :: getTabuleiro(){
    return tabuleiro;
}

/**
 * @brief Retorna a referência para o tabuleiro de ataque do jogador.
 * 
 * @return Referência para a matriz que exibe os ataques realizados.
 */
Matriz& Jogador :: getTabuleiroatk(){
    return matriz_ataque;
}

/**
 * @brief Verifica se o jogador venceu o jogo.
 * 
 * O jogador vence ao atingir 11 acertos nos navios do inimigo.
 * 
 * @return `true` se o jogador venceu, `false` caso contrário.
 */
bool Jogador::ganhou() const{
    return acertos >= 11;
}
=======
#include "..\include\jogador.hpp"
#include <iostream>

/**
 * @file jogador.cpp
 * @brief Implementação da classe Jogador, responsável por gerenciar as ações do jogador no jogo.
 */

/**
 * @brief Construtor da classe Jogador.
 *
 * Inicializa o jogador com 0 acertos e adiciona os navios disponíveis ao vetor de navios.
 */
Jogador :: Jogador(): acertos(0){
    navios.push_back(Carrier());   ///< Adiciona um porta-aviões ao vetor de navios.
    navios.push_back(Tanker());    ///< Adiciona um navio-tanque ao vetor de navios.
    navios.push_back(Destroyer()); ///< Adiciona um contratorpedeiro ao vetor de navios.
    navios.push_back(Submarine()); ///< Adiciona um submarino ao vetor de navios.
}

/**
 * @brief Posiciona um navio no tabuleiro do jogador.
 * 
 * O jogador insere a linha, coluna, tipo de navio e a direção de posicionamento.
 * A função verifica a validade da entrada e posiciona o navio caso o espaço esteja livre.
 * 
 * @param linha Linha onde o navio será posicionado.
 * @param coluna Coluna onde o navio será posicionado.
 * @param tipo Tipo do navio a ser posicionado.
 * @param _direcao Direção do navio ('H' para horizontal, 'V' para vertical).
 * @return `true` se o navio foi posicionado com sucesso, `false` caso contrário.
 */
bool Jogador::Posicionar(int linha, char coluna, char tipo, char _direcao) {
    try {
        // Verifica se as coordenadas estão dentro dos limites tratamento de exceção
        if (coluna < 'A' || coluna > 'J' || linha < 0 || linha > 9) {
            throw std::out_of_range("Coordenadas inválidas! As coordenadas devem estar entre A-J e 0-9.");
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
                    throw std::out_of_range("O navio não cabe no tabuleiro!");
                }

                // Verifica se o espaço está livre
                for (int i = 0; i < altura; i++) {
                    for (int j = 0; j < largura; j++) {
                        if (tabuleiro.getPosicao(linha + i, 'A' + colunaIndex + j) != ' ') {
                            throw std::logic_error("A posição já está ocupada!");
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
        throw std::logic_error("Navio não encontrado ou quantidade esgotada!");

    } catch (const std::out_of_range& e) {
        std::cout << "Erro: " << e.what() << "\n";
        return false;
    } catch (const std::logic_error& e) {
        std::cout << "Erro: " << e.what() << "\n";
        return false;
    } catch (const std::exception& e) {
        std::cout << "Erro inesperado: " << e.what() << "\n";
        return false;
    }
}

/**
 * @brief Realiza um disparo contra o inimigo.
 * 
 * O jogador escolhe uma linha e uma coluna para atacar. Se acertar um navio inimigo,
 * a posição será marcada com 'X', caso contrário, será marcada com 'O'.
 * 
 * @param inimigo Referência para o jogador inimigo que receberá o ataque.
 * @param linha Linha onde o disparo será realizado.
 * @param coluna Coluna onde o disparo será realizado.
 * @return `true` se o disparo acertou um navio, `false` caso contrário.
 */
bool Jogador::disparar(Jogador& inimigo, int linha, char coluna) {
    try {
        // Verifica se a linha está dentro do intervalo permitido
        if (linha < 0 || linha > 9) {
            throw std::out_of_range("Linha inválida! Deve estar entre 0 e 9.");
        }

        // Verifica se a coluna está dentro do intervalo permitido
        if (coluna < 'A' || coluna > 'J') {
            throw std::out_of_range("Coluna inválida! Deve estar entre A e J.");
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
    } catch (const std::out_of_range& e) {
        std::cout << "Erro: " << e.what() << "\n";
        return false;
    } catch (const std::exception& e) {
        std::cout << "Erro inesperado: " << e.what() << "\n";
        return false;
    }
}

/**
 * @brief Exibe os tabuleiros do jogador.
 *
 * Mostra o tabuleiro de ataque e o tabuleiro de embarcações após cada rodada.
 */
void Jogador :: exibirtabuleiros() const{
    std::cout << "\n Seu tabuleiro de ataque após essa rodada: " << std::endl;
    matriz_ataque.printar();
    std::cout<< "\n Seu tabuleiro de embarcações após essa rodada: " << std::endl;
    tabuleiro.printar();
}

/**
 * @brief Retorna a referência para o tabuleiro do jogador.
 * 
 * @return Referência para o tabuleiro onde os navios estão posicionados.
 */
Matriz& Jogador :: getTabuleiro(){
    return tabuleiro;
}

/**
 * @brief Retorna a referência para o tabuleiro de ataque do jogador.
 * 
 * @return Referência para a matriz que exibe os ataques realizados.
 */
Matriz& Jogador :: getTabuleiroatk(){
    return matriz_ataque;
}

/**
 * @brief Verifica se o jogador venceu o jogo.
 * 
 * O jogador vence ao atingir 11 acertos nos navios do inimigo.
 * 
 * @return `true` se o jogador venceu, `false` caso contrário.
 */
bool Jogador::ganhou() const{
    return acertos >= 11;
}
>>>>>>> bf1b1bbd375db4663fa0dbd6df779c42c7cf67bc:jogador.cpp
