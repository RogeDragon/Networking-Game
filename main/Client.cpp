
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <iostream>

const int WIDTH = 800;
const int HEIGHT = 600;

int main(int argc, char* argv[]){ //SDL requires you have the followingfunction signature
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    SDL_Window *window = SDL_CreateWindow("Test Project!", WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

    bool running = true;
    SDL_Event event;

    while (running){
        while (SDL_PollEvent(&event)){
            if (event.type ==  SDL_EVENT_QUIT) {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}