```sh
# compile
gcc -o hello hello.c

# disassemble
otool -tV hello

# compile with optimization (O0, O1, O2, O3)
gcc -O0 -o hello hello.c
gcc -O1 -o hello hello.c
# Please note that clang-based compiler (e.g. X-code on Mac OS X) only supports level 1 (-O1) optimization.
gcc -O2 -o hello hello.c
gcc -O3 -o hello hello.c

# compile a program with immediate assembly result
gcc -S hello.c -o hello_0.s
gcc -O1 -S hello.c -o hello_1.s
```

## O0
```asm
hello:
(__TEXT,__text) section
_main:
0000000100003f5c        sub     sp, sp, #0x20
0000000100003f60        stp     x29, x30, [sp, #0x10]
0000000100003f64        add     x29, sp, #0x10
0000000100003f68        stur    w0, [x29, #-0x4]
0000000100003f6c        str     x1, [sp]
0000000100003f70        adrp    x0, 0 ; 0x100003000
0000000100003f74        add     x0, x0, #0xf98 ; literal pool for: "Hello, World\n"
0000000100003f78        bl      0x100003f8c ; symbol stub for: _printf
0000000100003f7c        mov     w0, #0x0
0000000100003f80        ldp     x29, x30, [sp, #0x10]
0000000100003f84        add     sp, sp, #0x20
0000000100003f88        ret
```

## O1
```asm
hello:
(__TEXT,__text) section
_main:
0000000100003f6c        stp     x29, x30, [sp, #-0x10]!
0000000100003f70        mov     x29, sp
0000000100003f74        adrp    x0, 0 ; 0x100003000
0000000100003f78        add     x0, x0, #0xf98 ; literal pool for: "Hello, World"
0000000100003f7c        bl      0x100003f8c ; symbol stub for: _puts
0000000100003f80        mov     w0, #0x0
0000000100003f84        ldp     x29, x30, [sp], #0x10
0000000100003f88        ret
```