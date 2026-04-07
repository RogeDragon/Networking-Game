#include "MessageQueue.hpp"

template <typename Data>
LinkedList<Data>::LinkedList()
{
    Head = std::make_unique<Node>(); //Making a Dummy Node For the Linked LIst
    Tail = Head.get();
}

template <typename Data>
void LinkedList<Data>::PushNode(Data InsertedData)
{
    std::scoped_lock<std::mutex> Lock(TailLock);

    Tail->Next = std::make_unique<Node>();
    Tail->NodeData = std::make_unique<Data>(InsertedData);
    Tail = Tail->Next.get();
}

template <typename Data>
typename LinkedList<Data>::Node * LinkedList<Data>::GetTail()
{
    std::scoped_lock<std::mutex> Lock(TailLock);
    return Tail;
}

template <typename Data>
void LinkedList<Data>::PopNode(Data &ReturnData)
{
    std::scoped_lock<std::mutex> Lock(HeadLock);
    if (Head.get() == GetTail()) return;

    ReturnData = *(Head->NodeData);
    std::unique_ptr<Node> Temp = std::move(Head);
    Head = std::move(Temp->Next);
}

/*
template <typename Data>
void LinkedList<Data>::DisplayNodes()
{
    std::scoped_lock<std::mutex> Lock(TailLock, HeadLock);

    Node * Current =  Head.get();
    while (Current != nullptr) 
    {
        if (Current->NodeData)
            std::cout << Current->NodeData->GetInfo() << " ";
        Current = Current->Next.get();
    }
    std::cout << std::endl;
}
*/