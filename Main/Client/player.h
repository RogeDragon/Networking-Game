#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <thread>
#include <iostream>
#include <mutex>

namespace ClientTools{
    extern std::string PlayerImage;
    extern std::string FoodImage;

    class Entity {
        private:
        int x, y, size;
        std::mutex entitylock;

        SDL_FRect* rectangle;
        SDL_FRect* GetRectangle();

        public:
        Entity(): x{100}, y{100}, size{100} {}
        Entity(const Entity&) = delete;
        Entity& operator=(const Entity&) = delete;

        virtual SDL_Texture* GetTexture(SDL_Renderer *renderer);
        void UpdateEntity(int x, int y, int size = 10);
    };

    class Player: Entity{
    };
}