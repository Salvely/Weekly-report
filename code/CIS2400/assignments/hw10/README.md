# HW 10 & 11: J compiler

## The J Language Overview

### Operands

- 16 bits

### Literals

- decimal: start with optional `-` sign
- hex: start with `0x` sign
- decimal: 16 bit
- hex: at most 16 bits

### Arithmetic Operations

- - + * / %

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

### Functions

## Steps

- [ ] ASM generation for **literals, arithmetic operations and bitwise operations**
- [ ] Comparisons
- [ ] Stack operations (dup, rot, argN, etc)
- [ ] If statements
- [ ] While loops
- [ ] Function Calls
- [ ] Function Definitions & Returns

### Error Handling

- handle the malformed j program

### Extra

- Prime.j
- Hanoi
