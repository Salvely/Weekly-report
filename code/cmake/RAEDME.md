# CMake 学习

> [参考资料](https://github.com/ttroy50/cmake-examples)

- [简单的`helloworld`示例](./demo1/)

  1. 必须有`main.cpp & main函数`，否则无法构建
  2. `cmake_minimum_required(VERSION 3.16)`中`VERSION`和`set(CMAKE_CXX_STANDARD 17)中的CMAKE_CXX_STANDARD`必须大写
  3. `set(CMAKE_CXX_STANDARD 17)`必须在`project(demo1)`的前面
  4. 最后使用`add_executable`编译
  5. 如果想让编译文件和源代码分开，可以创建一个目录`build`，先`cd build`，然后再`cmake ..`,最后`make`

- [`.h`和`.cpp`分开的多文件构建示例](./demo2/)

  1. 使用`set(SOURCES src/greet.cpp src/main.cpp)`来指定`SOURCES`变量为所有`.cpp`文件
  2. 使用`add_executable(main ${SOURCES})`来生成可执行文件
  3. 使用`target_include_directories`来`target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR}/include)`，使用`main`来指代生成的可执行文件

- [创建并链接静态库](./demo3/)

  整个过程分为 3 步:

  1. `add_library`添加静态库
  2. `target_include_directories`引入头文件
  3. `add_executable`生成可执行文件，并且通过`target_link_libraries`链接到库

- [创建`shared library`](./demo4/)

  和`demo3`差别不大，除了`add_library`时把`STATIC`换成`SHARED`

- [`CMake install`](./demo5/)

  将二进制目标文件和可执行文件放在`install/bin`中，将库文件放在`install/lib`中，将头文件放在`install/include`中
  在`CMakeLists.txt`最后加 4 行代码搞定：

  ```cmake
  # set the install path

  set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install)

  # set the binary installation path

  install(TARGETS main DESTINATION bin)

  # set the libarry installation path

  install(TARGETS greet LIBRARY DESTINATION lib)

  # set the header file path

  install(DIRECTORY ${CMAKE_SOURCE_DIR}/include DESTINATION .)
  ```
