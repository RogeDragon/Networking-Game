#include "Player.hpp"

Player::Player(std::string IPAddress) : X{0}, Y{0}, Size{100}, Colour{0xFF0000FF}, Speed{10}, IPAddress{IPAddress}
{
    std::cout << "New Player has been created!" << std::endl;
}

void Player::InsertPacket(ReceivedPacket &InsertedPacket)
{
    MessageQueue.PushNode(InsertedPacket);
}

void Player::Update()
{
    ReceivedPacket NewPacket;
    MessageQueue.PopNode(NewPacket);

    if (NewPacket.X > 0) X += Speed;
    else if (NewPacket.X < 0) X -= Speed;

    if (NewPacket.Y > 0) Y += Speed;
    else if (NewPacket.Y < 0) Y -= Speed;
}

uint16_t Player::GetDistance(Player &other)
{
    uint16_t XSquared =  (X - other.X) * (X - other.X);
    uint16_t YSquared =  (Y - other.Y) * (Y - other.Y);

    uint16_t Distance = std::sqrt(XSquared + YSquared);

    return Distance;
}

bool Player::CalculateCollisons(Player &other)
{
    uint16_t Distance = Player::GetDistance(other);
    return Distance < Size || Distance < other.Size;
}

void Player::DisplayPlayerInfo()
{
    std::cout << "The position of the player is: (" << X << ", " << Y << ")" << std::endl;
    std::cout << "The size of the player is: " << Size << std::endl;
    std::cout << "The speed of the player is: " << Speed << std::endl;
}

SentPacket Player::Serialise()
{
    SentPacket SerialisedPlayer;
    SerialisedPlayer.X = X;
    SerialisedPlayer.Y = Y;
    SerialisedPlayer.Colour = Colour;
    SerialisedPlayer.Size = Size;

    return SerialisedPlayer;
}

/*
Just testing the program!

int main()
{
    Player PlayerOne;
    //Creating an Example Packet
    ReceivedPacket PlayerOnePacket;
    PlayerOnePacket.X = 1;
    PlayerOnePacket.Y = 1;

    PlayerOne.InsertPacket(PlayerOnePacket);
    PlayerOne.Update();
    PlayerOne.DisplayPlayerInfo();

    std::cout << "\n" << std::endl;

    Player PlayerTwo;

    ReceivedPacket PlayerTwoPacket;
    PlayerTwoPacket.X = -1;
    PlayerTwoPacket.Y = -1;

    PlayerTwo.InsertPacket(PlayerTwoPacket);
    PlayerTwo.Update();
    PlayerTwo.DisplayPlayerInfo();

    std::cout << "\n" << std::endl;
    uint16_t Distance = PlayerOne.GetDistance(PlayerTwo);
    std::cout << "The distance between the two players: " << Distance << std::endl;

    std::cout << "\n" << std::endl;
    bool isColliding = PlayerOne.CalculateCollisons(PlayerTwo);
    std::cout << "Are the players colliding? " << isColliding << std::endl;

    return 0;
}
*/