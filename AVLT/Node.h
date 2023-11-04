#ifndef AVLTREERECORD_NODE_H
#define AVLTREERECORD_NODE_H

class Node{
    public:
        Node() : left(nullptr), right(nullptr), _value(0) {}
        Node(int n) : left(nullptr), right(nullptr), _value(n) {}
        Node *leftSubtree(){return left;}
        Node *rightSubtree(){return right;}
        void leftSubtree(Node *left){this->left = left;} 
        void rightSubtree(Node *right){this->right = right;} 
        int getValue(){return _value;}
        void setValue(const int val){_value = val;}
    private:
        Node *left;
        Node *right;
        int _value;
    
};
#endif