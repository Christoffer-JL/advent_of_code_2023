# Define the compiler
CXX = g++ 

# Define compile-time flags
CXXFLAGS = -Wall -Wextra -std=c++17 -g

# Define the target executable
TARGET_A = main_a 
TARGET_B = main_b

# Define source files
SOURCES_A = a/main.cpp
SOURCES_B = b/main.cpp

HEADERS = debug.h

# Define object files (replace .cpp with .o)
OBJECTS_A = $(SOURCES_A:.cpp=.o)
OBJECTS_B = $(SOURCES_B:.cpp=.o)

# Default target
all: $(TARGET_A) $(TARGET_B)

# Rule to link the first program
$(TARGET_A): $(OBJECTS_A)
	$(CXX) $(CXXFLAGS) -o $(TARGET_A) $(OBJECTS_A)

# Rule to link the second program
$(TARGET_B): $(OBJECTS_B)
	$(CXX) $(CXXFLAGS) -o $(TARGET_B) $(OBJECTS_B)

# Rule for building object files from a/main.cpp
a/%.o: a/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule for building object files from b/main.cpp
b/%.o: b/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(TARGET_A) $(OBJECTS_A) $(TARGET_B) $(OBJECTS_B)

# Phony targets
.PHONY: all clean
