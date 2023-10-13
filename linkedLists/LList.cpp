#include "LList.h"
#include "LNode.h"
#include <iostream>

using namespace std;

LList::LList(){
    head = tail = nullptr;
    _size = 0;
}

void LList::append(int data_val){
    //create a new node and set the data member
    LNode *newnode = new LNode();
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
        LNode *cur = head;
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

void LList::print(){
    //Loop through the list and print out the values
    LNode *cur = head;
    while(cur!=nullptr){
        cout<<cur->data()<<"-> ";
        cur = cur->next();
    }
    cout<<endl;
}