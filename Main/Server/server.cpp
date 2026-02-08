#include <random>
#include <cstdint>
#include <iostream>

#include <thread>
#include "game"

int MapHeight = 1000;
int MapWidth = 1000;

unsigned short MaxPlayers = 10;
unsigned short CurrentPlayers = 0;

volatile bool running = true;

using coordinate = std::array < int, 2 >;

int8_t generate_player_id(){
  static int8_t PlayerID = 0;
  return PlayerID++;
}

void run_debugger(){
    while (running){
      std::string debug; 
      std::cin >> debug;

      if (debug == "exit") {running = false; break;}
      else if (debug == "player count") {
        std::cout << "The number of players are: " << CurrentPlayers << std::endl; 
      }
    }
}

int main() {
  std::thread debugging_thread(run_debugger);

  while (running){
    // wait for connections from players

    // run a seperate thread per player

  }

  debugging_thread.join();

  return 0;
}