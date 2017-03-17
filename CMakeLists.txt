CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(UOSnake)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -Wall")
SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

SET(ROOT ${CMAKE_CURRENT_SOURCE_DIR})
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)

INCLUDE_DIRECTORIES(${ROOT}/src)
INCLUDE_DIRECTORIES(${ROOT}/include)

# The version number
SET(UOSnake_VERSION_MAJOR 0)
SET(UOSnake_VERSION_MINOR 1)


# Libraries
SET(LIBCORE_SRC
		src/SCoord.cpp
		src/SDirection.h
		src/Snake.cpp
		src/SCell.cpp
		src/SMap.cpp)
ADD_LIBRARY(core STATIC ${LIBCORE_SRC})


# Executables
SET(UOSNAKE_SRC
	src/main.cpp)
ADD_EXECUTABLE(uosnake ${UOSNAKE_SRC})
TARGET_LINK_LIBRARIES(uosnake core)

# Tests
SET(TESTS
		tests/SCoordTest.cpp
		tests/SnakeTest.cpp)
ADD_EXECUTABLE(global_test ${TESTS} tests/main.cpp)
TARGET_LINK_LIBRARIES(global_test core)
