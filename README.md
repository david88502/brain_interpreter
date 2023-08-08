# C++ BF Interpreter

## Description

This is a simple C++ interpreter for the BF programming language. BF is an esoteric programming language
known for its minimalistic design and is Turing-complete.

## Features

- Supports BF code execution by interpreting BF commands.
- Allows reading input from the user and printing output during program execution.
- Provides a straightforward interface for running BF programs.

## Getting Started

### Prerequisites

- C++ compiler (e.g., g++, Clang)
- CMake (optional, for building with CMake)

### Building

You can build the C++ BF interpreter using the following steps:

1. Clone the repository:
   git clone https://github.com/yourusername/BF-interpreter.git
   cd BF-interpreter


2. Build the interpreter:
   g++ -o BF_interpreter main.cpp

### Usage

To execute BF code using the interpreter, run the built executable with the path to the BF file as a
command-line argument:
./BF_interpreter path/to/BF_code.bf

Alternatively, you can input BF code directly through the standard input:
./BF_interpreter

Then, type or paste your BF code and press Ctrl+D (Linux/Mac) or Ctrl+Z (Windows) to signal the end of input.

### Examples

1. Running a BF program from a file:
   ./BF_interpreter examples/hello_world.bf


2. Running a BF program interactively:
   ./BF_interpreter
   ++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

- This interpreter is based on the BF language created by Urban Müller in 1993.
- Special thanks to the C++ community for their valuable resources and support.

