CFLAGS=-Wall -g
.SILENT: fun

all:	clean
	mkdir build
	cc ex*.c -o ./build/ex 

clean:
	rm -fr build

run: 
	./build/ex*

gdb: 
	gdb ./build/ex*	 
	echo ""
	
