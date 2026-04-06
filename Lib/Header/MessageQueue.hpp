#pragma once
#include <mutex>
#include <memory>
#include <iostream>
#include <utility>


struct Packet 
{
    void GetInfo();
    private:
};

template <typename Data>
class LinkedList
{
public:
    struct Node
    {
        std::unique_ptr<Data> NodeData;
        std::unique_ptr<Node> Next;
    };

private:
    std::unique_ptr<Node> Head;
    Node *Tail;

    std::mutex HeadLock;
    std::mutex TailLock;

public:
    LinkedList();
    void PushNode(Data InsertedData);
    void PopNode(Data &ReturnData);
    void DisplayNodes();
    Node * GetTail();
};