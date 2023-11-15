# set the minimum version for cmake
cmake_minimum_required(VERSION 3.16)

# set the c++ standard for project
set(CMAKE_CXX_STANDARD 17)

# set the project name
project(demo2)

# set sources
set(SOURCES src/greet.cpp src/main.cpp)

# add executable
add_executable(main ${SOURCES})

# include directory
target_include_directories(main 
    PRIVATE 
    ${PROJECT_SOURCE_DIR}/include)