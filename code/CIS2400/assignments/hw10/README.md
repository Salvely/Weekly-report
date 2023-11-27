# HW 10 & 11: J compiler

## Introduction

- J Language -> LC4 Assembly
- the executable should be named jc, call `./jc source.j` to produce source.asm

## The J Language Overview

### Token Structure

- There are no parentheses or square brackets or curly braces
- just tokens and comments in J
- it reads tokens sequentially from a source file and generate the corresponding assembly for each token as you read it.

### Operands

- 16 bits

### Literals

- decimal: start with `-` sign
- hex: start with `0x` sign
- decimal: 16 bit
- hex: at most 16 bits

### Arithmetic Operations

- - / + / \* / \ / %

### Comparison Operators

- lt, le, eq, ge, gt

### Logical Operations

- and or not

### Stack Operations

- drop, dup, swap, rot
- argN copies an entry from the corresponding argument location in memory and pushes that argument’s value onto the top of the stack.

### If Statements

- `if <block A> else <block B> endif`
- use **CMPR and BR instructions**
- generate unique labels: use a label counter
- for nested if statement:
  - Use recursion.
    - If an IF token is identified, generate the ASM necessary for the start of this IF and then recursively call a function to generate the body until the corresponding ELSE and/or ENDIF tokens are found.
  - Maintain some data structure that supports LIFO (e.g. a Stack or Deque data structure) to keep track how “nested” the compiler is when handling tokens.
    - When you see an IF token, push data onto the structure and when your compiler sees an ENDIF token, pop data. What exact data you store and data structure you use is up to you. Do keep in mind that the Stack being referred to in this hint is a data structure and separate from the stack in memory used to keep track of variables and used in J.

### While Loops

- `while <block> endwhile`

### Comments

- start with `;`

### Functions

## Steps

- [ ] Token Reading
- [ ] ASM generation for literals, arithmetic operations and bitwise operations
- [ ] Function Calls
- [ ] Function Definitions & Returns
- [ ] While loops
- [ ] If statements
- [ ] Comparisons
- [ ] Stack operations (dup, rot, argN, etc)

### Suggested Ordering

- `next_token()`
- `token.c`: `next_token()` and other helper functions
- After you do, you should create a `jc.c` file with a main function that can be compiled into an executable `jc` and a `makefile` that can compile `jc.c` into `jc` and `token.c` into `token.o`.
- you can implement the optional function specified in token.h called print_token to be used for debugging your code locally and have your main function in jc.c open a file, read it with next_token and then print out the token with print_token.
- You should be able to compile your code into the executable called jc and run it like shown below:

```bash
$ ./jc source.j
```

Doing this should produce a new file called source.asm if source.j contains an acceptable j program, otherwise some helpful error messages should be printed instead. You should modify jc.c’s main function to start supporting this.

- The way the compiler proceeds is that it repeatedly reads tokens from the file and for each token it generates the requisite assembly. You can look at what the LCC compiler does with your C files for inspiration. Here is the pseudo code for body of the compiler – note how short it is, at least conceptually.

```C++
while next_token():
  generate_asm()
```

- implement the instructions incrementally

### Error Handling

- handle the malformed j program

### Code Structure

- Parsing
- Generating the ASM

### Extra

- Prime.j
- Hanoi
