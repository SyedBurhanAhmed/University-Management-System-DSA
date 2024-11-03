#include "Node.h"
using namespace std;


template <class T>
Node<T>::Node(T d,Node* p,Node* n):data(d),prev(p),next(n){}

template <class T>
Node<T>::~Node()
{
    //dtor
}

template <class T>
Node<T>::Node(const Node& other):data(other.data),prev(other.prev),next(other.next){}



template <class T>
T& Node<T>::get_data()
{
    return data;
}

template <class T>
void Node<T>::set_data(T data)
{
    this->data=data;
}


template <class T>
Node<T>* Node<T>::get_prev()
{
    return prev;
}


template <class T>
void Node<T>::set_prev(Node<T>* prev)
{
    this->prev=prev;
}


template <class T>
Node<T>* Node<T>::get_next()
{
    return this->next;
}


template <class T>
void Node<T>::set_next(Node<T>* next)
{
    this->next=next;
}


