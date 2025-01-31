# Definir o compilador e as flags
CXX = g++
CXXFLAGS = -std=c++17 -I./include -Wall -Wextra

# Diretórios
SRC_DIR = src
OBJ_DIR = ./bin
BIN_DIR = ./bin
INCLUDE_DIR = include

# Arquivos de origem
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Nome do executável
EXEC = $(BIN_DIR)/main.exe

# Alvo padrão (compilar tudo)
all: $(EXEC)

# Compilar o executável
$(EXEC): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o $(EXEC)

# Compilar arquivos .cpp em arquivos .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run:
	$(EXEC)

# Limpar arquivos gerados
clean:
	del .\bin\*.o
	del .\bin\*.exe

test:
	g++ -std=c++11 ./program/*.cpp -Iinclude -Idoctest -o ./bin/test
	./bin/test.exe
# pegar doctest no link:  https://github.com/pds2/20231-team-11/blob/main/logic/thirdy_party/doctest.hpp
# fazer pasta chamada doctest e colocar arquivo
# fazer pasta chamada program e fazer aquivo test.cpp
# rodar -> mingw32-make test