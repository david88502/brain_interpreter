#pragma once

#include <array>
#include <iostream>
#include <limits>
#include <stack>
#include <unordered_map>

// The interpreter's memory size is 30,000 bytes
const int kArraySize = 30000;
/*
 *
 *
 */
class Interpreter {
 private:
  int mem_idx_;
  std::ostream &out_;
  std::string &input_string_;
  std::array<unsigned char, kArraySize> memory_;
  std::unordered_map<int, int> bracket_map_;

  int IncrementDataPointer();
  int DecrementDataPointer();
  int IncrementByte();
  int DecrementByte();
  int OutputByte();
  int ReadByte();
  int FindBrackets();
 public:
  explicit Interpreter(std::ostream &output_stream, std::string &input_string);

  int RunProgram();

};