#ifndef NAVIOS_HPP
#define NAVIOS_HPP

#include <string>

/**
 * @file navios.hpp
 * @brief Declaração das classes que representam os navios do jogo.
 */

/**
 * @class Navios
 * @brief Classe base para os navios do jogo.
 *
 * A classe Navios armazena as informações de tamanho, tipo e quantidade de cada tipo de navio.
 * Também fornece métodos para acessar e modificar essas informações.
 */
class Navios{
private:
    int altura;              ///< Altura do navio no tabuleiro.
    int largura;             ///< Largura do navio no tabuleiro.
    int quantidade;          ///< Quantidade de navios desse tipo disponíveis.
    char comando_direcao;    ///< Direção do navio ('H' para horizontal, 'V' para vertical).
    char tipo;               ///< Tipo do navio (ex: 'T' para Tanker, 'D' para Destroyer).

public:
    /**
     * @brief Construtor da classe Navios.
     * 
     * @param altura Altura do navio.
     * @param largura Largura do navio.
     * @param tipo Tipo do navio.
     * @param quantidade Quantidade de navios desse tipo disponíveis.
     */
Navios(int altura, int largura, char tipo, int quantidade);

    /**
     * @brief Obtém a altura do navio.
     * 
     * @return A altura do navio.
     */
int get_altura() const;

    /**
     * @brief Obtém a largura do navio.
     * 
     * @return A largura do navio.
     */
int get_largura() const;

    /**
     * @brief Obtém o tipo do navio.
     * 
     * @return O caractere representando o tipo do navio.
     */
char get_tipo() const;

    /**
     * @brief Obtém a quantidade de navios desse tipo disponíveis.
     * 
     * @return O número de navios disponíveis.
     */
int getquantidade() const;

    /**
     * @brief Define a direção do navio.
     * 
     * @param direcao Direção do navio ('H' para horizontal, 'V' para vertical).
     */
void setdirecao(char direcao);

    /**
     * @brief Obtém a direção do navio.
     * 
     * @return O caractere representando a direção do navio.
     */
char getdirecao() const;

    /**
     * @brief Define a quantidade de navios disponíveis.
     * 
     * @param _quantidade Novo valor para a quantidade de navios.
     */
void setquantidade(int _quantidade);
};


/**
 * @class Tanker
 * @brief Representa um navio do tipo Tanker.
 */
class Tanker : public Navios{
public:
    /**
     * @brief Construtor da classe Tanker.
     *
     * Inicializa um navio do tipo Tanker com atributos específicos.
     */
Tanker();
};

/**
 * @class Destroyer
 * @brief Representa um navio do tipo Destroyer.
 */
class Destroyer : public Navios{
public:

    /**
     * @brief Construtor da classe Destroyer.
     *
     * Inicializa um navio do tipo Destroyer com atributos específicos.
     */
Destroyer();
};

/**
 * @class Carrier
 * @brief Representa um navio do tipo Carrier.
 */
class Carrier : public Navios{
public:
    /**
     * @brief Construtor da classe Carrier.
     *
     * Inicializa um navio do tipo Carrier com atributos específicos.
     */
Carrier();
};

/**
 * @class Submarine
 * @brief Representa um navio do tipo Submarine.
 */
class Submarine : public Navios{
public:
    /**
     * @brief Construtor da classe Submarine.
     *
     * Inicializa um navio do tipo Submarine com atributos específicos.
     */
Submarine();
};

#endif
