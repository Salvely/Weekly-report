cmake_minimum_required(VERSION 3.16)
set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_COMPILER clang++)
project(shape)

set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
add_library(shape STATIC src/shape.cpp src/square.cpp src/triangle.cpp)
target_include_directories(shape PUBLIC ${CMAKE_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE shape)