if(EXISTS "/Users/david/Desktop/cpp_projects/brain_interpreter/cmake-build-release/interpreter/test/interpreter_test[1]_tests.cmake")
  include("/Users/david/Desktop/cpp_projects/brain_interpreter/cmake-build-release/interpreter/test/interpreter_test[1]_tests.cmake")
else()
  add_test(interpreter_test_NOT_BUILT interpreter_test_NOT_BUILT)
endif()
