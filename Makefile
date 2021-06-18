CC=g++

build_linux:
	$(CC) -o downloadapod main.cpp -lcurl

run_linux:
	$(CC) -o downloadapod main.cpp -lcurl
	./downloadapod

build_windows:
	x86_64-w64-mingw32-g++ -o downloadapod.exe main.cpp -static-libgcc -static-libstdc++ -lcurl

clean:
	rm downloadapod
	rm apod.txt
