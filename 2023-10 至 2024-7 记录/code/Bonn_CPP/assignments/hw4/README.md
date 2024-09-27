# Bonn Modern C++ Homework 4

## 要求

- [x] 提供一个`homework_4.h`的头文件
- [x] 设计一个自己的`vector`
- [x] 针对自己的`vector`，设计一套`algorithms`，不用`iterator`

## `my vector`

- [x] 使用`template`，设计一个`ipb::named_vector<T>`
- [x] `vector()`获取`vector`的`data`域
- [x] `name()`获取`vector`的`name`域
- [x] 头文件为`homework_4.h`
- [x] `size()`获取`data`域的大小+`name`域的大小
- [x] 如果`data`域或者`name`域为空，`empty()`返回`true`
- [x] 还需要提供`reserve(), resize(), capacity()`等函数

### Member Functions

- [x] vector()
- [x] name()
- [x] size()
- [x] capacity()
- [x] resize()
- [x] empty()
- [x] reserve()

## `algorithms`

- [x] 实现一个`ipb::algorithms`，只用到`ipb::named_vector<T>`数据结构。
- [x] 要生成`ipb_algorithm`库
- [x] 所有实现都在`algorithms`库下
- [x] `accumulate()`
- [x] `count()`
- [x] `all_even()`
- [x] `clamp()`
- [x] `fill()`
- [x] `find()`
- [x] `print()`
- [x] `toupper()`
- [x] `sort()`
- [x] `rotate()`
- [x] `reverse()`
