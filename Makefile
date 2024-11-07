PROJECT := Jogo

SRC_DIR := src
BIN_DIR := bin
OBJ_DIR := obj

# Captura todos os arquivos .cpp nas subpastas de src
SRC := $(shell find $(SRC_DIR) -name '*.cpp')
# Gera os objetos a partir dos .cpp, mantendo a estrutura de pastas
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

#OI CHEGUEI

CC := g++
CPPFLAGS := -Iinclude -O2
CFLAGS   := -Wall
LDFLAGS  := -Llib 
LDLIBS   := -lm -lsfml-graphics -lsfml-window -lsfml-system

.PHONY: all clean build

all: build $(PROJECT)

$(PROJECT): $(OBJ)
	@ $(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@
	@ echo '============================ Finished building ============================'

# Compila cada arquivo .cpp em seu respectivo .o, criando o diretório se necessário
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@ mkdir -p $(dir $@)  # Cria o diretório do objeto, se não existir
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

build:
	@ echo '=============== Started building project using g++ compiler ==============='

clean:
	@ $(RM) -r $(PROJECT) $(BIN_DIR) $(OBJ_DIR)

rebuild: clean all
