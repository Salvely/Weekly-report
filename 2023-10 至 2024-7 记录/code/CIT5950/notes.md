# Lecture Notes for CIT5950: System Programming

- [Lecture Notes for CIT5950: System Programming](#lecture-notes-for-cit5950-system-programming)
  - [Process](#process)
  - [Threads](#threads)
  - [Synchronization](#synchronization)
  - [Virtual Memory](#virtual-memory)
  - [Networking](#networking)

## Process

- OS Intro
  - OS: Abstraction Provider
    - What's an OS?
      - Interact with the Hardware
      - Provide an abstraction to the hardware
      - Manages/allocates/protects the hardware resources
    - How user program interact with it?
      - Using `system calls`
      - system callls are provided through an API: such as `POSIX standard API and Windows API`
    - OS Composition
      - File System
      - Network Stack
      - Virtual Memory
      - Process managment
      - etc..
    - System Call Process
      - update the CPU privilage bit: user level -> os level
      - record the return address
      - goes into the trap table in os.asm code
      - goes into the trap subroutine and executes it
      - when trap finished, update the privilage bit: os level -> user level
      - return back to the caller
    - Library calls
      - handled directly by `glibc` without interacting with system calls
        - `glibc` is a shared library, there is some overhead to load it into the program
        - but after loading, it's efficient to interact with it as interacting your own program!
      - Some `glibc` functions indirectly call system calls
        - such as stdio: it keeps a buffer for reading, and calls `read()/write()` in `fread()/fwrite()` underneath
      - directly call system calls: less protable, sometimes less efficient
        - such as `read()` and `write()` every time we want to write a new character into a file
        - it's more efficient to use a buffer to store some of them and write them all at once
  - POSIX I/O
    - POSIX
      - Portable Operating System Interface
      - `open(), read(), write(), close(), lseek()`
    - C stdlib doesn’t provide everything POSIX does
  - Locality
    - It's faster to retrieve data from places next to the last position
    - Stdio
      - Use buffering!
    - Reliability – the buffer needs to be flushed
      - data may lost when power is off
      - completion of a write does not mean the data has actually been written
    - Performance – buffering takes time
      - Copying data into the stdio buffer consumes CPU cycles and memory bandwidth
      - Can potentially slow down high-performance applications, like a web server or database (“zero-copy”)
    - When is buffering faster? Slower?
      - Faster: many small writes or writes a little
      - Slower: large writes
- Process
  - Control Flow
  - Exceptions
  - Processes
  - `fork()`

## Threads

## Synchronization

## Virtual Memory

## Networking
