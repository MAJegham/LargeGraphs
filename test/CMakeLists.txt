cmake_minimum_required(VERSION 3.8)

set(This UnitTests)

set(Sources
	${PROJECT_SOURCE_DIR}/test/ReadGraphTest.cpp
	${PROJECT_SOURCE_DIR}/test/FileUtilsTest.cpp
	${PROJECT_SOURCE_DIR}/test/ReadEdgeListGraphTest.cpp
)

add_executable(${This} ${Sources} )

target_include_directories(${This} PRIVATE ${PROJECT_SOURCE_DIR}/src)

target_link_libraries(${This} PRIVATE
	gtest_main
	LargeGraphs
	)

add_test(
	NAME ${This}
	COMMAND ${This}
)

# add_custom_command(
#      TARGET ${This}
#      COMMENT "Run UnitTests"
#      POST_BUILD
#      WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
#      COMMAND ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> -R "^${This}$" --output-on-failures
# )


add_custom_command(
     TARGET ${This}
     COMMENT "execute unit tests"
     POST_BUILD
     COMMAND ${This}
)

