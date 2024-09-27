cmake_minimum_required(VERSION 3.16)
set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_COMPILER clang++)
project(homework_3)

# include the include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# set the library output path
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

# add src/html_writer.cpp as library
# add_library(html_writer STATIC src/html_writer.cpp)
add_library(image_browser STATIC src/image_browser.cpp src/html_writer.cpp)

# map the api header files to the library
# target_include_directories(html_writer PUBLIC ${CMAKE_SOURCE_DIR}/api)
target_include_directories(image_browser PUBLIC ${CMAKE_SOURCE_DIR}/api)

# set the executable output path
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

# add executable
add_executable(main src/main.cpp)

# link the executable to the library
target_link_libraries(main PRIVATE image_browser stdc++fs fmt)