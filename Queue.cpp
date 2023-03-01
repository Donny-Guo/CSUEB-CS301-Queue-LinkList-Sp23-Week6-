#include "Queue.h"


template<class T>
Queue<T>::Queue(int max)
{
    head = nullptr;
    tail = nullptr;
    numOfItems = 0;
    maxSize = max;
}

template<class T>
Queue<T>::Queue()
{
    head = nullptr;
    tail = nullptr;
    numOfItems = 0;
}

template<class T>
Queue<T>::~Queue()
{
    while (head != nullptr) {
        Node * tmp = head;
        head = head->next;
        delete tmp;
    }
}

template<class T>
void Queue<T>::MakeEmpty()
{
    while (head != nullptr) {
        Node * tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = nullptr;
    numOfItems = 0;
}

template<class T>
bool Queue<T>::IsEmpty() const
{
    return numOfItems == 0;
}

template<class T>
bool Queue<T>::IsFull() const
// Returns true if the queue is full; false otherwise.
{
    return numOfItems >= maxSize;
}

template<class T>
void Queue<T>::Enqueue(T newItem)
{
    if (IsFull()){
        throw FullQueue();
    }
    numOfItems++;

    Node * nodeToInsert = new Node;
    nodeToInsert->value = newItem;
    nodeToInsert->next = nullptr;
    if (tail == nullptr){
        head = nodeToInsert;
        tail = nodeToInsert;
    }
    tail->next = nodeToInsert;
    tail = nodeToInsert;
}

template<class T>
T Queue<T>::Dequeue()
{
    if (IsEmpty()){
        throw EmptyQueue();
    }
    T valueToReturn = head->value;
    Node * tmp = head;
    head = head->next;
    delete tmp;
    --numOfItems;

    if (head == nullptr){
        tail = nullptr;
    }
    return valueToReturn;
}
