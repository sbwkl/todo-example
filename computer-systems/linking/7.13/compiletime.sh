gcc -DCOMPILETIME -c mymalloc.c -o target/mymalloc.o
gcc -I. -o target/intc int.c target/mymalloc.o
target/intc
