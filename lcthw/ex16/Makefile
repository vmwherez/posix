CFLAGS=-Wall -g
.SILENT: read

# having to use `y` and `p` to yank and paste in vim on iSH, which is fine

all:	clean
	mkdir build
	cc ex*.c -o ./build/ex 

clean:
	rm -fr build

run: 
	./build/ex*
	echo "read the man pages, make read"

read: 
	man 3 assert
	echo ""
	man 3 free # moving between Alpine (linux)  and Darwin (BSD) we get different manpages. Cool. 
	man 3 malloc
	
