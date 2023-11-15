# Homework 3 Notes

## General Rules

1. - [x] 需要一个`homework_3.h`的头文件，里面应该包括所有函数的接口

## Image Browser Web Application

> 应该写一个`test program`来进行测试。

### `html_writer` library

#### Requirements

- [x] 实现`html_writer.hpp`中所有函数
- [x] 本质是将`html`文件输出到终端，然后再重定向到文件中
- [x] 需要生成一个`html_writer library`
- [x] 只处理`.jpg`和`.png`后缀的文件，如果有其他后缀名文件，就输出`stderr`
- [x] 使用`fmt`库而不是`iostream`
- [x] 可以使用`C++`提供的`filesystem library`来简化一些操作
- [x] 在调用`AddImage`函数来添加照片时，有如下要求：
  - [x] 如果用户要求，需要高亮照片
  - [x] 照片的名字就是文件名，不要加路径
  - [x] 照片的`score`需要精确到小数点后两位

#### Todo

- [x] 设置`CMAKE`版本，编译器，C++标准，项目的基本配置
- [x] 将`include`目录作为头文件`include`进来
- [x] 设置可执行文件的输出路径为`bin`
- [x] 设置库的输出路径为`lib`
- [x] 将`src`中的`html_writer.cpp`打包成`library`
- [x] 将`api`目录映射到`library`
- [x] `main.cpp`生成目标文件
- [x] 将目标文件链接到`library`

### `image_browser` library

#### Requirements

- [x] 需要生成一个`image_browser library`，其中需要包含所有`api`中的函数
- [x] 第一张照片都必须highlight
- [x] 打印到`stdout`
- [x] 用`xmllint --html test.html > /dev/null`来测试生成的`html`文件是否符合规范(需要先安装)
