# Compiler and flags
CC = gcc
CFLAGS = -Wall -g -Iinclude -std=c99

# Project directories
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# Source files
SRC_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/game.c $(SRC_DIR)/screen.c $(SRC_DIR)/keyboard.c $(SRC_DIR)/timer.c
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Output binary name
TARGET = $(BIN_DIR)/enforcados

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(TARGET)

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the build
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Run the game
run: $(TARGET)
	$(TARGET)

# Phony targets
.PHONY: all clean run
