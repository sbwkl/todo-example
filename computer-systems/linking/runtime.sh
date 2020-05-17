gcc -DRUNTIME -shared -fpic -o target/mymalloc.so mymalloc.c  -ldl
gcc -o target/intr int.c
LD_PRELOAD="./target/mymalloc.so" target/intr
