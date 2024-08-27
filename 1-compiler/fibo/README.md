```sh
gcc -o fibo_0 fibo.c
time ./fibo_0
# avg 10.97s user 0.01s system 96% cpu 11.419 total

gcc -O1 -o fibo_1 fibo.c
time ./fibo_1
# avg  6.08s user 0.01s system 95% cpu 6.388 total

gcc -O2 -o fibo_2 fibo.c
time ./fibo_2

gcc -S fibo.c

gcc -S fibo.c -o fibo_0.s
gcc -O1 -S fibo.c -o fibo_1.s
gcc -O2 -S fibo.c -o fibo_2.s
gcc -O3 -S fibo.c -o fibo_3.s
```