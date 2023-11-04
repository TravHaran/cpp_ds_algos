#ifndef DOUBLY_LINKED_LIST_LLIST_H
#define DOUBLY_LINKED_LIST_LLIST_H
#include "LNode.h"

template<class T>
class LList{
    public:
        LList();
        ~LList();
        void append(string key, T data_val);
        void insert(T data_val); // this inserts in ordered fashion
        void del(T data_val); // this deletes inn ordered fashion
        T search(std::string key);
        void print();
        bool isPalindrome();
    private:
        LNode<T> *head, *tail;
        int _size;
};
#include "LList.cpp"
#endif