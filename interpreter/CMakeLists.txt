set(SOURCES
	src/interpreter.cc
	)

set(HEADERS
	include/interpreter.h
	)

add_library(Interpreter ${SOURCES} ${HEADERS})


target_include_directories(
	Interpreter
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_subdirectory(test)
