#include "player.h"
#include <mutex>

using namespace ClientTools;

std::string PlayerImage = "Images/player.png";
std::string FoodImage = "Images/food.png";

SDL_FRect* Entity::GetRectangle(){
    std::lock_guard<std::mutex> lock(entitylock);
    rectangle->x = x - size;
    rectangle->y = y - size;

    rectangle->w = size;
    rectangle->h = size;

    return rectangle;
}

SDL_Texture* Entity::GetTexture(SDL_Renderer *renderer){
    return nullptr;
}

void Entity::UpdateEntity(int x, int y, int size){
    std::lock_guard<std::mutex> lock(entitylock);
    this->x = x;
    this->y = y;
    this->size = size;
}