# automate-lalr

## Overview

`automate-lalr` is a C++ project that implements a Look-Ahead LR (LALR) parser. The parser is designed to analyze and evaluate arithmetic expressions involving addition, multiplication, and parentheses.

## Project Structure

- `automate.cpp` / `automate.h`: Implements the main LALR parser logic.
- `lexer.cpp` / `lexer.h`: Implements the lexical analyzer (lexer) that tokenizes the input string.
- `symbole.cpp` / `symbole.h`: Defines the symbols used by the lexer and parser.
- `regle.cpp` / `regle.h`: Defines the grammar rules and their evaluation functions.
- `TAE.cpp` / `TAE.h`: Implements the Table of Analysis (TAE) which guides the parser's actions.
- `main.cpp`: Entry point of the program, initializes the parser and lexer, and runs the analysis.
- `Makefile`: Defines the build process using `make`.
- `valgrind.txt`: Output from Valgrind, a tool for memory debugging.

## How to use
### Building the Project

To build the project, you can use the provided `Makefile`. Run the following command in the terminal:

```sh
make
```

This will compile the source files and generate the `main` executable.

### Running the Project
After building the project, you can run the executable:

```sh
./main
```

### Memory Leak Check
To check for memory leaks using Valgrind, run:
```sh
make leak
```

This will execute the program with Valgrind and output the results to `valgrind.txt`.

## Contributors
This triome includes 3 students from group 4IF-2:
- VU Thi Tho
- HUYNH Huu Thanh Tu
- NGO Truong Son