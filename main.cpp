
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "interpreter.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
	std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
	return 1; // Exit with an error code
  }
  // Open the file
  std::ifstream input_stream(argv[1]);

  // Check if the file was successfully opened
  if (!input_stream) {
	std::cout << "Error opening the file: " << argv[1] << std::endl;
	return 1; // Exit with an error code
  }

  std::string input_string;
  std::ostringstream ss;
  ss << input_stream.rdbuf(); // reading data
  input_string = ss.str();

  auto *interpreter = new Interpreter(std::cout, input_string);
  int rc = interpreter->RunProgram();
  delete interpreter;
  input_stream.close();
  return rc; // Exit successfully
}
