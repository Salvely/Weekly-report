# Notes for homework 6

## A list of files

1. `Wordle.c` main program for the Wordle game
2. `dict.h` a list of words
3. `alpha_sprites.h` patterns used to draw the letters on the video display
4. `lc4libc.h` functions available from `libc.asm`
5. `libc.asm` some utility routines for accessing the operating system
6. `os.asm` operating systems containing traps that perform various I/O operations
7. `WordleScript.txt`

## Part 1: Operating System Traps

user program -> trap -> os utilities, implements the traps in os part.

- `TRAP_PUTS` outputs a null terminated string to the ASCII display. When the trap is called, R0 should contain the address of the first character in the string. Last character in the string should be `\0`.

- `TRAP_DRAW_SQUARE` draws a solid square block in the display.
  - `R0` the starting column in the video memory(0-127)
  - `R1` the starting row in video memory(0-123)
  - `R2` width and height of the block
  - `R3` color that should be draw into the designated area
  - extra: check for boundaries, row[0-127],col[0-123]

    ```C++
    // check boundary function
    void check_boundary(int& r0, int& r1) {
        if(r0 < 0)
            r0 = 0;
        else if(r0 > 127)
            r0 = 127;
        
        if(r1 < 0)
            r1 = 0;
        else if(r1 > 123)
            r1 = 123;        
    }

    // C++-pseudo code for this task
    void trap_draw_square(int r0, int r1, int r2, int r3) {
        // check if the starting point is in the right boundaries
        check_boundary(r0,r1);
        int r5 = r1;
        int r6 = r0; // 迫不得已

        int r0 = r0 + r2;
        int r1 = r1 + r2;

        int temp = r6; // 迫不得已(开发temp时借用一下r2)

        check_boundary(r0,r1);
    
        for(; r5 < r1; r5++) {
            
            int r6 = temp; // 迫不得已(开发temp时借用一下r2)

            for(; r6 < r0; r6++) {
                // where = 0xc000 + (r5 * num_of_cols) + r6
                printf("%d", r3);
            }
            printf("\n");
        }
    }
    ```

## Part 2: C Game Code
