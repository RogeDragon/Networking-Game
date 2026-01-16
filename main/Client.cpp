
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <cstdint>
#include <iostream>

#include <vector>
#include <array>

#include <thread>

using coordinate = std::array <int8_t, 2 >;
using setting =  const int;

setting WIDTH = 800;
setting HEIGHT = 600;
setting MAX = 6535;
setting PORT = 61611;

volatile bool running = true;

struct player {
    player() : size{100}, location{0, 0} {};

    player(const player&) = delete;
    player& operator=(const player&) = delete;

    void SetLocation(coordinate TargetLocation) {
        this->location = TargetLocation;
    }

    void SetSize(int size) {
        this->size = size;
    }

    private: 
    int8_t size = 10;
    int8_t playerID;
    coordinate location = {0, 0};
};

int main(int argc, char* argv[]){ //SDL requires you have the followingfunction signature
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    SDL_Window *window = SDL_CreateWindow("Test Project!", WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    
    SDL_Event event;

    while (running){
        while (SDL_PollEvent(&event)){
            if (event.type ==  SDL_EVENT_QUIT) {
                running = false;
            }
        }

        //std::thread collection(CollectPackets); 

        //get packet data

        //update the players

        //send off the packet for location

        //render players

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}