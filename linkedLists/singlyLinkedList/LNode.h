#ifndef SINGLY_LINKED_LIST_LNODE_H
#define SINGLY_LINKED_LIST_LNODE_H

template<class T>
class LNode {
    public:
        LNode();
        LNode<T> *next();
        void next(LNode<T> *next);
        T &data(); //setter & getter
    private:
        T _data;
        LNode<T> *_next;
};
#include "LNode.cpp"
#endif