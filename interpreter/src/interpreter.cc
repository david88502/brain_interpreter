#include "interpreter.h"

Interpreter::Interpreter(std::ostream &output_stream, std::string &input_string)
	: mem_idx_(0), out_(output_stream), input_string_(input_string) {
  memory_.fill(0);
}

int Interpreter::IncrementDataPointer() {
  if (mem_idx_ == kArraySize - 1) {
	out_ << "Error: Incrementing data pointer above " << kArraySize - 1 << std::endl;
	return 1;
  }
  ++mem_idx_;
  return 0;
}

int Interpreter::DecrementDataPointer() {
  if (mem_idx_ == 0) {
	out_ << "Error: Decrementing data pointer below 0" << std::endl;
	return 1;
  }
  --mem_idx_;
  return 0;
}

int Interpreter::IncrementByte() {
  if (memory_[mem_idx_] == UCHAR_MAX) {
	out_ << "Error: Incrementing UCHAR_MAX" << std::endl;
	return 1;
  }
  ++memory_[mem_idx_];
  return 0;
}

int Interpreter::DecrementByte() {
  if (memory_[mem_idx_] == 0) {
	out_ << "Error: Decrementing 0" << std::endl;
	return 1;
  }
  --memory_[mem_idx_];
  return 0;
}

int Interpreter::OutputByte() {
  out_ << memory_[mem_idx_];
  return 0;
}

int Interpreter::ReadByte() {
  // Read a byte from stdin and save it as an unsigned char
  unsigned char c;
  std::cin >> c;
  if (std::cin.fail()) {
	std::cout << "Error: Invalid byte input" << std::endl;
	return 1;
  }
  memory_[mem_idx_] = c;
  return 0;
}

int Interpreter::FindBrackets() {

  std::stack<int> left_brackets;
  for (int i = 0; i < input_string_.length(); ++i) {
	if (input_string_[i] == '[') {
	  left_brackets.push(i);
	} else if (input_string_[i] == ']') {
	  if (left_brackets.empty()) {
		std::cout << "Error: Unmatched brackets" << std::endl;
		return 1;
	  }
	  bracket_map_[i] = left_brackets.top();
	  bracket_map_[left_brackets.top()] = i;
	  left_brackets.pop();
	}
  }
  if (!left_brackets.empty()) {
	std::cout << "Error: Unmatched brackets" << std::endl;
  }
  return 0;
}

int Interpreter::RunProgram() {
  int rc = FindBrackets();
  if (rc) { return rc; }
  int i = 0;
  while (i < input_string_.length()) {
	char c = input_string_[i];
	switch (c) {
	  case '>': rc = IncrementDataPointer();
		++i;
		break;
	  case '<': rc = DecrementDataPointer();
		++i;
		break;
	  case '+': rc = IncrementByte();
		++i;
		break;
	  case '-': rc = DecrementByte();
		++i;
		break;
	  case '.': rc = OutputByte();
		++i;
		break;
	  case ',': rc = ReadByte();
		++i;
	  case '[':
		if (memory_[mem_idx_] == 0) {
		  i = bracket_map_[i];
		} else {
		  ++i;
		}
		break;
	  case ']':
		if (memory_[mem_idx_] != 0) {
		  i = bracket_map_[i];
		} else {
		  ++i;
		}
		break;
	  default: ++i;
		break;

	}
	if (rc) {
	  std::cout << "Error at instruction index " << i << " with character " << c << std::endl;
	  return rc;
	}
  }
//  if (out_.tellp() != std::streampos(0)) {
//	out_ << std::endl; // Insert a newline and flush the buffer
//  }
  return 0;
}

