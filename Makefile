CC=g++

build_linux:
	$(CC) -o downloadapod main.cpp -lcurl

run_linux:
	$(CC) -o downloadapod main.cpp -lcurl
	./downloadapod

clean:
	rm downloadapod
	rm apod.txt
