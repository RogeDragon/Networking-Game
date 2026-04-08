#pragma once
#include <string>
#include <cstdint>
#include <mutex>
#include "MessageQueue.hpp"
#include "Packet.hpp"

#include <iostream>
#include <cmath>

class Player
{
    public:
    std::string IPAddress;

    private:
    int16_t X;
    int16_t Y;
    uint16_t Size;
    uint32_t Colour;
    uint32_t Speed;

    LinkedList<ReceivedPacket> MessageQueue; // no mutexes need for this since it is thread safe

    public:
    Player(std::string IPAddress);

    void InsertPacket(ReceivedPacket &InsertedPacket);
    void Update(); // this will pop the node

    uint16_t GetDistance(Player &other);
    bool CalculateCollisons(Player &other);
    SentPacket Serialise();
    void DisplayPlayerInfo();
};

