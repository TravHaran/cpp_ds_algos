#ifndef SINGLY_LINKED_LIST_LLIST_H
#define SINGLY_LINKED_LIST_LLIST_H
#include "LNode.h"

class LList{
    public:
        LList();
        void append(int data_val);
        void print();
    private:
        LNode *head, *tail;
        int _size;
};
#endif