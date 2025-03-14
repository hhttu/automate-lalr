CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

SRC = lexer.cpp symbole.cpp main.cpp automate.cpp regle.cpp TAE.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

run: all
	./$(EXEC)

leak:$(EXEC)
	valgrind --leak-check=full\
		--show-leak-kinds=all\
		--track-origins=yes\
		--verbose\
		--log-file=valgrind.txt\
	    ./$(EXEC)