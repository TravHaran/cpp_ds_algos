#ifndef SINGLY_LINKED_LIST_LNODE_H
#define SINGLY_LINKED_LIST_LNODE_H

class LNode {
    public:
        LNode();
        LNode *next();
        void next(LNode *next);
        int &data(); //setter & getter
    private:
        int _data;
        LNode *_next;
};
#endif