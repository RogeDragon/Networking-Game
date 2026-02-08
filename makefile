CXX = g++
CXXFLAGS = -std=c++20

build_loc = Builds
client_location = Main\Client
server_location = Main\Server

#If you add more files to this, make sure to add it here
client_code = $(client_location)\client.cpp 
server_code = $(server_location)\server.cpp

#Organising all the 
client_includes = -I "C:\Dev\SDL\x86_64-w64-mingw32\include" -I"C:\Dev\SDL_image\x86_64-w64-mingw32\include"
client_directories = -L "C:\Dev\SDL\x86_64-w64-mingw32\lib" -L "C:\Dev\SDL_image\x86_64-w64-mingw32\lib"
client_libraries = $(client_includes) $(client_directories) -lSDL3 -lSDL3_image

client: $(client_location)\client.cpp
	$(CXX) $(CXXFLAGS) $(client_code) -o $(build_loc)\client $(client_libraries)

server: $(server_location)\server.cpp
	$(CXX) $(CXXFLAGS) $(server_code) -o $(build_loc)\server