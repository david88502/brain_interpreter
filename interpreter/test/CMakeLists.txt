# Enables testing for current directory and below
enable_testing()

# Add a testing executable
add_executable(
	interpreter_test
	interpreter_test.cc
)

target_link_libraries(
	interpreter_test
	Interpreter
	GTest::gtest_main
)

# Add the test to Google Test
include(GoogleTest)
gtest_discover_tests(interpreter_test)
