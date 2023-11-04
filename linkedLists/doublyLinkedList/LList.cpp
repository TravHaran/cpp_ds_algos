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
        newnode->prev(head);
        tail = newnode;
        _size += 1;
    }

    //add newnode to the end
    else{
        tail->next(newnode);
        newnode->prev(tail);
        tail = newnode;
        _size++; 
    }
}

template<class T>
void LList<T>::insert(T data_val){
    //create a new node and set the data member
    LNode<T> *newnode = new LNode<T>();
    newnode->data() = data_val;

    //if list is empty
    if(_size==0){
        head = tail = newnode;
        _size += 1;
    }else if(_size==1){
        if(head->data() > data_val){
            // insert behind
            newnode->next(head);
            head->prev(newnode);
            head = newnode;
        } else {
            //insert after
            head->next(newnode);
            newnode->prev(head);
            tail = newnode;
        }
        _size += 1;
    } else {
        // move through list until the current node is no longer less than the newnode
        // then insert before the current node.
        LNode<T> *cur = head;
        while(cur != nullptr){
            if(cur->data()>=newnode->data()){
                if(cur->prev()==nullptr){
                    cur->prev(newnode);
                    newnode->next(cur);
                    head = newnode;
                    _size++;
                    return;
                } else {
                    newnode->prev(cur->prev());
                    (cur->prev())->next(newnode);
                    newnode->next(cur);
                    cur->prev(newnode);
                    _size++;
                    return;
                }  
            }
            if(cur->next()==nullptr){
                cur->next(newnode);
                newnode->prev(cur);
                tail = newnode;
                _size++;
                return;
            }   
            cur = cur->next();  
        }
    }
}

template<class T>
void LList<T>::del(T data_val){
    LNode<T> *cur = head;
    LNode<T> *destroy;
    if(_size==0){
        return;
    }
    //if size = 1;
    else if(_size==1){
        if(cur->data()==data_val){
            head = tail = nullptr;
            delete(cur);
            _size--;
        }
    }
    else {
        while(cur!=nullptr){
            if(cur->data()==data_val){
                // if the node we need to delete is the head
                if(cur==head){
                    cur = cur->next();
                    cur->prev()->next(nullptr);
                    destroy = cur->prev();
                    cur->prev(nullptr);
                    head = cur;
                    delete(destroy);
                    _size--;
                    return;
                }
                // if the node we need to delete is the tail
                else if(cur==tail){
                    cur = cur->prev();
                    cur->next()->prev(nullptr);
                    destroy = cur->next();
                    cur->next(nullptr);
                    tail = cur;
                    delete(destroy);
                    _size--;
                    return;
                }
                // if the node we need to delete is in the middle
                else {
                    cur = cur->next();
                    cur->prev()->next(nullptr);
                    cur->prev()->prev()->next(cur);
                    destroy = cur->prev();
                    cur->prev(cur->prev()->prev());
                    delete(destroy);
                    _size--;
                    return;
                }
            }
            cur = cur->next();
        }
    }  
}

template<class T>
void LList<T>::print(){
    //Loop through the list and print out the values
    LNode<T> *cur = head;
    cout<<"Forwards"<<endl;
    while(cur!=nullptr){
        cout<<cur->data()<<"-> ";
        cur = cur->next();
    }
    cout<<endl;
    LNode<T> *backwards_cur = tail;
    cout<<"Backwards"<<endl;
    while(backwards_cur!=nullptr){
        cout<<backwards_cur->data()<<"-> ";
        backwards_cur = backwards_cur->prev();
    }
    cout<<endl;
}

template<class T>
bool LList<T>::isPalindrome(){
    if(_size>1){
        LNode<T> *first = head;
        LNode<T> *end = tail;
        int f_count = 0;
        int b_count = _size;
        while(f_count <= b_count){
            if(first->data() != end->data()){
                return false;
            }
            first = first->next();
            f_count++;
            end = end->prev();
            b_count--;
        }
    }
    return true;
}

template<class T>
LList<T>::~LList(){
    while(head != nullptr){
        LNode<T> *destroy = head;
        head = head->next();
        delete(destroy);
        _size--;
    }
}