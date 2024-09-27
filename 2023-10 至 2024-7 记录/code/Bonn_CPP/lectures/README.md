# Bonn University - `Modern C++ for Computer Vison and Image Processing` 课程大纲

- [Bonn University - `Modern C++ for Computer Vison and Image Processing` 课程大纲](#bonn-university---modern-c-for-computer-vison-and-image-processing-课程大纲)
  - [学习流程](#学习流程)
  - [Lec 1 - Modern C++: Build and Tools](#lec-1---modern-c-build-and-tools)
  - [Lec 2 - Core C++](#lec-2---core-c)
  - [Lec 3 - C++ Functions](#lec-3---c-functions)
  - [Clang Tools Tutorial](#clang-tools-tutorial)
  - [Lec 4 - STL](#lec-4---stl)
  - [Lec 5 - File I/O \& C++ Classes \& OpenCV](#lec-5---file-io--c-classes--opencv)
  - [Lec 6 - C++ Classes](#lec-6---c-classes)
  - [Lec 7 - Object Oriented Design](#lec-7---object-oriented-design)
  - [Tutorial: Object-oriented programming](#tutorial-object-oriented-programming)
  - [Tutorial: Pointers \& Stack and Heap \& Memory Leak and Dangling Pointers \& Smart Pointers](#tutorial-pointers--stack-and-heap--memory-leak-and-dangling-pointers--smart-pointers)
  - [Lec 8 - Smart/Unique/Shared ptrs](#lec-8---smartuniqueshared-ptrs)
  - [Lec 9 - Templates, Exceptions, Program input parameters, OpenCV](#lec-9---templates-exceptions-program-input-parameters-opencv)

## 学习流程

1. 按照课程`Video`，整理笔记到`Lectures`目录中，听课的时候在`README.md`中记录下大致的框架，每节课结束后完善对应笔记
2. 作业实现在`Assignment`目录中
3. 课程完成后将笔记发布到博客中

## Lec 1 - Modern C++: Build and Tools

- Some C++ development tools
- The compilation process & the build system (using `clang`)
  - `clang++ -E main.cpp > main.i` 预处理
  - `clang++ -S main.i > main.s` 编译成汇编语言
  - `clang++ -c main.s` 将汇编语言转化为目标文件（二进制），文件名为`main.o`（无需指代）
  - `clang++ main.o -o main` 将目标文件与其他二进制文件链接，生成可执行文件`main`
- Compilation Flags
- Libraries: Static & Dynamic
- Function Declaration & Definition
- Linking
- Link modules and libraries
- Build Systesm
- Why we need build system
- CMake Build System Generator Intro & Usage
- Use pre-compiled library!

## Lec 2 - Core C++

- What is C++ program?
- What are C++ keywords? Identifiers?
- What are C++ entities?
- What are C++ Declarations?
- C++ Definitions, Statements, and Expressions
- C++ Name and their scope
- C++ Type
- C++ Variables
- Control Structures: if, switch, enum(C vs C++), while, for, enhanced for, Structure bindings,
  break, continue ...
- Primitive Types in C++
- Numerical Arithmetic && Logical Arithmetic
- Declaring Variables
- Const Variable
- Reference & const reference
- Streams
- GDB

## Lec 3 - C++ Functions

- C++ strings
  - C style strings are evil! If destiation buffer too small, buffer overflow!
- C++ Function
  - Definition
  - Some Style Guides
  - Function Anatomy
  - Function Body
  - Return Type
    - `auto` keywords
    - Structured Bindings
    - **Don't return REFERENCE TO LOCAL VALUES!**
    - But if we add a std::cout statement before returning reference to the local value, it returns the right value instead of the garbage, why?
  - Local Variable & Static Variable(Compile time allocated)
  - Augument List
    - Pass by value & Pass by reference
    - Default arguments in function declartion, use them only when necessary!
    - Pass by reference when the object is big!
    - Pass by const reference when we don't want to change the object
  - Function Options
    - Inline function call
- C++ Overloading
  - C style overload: different functions for every type
  - C++ style overload: **same function name, different AUGUMENT TYPE** -> template!
  - **Overload is not determined by RETURN TYPE!**
- C++ Style Guide
  - `CamelCase` for Functions, `snake_case` for variables
  - Name must be meaningful
  - Don't use too long names
  - Add additional comments to the function
- C++ Namespace
  - Help avoid name conflicts
  - Group the projects into logical modules
  - avoid `using namespace <xxx>`
  - If you find yourself using some constants in a file, but you don't want them in other files, place them in a namespace

## Clang Tools Tutorial

1. 调整代码风格：`clang-format -i <file>` 修改`file`的格式，并且直接写到文件中
2. 调整`clang`配置：`clang-format -style=<xxx> --dump-config > .clang-format`
3. 检查源代码：`clang-tidy <file>`

## Lec 4 - STL

- static containers & dynamic containers
- std::array
  - `#include <array>`
  - `std::array<Type,size> [name]`
  - `[name].size()`
  - `[name].empty()`
- std::vector
  - `emplace_back()`
  - `back()`
  - `front()`
  - `reserve(n)`
- Why use C++ containers?
  - To get size: use `size()` instead of `sizeof(array)/sizeof(int)`
  - Check if empty: use `empty()` instead of `array[0] == NULL`
  - Access the last element: use `back()` instead of indexing
  - Clear an array: use `clear()` instead of `memset`
  - Same speed, safer, more readable, more functionalities
- Associative Containers
  - `std::map`
    - key-value pairs
    - keys are unique
    - keys must be comparable, and stored accoding to `<` operator
    - value can be any type
    - implemented in `Red-Black Tree`
    - `m.size()`
    - `m.emplace(key,value)` add item
    - `m[key] = value` modify or add item
    - `m.at(key)`
    - `m.count(key)`
    - `m.contains(key)`
  - `std::unordered_map`
    - implemented in **hash-table**
    - key type must be hashable
    - faster than std::map
    - same interface as std::map
  - use structued bindings to store the elements when iterating `std::map` and `std::unordered_map`
- C++ Iterators
  - C++ Containers -> C++ Iterators -> C++ algorithms
  - Iterators minimize the algorithms dependency
- C++ Algorithsm
  - `std::sort(s.begin(),s.end())`
  - `std::find(s.begin(),s.end(),element)`
  - `std::fill(s.begin(),s.end(),element)`
  - `std::count(s.begin(),s.end(),element)` / `count_if(s.begin(),s.end(),condition)`
  - `std::for_each(s.begin(),s.end(),function)`
  - `std::all_of(s.begin(),s.end(),function)`
  - `std::rotate(s.begin(),s.begin() + rotate_num,s.end())`
  - `std::transform`
  - `std::accumulate(s.begin(),s.end(),initial_sum)`
  - `std::max`
  - `std::min_element`
  - `std::minmax_element`
  - `std::clamp`
  - `std::sample`

## Lec 5 - File I/O & C++ Classes & OpenCV

- C++ Utilities
  - Language Support libraries
  - General-purpose libraries
- Some Utilities
  - `std::swap`
  - `std::variant`
  - `std::any`
  - `std::optional`
  - `std::tuple`
  - `std::chrono`
- Error Handling
- I/O Library
  - `ifstream & ofstream & fstream` from `std`
  - Regular Columns
  - Read in
    - `ifstream`
    - `getline()`
  - Write out
    - `ofstream`
  - Serialization (read in/out binary files)
    - write bytes to data
      - data must be structured
      - fast
      - No precision lost for floating point
      - smaller than ascii-files
      - Mode: `io_base::out | io_base::binary`
    - read from files
      - must know the structure of the data
    - Advantages
      - faster
      - smaller
      - many libraries support serialization
    - Disadvantages
      - syntax ugly
      - files not readable
      - you need to know the structure of the file in advance
    - C++17 Filesystem
      - `path()`
      - `filename()`
      - `extension()`
      - `stem()`
      - `exists()`
- C++ Type is important!
- C++ Class Basics
- [Tutorial - OpenCV](https://www.ipb.uni-bonn.de/html/teaching/modern-cpp/tutorials/opencv.pdf)

## Lec 6 - C++ Classes

> class basics 部分省略

- class variables
  - use `snake_case_` with trailiing `_` for private data members
- `std::move` semantics
  - lvalue & rvalue
  - Explicit rvalue defined using `&&`
  - use `std::move` to convert a lvalue into an rvalue reference to it
  - it's about ownership
  - cannot use that variable after `std::move`
- Operator overloading
- Class Special Functions
  - Copy Constructor
    - use `*this` to get the reference to the current object
    - Operator assignment
  - Move constructor
    - `MyClass b(std::move(a))`
    - `MyClass c = std::move(a)`
    - Operator assignment
  - Define **all of the constructor** or **None or the constructor**
  - use `= default` to use the default implementation
  - use `= deleted` when no longer wants to use that function
- Static variables & methods
  - static variables
    - exists one per class, generated during compilation
    - Must be defined in `.cpp` file
  - static methods
    - called using `ClassName::method()`
    - declared `static` in function declaration
- `using` keyword
  - `using <new_name> = <old_name>`
  - when declared outside of the function, it's useful globally
  - Otherwise, it's useful inside the function
- Enumeration Classes
  - enum name must be `CamelCase`
  - enum variable must be `SNAKE_CASE` or `snakeCase`

## Lec 7 - Object Oriented Design

- Inheritance
  - 3 types of inheritance
    - public: `is a` relationship, derive all `public` and `protected` methods from base class
    - protected:
    - private
  - Function overriding
    - `virtual`: if a function is `virtual` in base class, then it could be overriden in derived class
    - `pure virtual`: make a function `virtual <function> = 0` in base class makes all derived class to override it. Should add `[const] override` after the function when overriding it.
  - overload & override
    - overload: same name, different parameters, pick a function at compile time
    - override: same name and parameters, but pick from a class from the hierarchy tree
  - abstract class & interface
    - abstract class: class that has at least one pure virtual functions
    - interface: class that has only pure virtual functions and no data members
    - virtual functions -> virtual table
  - Polymorphism
    - `const Base& base = Derived(...)`
    - call corresponding methods according to the objects
  - Inheritance & Composition
  - Type Casting
    - `static_cast`:
      - `static_cast<NewType>(variable)`
      - happpened at compile time
      - primitive type or class type
    - `reinterpret_cast`
      - `reinterpret_cast<NewType>(variable)`
      - Reinterpret the bytes of a variable to another type
    - `const_cast`
    - `dynamic_cast`
      - `dynamic_cast<Base*>(Derived_ptr)`, returns null if conversion failed
      - happened at runtime
      - Derived class -> Base class
      - **GOOGLE STYLE: AVOID USING THIS!**
    - C style cast(a composition of the above 4 methods, it's unsafe)
  - Design Patterns
    - strategy pattern
      - if a class relies on complex external functionalities
      - Strategy example
        - class Strategy -> class StrategyA/B/C...
        - class MyClass
          - maintains a `Strategy class` member(Base class, not the derived class)
          - initialize the `Strategy class` member when calling constructor method
          - call the corresponding strategy class function according to that data member(Polymorphism)
    - singleton pattern
      - only one instance of a given class at compile time
      - how?
        - delete any class member functions
        - hide constructor and destructor of the class so no new instance could be created(make it `private` and `= default`)
        - delete copy constructor and copy assignment operator(make them `= deleted`)
        - one unique instance at compile time -> use static!
        - provide a public static method called `GetInstance()`
    - CRPT pattern
      - recursively
      - example: pass the derived class as a template variable to the based class, and gets its name printed

## Tutorial: Object-oriented programming

- 4 concepts
  - encapsulation
  - abstraction
    - Simpler interface
    - Reduce the impact of change
    - hide details
  - inheritance
    - eliminate redundant code
  - polymorphism
    - poly morph = many forms
    - refactor switch case statement

## Tutorial: Pointers & Stack and Heap & Memory Leak and Dangling Pointers & Smart Pointers

- Using pointers
  - can be reassigned
  - could be `nullptr`
  - can be stored to an array or vector
- pointers are polymorphism

  ```C++
  Derived derived;
  Base* ptr = &derived;
  ```

- Pointer "this": a pointer to the object/struct itself
- Using const with pointers
  - points to const variable: the variable is constant but the pointer could be reassigned

  ```C++
  const MyType* const_var_ptr = &var;
  const_var_ptr = &another_var;
  ```

  - const pointer: the pointer could not be reassigned, but could change variable value

  ```C++
  MyType* const const_ptr = &var;
  const_ptr->var = 10;
  ```

  - read from right to left
- Stack and Heap
  - Stack
    - static memory
    - short term storage
    - small and limited
    - memory allocation is fast
    - LIFO structure with operation `Push`/`Pop`
  - Heap
    - Dynmaic memory
    - persists for a long time
    - Allocate with `new`/`delete`, clear space with `delete`(manually)
    - allocation slower than stack
    - prefer using `smart pointers`!
- Memory leak and dangling pointers
  - Memory leak(mostly on heap)
    - access to memory which has been freed
    - forgot to free the memory allocated
    - double free memory
  - Dangling pointer: make `ptr1` and `ptr2` point to the same memory, and free `ptr1`, thus left `ptr2` dangling
  - RAII
    - **Resource Allocation Is Initialization**
    - new object -> allocate memory
    - remove object -> free memory
    - Objects own their data
  - Shallow copy & deep copy
    - shallow copy: only copy pointers, not data
    - deep copy: copy data and assign them new pointers
    - Notes that:
      - default copy constructor and assignment operator use shallow copy
      - RAII + Shallow copy -> dangling pointers!
      - RAII + Rule of all or Nothing -> correct!
      - use smart pointers instead
- Smart pointers
  - wrap a pointer into a class and manage its lifetime
  - all about **ownership**
  - always use smart pointers when the pointer should **own heap memory**
  - `#include <memory>`
  - 2 types
    - Unique pointer
    - shared pointer

## Lec 8 - Smart/Unique/Shared ptrs

- characteristics
  - can be set to `nullptr`
  - use `*ptr` to dereference ptr
  - use `ptr->` to access methods
  - smart pointers are polymorphic
  - `ptr.get()` returns the raw pointer
  - `ptr.reset(raw_ptr)` stops using currently managed pointer
- `std::unique_ptr`
  - the class takes over the ownership of the unique pointer
  - `auto p = std::unique_ptr<Type>(new Type(<Params>))`
  - `auto p = std::make_unique<Type>(<params>)`
  - unique pointer has no copy constructor, cannot be copied, can be moved
  - guaranteed that memory is always owned by a single unique pointer
- `std::shared_ptr`
  - constructed like `unique_ptr`
  - can be copied and moved(won't increment the counter)
  - storage a usage counter and a raw pointer
    - counter increase when constructed
    - counter decrease when destructed
  - free memory when counter reaches 0
  - can be initialized from a `unique_ptr`
- When to use what
  - use smart pointer when the pointer must manage memory
  - By default using `unique_ptr`
  - If multiple objects share a piece of memory, use `shared_ptr` instead
  - you don't need to use the destructor yourself
  - `new` and `delete` is dangerous(may cause memory leak and dangling pointers)
    - don't use `delete`
    - allocate memory using `make_unique` or `std::makr_shared`
  - use it with memory **on the heap**

## Lec 9 - Templates, Exceptions, Program input parameters, OpenCV

- Generic Programming
  - separate algorithms from data type
  - data type must be
    - copy constructable
    - assignable
    - is defined(for custom classes)
  - Template functions
  - Template classes
- Error handling
  - Usage
    - throw `exception`
    - base class: `exception`
    - to use `exception`: `#include <stdexcept>`
    - `try..catch..throw`
    - parameter: string type message
    - use `what()` to get info about the exception
  - Error type
    - runtime error
    - logic error
  - **GOOGLE STYLE: NOT TO USE `try...catch...`!**
- Program input parameters
- Type alias: `using <NewType> = <OldType>`
  - used outside of functions: global
  - used inside functions: locally scope
- OpenCV
  - `cv::Mat`
  - `cv::Mat I/O`
  - `SIFT` Extraction
  - `FLANN` in OpenCV
  - OpenCV with CMake
