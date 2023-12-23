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
    CC := /usr/bin/clang
    CFLAGS := -fsanitize=address -std=c11 -Wall
endif

# Target and sources
TARGET := ./build/ex4
SOURCES := example_UseAfterFree.c 


all:   	clean build_dir $(TARGET)
	
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^ #tab, not spaces!
	# clang -fsanitize=address -g memory-leak.c -o ./build/ex4 

build_dir: 
	mkdir -p build

clean:
	rm -fr build

run: 
	 ASAN_SYMBOLIZER_PATH=/usr/local/bin/llvm-symbolizer ./build/ex4

fun: 
	# lsof -f
	# I have GEF working on iSH and I'm waiting for llvm to compile
	# so I thought it would be cool to detect the OS 
	echo $(UNAME_S)
	echo ""
	echo "This exercise is getting into memory safety straight away."
	echo ""
	echo "Note: 'use after free' is not exactly the same thing as a memory leak. "
	

