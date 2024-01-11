CFLAGS=-Wall -g
.SILENT: test

all:	clean
	mkdir build
	cc ex*.c -o ./build/ex 

clean:
	rm -fr build

run: 
	./build/ex*

test:   all
	echo "Create the database:"
	./build/ex* db.dat c  
	echo "Add entry to the database:"
	./build/ex* db.dat s 1 zed zed@zedshaw.com
	./build/ex* db.dat s 2 bob bob@acme.net
	echo "List entries:"
	./build/ex* db.dat l
	

