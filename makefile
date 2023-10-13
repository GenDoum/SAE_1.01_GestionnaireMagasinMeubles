CC = gcc
SRC_DIR = src
OBJ_DIR = obj
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
EXECUTABLE = APP
BUILD_DIR = build
LDFLAGS =
CFLAGS_RELEASE = -O3
CFLAGS_DEBUG = -g -O0

# Generate dependency files
DEPS = $(OBJECTS:.o=.d)
-include $(DEPS)

# Commands
all: build

build: $(BUILD_DIR)/$(EXECUTABLE)

$(BUILD_DIR)/$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS_RELEASE) -MMD -MP -o $@ $<

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

