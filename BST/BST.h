#ifndef BSTRECORD_BST_H
#define BSTRECORD_BST_H
#include "TreeNode.h"

using namespace std;

class BST{
    public:
        BST();
        ~BST();
        void insert(int v);
        bool find(int v);
        bool iterFind(int v);
        int size();
        void levelOrderDump();
        void inorderDump();
        int kthSmallest(int k);
    private:
        TreeNode *insert(TreeNode *Node, int v);
        bool find(TreeNode *Node, int v);
        int size(TreeNode *Node);
        void inorderDump(TreeNode *Node);
        void levelOrderDump(TreeNode *Node);
        TreeNode *kthSmallest(TreeNode *Node, int &kth);

        TreeNode *root;
        int _size;
};
#include "BST.cpp"
#endif

//Nisheet 