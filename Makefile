PROJECT := Jogo

SRC_DIR := src
BIN_DIR := bin

# Captura todos os arquivos .cpp nas subpastas de src
SRC := $(shell find $(SRC_DIR) -name '*.cpp')
# Gera os objetos a partir dos .cpp, mantendo a estrutura de pastas
OBJ := $(SRC:.cpp=.o)

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

# Compila cada arquivo .cpp em seu respectivo .o
%.o: %.cpp
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

build:
	@ echo '=============== Started building project using g++ compiler ===============' 

clean:
	@ $(RM) -r $(PROJECT) $(BIN_DIR)

rebuild: clean all
