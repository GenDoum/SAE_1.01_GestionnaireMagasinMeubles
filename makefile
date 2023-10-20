GCCFLAGS = -Wall -Wextra -I src -Wno-unused-parameter -Wno-unused-but-set-variable
BUILD_DIR = build
SOURCES = $(shell find src -name '*.c')
TARGETS = $(patsubst %.c, %.o, $(SOURCES))
TARGETS := $(addprefix $(BUILD_DIR)/, $(TARGETS))
APP_NAME = app

all: $(APP_NAME)

$(APP_NAME): $(TARGETS)
	@gcc $(GCCFLAGS) -o $(APP_NAME) $(TARGETS)
	@echo -e $(GREEN)build done.$(RESET)

$(TARGETS): $(SOURCES)
	@mkdir -p $(@D)
	@gcc $(GCCFLAGS) -c $(patsubst %.o, %.c, $(@:$(BUILD_DIR)/%=%)) -o $@


clean:
	@rm -r $(BUILD_DIR) $(APP_NAME)
	@echo -e $(GREEN)clean done.$(RESET)
