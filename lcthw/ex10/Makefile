CFLAGS=-Wall -g
.SILENT: fun

all:	clean
	mkdir build
	cc ex*.c -o ./build/ex 

clean:
	rm -fr build

run: 
	./build/ex* vowel

test: 
	./build/ex* abcdefghijklmnopqrstuvwxyz	
	echo ""
	
