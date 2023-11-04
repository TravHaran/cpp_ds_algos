#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <iostream>
#include "LList.h"

template<class T>
class HashTable{
    public:
        HashTable();
        // ~HashTable();
        void add(string key, T value);
        T search(string key);
        // void del(string key, T value);
        void print();
    private:
        LList<T> *_slots;
        int _size;
};
#include "HashTable.cpp"
#endif