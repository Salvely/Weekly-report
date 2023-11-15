cmake_minimum_required(VERSION 3.16)
set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_COMPILER clang++)

project(homework_4)

# set library output path
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

# add library
add_library(vector STATIC src/homework_4.cpp)

# map library to the header file
target_include_directories(vector PUBLIC ${CMAKE_SOURCE_DIR}/include)

# set executable output path
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

# add executable
add_executable(main src/main.cpp)

# link library with the executable
target_link_libraries(main PRIVATE vector)