// #include "LList.h"
#include "LNode.h"
#include <iostream>

using namespace std;

template<class T>
LList<T>::LList(){
    head = tail = nullptr;
    _size = 0;
}

template<class T>
void LList<T>::append(T data_val){
    //create a new node and set the data member
    LNode<T> *newnode = new LNode<T>();
    newnode->data() = data_val;

    //if list is empty
    if(_size==0){
        head = tail = newnode;
        _size += 1;
    }

    //if the size of the list is 1
    else if(_size==1){
        head->next(newnode);
        tail = newnode;
        _size += 1;
    }

    //Move through list and add newnode to the end
    else{
        LNode<T> *cur = head;
        while(cur != nullptr){
            if(cur->next()==nullptr){
                cur->next(newnode);
                tail = newnode;
                _size += 1;
                return;
            }
            cur = cur->next();
        }
    }
}

template<class T>
void LList<T>::print(){
    //Loop through the list and print out the values
    LNode<T> *cur = head;
    while(cur!=nullptr){
        cout<<cur->data()<<"-> ";
        cur = cur->next();
    }
    cout<<endl;
}