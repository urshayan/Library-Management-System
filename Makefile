# ------------------------------
# Simple Makefile for Library Management System
# ------------------------------

# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Source files
SOURCES = src/main.cpp include/Book.cpp include/BST.cpp include/LibraryManager.cpp \
          include/LinkedList.cpp include/Queue.cpp include/Stack.cpp \
          include/Student.cpp include/Transaction.cpp
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Executable
TARGET = library_system

# ------------------------------
# Default target
# ------------------------------
all: $(BUILD_DIR) $(TARGET)

# ------------------------------
# Link object files to create executable
# ------------------------------
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# ------------------------------
# Compile .cpp files into .o files
# ------------------------------
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ------------------------------
# Create build directory if it doesn't exist
# ------------------------------
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# ------------------------------
# Clean build files
# ------------------------------
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# ------------------------------
# Run the executable
# ------------------------------
run: all
	./$(TARGET)

.PHONY: all clean run

