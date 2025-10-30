# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Target executable
TARGET = submission

# Source files .cpp and .h files
SRC = main.cpp proj4.cpp
HEADERS = proj4.h

# Object files
OBJ = $(SRC:.cpp=.o)

# Default rule
all: clean clear $(TARGET) run

INPUT2 ?= q2input.txt
INPUT5 ?= q5input.txt
INPUT10 ?= q10input.txt
INPUTlp ?= lpinput.txt
OUTPUT ?= output.txt

# Compile the main executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compile object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -f $(OBJ) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET) $(INPUT2) $(INPUT5) $(INPUT10) $(INPUTlp) $(OUTPUT)

clear:
	clear
