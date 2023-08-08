add_test([=[SucessfulRunTest.HelloWorld]=]  /Users/david/Desktop/cpp_projects/brain_interpreter/cmake-build-debug/interpreter/test/interpreter_test [==[--gtest_filter=SucessfulRunTest.HelloWorld]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[SucessfulRunTest.HelloWorld]=]  PROPERTIES WORKING_DIRECTORY /Users/david/Desktop/cpp_projects/brain_interpreter/cmake-build-debug/interpreter/test SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  interpreter_test_TESTS SucessfulRunTest.HelloWorld)
