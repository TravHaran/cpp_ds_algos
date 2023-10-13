#include "LNode.h"
#include <iostream>
using namespace std;

LNode::LNode(){
    _next = nullptr;
    _data = 0;
}

LNode *LNode::next(){
    return _next;
}

void LNode::next(LNode *next){
    _next = next;
}

int &LNode::data(){
    return _data;
}