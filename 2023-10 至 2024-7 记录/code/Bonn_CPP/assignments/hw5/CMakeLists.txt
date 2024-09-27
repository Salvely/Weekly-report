cmake_minimum_required(VERSION 3.16)
set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_COMPILER clang++)
project(homework_5)

find_package(OpenCV REQUIRED)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
add_library(mat_serialization STATIC ${CMAKE_SOURCE_DIR}/include)
target_link_directories(mat_serialization PRIVATE ${CMAKE_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
add_executable(main src/main.cpp)

target_link_libraries(main mat_serialization opencv2)