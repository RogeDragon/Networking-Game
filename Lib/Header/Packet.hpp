#pragma once
#include <cstdint>
#include <string>

#define ADDRESS_SIZE 15

struct ReceivedPacket
{
    int8_t X;
    int8_t Y;
    char IPAddress[ADDRESS_SIZE] ;
};

struct SentPacket 
{
    int16_t X;
    int16_t Y;
    uint16_t Size;
    uint32_t Colour;
};
