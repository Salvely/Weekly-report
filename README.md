# Weekly-report

> 循此苦旅，以达天际
>
> 这是本人的学习周报记录，参考的是[Skr-Learning](https://github.com/Kiprey/Skr_Learning)学习周报。这里定期记录一些学习的内容与进度。
> 输入`./create [周数]`生成下一周

## Week 1: 2023.10.30-2023.11.5

### 主要任务

- C++ Basics 学习

### Logs

- [2023.10.30](./week1/journal/day1.md): 哎哟，啥也没干，郁闷。。。
- [2023.10.31](./week1/journal/day2.md): 用`STL`实现了[贪吃蛇小游戏](./code/snake/)
- [2023.11.1](./week1/journal/day3.md): 完成了`STL Vectors`一章的`Reading`,今天因为出去了，效率不是太高
- [2023.11.2](./week1/journal/day4.md): `STL Associative Containers Reading`完成，用`STL Multimap`实现了一个[`NFA`](./code/nfa/)
- [2023.11.3](./week1/journal/day5.md): 杂事很多，很累，今天摆烂了。。。
- [2023.11.4](./week1/journal/day6.md): 阅读了`STL Algorithms`
- [2023.11.5](./week1/journal/day7.md): 身体不太舒服，没有学习。。。

## Week 2: 2023.11.6-2023.11.12

### 主要任务

- Modern C++基础
  - [Bonn Modern C++ for image processing](./code/Bonn_CPP/)
- [CMake 基础](./code/cmake/)

### Logs

- [2023.11.6](./week2/journal/day1.md): 又摆烂了，郁闷。。。
- [2023.11.7](./week2/journal/day2.md): 学习了 C++ 编译系统和`CMake`基础，对虚拟机空间进行了一些清理，先使用命令行和`build.sh`脚本手动编译了一个工程项目，而后又使用`CMake`构建项目并`make`编译，其中`library output path`需要特别声明，留待明早完成。
- [2023.11.8](./week2/journal/day3.md): 实现了`CMake`多文件多目录项目构建，了解了基本的一些`CMAKE_DIR`,`CMake shared library`构建，以及`CMake install`，了解了一些`GDB`高级用法
- [2023.11.9](./week2/journal/day4.md): 学习了`C++ Functions`，以及`clang-format`和`clang-tidy`的用法
- [2023.11.10](./week2/journal/day5.md): 学习了`C++ Containers & Iterators & Algorithms`，完成了`Bonn Modern C++ hw3`和一部分`hw4`
- [2023.11.11](./week2/journal/day6.md): 实现`hw4`，还需要参考一下《STL 源码剖析》中的实现，按照作业测试来看他的需求就是在自己的实现里面套壳，没什么意思，就不管他了
- [2023.11.12](./week2/journal/day7.md): 学习了一些`C++ Utilities & Library & Classes & visual words & opencv tutorial`，不是很多，下周加油！

## Week 3: 2023.11.13-2023.11.19

### 主要任务

- Modern C++基础
  - [Bonn Modern C++ for image processing](./code/Bonn_CPP/)
  - [CIS1900](./code/cis1900/)
- [OpenCV C++学习](./code/opencv_test/)
- [Google Test 测试框架学习](./code/gTest/)
- 系统入门
  - [CIS2400](./code/CIS2400/)

### Logs

- [2023.11.13](./week3/journal/day1.md): `googletest`使用学习，`C++ Classes`，修复了`hw4`的一些小问题，安装了`opencv`
- [2023.11.14](./week3/journal/day2.md): 学习了`C++ Inheritance, Static, Numbers, Arrays, Pointers, Stack and Heap, Memory Leak, Smart Pointers`，今天主要是在看 lecture, assignment 倒没怎么做。
- [2023.11.15](./week3/journal/day3.md): `Modern C++ Basics`理论部分全部学完，`opencv`环境配置完成，尚未测试，，`CIS1900 C++`前三个`lecture`复习。今天效率不是很高。
- [2023.11.16](./week3/journal/day4.md): 身体不太舒服，头有点疼，可能是昨天睡太晚了，效率不高，今天早点睡。
- [2023.11.17](./week3/journal/day5.md): 效率不高，搞虚拟机搞了半天，明天加油！
- [2023.11.18](./week3/journal/day6.md): 复习了点系统基础，其他的啥也没干，又是摆烂的一天。唉，运动多了，膝盖搞疼了，明天一定要加油！早睡早起，打起精神来！
- [2023.11.19](./week3/journal/day7.md): LC4 汇编程序作业完成，复习数据通路，MIPS I-type 和 J-type 指令跳转实现。

## Week 4: 2023.11.20-2023.11.26

### 主要任务

1. 系统基础复习
   - [CIS2400](./code/CIS2400/)

### Logs

- [2023.11.20](./week4/journal/day1.md): LC4 数据通路和信号，完成指令译码，学习 I/O 设备和控制器，Memory Mapped I/O, Subroutines, TRAP 指令过程以及 TRAP 指令和 JSR 指令的比较，巩固 C 基础
- [2023.11.21](./week4/journal/day2.md): I/O Memory Mapped Console & Video Display 部分复习，完成`hw6`，复习 Memory leaks & C 程序结构 & 预处理过程 & makefile
- [2023.11.22](./week4/journal/day3.md): Makefiles & Command Line Arguments & File I/O & Binary Files & Endianness 复习，完成 hw7，总体效率不高
- [2023.11.23](./week4/journal/day4.md): 完成了反汇编器的大部分工作，还有一些立即数和打印的问题需要修改一下。
- [2023.11.24](./week4/journal/day5.md): 实现反汇编器，修复了指令结构打印，立即数等一些问题
- [2023.11.25](./week4/journal/day6.md): 出去逛街了，今天没有学习。。。

## Week 5: 2023.11.27-2023.12.3

### 主要任务

1. 系统基础复习
   - [CIS2400](./code/CIS2400/)
   - [CIT5950](./code/CIT5950/)

### Logs

- [2023.11.27](./week5/journal/day1.md): 去东湖骑单车了，太累了，没怎么学习
- [2023.11.28](./week5/journal/day2.md): 完成 J 语言->LC4 汇编器，除了函数调用以外的大部分工作
- [2023.11.29](./week5/journal/day3.md): 完成了汇编器。复习了一下 C/C++。
- [2023.11.30](./week5/journal/day4.md): 出去逛街了，今天没有学习。。。
- [2023.12.1](./week5/journal/day5.md): HashTable 实现（因为一些小 bug，卡了比较长时间，其实效率还可以更高）
- [2023.12.2](./week5/journal/day6.md): HashTable Iterator 实现
- [2023.12.3](./week5/journal/day7.md): 摆烂了， 啥也没干，呜呜呜

## Week 6: 2023.12.4-2023.12.10

### 主要任务

1. 系统基础复习
   - [CIT65950](./code/CIT5950/)
2. 基础数学修炼
   - [微积分](./mathematics/Calculus)
   -

### Logs

- [2023.12.4](./week6/journal/day1.md): 摆烂了，没学习，呜呜呜。。。
- [2023.12.5](./week6/journal/day2.md): 又摆了一天，呜呜呜。。。。
- [2023.12.6](./week6/journal/day3.md): 又摆了一天，呜呜呜。。。。
- [2023.12.7](./week6/journal/day4.md): File I/O 实现一部分(SimpleFileReader 实现，Buffered 实现了一部分), 今天效率相较，前几天的摆烂有所提升，明天继续加油！
- [2023.12.8](./week6/journal/day5.md): BufferedFileReader 实现，效率还是低
- [2023.12.9](./week6/journal/day6.md): 就装了个Ubuntu 20.04 Latex环境，最近是怎么回事啊哎哟喂。。。。
- [2023.12.10](./week6/journal/day7.md): 就复习了点微积分，又摆了一天，这周是怎么回事啊，唉。。。

## Week 7: 2023.12.11-2023.12.17

### 主要任务

1. 基础数学修炼
  - [微积分](./mathematics/Calculus/)

### Logs

- [2023.12.11](./week7/journal/day1.md): 