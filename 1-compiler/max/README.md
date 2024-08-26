```sh
gcc -S max.c

gcc -S max.c -o max_0.s
gcc -O1 -S max.c -o max_1.s
gcc -O2 -S max.c -o max_2.s
gcc -O3 -S max.c -o max_3.s
```