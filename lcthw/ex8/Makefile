CFLAGS=-Wall -g
.SILENT: fun

all:    clean
	
	mkdir build
	cc ex*.c -o ./build/ex1 

clean:
	rm -fr build

run: 
	./build/ex* 

test: 
	# lsof -f 
	echo ""
	./build/ex* one
	./build/ex* one two
	./build/ex* one two three

