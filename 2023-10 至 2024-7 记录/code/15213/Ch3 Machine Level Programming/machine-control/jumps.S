        // Demonstrate the syntax and encoding of jump instructions.
        .text
        .globl jump_insns
jump_insns:
        jmp     destination
        jo      destination
        jno     destination
        jb      destination
        jc      destination
        jnae    destination
        jae     destination
        jnc     destination
        jnb     destination
        je      destination
        jz      destination
        jne     destination
        jnz     destination
        jbe     destination
        jna     destination
        ja      destination
        jnbe    destination
        js      destination
        jns     destination
        jl      destination
        jnge    destination
        jge     destination
        jnl     destination
        jle     destination
        jng     destination
        jg      destination
        jnle    destination

        .skip   98

destination:
        ret
