CFLAGS=-Wall -g
.SILENT: fun

# having to use `y` and `p` to yank and paste in vim on iSH, which is fine
# note, cc worked as compiler but we prob want to use gcc/gdb in linux vs llvm/lldb on mac

all:	clean
	mkdir build
	cc ex*.c -o ./build/ex 

clean:
	rm -fr build

run: 
	./build/ex*

fun: 
	man make 
	echo ""
	
