#include "doctest.h"
#include "../include/jogador.hpp"
#include <iostream>
#include <sstream>

// Classe auxiliar para capturar cout
class CaptureCout {
    std::streambuf* old;
    std::stringstream buffer;

public:
    CaptureCout() : old(std::cout.rdbuf(buffer.rdbuf())) {}
    ~CaptureCout() { std::cout.rdbuf(old); }
    std::string get() const { return buffer.str(); }
};

TEST_SUITE("Testes da classe Jogador") {
    TEST_CASE("Construtor inicializa navios corretamente") {
        Jogador jogador;
        CHECK(jogador.ganhou() == false); // Acertos iniciais devem ser 0
        
        // Verifica quantidade inicial de navios
        CHECK(jogador.Posicionar(0, 'A', 'C', 'H')); // Carrier (quantidade 1)
        CHECK_FALSE(jogador.Posicionar(0, 'B', 'C', 'H')); // Deve falhar (sem mais Carriers)
    }

    TEST_CASE("Posicionar navios válidos e inválidos") {
        Jogador jogador;

        SUBCASE("Posicionamento válido") {
            CHECK(jogador.Posicionar(0, 'A', 'C', 'H')); // Carrier horizontal
            CHECK(jogador.Posicionar(5, 'D', 'T', 'V')); // Tanker vertical
        }

        SUBCASE("Coordenadas inválidas") {
            CaptureCout capture;
            CHECK_FALSE(jogador.Posicionar(10, 'A', 'C', 'H')); // Linha inválida
            CHECK(capture.get().find("Coordenadas inválidas") != std::string::npos);
        }

        SUBCASE("Sobreposição de navios") {
            jogador.Posicionar(0, 'A', 'C', 'H');
            CaptureCout capture;
            CHECK_FALSE(jogador.Posicionar(0, 'A', 'T', 'H')); // Sobreposição
            CHECK(capture.get().find("posição já está ocupada") != std::string::npos);
        }
    }

    TEST_CASE("Disparar e acertos") {
        Jogador atacante;
        Jogador inimigo;

        SUBCASE("Disparo válido em água") {
            CHECK_FALSE(atacante.disparar(inimigo, 0, 'A')); // Água
            CHECK(atacante.getTabuleiroatk().getPosicao(0, 'A') == 'O');
        }

        SUBCASE("Disparo em navio") {
            inimigo.Posicionar(0, 'A', 'C', 'H'); // Posiciona Carrier
            CHECK(atacante.disparar(inimigo, 0, 'A')); // Acerto
            CHECK(atacante.getTabuleiroatk().getPosicao(0, 'A') == 'X');
        }

        SUBCASE("Coordenadas de disparo inválidas") {
            CaptureCout capture;
            CHECK_FALSE(atacante.disparar(inimigo, -1, 'Z')); // Inválido
            CHECK(capture.get().find("Linha inválida") != std::string::npos);
        }
    }

    TEST_CASE("Verificação de vitória") {
        Jogador jogador;
        CHECK_FALSE(jogador.ganhou()); // Inicialmente 0 acertos
        
        SUBCASE("Acertos insuficientes") {
            jogador.disparar(Jogador(), 0, 'A'); // Assume 1 acerto (mock)
            CHECK_FALSE(jogador.ganhou());
        }

        SUBCASE("Vitória com 11 acertos") {
            for (int i = 0; i < 11; i++) jogador.disparar(Jogador(), 0, 'A'); // Mock
            CHECK(jogador.ganhou());
        }
    }

    TEST_CASE("Exibição dos tabuleiros") {
        Jogador jogador;
        CaptureCout capture;

        jogador.exibirtabuleiros();
        std::string output = capture.get();

        CHECK(output.find("tabuleiro de ataque") != std::string::npos);
        CHECK(output.find("tabuleiro de embarcações") != std::string::npos);
    }
}