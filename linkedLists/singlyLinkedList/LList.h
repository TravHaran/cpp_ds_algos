#ifndef SINGLY_LINKED_LIST_LLIST_H
#define SINGLY_LINKED_LIST_LLIST_H
#include "LNode.h"

template<class T>
class LList{
    public:
        LList();
        void append(T data_val);
        void print();
    private:
        LNode<T> *head, *tail;
        int _size;
};
#include "LList.cpp"
#endif