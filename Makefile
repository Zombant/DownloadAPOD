CC=g++

build:
	$(CC) -o downloadapod main.cpp -lcurl

run:
	$(CC) -o downloadapod main.cpp -lcurl
	./downloadapod

clean:
	rm downloadapod
	rm apod.txt
	rm config.txt
