#include "TreeNode.h"
#include "BST.h"
#include <iostream>
#include <queue>
using namespace std;

BST::BST(){
    root = nullptr;
    _size = 0;
}

BST::~BST() = default;

void BST::insert(int v){
    if(!find(v))
        root = insert(root, v);

}

bool BST::find(int v){
    return find(root, v);
}

TreeNode *BST::insert(TreeNode *Node, int v){
    if(Node==nullptr)
        return new TreeNode(v);
    if(Node->data() < v)
        Node->rightSubtree(insert(Node->rightSubtree(), v));
    else 
        Node->leftSubtree(insert(Node->leftSubtree(), v));
    return Node;
}

bool BST::find(TreeNode *Node, int v){
    if(Node==nullptr)
        return false;
    if(Node->data()==v){
        return true;
    }
    if(v < Node->data())
        return find(Node->leftSubtree(), v);
    return find(Node->rightSubtree(), v);
}

int BST::size(){
    _size = size(root);
    return _size;
}

int BST::size(TreeNode *Node){
    if(Node==nullptr)
        return 0;
    return 1 + size(Node->rightSubtree()) + size(Node->leftSubtree());
}

void BST::inorderDump(){
    inorderDump(root);
}

void BST::levelOrderDump(){
    levelOrderDump(root);
}

void BST::inorderDump(TreeNode *Node){
    if(Node==nullptr)
        return;
    inorderDump(Node->leftSubtree());
    cout<<Node->data()<<endl;
    inorderDump(Node->rightSubtree());
}

void BST::levelOrderDump(TreeNode *Node){
    queue<TreeNode*>fifo;
    fifo.push(Node);
    while(!fifo.empty()){
        Node = fifo.front();
        fifo.pop();
        if(Node->leftSubtree()!=nullptr){
            fifo.push(Node->leftSubtree());
        }
        if(Node->rightSubtree()!=nullptr){
            fifo.push(Node->rightSubtree());
        }
        cout<<Node->data()<<endl;
    }
}

int BST::kthSmallest(int k){
    if(size()<=k)
        return 0;
    TreeNode *ksmall = kthSmallest(root, k);
    return ksmall->data();
}

TreeNode *BST::kthSmallest(TreeNode *Node, int &kth){
    if(Node==nullptr)
        return nullptr;
    TreeNode *answer = kthSmallest(Node->leftSubtree(), kth);
    if(answer!=nullptr)
        return answer;
    kth--;
    if(kth==0)
        return Node;
    return kthSmallest(Node->rightSubtree(), kth);
}

