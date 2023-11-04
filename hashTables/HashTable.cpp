#include "LList.h"
#include <iostream>

using namespace std;

template<class T>
HashTable<T>::HashTable(){
    _slots = new LList<T>[4];
    _size = 0;
}

template<class T>
void HashTable<T>::add(string key, T value){
    int index  = value % 4;
    _slots[index].append(key, value);
}

template<class T>
T HashTable<T>::search(string key){
    for(int i = 0; i < 4; i++){
        int target = _slots[i].search(key);
        if(target != -1){
            return target;
        }
    }
    cout<<"no entry"<<endl;
    return -1;
}

template<class T>
void HashTable<T>::print(){
    for(int i = 0; i < 4; i++){
        LNode<T> *cur = _slots[i]->head;
        while(cur!=nullptr){
            cout<<cur->key()<<": "<<cur->data()<<endl;
            cur = cur->next();
        }
    }
}





