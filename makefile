# Compiler options
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Source files
SRCS = X_or_O_Game.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXECUTABLE = program

# Default target
all: $(EXECUTABLE)

# Link object files to create the executable
$(EXECUTABLE): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJS) $(EXECUTABLE)

# Phony targets
.PHONY: all clean

