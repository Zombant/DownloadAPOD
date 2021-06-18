CC=g++

build_linux:
	$(CC) -o downloadapod main.cpp

run_linux:
	$(CC) -o downloadapod main.cpp
	./downloadapod

clean:
	rm downloadapod
