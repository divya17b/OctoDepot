CC=g++

hello: src/hello/hello.cpp
	$(CC) src/hello/hello.cpp -o bin/hello

oop_hello:
	$(CC) -c src/oop_hello/oop_hello.cpp -o bin/oop_hello.o
	$(CC) -c -fPIC src/oop_hello/speak/speak.cpp -o bin/shared/speak.o
	$(CC) -shared bin/shared/speak.o -o bin/shared/libspeak.so
	$(CC) bin/oop_hello.o -Lbin/shared -lspeak -o bin/oop_hello

clean:
	find bin -type f -delete
