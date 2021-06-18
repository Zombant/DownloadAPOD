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


install_libcurl:
	cp -r libcurl/lib/* /usr/x86_64-w64-mingw32/lib/
	cp -r libcurl/bin/* /usr/x86_64-w64-mingw32/bin/
	cp -r libcurl/include/* /usr/x86_64-w64-mingw32/include/
	cp -r libcurl/bin/libcurl-x64.dll ../..

