#ifndef DOUBLY_LINKED_LIST_LNODE_H
#define DOUBLY_LINKED_LIST_LNODE_H

template<class T>
class LNode {
    public:
        LNode();
        ~LNode();
        LNode<T> *next();
        LNode<T> *prev();
        void next(LNode<T> *next);
        void prev(LNode<T> *prev);
        T &data(); //setter & getter
    private:
        T _data;
        LNode<T> *_next;
        LNode<T> *_prev;
};
#include "LNode.cpp"
#endif