#include "doctest.h"
#include <iostream>
#include <sstream>
#include <string>
#include "jogo.hpp"

// Classe para capturar cout
class CaptureCout {
    std::streambuf* old;
    std::stringstream buffer;

public:
    CaptureCout() : old(std::cout.rdbuf(buffer.rdbuf())) {}
    ~CaptureCout() { std::cout.rdbuf(old); }
    std::string get() const { return buffer.str(); }
};

// Classe para simular cin
class CaptureCin {
    std::streambuf* old;
    std::stringstream input;

public:
    CaptureCin(const std::string& data) : old(std::cin.rdbuf()), input(data) {
        std::cin.rdbuf(input.rdbuf());
    }
    ~CaptureCin() { std::cin.rdbuf(old); }
};

TEST_CASE("Testar mensagens iniciais e posicionamento de navios") {
    // Simula entrada do usuário para posicionar todos os navios válidos
    std::string input;
    // Para cada navio (C, T, T, D, D, S, S, S, S, S), insira dados válidos
    // Exemplo: linha=0, coluna=A, direção=H para todos
    for (int i = 0; i < 10; i++) {
        input += "0\nA\nH\n"; // linha, coluna, direção
    }

    CaptureCin cap_cin(input);
    CaptureCout cap_cout;

    Jogo jogo;
    jogo.iniciarJogo();

    // Verifica se as mensagens críticas estão presentes
    std::string output = cap_cout.get();
    CHECK(output.find("Bem-vindo ao Batalha Naval!") != std::string::npos);
    CHECK(output.find("Todos os navios foram posicionados!") != std::string::npos);
}

TEST_CASE("Testar posicionamento inválido") {
    // Primeiro um posicionamento inválido (linha 10), depois válido
    std::string input = "10\nA\nH\n"   // Inválido (linha 10)
                        "0\nA\nH\n";   // Válido
    // Completa com entradas para os 9 navios restantes
    for (int i = 0; i < 9; i++) {
        input += "0\nA\nH\n";
    }

    CaptureCin cap_cin(input);
    CaptureCout cap_cout;

    Jogo jogo;
    jogo.iniciarJogo();

    // Verifica mensagem de erro
    std::string output = cap_cout.get();
    CHECK(output.find("Tente novamente.") != std::string::npos);
}

TEST_CASE("Testar loop do jogo e mensagens de ataque") {
    // Posiciona todos navios válidos primeiro
    std::string input;
    for (int i = 0; i < 10; i++) {
        input += "0\nA\nH\n";
    }
    // Simula dois ataques do jogador (0, A) e (1, B)
    input += "0\nA\n1\nB\n";

    CaptureCin cap_cin(input);
    CaptureCout cap_cout;

    Jogo jogo;
    jogo.iniciarJogo(); // Executa até o loop do jogo

    // Verifica mensagens de ataque
    std::string output = cap_cout.get();
    CHECK(output.find("Sua vez de atacar!") != std::string::npos);
    CHECK(output.find("Turno do inimigo...") != std::string::npos);
    CHECK((output.find("Você acertou") != std::string::npos || 
           output.find("Você errou") != std::string::npos));
}