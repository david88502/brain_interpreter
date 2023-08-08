cmake_minimum_required(VERSION 3.25.2)
project(brain_interpreter)

set(CMAKE_CXX_STANDARD 17)

# Include the subdirectories
add_subdirectory(interpreter)

# Add the main executable
add_executable(brain_interpreter main.cpp)

# Link the main executable with the submodule libraries
target_link_libraries(brain_interpreter PRIVATE Interpreter)

## Include and link gtest
include(FetchContent)
FetchContent_Declare(
	googletest
	# Specify the commit you depend on and update it regularly.
	URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

## Add GTest required libraries to linker
link_libraries(${GTEST_LIBRARIES} gtest_main pthread)