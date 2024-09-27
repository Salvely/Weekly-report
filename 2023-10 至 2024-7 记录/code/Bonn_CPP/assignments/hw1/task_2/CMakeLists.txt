# set the minimum version for cmake
CMAKE_MINIMUM_REQUIRED(VERSION 3.16)

# specify the C++ standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_COMPILER clang++)

# set library output path
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/results/lib)

# set the project name
project(arithmetic)

# set sources file
set(SOURCES src/subtract.cpp src/sum.cpp)

# add a library for subtract.cpp and sum.cpp
add_library(ipb_arithmetic STATIC ${SOURCES})

# include the header files
target_include_directories(ipb_arithmetic PUBLIC ${PROJECT_SOURCE_DIR}/include)

# set the executable output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/results/bin)

# add the executable
add_executable(main src/main.cpp)

# link the executable and the library
target_link_libraries(main PRIVATE ipb_arithmetic)

################ install #####################
# set the CMAKE_INSTALL_PREFIX as the `install` directory
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install)

# install the executables to install/bin
install(TARGETS main DESTINATION bin)

# install the libraries to install/lib
install(TARGETS ipb_arithmetic LIBRARY DESTINATION lib)

# install the include files to install/include
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include DESTINATION .)