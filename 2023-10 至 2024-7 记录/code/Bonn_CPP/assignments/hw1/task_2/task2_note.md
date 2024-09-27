# Note for hw1 task2

## Exercise 1: Build by hand

本练习要求我们手动编译这个项目，首先，这个项目有一个库`ipb_arithmetic`，其中包含两个文件`subtract.hpp`和`sum.hpp`。
在`src`中放置了我们的程序源文件，其中也包含`subtract.hpp`和`sum.hpp`的函数实现。`results`目录暂且不管。

使用命令如下：

```bash
clang++ -std=c++17 -I ./include -c src/substract.cpp
clang++ -std=c++17 -I ./include -c src/sum.cpp
clang++ -std=c++17 -I ./include -c src/main.cpp
clang++ -std=c++17 subtract.o sum.o main.o -o main
./main
```

其中`-I [path]`指定了`include`的路径，`-c <file>`指定了编译哪个文件生成对应目标文件`.o`

## 利用`build.sh`构建工程

```bash
#!/bin/bash
rm -r build
# make a directory called build
mkdir build

# compile the two object files
clang++ -c -std=c++17 -I./include src/subtract.cpp -o build/subtract.o
clang++ -c -std=c++17 -I./include src/sum.cpp -o build/sum.o

# build a library according to the two object files
ar rcs build/libipb_arithmetic.a build/sum.o build/subtract.o

# link the library to the main.cpp
clang++ src/main.cpp -std=c++17 -I./include -L ./build -lipb_arithmetic -o main

mv build/*.o results/bin
mv build/*.a results/lib
mv main results/bin
```

这里有一些较为关键的点：

1. `clang++` 将 `*.cpp` 编译为目标文件时，必须使用`-I <path>`指定头文件的路径
2. 生成的库必须以`lib`开头，如`libipb_arithmetic.a`
3. 链接库时，`main.cpp`必须放在最开头处（很重要！），然后相同的，必须用`-I <path>`指定头文件的路径，`-L`指定库的路径，`-l`后接库的名称，要注意的是，加入库的命名是`libxxx.a`,那么`lib`要省略，`.a`要省略，在这里只`-lxxx`即可。

## 使用`CMake`实现上述过程

### 步骤

1. 设置基本的一些变量，如 CMake 版本号，所使用到的 C++ 标准和编译器等
2. 设置库的输出路径和可执行文件的输出路径
3. 设置项目工程名
4. 设置`SOURCES`为`.cpp`文件
5. **将`.cpp`文件打包成库**
6. **在库中引入头文件**
7. **生成目标文件**
8. **链接目标文件和库**

### 源码

```cmake
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
```

### 注意

1. 要将`library`和可执行文件输出到特定目录，不能直接在`add_library`和`add_executable`中指定目录，必须使用`set(CMAKE_LIBRARY_OUTPUT_DIRECTORY XXX)`和`set(CMAKE_RUNTIME_OUTPUT_DIRECTORY)`指定目录
2. 注意`CMake`各个`directory`的区别，尤其是：
   - `PROJECT_SOURCE_DIR`：当前`project`所在目录，在该目录中声明了`project`名
   - `CMAKE_SOURCE_DIR`：项目顶层`CMakeLists.txt`所在目录
   - `CMAKE_CURRENT_SOURCE_DIR`：当前`CMakeLists.txt`所在目录
   - `CMAKE_CURRENT_BINARY_DIR`：当前所引用的二进制目标文件所在目录
3. 使用`set(CMAKE_CXX_COMPILER clang++)`指定编译器为`clangd`
4. 要引入`include`目录下的头文件，使用的路径必须是以`include`为根，到该文件位置的路径，如`ipb_arithmetic/subtract.h`
5. 在标记路径时，必须从从绝对路径开始，如`${CMAKE_SOURCE_DIR}`，不能直接写`results/bin`，否则`CMake`会认为是从当前目录下找

## Install your library

1. 创建一个`install`目录
2. 在`install.sh`中：

   ```bash
   cd build
   make install
   ```

3. 在`CMakeLists.txt`中加入如下代码：

   ```cmake
   ################ install #####################
   # set the CMAKE_INSTALL_PREFIX as the `install` directory
   set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install)

   # install the executables to install/bin
   install(TARGETS main DESTINATION bin)

   # install the libraries to install/lib
   install(TARGETS ipb_arithmetic LIBRARY DESTINATION lib)

   # install the include files to install/include
   install(DIRECTORY ${CMAKE_SOURCE_DIR}/include DESTINATION .)
   ```

   注意，目录是`install`，不是`include`，不要手误填错了。
   而后执行如下代码即可。

   ```bash
   cd build
   cmake ..
   make
   cd ..
   ./install.sh
   ```

   完成后目录结构如下：

   ```bash
   .
   ├── build
   │   ├── CMakeCache.txt
   │   ├── CMakeFiles
   │   │   ├── 3.16.3
   │   │   ├── cmake.check_cache
   │   │   ├── CMakeDirectoryInformation.cmake
   │   │   ├── CMakeOutput.log
   │   │   ├── CMakeTmp
   │   │   ├── ipb_arithmetic.dir
   │   │   ├── main.dir
   │   │   ├── Makefile2
   │   │   ├── Makefile.cmake
   │   │   ├── progress.marks
   │   │   └── TargetDirectories.txt
   │   ├── cmake_install.cmake
   │   ├── install_manifest.txt
   │   ├── libipb_arithmetic.a
   │   └── Makefile
   ├── build.sh
   ├── CMakeLists.txt
   ├── include
   │   ├── ipb_arithmetic
   │   │   ├── subtract.hpp
   │   │   └── sum.hpp
   │   └── ipb_arithmetic.hpp
   ├── install
   │   ├── bin
   │   │   └── main
   │   ├── include
   │   │   ├── ipb_arithmetic
   │   │   └── ipb_arithmetic.hpp
   │   └── lib
   │       └── libipb_arithmetic.a
   ├── install.sh
   ├── LICENSE
   ├── main.o
   ├── README.md
   ├── results
   │   ├── bin
   │   │   ├── example_output
   │   │   ├── main
   │   │   ├── subtract.o
   │   │   └── sum.o
   │   └── lib
   │       └── libipb_arithmetic.a
   ├── src
   │   ├── main.cpp
   │   ├── subtract.cpp
   │   └── sum.cpp
   ├── subtract.o
   ├── sum.o
   └── task2_note.md

   17 directories, 35 files

   ```
