#ifndef _BSTRECORD_TREENODE_H
#define _BSTRECORD_TREENODE_H
class TreeNode{
    public:
        TreeNode(): left(nullptr), right(nullptr), _data(0){}
        TreeNode(int n): left(nullptr), right(nullptr), _data(n) {}

        TreeNode *leftSubtree() {return left;}
        TreeNode *rightSubtree() {return right;}

        void leftSubtree(TreeNode *left) {this->left = left;}
        void rightSubtree(TreeNode *right) {this->right = right;} 

        int& data() {return _data;}

    private:
        TreeNode *left, *right;
        int _data;
};
#endif