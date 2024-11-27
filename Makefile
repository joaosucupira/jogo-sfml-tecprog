CC = g++

BIN_DIR = bin
SRC_DIR = src
OBJ_DIR = obj

BIN = $(BIN_DIR)/Jogo

INCLUDEs = -Iinclude
CPPs = $(shell find $(SRC_DIR) -name '*.cpp')
# Usamos apenas a parte final do caminho para os arquivos objetos
OBJs = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(CPPs))

CPPFLAGS = -g -Wall $(INCLUDEs)
LDFLAGS = -Llib
LDLIBS = -lm -lsfml-graphics -lsfml-window -lsfml-system

all: build $(BIN)

$(BIN): $(OBJs) | $(BIN_DIR)
	@echo '[Linking] $(BIN)'
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@
	@echo '============================ Finished building ============================'

# Compila os arquivos .cpp em .o diretamente no obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo '[Compiling] $< -> $@'
	mkdir -p $(dir @)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

build:
	@echo '=============== Started building project using g++ compiler ==============='

clean:
	@echo '[Cleaning] Removing $(OBJ_DIR) and $(BIN_DIR)'
	$(RM) -r $(OBJ_DIR) $(BIN_DIR)

rebuild: clean all

.PHONY: all clean build rebuild






