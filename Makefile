all: build/sophix

# Source files
SRCS= src/sophix.c src/window_manager.c src/pointer.c src/window_collection.c

# Output directory
BUILD_DIR := build
BIN := $(BUILD_DIR)/sophix

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra
LIBS := -lX11

# Create build directory if not exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile binary into ./build directory
$(BIN): $(SRCS) | $(BUILD_DIR)
	$(CC) $(SRCS) -o $(BIN) $(CFLAGS) $(LIBS)

# Default target
build: $(BIN)

# Clean build files
clean:
	rm -rf $(BUILD_DIR)
