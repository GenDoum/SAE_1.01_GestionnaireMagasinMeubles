
# Compiler
CC = gcc

# Options de compilation pour le release
CFLAGS_RELEASE = -O3
# Options de compilation pour le debug
CFLAGS_DEBUG = -g -Wall

# Dossiers source
SRC_DIR = src
# Dossiers pour les fichiers objets
OBJ_DIR = obj

# Fichiers source
SOURCES = $(wildcard $(SRC_DIR)/*.c)

# Fichiers objets
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

# Nom de l'exécutable
EXECUTABLE = APP

# Répertoire de construction
BUILD_DIR = build

# Options pour l'exécutable
LDFLAGS =

# Commandes

all: build

build: $(BUILD_DIR)/$(EXECUTABLE)

$(BUILD_DIR)/$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS_RELEASE) -o $@ $<

debug:
	$(MAKE) CFLAGS_RELEASE="$(CFLAGS_DEBUG)" build

clean:
	rm -rf $(OBJ_DIR) $(BUILD_DIR)

run: build
	$<

doc_doxygen:
	@echo "Doxygen build started"
	@$(MAKE) -C docs

.PHONY: all build debug clean run doc_doxygen


