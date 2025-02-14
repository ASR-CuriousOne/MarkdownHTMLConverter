OS := $(shell uname -s)

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g
SRC_DIR = src
BUILD_DIR = build
BIN = app

# Find all C++ source files
SRC = $(wildcard $(SRC_DIR)/*/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC))

# Default target
all: $(BIN)

ifeq ($(OS), Windows_NT)  # Windows
    BIN = app.exe
else  # Linux/macOS
    BIN = app
endif


# Build Executable
$(BIN): $(OBJ) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build directory if not exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)/app $(BUILD_DIR)/core

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

# Run application
run: all
	./$(BIN)

.PHONY: all clean run

