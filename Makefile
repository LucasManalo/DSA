# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g -Iinc

# Directories
SRC_DIR = src
INCLUDE_DIR = inc
BUILD_DIR = build

# Executable name
TARGET = program

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Run the program with Valgrind
valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Phony targets
.PHONY: all run valgrind clean
