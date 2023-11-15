# set the minimum version for cmake
cmake_minimum_required(VERSION 3.16)

# set the c++ standard for project
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_COMPILE clang++)

# set the project name
project(demo4)

# add the static library
add_library(greet SHARED src/greet.cpp)

# include the header files
target_include_directories(greet PUBLIC ${PROJECT_SOURCE_DIR}/include)

# generate the executable files
add_executable(main src/main.cpp)

# and link to the library
target_link_libraries(main PRIVATE greet)