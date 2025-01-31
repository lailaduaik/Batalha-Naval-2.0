#ifndef MENU_HPP
#define MENU_HPP

#include "..\include\jogo.hpp"
#include <iostream>

using namespace std;

/**
 * @file menu.hpp
 * @brief Declaração da classe Menu, responsável por gerenciar a interface do jogo.
 */

/**
 * @class Menu
 * @brief Representa o menu do jogo, responsável por iniciar e exibir informações.
 *
 * A classe Menu instancia o jogo e controla a interação inicial do usuário, 
 * incluindo a exibição de objetivos e a inicialização da partida.
 */
class Menu {
private:
    Jogo* jogo; ///< Ponteiro para o objeto do jogo, que será instanciado no menu.
public:

    /**
     * @brief Construtor da classe Menu.
     *
     * Inicializa um objeto do tipo Menu e prepara o jogo.
     */
    Menu();

    /**
     * @brief Destrutor da classe Menu.
     *
     * Libera a memória alocada para o objeto do jogo.
     */
    ~Menu();

    /**
     * @brief Inicia o jogo chamando os métodos necessários para a execução.
     *
     * Esse método inicia a partida e faz as chamadas adequadas para configurar o jogo.
     */
    void iniciarJogo();

    /**
     * @brief Exibe os objetivos do jogo ao jogador.
     *
     * Mostra informações sobre as regras e metas do jogo.
     */
    void objetivos();
};

#endif
