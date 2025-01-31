# **Batalha-Naval-2.0** 🚢
Segundo repositório do trabalho final de PDS 2

Grupo 11
- Ana Julia Pinheiro Macedo  
- Laila Duaik  
- Thiago Erick de Jesus Tomaz  
- João Pedro de Moraes Nascente  

## 📘 Descrição do Projeto
Este é um jogo de Batalha Naval desenvolvido em C++, projetado para simular o clássico jogo de estratégia. O objetivo é afundar todos os navios do adversário antes que seus próprios navios sejam destruídos.

O projeto foi reestruturado para maior simplicidade e eficiência, removendo bibliotecas externas problemáticas e mantendo apenas as funcionalidades essenciais.

Esse novo repositório também conta com uma implementação melhorada, incluindo funcionalidades de jogabilidade aprimoradas e testes unitários para garantir estabilidade.

## Funcionalidades
- Menu interativo com opções de jogo.
- Sistema de posicionamento e ataques.
- Exibição do status da partida (navios restantes, turno atual).
- IA para o inimigo, que posiciona e realiza ataques automaticamente.
- Testes automatizados utilizando Doctest.

## Como Executar o Projeto?
Esse código foi escrito para funcionar no sistema Windows. Siga os passos abaixo para configurar e executar o projeto corretamente.

### Requisitos:
- Compilador **g++** (MinGW recomendado para Windows)
- Biblioteca **Doctest** para rodar os testes
- GitHub

### Passos:
1. Clone este repositório ou baixe os arquivos manualmente.
2. Confirme se o "`mingw32-gcc-g++`" esta selecionado no menu de seleção de pacotes.
3. Configure o PATH
   - Adicione o caminho do MinGW ao seu PATH (O caminho é algo como "C:\MinGW\bin")
     - Abra o Painel de Controle
       - Vá em Sistema e Segurança > Sistema > Configurações avançadas do sistema
       - Clique em "Variáveis de Ambiente"
       - Em "Variáveis do sistema", encontre a variável Path e edite-a
       - Adicione o caminho do MinGW (por exemplo, C:\MinGW\bin)

4. Compile o código
   - Navegue até o diretório do projeto clonado e compile o código usando "`mingw32-make`"

5. Execute o programa
   - Após a compilação bem-sucedida, você pode executar o programa usando "`.\bin\main.exe`" ou o comando "`mingw32-run`"
  
### Para rodar os testes:
1. Compile os arquivos de teste com:
   ```bash
   g++ -o teste testeJogo.cpp testeMenu.cpp testeJogador.cpp -std=c++11
   ```
2. Execute os testes:
   ```bash
   ./teste
   ```

## Como Jogar
1. O jogo inicia exibindo um menu com opções:
   - **Jogar**: Inicia uma nova partida.
   - **Objetivo**: Exibe instruções do jogo.
2. O jogador deve posicionar seus navios antes do início da batalha.
3. O objetivo é destruir todos os navios inimigos antes que os seus sejam destruídos.

## Estrutura do Projeto
- **`main.cpp`**: Arquivo principal que controla o fluxo do jogo.
- **`jogo.hpp` / `jogo.cpp`**: Contém as funções principais do jogo, como verificação de ataques e controle dos turnos.
- **`menu.hpp` / `menu.cpp`**: Gerencia a interface inicial e fluxo do menu.
- **`jogador.hpp` / `jogador.cpp`**: Define as ações do jogador e controla os disparos.
- **`inimigo.hpp` / `inimigo.cpp`**: Implementa a IA do inimigo, incluindo posicionamento automático e ataques.
- **`navios.hpp` / `navios.cpp`**: Define os tipos de navios e suas características.
- **`matriz.hpp` / `matriz.cpp`**: Gerencia a estrutura da matriz do tabuleiro.
- **Testes automatizados**:
  - **`testeJogo.cpp`**: Testa a inicialização e mecânica principal do jogo.
  - **`testeMenu.cpp`**: Testa a exibição e fluxo do menu.
  - **`testeJogador.cpp`**: Testa o posicionamento e ataques dos jogadores.
