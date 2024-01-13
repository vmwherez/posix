default: build

build: clean
	mkdir build	
	gcc -Wall -o ./build/curl main.c util.c -l curl 

clean:
	rm -rf ./build 

test: 	build
	./build/curl https://freegeoip.app/json/ 
