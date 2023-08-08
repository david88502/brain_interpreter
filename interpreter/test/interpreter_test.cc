#include "interpreter.h"
#include <ostream>
#include <sstream>
#include <string>

#include "gtest/gtest.h"

TEST(SucessfulRunTest, HelloWorld) {
  std::ostringstream output_stream;
  std::string hello_world_instruction =
	  "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";
  auto *interpreter = new Interpreter(output_stream, hello_world_instruction);
  int rc = interpreter->RunProgram();
  delete interpreter;
  EXPECT_EQ(rc, 0);
  EXPECT_EQ(output_stream.str(), "Hello World!\n");
}
