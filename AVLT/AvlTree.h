#ifndef AVLTREERECORD_AVLTREE_H
#define AVLTREERECORD_AVLTREE_H

#include "Node.h"

class AvlTree{
    public:
        AvlTree();
        int height(Node *root);
        int balanceFactor(Node *root);
        void insert(int v);
        void levelOrderDump();

    private:
        Node *localInsert(Node *root, int v);
        Node *LLRotation(Node *nroot);
        Node *LRRotation(Node *nroot);
        Node *RRRotation(Node *nroot);
        Node *RLRotation(Node *nroot);
        void levelOrderDump(Node *n, int level);
        Node *root;
};
#include"AvlTree.cpp"
#endif