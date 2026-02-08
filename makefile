
VERISON = c++20
BUILDLOC = Builds
SRCLOC = Main

client: main/client.cpp
	g++ -std=$(VERISON) $(SRCLOC)/client.cpp -o $(BUILDLOC)/client -I "C:\Dev\SDL\x86_64-w64-mingw32\include" -L "C:\Dev\SDL\x86_64-w64-mingw32\lib" -lSDL3

server: main/server.cpp
	g++ -std=$(VERISON) $(SRCLOC)/server.cpp -o $(BUILDLOC)/server