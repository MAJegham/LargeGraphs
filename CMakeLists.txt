cmake_minimum_required(VERSION 3.8)

set(This LargeGraphs)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(lib/googletest)

set(Headers 
	src/Edge.hpp
	src/Graph.hpp
	src/Utils.hpp
)

set(Sources 
	src/Graph.cpp
	src/main.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)
