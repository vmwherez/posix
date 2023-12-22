CFLAGS=-Wall -g
.SILENT: fun

all:
	mkdir build
	clang -fsanitize=address -g memory-leak.c -o ./build/ex4 

clean:
	rm -fr build

run: 
	./build/ex4

fun: 
	# lsof -f 
	echo ""
	echo "This exercise is getting into memory leaks straight away."
	echo ""
	

