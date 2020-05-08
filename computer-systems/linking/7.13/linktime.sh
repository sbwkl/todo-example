gcc -DLINKTIME -c mymalloc.c -o target/mymalloc.o
gcc -c int.c -o target/int.o
gcc -Wl,--wrap,malloc -Wl,--wrap,free -o target/intl target/int.o target/mymalloc.o
target/intl
