cmake_minimum_required(VERSION 3.8)

set(This LargeGraphs)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(lib/googletest)

set(Headers
	${PROJECT_SOURCE_DIR}/src/graph/elements/Edge.hpp
	${PROJECT_SOURCE_DIR}/src/graph/Graph.hpp
	${PROJECT_SOURCE_DIR}/src/graph/EdgeListGraph.hpp
	${PROJECT_SOURCE_DIR}/src/utils/MathUtils.hpp
	${PROJECT_SOURCE_DIR}/src/utils/FileUtils.hpp
)

set(Sources
	${PROJECT_SOURCE_DIR}/src/graph/Graph.cpp
	${PROJECT_SOURCE_DIR}/src/graph/EdgeListGraph.cpp
	${PROJECT_SOURCE_DIR}/src/utils/FileUtils.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

include_directories(${This} PRIVATE ${PROJECT_SOURCE_DIR}/src)

add_subdirectory(test)
