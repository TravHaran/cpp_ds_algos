#include <iostream>

using namespace std;

AvlTree::AvlTree(){
    root = nullptr;
}

int AvlTree::height(Node *root){
    // int height = 0;
    if(root==nullptr)
        return 0;
    int left = height(root->leftSubtree());
    int right = height(root->rightSubtree());
    if(left > right)
        return left + 1;
    return right + 1;
}

int AvlTree::balanceFactor(Node *root){
    int h_left;
    int h_right;
    if(root){
        h_left = root->leftSubtree() ? height(root->leftSubtree()) : 0;
        h_right = root->rightSubtree() ? height(root->rightSubtree()) : 0;
    }
    return h_left - h_right;
}

void AvlTree::insert(int v){
    root = localInsert(root, v);
}

Node *AvlTree::localInsert(Node *root, int v){
    if(root==nullptr){
        Node *nn = new Node(v);
        return nn;
    }
    if(v > root->getValue()){
        //Do right Subtree recursion
        root->rightSubtree(localInsert(root->rightSubtree(), v));
    }
    else if(v < root->getValue()){
        //Do left Subtree recursion
        root->leftSubtree(localInsert(root->leftSubtree(), v));
    }
    //If there is a left-left imbalance
    if(balanceFactor(root)==2 && balanceFactor(root->leftSubtree())==1){
        return LLRotation(root);
    }
    //If there is left-right imbalance
    else if(balanceFactor(root)==2 && balanceFactor(root->leftSubtree())==-1){
        return LRRotation(root);
    }
    //If there is a right-right imbalance
    else if(balanceFactor(root)==-2 && balanceFactor(root->rightSubtree())==-1){
        return RRRotation(root);
    }
    //If there is a right-left imbalance
    else if(balanceFactor(root)==-2 && balanceFactor(root->rightSubtree())==1){
        return RLRotation(root);
    }

    return root;
}

Node *AvlTree::LLRotation(Node *nroot){
    Node *rl = nroot->leftSubtree();
    Node *rlr = rl->rightSubtree();
    rl->rightSubtree(nroot);
    nroot->leftSubtree(rlr);
    //if the passed in node was the root, then update the root to the new node
    if(root==nroot)
        root=rl;
    return rl;
}

Node *AvlTree::RRRotation(Node *nroot){
    Node *rr = nroot->rightSubtree();
    Node *rrl = rr->leftSubtree();
    rr->leftSubtree(nroot);
    nroot->rightSubtree(rrl);
    //if the passed in node was the root, then update the root to the new node
    if(root==nroot)
        root=rr;
    return rr;
}

Node *AvlTree::RLRotation(Node *nroot){
    Node *rr = nroot->rightSubtree();
    Node *rrl = rr->leftSubtree();
    rr->leftSubtree(rrl->rightSubtree());
    nroot->rightSubtree(rrl->leftSubtree());
    rrl->rightSubtree(rr);
    rrl->leftSubtree(nroot);
    //if the passed in node was the root, then update the root to the new node
    if(root==nroot)
        root=rrl;
    return rrl;
}

Node *AvlTree::LRRotation(Node *nroot){
    Node *rl = nroot->leftSubtree();
    Node *rlr = rl->rightSubtree();
    rl->rightSubtree(rlr->leftSubtree());
    nroot->leftSubtree(rlr->rightSubtree());
    rlr->leftSubtree(rl);
    rlr->rightSubtree(nroot);
    //if the passed in node was the root, then update the root to the new node
    if(root==nroot)
        root = rlr;
    return rlr;
}

void AvlTree::levelOrderDump(){
    for(int i = 1; i<=height(root); i++)
        levelOrderDump(root, i);
}

void AvlTree::levelOrderDump(Node *n, int level){
    if(n==nullptr)
        return;
    else if(level==1)
        cout<<n->getValue()<<endl;
    levelOrderDump(n->leftSubtree(), level-1);
    levelOrderDump(n->rightSubtree(), level-1);
}