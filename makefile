


client: main/client.cpp
	g++ main/client.cpp -o client -I "C:\Dev\SDL\x86_64-w64-mingw32\include" -L "C:\Dev\SDL\x86_64-w64-mingw32\lib" -lSDL3

server: main/server.cpp
	g++ main/server.cpp -o server