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

### Logs

- [2023.12.4](./week6/journal/day1.md): 摆烂了，没学习，呜呜呜。。。
- [2023.12.5](./week6/journal/day2.md): 又摆了一天，呜呜呜。。。。
- [2023.12.6](./week6/journal/day3.md): 又摆了一天，呜呜呜。。。。
- [2023.12.7](./week6/journal/day4.md): File I/O 实现一部分(SimpleFileReader 实现，Buffered 实现了一部分), 今天效率相较，前几天的摆烂有所提升，明天继续加油！
- [2023.12.8](./week6/journal/day5.md): BufferedFileReader 实现，效率还是低
- [2023.12.9](./week6/journal/day6.md): 就装了个 Ubuntu 20.04 Latex 环境，最近是怎么回事啊哎哟喂。。。。
- [2023.12.10](./week6/journal/day7.md): 就复习了点微积分，又摆了一天，这周是怎么回事啊，唉。。。

## Week 7: 2023.12.11-2023.12.17

### 主要任务

1. 基础数学修炼

- [微积分](./mathematics/Calculus)

### Logs

- [2023.12.11](./week7/journal/day1.md): 数与函数、图，微积分的基本概念复习，切线的定义、计算及存在性学习，可微分定义，可微分函数定义，以及一些 Notation 的由来学习，极限的标准定义，定义中的注意事项，左极限和右极限，极限存在条件，计算定律，以及一些重要的三角极限学习，点的连续，函数连续，连续的严格定义，函数微分必有函数连续，连续函数的 3 个定理学习(MVT,EVT,IVT)，导数的定义、计算学习（Calculus with Analytic Geometry 第 1、2、3 章）
- [2023.12.12](./week7/journal/day2.md): 导数的应用(图像绘制、凹凸性、其他应用)、根据 dy/dx 的切线近似曲线的微分思想、不定积分的计算(换元法、分离分式法)学习，不定积分的应用，定积分的思想(面积累加和)，微积分三大基本定理，定积分的性质学习(Calculus with Analytic Geometry 第 3、4、5、6 章)
- [2023.12.13](./week7/journal/day3.md): 中国近现代史纲要复习
- [2023.12.14](./week7/journal/day4.md): Calculus with Analytic Geometry 第六章习题完成，Chapter 7.8 复习，第 9 章看了个开头，实在是学不动了
- [2023.12.15](./week7/journal/day5.md): Calculus with Analytic Geometry 三角函数部分复习+托马斯微积分参数方程和极坐标一章复习
- [2023.12.16](./week7/journal/day6.md): Thomas Calculus 参数方程习题看完，Chapter 12 搞完
- [2023.12.17](./week7/journal/day7.md): Thomas Calculus Chapter 13.14.15 复习，15 章复习了一半

## Week 8: 2023.12.18-2023.12.24

### 主要任务

> 重点不是考试，是知识的掌握和能力的进化！
> 重要的不是刷题，是掌握知识本身！

1. 考研复习

- [微积分](./mathematics/Calculus/)

2. 考研

### Logs

- [2023.12.18](./week8/journal/day1.md): 重积分和曲面积分复习，MIT Single Variable Calculus 复习
- [2023.12.19](./week8/journal/day2.md): MIT Single Variable Calculus 所有内容学完
- [2023.12.20](./week8/journal/day3.md): 单变量微积分彻底学习完
- [2023.12.21](./week8/journal/day4.md): 单变量微积分复习，多变量微积分线积分复习，复习不完了哇哇哇
- [2023.12.22](./week8/journal/day5.md): 肖四记忆，多变量微积分复习，感觉复习不完了哇哇哇，我太累了，每天肝上十个小时复习，但是前面刷课去了，复习搞得太晚了，复习的时间太少了，哇哇哇怎么办
- [2023.12.23](./week8/journal/day6.md): 考研第一天
- [2023.12.24](./week8/journal/day7.md): 考研第二天

## Week 9: 2023.12.25-2023.12.31

### 主要任务

> 本周内刷完所有相关课程，加油！本周先把工作和语言成绩确定下来！
> 人生还很长，要向前看！

- 休息

### Logs

- [2023.12.25](./week9/journal/day1.md): 休息了一天，觉得自己考研数学考的不好，有点难过（不，是非常难过），但是我明年肯定不再考了，不会再考虑这些东西了，数学和政治的复习太折磨人了，完全是没有定数，不像英语和专业课，基本功够扎实就可以了
- [2023.12.26](./week9/journal/day2.md): 休息第二天，明天开始继续刷课，加油！人生还很长，不要因为数学就被彻底击败了！海明威在《老人与海》里面写过，人可以被毁灭，但不能被打败！每次精神意志遭受挫折之后，总要再站起来！
- [2023.12.27](./week9/journal/day3.md): 今天休息了一天
- [2023.12.28](./week9/journal/day4.md): 休息第四天
- [2023.12.29](./week9/journal/day5.md): 休息第五天
- [2023.12.30](./week9/journal/day6.md): 复习了一些系统基础
- [2023.12.31](./week9/journal/day7.md): 和别人一块去东湖落雁岛玩

---

> 今年定个小目标，坚持 github 365 天全绿。

## Week 10: 2024.1.1-2024.1.7

### 主要任务

1. [CIT5950 课程学习](./code/CIT5950/)

### Logs

- [2024.1.1](./week10/journal/day1.md): 去看望爷爷奶奶
- [2024.1.2](./week10/journal/day2.md): 见鬼，今天又摆了，怎么回事啊
- [2024.1.3](./week10/journal/day3.md): 单线程和多线程版本图像模糊处理程序实现，今天还是挺摆的，明天加油！
- [2024.1.4](./week10/journal/day4.md): Thread 作业 DoubleQueue 实现
- [2024.1.5](./week10/journal/day5.md): HW3 Page & PageTable 虚拟内存模拟作业完成
- [2024.1.6](./week10/journal/day6.md): C++语法复习，HW4 Pipe & Shell 基本框架完成，Pipe 读写端和 STDIN 及 STDOUT 的重定向尚未完成
- [2024.1.7](./week10/journal/day7.md): Shell & Pipe 实现

## Week 11: 2024.1.8-2024.1.14

### 主要任务

1. [CIT5950 课程学习](./code/CIT5950/)

### Logs

- [2024.1.8](./week11/journal/day1.md): Final Project 的答案已经给了，做不了了。复习了一下 Socket 编程。因为这两天来例假了，所以效率不高，看了会儿《天使爱美丽》就睡了，明天加油！
- [2024.1.9](./week11/journal/day2.md): 实现[多级 pipe](./code/CIT5950/Pipe/multi_pipe.cc)了！复习网络编程，完成 Socket 单进程互相发送消息程序。
- [2024.1.10](./week11/journal/day3.md): 实现多进程 Socket 通信，今天主要是在休息
- [2024.1.11](./week11/journal/day4.md): 休息
- [2024.1.12](./week11/journal/day5.md): 休息
- [2024.1.13](./week11/journal/day6.md): 和双胞胎出去玩
- [2024.1.14](./week11/journal/day7.md): 休息
