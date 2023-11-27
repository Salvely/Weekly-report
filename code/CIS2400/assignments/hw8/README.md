# Notes for HW8

## Instructions

- LC4 Object Files -> ASCII Text Files

## Input Object File Format

### 5 sections

- **Code**: 3-word header (xCADE, \<address\>, \<n\>), n-word body comprising the instructions.
- **Data**: 3-word header (xDADA, \<address\>, \<n\>), n-word body comprising the initial data values.
- **Symbol**: 3-word header (xC3B7, \<address\>, \<n\>), n-character body comprising the symbol string. Note, each character in the file is 1 byte, not 2. There is no null terminator. Each symbol is its own section.
- **File name**: 2-word header (xF17E, \<n\>), n-character body comprising the filename string. Note, each character in the file is 1 byte, not 2. There is no null terminator. Each file name is its own section.
- **Line number**: 4-word header (x715E, \<addr\>, \<line\>, \<file-index\>), no body. File-index is the index of the file in the list of file name sections. So if your code comes from two C files, your line number directives should be attached to file numbers 0 or 1.

### section format

- Each section starts with a fixed size header and may have a body trailing it that would be of some variable length.
- a word is 16-bits (2 bytes) and a character is 8-bits (1-byte).

## Output File format

- list the non-zero contents of LC4 memory after all of the object files have been loaded starting from address 0
- listing the address as a 4 bit hex value followed by the contents of that memory location also as a 4 bit hex value.
- For memory locations in code section with non-zero entries you must not only print out the memory contents but also decode the corresponding instruction.

```asm
2020 : FADE
0020 : 9A0A -> CONST R5, #10
```

## Code Structure

```bash
./disas output_filename first.obj second.obj third.obj
```

## Todos

- [x] 完成 Makefile编写
- [x] 完成`disas.c`中的main基本框架
- [x] 在`loader.c`中完成object files的导入，每个指令都是16位，导入一个数组中
- [x] 在`decode.c`中，对照指令手册，完成每条指令的`decode`和`print`，并且将其输出导入到文件中
- [x] 测试输出
