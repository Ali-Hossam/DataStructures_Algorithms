#pragma once
#include "Node.h"

template<typename T>
class LinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	
public:
	LinkedList(Node<T>*);
	~LinkedList();
    bool remove(T key);
	void insert(T key);
    Node<T>* search(T key) const;
    Node<T>* getHead() const;
	Node<T>* getTail() const;

};


template<typename T>
LinkedList<T>::LinkedList(Node<T>* head)
{
    this->head = head;
    this->tail = head;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node<T>* node = head;
    while (node->next)
    {
        Node<T>* nextNode = node->next;
        delete node;
        node = nextNode;
    }
}

template <typename T>
void LinkedList<T>::insert(T key)
{
    tail->next = new Node<T>{ key };
    tail = tail->next;
}

template <typename T>
Node<T>* LinkedList<T>::getHead() const
{
    return head;
}

template<typename T>
Node<T>* LinkedList<T>::getTail() const
{
    return tail;
}

template<typename T>
bool LinkedList<T>::remove(T key)
{
    Node<T>* node = head;
    Node<T>* prevNode = nullptr;

    do
    {
        if (node->data == key)
        {
            if (prevNode) prevNode->next = node->next;
            else
            {
                if (node->next) head = node->next;
                else head = nullptr;
            }
            if (node == tail) tail = prevNode;
            delete node;
            return true;
        }
        prevNode = node;
        node = node->next;   
    } while (node);
    return false;
}

template <typename T>
Node<T>* LinkedList<T>::search(T key) const
{
    Node<T>* node = head;
    Node<T>* prevNode = nullptr;

    do
    {
        if (node->data == key)
        {
            return node;
        }
        node = node->next;
    } while (node);
    return nullptr;
}