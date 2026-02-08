
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>
#include <atomic>

class Game {
    private:
    std::atomic<bool> running{true};

    using setting =  const int;
    setting WIDTH = 800;
    setting HEIGHT = 600;

    SDL_Window *window;
    SDL_Renderer *renderer;

    public:
    Game(): running(true) {SetupGame();}
    Game(const Game& other) = delete;
    Game& operator=(const Game&) = delete; 

    void UpdateGame() {
        SDL_Event event;
        while (running.load()){
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
    }
    void SetupGame(){
        SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

        window = SDL_CreateWindow("Test Project!", WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
        renderer = SDL_CreateRenderer(window, NULL);

        std::cout << "The Game Has Been Set Up!" << std::endl;
    }
};

int main(int argc, char* argv[]){ //SDL requires you have the followingfunction signature
    Game game = Game();
    game.UpdateGame();

    return 0;
}