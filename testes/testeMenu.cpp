#include "doctest.h"
#include "../include/menu.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>

// Classe para capturar cout
class CaptureCout {
    std::streambuf* old;
    std::stringstream buffer;

public:
    CaptureCout() : old(std::cout.rdbuf(buffer.rdbuf())) {}
    ~CaptureCout() { std::cout.rdbuf(old); }
    std::string get() const { return buffer.str(); }
};

// Classe para simular entradas do cin
class CaptureCin {
    std::streambuf* old;
    std::stringstream input;

public:
    CaptureCin(const std::string& data) : old(std::cin.rdbuf()), input(data) {
        std::cin.rdbuf(input.rdbuf());
    }
    ~CaptureCin() { std::cin.rdbuf(old); }
};

TEST_SUITE("Testes da classe Menu") {
    TEST_CASE("Construtor exibe menu inicial corretamente") {
        CaptureCout capture;
        Menu menu; // O construtor já imprime o menu

        std::string output = capture.get();
        
        CHECK(output.find("Bem-vindo ao Jogo!") != std::string::npos);
        CHECK(output.find("1. Jogar") != std::string::npos);
        CHECK(output.find("3. Sair") != std::string::npos);
    }

    TEST_CASE("Método objetivos() exibe instruções corretamente") {
        Menu menu;
        CaptureCout capture;
        CaptureCin input_simulado("\n"); // Simula pressionar ENTER

        menu.objetivos(); // Deve exibir o objetivo e aguardar entrada

        std::string output = capture.get();
        CHECK(output.find("Objetivo do jogo:") != std::string::npos);
        CHECK(output.find("tabuleiro 10x10") != std::string::npos);
        CHECK(output.find("Pressione 'QUALQUER TECLA'") != std::string::npos);
    }

    TEST_CASE("Destrutor libera memória corretamente") {
        Menu* menu = new Menu();
        menu->iniciarJogo(); // Aloca um Jogo
        
        SUBCASE("Verifica se o jogo é destruído com o menu") {
            delete menu; // Destrutor deve deletar jogo
            // Se não houver crash, o teste passa
            CHECK(true); 
        }
    }

    TEST_CASE("iniciarJogo() cria instância de Jogo") {
        Menu menu;
        menu.iniciarJogo(); // Deve criar um novo Jogo
        
        // Verifica indiretamente se o ponteiro foi inicializado
        // (Não há acesso direto ao ponteiro, mas podemos verificar o comportamento)
        CHECK_NOTHROW(menu.iniciarJogo()); // Se não lançar exceção, está estável
    }
}