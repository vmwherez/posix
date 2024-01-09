CFLAGS=-Wall -g
.SILENT: fun
# https://stackoverflow.com/questions/30450197/how-to-efficiently-backtrace-segment-fault-using-lldb
# -O0 minimal optimizations
# -g debugging symbols enabled
# breakpoints vs watchpoints 

all:	clean
	mkdir build
	cc ex*.c -O0 -g  ./build/ex 

clean:
	rm -fr build

run: 
	./build/ex*

fun: 
	man make 
	echo ""

