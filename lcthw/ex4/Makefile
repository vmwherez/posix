CFLAGS=-Wall -g
.SILENT: fun
# Detect the operating system
UNAME_S := $(shell uname -s)

# Compiler and flags for different operating systems
ifeq ($(UNAME_S),Linux)
    CC := gcc
    CFLAGS := -std=c11 -Wall
endif
ifeq ($(UNAME_S),Darwin)
    CC := clang
    CFLAGS := -std=c11 -Wall
endif

# Target and sources
TARGET := ex4
SOURCES := memory-leak.c


all:   	build_dir $(TARGET)
	
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^ #tab, not spaces!
	# clang -fsanitize=address -g memory-leak.c -o ./build/ex4 

build_dir: 
	mkdir -p build

clean:
	rm -fr build

run: 
	./build/ex4

fun: 
	# lsof -f
	# I have GEF working on iSH and I'm waiting for llvm to compile
	# so I thought it would be cool to detect the OS 
	echo $(UNAME_S)
	echo ""
	echo "This exercise is getting into memory leaks straight away."
	echo ""
	

