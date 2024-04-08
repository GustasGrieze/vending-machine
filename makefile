# Compiler settings
CXX=g++
CXXFLAGS=-std=c++11 -Wall

# Output executable name
TARGET=vending_machine

# Source files
SOURCES=VendingMachine.cpp main.cpp

# Object files
OBJECTS=$(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Rule for linking the final executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Rule for compiling to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJECTS) $(TARGET)

# Rebuild everything
rebuild: clean all

# Phony targets
.PHONY: all clean rebuild
