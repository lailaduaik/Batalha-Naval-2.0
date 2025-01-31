#include <iostream>
#include "..\include\menu.hpp"

/**
 * @file main.cpp
 * @brief Arquivo principal do jogo Batalha Naval.
 *
 * Contém a função `main()` responsável por iniciar o menu e gerenciar as escolhas do jogador.
 */

/**
 * @brief Função principal do jogo Batalha Naval.
 *
 * Exibe um menu simples que permite ao jogador iniciar o jogo, visualizar os objetivos
 * ou sair do programa. O loop continua até que o jogador escolha a opção de saída.
 *
 * @return `0` ao finalizar o programa com sucesso.
 */
int main() {
    Menu menu; ///< Objeto do menu que gerencia o jogo.

    int escolha; ///< Armazena a opção escolhida pelo jogador.

    do {
        std::cout << "Escolha uma opção:\n";
        std::cout << "1 - Iniciar Jogo\n";
        std::cout << "2 - Ver Objetivos\n";
        std::cout << "3 - Sair\n";
        std::cout << "Opção: ";
        
        std::cin >> escolha;

        /**
         * @brief Executa a ação correspondente à escolha do jogador.
         *
         * - `1`: Inicia o jogo chamando `menu.iniciarJogo()`.
         * - `2`: Exibe os objetivos do jogo chamando `menu.objetivos()`.
         * - `3`: Exibe uma mensagem de saída e encerra o programa.
         * - Padrão: Exibe uma mensagem de erro para escolhas inválidas.
         */
        switch (escolha) {
            case 1:
                menu.iniciarJogo();
                break;
            case 2:
                menu.objetivos();
                break;
            case 3:
                std::cout << "Saindo da batalha naval..." << std::endl;
                break;
            default:
                std::cout << "Opção inválida! Tente novamente." << std::endl;
                break;
        }
    } while (escolha != 3); ///< O loop continua até que o jogador escolha sair.

    std::cout << "FIM DE JOGO\n"; ///< Mensagem final do programa.

    return 0;
}
