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

## Week 12: 2024.1.15-2024.1.21

> 养成规律作息，每天 11 点钟睡觉，早上 6 点起床

### 主要任务

- [CMU 15-213](./code/15213/)

### Logs

- [2024.1.15](./week12/journal/day1.md): 休息
- [2024.1.16](./week12/journal/day2.md): 摆烂
- [2024.1.17](./week12/journal/day3.md): [IPC](./code/system_prog_exercise/IPC/)复习，[网络编程基础](./code/system_prog_exercise/Network/)复习
- [2024.1.18](./week12/journal/day4.md): libcurl 安装 + 基础用法学习, 多线程基础复习
- [2024.1.19](./week12/journal/day5.md): [CMU 15-213 & CSAPP](./code/15213/) Chapter 1,2 学习
- [2024.1.20](./week12/journal/day6.md): [CMU 15-213 & CSAPP](./code/15213/) Chapter 2 学习
- [2024.1.21](./week12/journal/day7.md): [CMU 15-213 & CSAPP](./code/15213/) Chapter 3 汇编学习，这几个星期效率真是低下

## Week 13: 2024.1.22-2024.1.28

### 主要任务

> 大部分时间在摆烂。

### Logs

- [2024.1.22](./week13/journal/day1.md): Machine Level Programming Lecture 学完
- [2024.1.23](./week13/journal/day2.md): 摆烂
- [2024.1.24](./week13/journal/day3.md): 摆烂
- [2024.1.25](./week13/journal/day4.md): 摆烂
- [2024.1.26](./week13/journal/day5.md): 摆烂
- [2024.1.27](./week13/journal/day6.md): 摆烂
- [2024.1.28](./week13/journal/day7.md): 去医院看病

## Week 14: 2024.1.29-2024.2.4

### 主要任务

- [CSAPP 阅读及 15-213 课程学习](./code/15213/)

### Logs

- [2024.1.29](./week14/journal/day1.md): 医院做核磁共振检查膝盖，排队 3 小时（麻了，以后不能自己在家里健身了，不然搞出问题来了）
- [2024.1.30](./week14/journal/day2.md): 又去医院看了一天
- [2024.1.31](./week14/journal/day3.md): Data Representations 复习
- [2024.2.1](./week14/journal/day4.md): Mulplication & Division 部分学习 & Floating Point 部分学习
- [2024.2.2](./week14/journal/day5.md): Data Representation 一章阅读完成，习题基本完成，Data lab 完成一半
- [2024.2.3](./week14/journal/day6.md): Data lab 完成几个题
- [2023.2.4](./week14/journal/day7.md): [Data lab](./code/15213/lab/lab1-datalab/)所有习题完成，Data lab recitation video 观看，Data lab 总结写了一半

## Week 15: 2024.2.5-2024.2.11

### 主要任务

- 15213: Data lab 结束，Machine Programming 复习

### Logs

- [2024.2.5](./week15/journal/day1.md): [分治法](https://www.cs.cmu.edu/afs/cs/academic/class/15213-f23/www/recitations/rec01_solutions.pdf)还没有完全搞清楚, Data lab 总结写完
- [2024.2.6](./week15/journal/day2.md): CSAPP Chapter 3 看了
- [2024.2.7](./week15/journal/day3.md): Chapter 3 数据运算指令和控制阅读，来例假了，休息一下
- [2024.2.8](./week15/journal/day4.md): Chapter 3 控制语句学习
- [2024.2.9](./week15/journal/day5.md): 除夕，休息一下
- [2024.2.10](./week15/journal/day6.md): Chapter 3 for,while 循环语句 & Switch 语句 & Procedure 学习
- [2024.2.11](./week15/journal/day7.md): switch 语句复习，Procedure 继续学习，数组 & 内存布局学习

## Week 16: 2024.2.12-2024.2.18

### 主要任务

- 过年，顺带学习一部分 CSAPP

### Logs

- 2024.2.12-2024.2.14: 在老家过年，复习了一部分 Machine Programming，一直到 buffer overflow 和栈随机化处，感觉 Procedure 调用部分讲的不是太清楚
- [2024.2.15](./week16/journal/day4.md): 家里来亲戚了，休息
- [2024.2.16](./week16/journal/day5.md): 去东湖爬山，休息
- [2024.2.17](./week16/journal/day6.md): 摆烂休息
- [2024.2.18](./week16/journal/day7.md): 摆烂休息

## Week 17: 2024.2.19-2024.2.25

> 这星期过后，进化成一个不一样的自己！

### 主要任务

- CSAPP + [15213](./code/15213/)学习

### Logs

- [2024.2.19](./week17/journal/day1.md): Procedure 调用过程复习，栈防护和攻击手段学习，变长栈帧汇编指令学习，浮点指令学习
- [2024.2.20](./week17/journal/day2.md): Machine Programming Basics & Control & Procedure Slides 复习，并完成[Basics Activity](./code/15213/Ch3%20Machine%20Level%20Programming/gdb-and-assembly/README.md),[Control Activity](./code/15213/Ch3%20Machine%20Level%20Programming/machine-control/README.md)完成了一半
- [2024.2.21](./week17/journal/day3.md): Procedure & Data & Advanced Topics Slides 阅读完，粗浅的学习了一下 return-oriented programmming attacks，[Design & Debugging 方法论](https://www.cs.cmu.edu/afs/cs/academic/class/15213-f23/www/lectures/08-design-debugging.pdf)的 Slides 粗浅的阅读了一下，[GDB & Valgrind 使用说明](https://www.cs.cmu.edu/afs/cs/academic/class/15213-f23/www/bootcamps/lab2_slides.pdf)粗浅的看了一下，[Control](./code/15213/Ch3%20Machine%20Level%20Programming/machine-control/README.md) & [Procedure](./code/15213/Ch3%20Machine%20Level%20Programming/machine-procedures/README.md) Activity 全部完成
- [2024.2.22](./week17/journal/day4.md): [Machine Programming: Data Activity](../../code/15213/Ch3%20Machine%20Level%20Programming/machine-data/README.md) 做完，[Machine Advanced Activity](../../code/15213/Ch3%20Machine%20Level%20Programming/machine-advanced/README.md)完成了一半，[Bomb lab recitation](../../code/15213/Ch3%20Machine%20Level%20Programming/rec4/README.md)除了第 4 个还没完成以外其他全部完成
- [2024.2.23](./week17/journal/day5.md): [gdb lab](../../code/15213/Ch3%20Machine%20Level%20Programming/lab2_handout/README.md)完成，[attack recitation](../../code/15213/Ch3%20Machine%20Level%20Programming/rec5/README.md)完成，复习 & 实战了几种 buffer overflow 攻击方式，Bomb lab phase 1-4 完成，5 & 6 进行了反汇编但是还没看
- [2024.2.24](./week17/journal/day6.md): Bomb lab phase 5 完成
- [2024.2.25](./week17/journal/day7.md): Bomb lab phase 6 彻底弄清楚，secret phase & func 7 做了下反汇编，今天很爽了

## Week 18: 2024.2.26-2024.3.3

> 重新出发，继续努力，加油！

### 主要任务

- CSAPP + [15213](./code/15213/)学习

### Logs

- [2024.2.26](./week18/journal/day1.md): Bomb lab 完全解决，Attack lab phase 1 完成，phase 2 还没有完全 debug 完成
- [2024.2.27](./week18/journal/day2.md): Attack lab Phase 2-3 完成，phase 4 分析了一半
- [2024.2.28](./week18/journal/day3.md): Attack lab phase 4 完成，phase 5 完成
- [2024.2.29](./week18/journal/day4.md): Attack lab 整理到博客，CSAPP Chapter 1 读书笔记更新完成，第二章完成了一半，Chapter 3 的 Activity 更新完成
- [2024.3.1](./week18/journal/day5.md): 今天休息一天
- [2024.3.2](./week18/journal/day6.md): 今天去东湖梨园跑步 6km + 骑行 7 km + 从东湖梨园骑回家用时 1 小时 48 分（今儿晚上陶喆 Soul Power II 武汉第一站 day 1 喔）
- [2024.3.3](./week18/journal/day7.md): 今天去东湖梨园跑步 6km + 步行 6 km，不骑行回家了，坐地铁回家（今儿晚上陶喆 Soul Power II 武汉第一站 day 2 喔）

## Week 19: 2024.3.4-2024.3.10

### 主要任务

- CSAPP 阅读学习

### Logs

- [2024.3.4](./week19/journal/day1.md): 休息一天
- [2024.3.5](./week19/journal/day2.md): Y86_64 指令集学习，跑步 5.3km，骑行 1.22km，步行 1.25km
- [2024.3.6](./week19/journal/day3.md): Y86_64 指令分析完成，顺序结构的 Y86_64 处理器设计时钟信号设计完成
- [2024.3.7](./week19/journal/day4.md): 东湖骑车游玩
- [2024.3.8](./week19/journal/day5.md): 看了《第二十条》
- [2024.3.9](./week19/journal/day6.md): Y86_64 流水线结构处理器设计入门
- [2024.3.10](./week19/journal/day7.md): CSAPP Chapter 4 流水线处理器设计 & Chapter 6 开头阅读

## Week 20: 2024.3.11-2024.3.17

- CSAPP Chapter 4 阅读学习

### Logs

- [2024.3.11](./week20/journal/day1.md): 看了《周处除三害》，其他时间摆烂
- [2024.3.12](./week20/journal/day2.md): 九曲阑干 CSAPP 第 4 章 & 第 6 章学习
- [2024.3.13](./week20/journal/day3.md): 摆烂的一天
- [2024.3.14](./week20/journal/day4.md): 摆烂的第二天
- [2024.3.15](./week20/journal/day5.md): Y86_64 顺序结构处理器设计
- 2024.3.16 - 2024.3.17: 摆烂两天

## Week 21: 2024.3.18-2024.3.24

### 主要任务

- CSAPP Chapter 4 阅读完成

### Logs

- [2024.3.18](./week21/journal/day1.md): 摆烂
- [2024.3.19](./week21/journal/day2.md): Y86_64 流水线结构处理器详细设计学习
- 2024.3.20 - 2024.3.21: CSAPP 第四章学习了流水线的控制逻辑 & 特殊条件的探测 & 流水线的控制机制 & 控制条件的组合，东湖游玩
- [2024.3.22](./week21/journal/day5.md): CSAPP Chapter 4 阅读完成
- [2024.3.23](./week21/journal/day6.md): Chapater 4 HCL 代码阅读，其他时间摆烂
- [2024.3.24](./week21/journal/day7.md): 去梦时代逛街了

## Week 22: 2024.3.25-2024.3.31

### 主要任务

- x86_64 Procedure 调用复习，Virtual Memory 部分学习，Nand2Tetris Project 1-3 完成
- 由于生病效率不高

### Logs

- [2024.3.25](./week22/journal/day1.md): 摆烂
- [2024.3.26](./week22/journal/day2.md): 去东湖骑车了，architecture lab 实现了一部分
- [2024.3.27](./week22/journal/day3.md): x86-64 procedure 调用过程复习，Cache 的出现及其组成学习，异常控制流学习，Process 学完了
- [2024.3.28](./week22/journal/day4.md): CSE351 Virtual Memory 部分学习
- [2024.3.29](./week22/journal/day5.md): 省人民医院看病，Nand2Tetris Project 1 完成
- [2024.3.30](./week22/journal/day6.md): Nand2Tetris Project 2,3 完成，其他时间生病休息
- 2024.3.31: 生病休息

## Week 23: 2024.4.1-2024.4.7

### 主要任务

- Nand2Tetris Project 4 - 6 完成

### Logs

- 2024.4.1-2024.4.2: 搭建了博客
- [2024.4.3](./week23/journal/day3.md): Nand2Tetris Project 4 完成
- [2024.4.4](./week23/journal/day4.md): Nand2Tetris Project 5 完成
- 2024.4.5-2024.4.6：清明节休息
- 2024.4.7: Nand2Tetris Project 6 完成

## Week 24: 2024.4.8-2024.4.14

### 主要任务

- Nand2Tetris

### Logs

- [2024.4.8](./week24/journal/day1.md): Nand2Tetris Proejct 7 框架搭建完成 + Project 8 部分视频观看
- [2024.4.9](./week24/journal/day2.md): Chapter 8 阅读完成+Project 8 视频看完+Project 8 框架搭完
- 2024.4.10 - [2024.4.13](./week24/journal/day6.md): Projct 7-8 完成

## Week 25 - Week 27

- 2024.4.14 - 2024.4.27: Nand2Tetris Project 9-12 完成(完结撒花！)
- 2024.4.28 - 2024.5.5: 五一劳动节休息，中途复习数字逻辑电路

## Week 28: 2024.5.6-2024.5.12

### 主要任务

### Logs

- [2024.5.6](./week28/journal/day1.md): DDCA 第三章内容总结完成，Vivado 安装+Vscode 配置，项目仿真成功，各触发器的特性方程和其之间的转换总结，第三章习题完成一部分
- [2024.5.7](./week28/journal/day2.md): Logisim 实现一些基础触发器，异步时序逻辑电路`preset & clear`机制学习，FSM 设计复习，DFA 学习
- [2024.5.8](./week28/journal/day3.md): FSM 相关内容复习，总体来说效率不高
- [2024.5.9](./week28/journal/day4.md): 今天是我的生日！生日快乐！
