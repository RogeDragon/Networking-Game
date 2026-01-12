#include <iostream>
#include <thread>
#include <random>

#include <cmath>

int MapHeight = 1000;
int MapWidth = 1000;

using coordinate = std::array < int, 2 >;

struct Player {

  coordinate GetPosition() const {
    return Position
  }

  int GetSize() const {
    return Size;
  }

  bool CalculateCollisions(const Player& enemy) {
    coordinate EnemyPosition = (enemy.GetPosition());
    int EnemySize = (enemy.GetSize())

    unsigned int distance = ((enemy.GetPosition()[0] - Position[0]) ** 2 )

    if () return true;

    return false;
  }

  private:
  int Size = 100;

  coordinate Position = {MapWidth / 2, MapHeight / 2};
};






unsigned short MaxPlayers = 10;
unsigned short CurrentPlayers = 0;
bool Running = true;

int main() {

  while (Running) {
    if (CurrentPlayers < MaxPlayers) {
      // checking if connected

      // creating a std::thread for the class & detach the thread

    }
  }

  return 0;
}