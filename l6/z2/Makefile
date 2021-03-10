all: clear
	test ! -d bin/ && mkdir bin
	g++ src/main.cpp -o bin/main

run:
	bin/main

clear:
	rm -Rf bin
