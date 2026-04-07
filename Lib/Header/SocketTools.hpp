#pragma once
#include <string>
#include <iostream>

#include <winsock2.h>
#include <ws2tcpip.h>

#include <cstdint>

//Helper functions for Library commands
int StartLibraries();
void CleanUp(SOCKET CleanUpSocket);

//Below, Are the helper functions for setting up a Socket.
int MakeSocket(SOCKET &ReturnSocket);
int SetUpServer(SOCKET &ReturnSocket, std::string Address, uint16_t PortNumber);

//Below, is helper functions for sending and receiving data.
template <typename DataStruct>
int RecvData(SOCKET &ReceivingSocket, DataStruct &Data, sockaddr_in &ClientAddress);

template <typename SentData>
int SendData(SOCKET &ReceivingSocket, SentData &Data, sockaddr_in &Address);

template <typename DataStruct>
int RecvDataFromServer(SOCKET &ReceivingSocket, DataStruct &Data, sockaddr_in &ServerAddress);