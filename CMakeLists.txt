cmake_minimum_required (VERSION 3.0)

project(cpp_test_any__problem_solving CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")

set(INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include)
include_directories(${INCLUDE_DIRS})

set(SOURCE_FILE_DIR ${PROJECT_SOURCE_DIR}/src)
set(SOURCE_FILES
		${SOURCE_FILE_DIR}/main_executor.cpp
)
add_executable(hot_cold_test ${SOURCE_FILES})

target_link_libraries(hot_cold_test
	pthread
	rt
)
