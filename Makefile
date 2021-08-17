CC=g++

build:
	$(CC) -o downloadapod main.cpp -lcurl

run:
	$(CC) -o downloadapod main.cpp -lcurl
	./downloadapod

install:
	make build
	cp downloadapod /usr/bin

uninstall:
	rm /usr/bin/downloadapod

clean:
	-rm downloadapod
	-rm apod.txt
	-rm config.txt
