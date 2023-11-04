// #include "LNode.h"
#include <iostream>
using namespace std;

template<class T>
LNode<T>::LNode(){
    _next = nullptr;
    _prev = nullptr;
    _data = 0;
}

template<class T>
LNode<T> *LNode<T>::next(){
    return _next;
}

template<class T>
LNode<T> *LNode<T>::prev(){
    return _prev;
}

template<class T>
void LNode<T>::next(LNode *next){
    _next = next;
}

template<class T>
void LNode<T>::prev(LNode *prev){
    _prev = prev;
}

template<class T>
T &LNode<T>::data(){
    return _data;
}

template<class T>
string &LNode<T>::key(){
    return _key;
}



template<class T>
LNode<T>::~LNode(){
}
