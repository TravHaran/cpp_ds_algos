#include "AvlTree.h"
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]){
    if(argc!=2){
        cout<<"usage:"<<argv[0]<<"name of an input file"<<endl;
        exit(-1);
    }
    ifstream fileIn;
    fileIn.open(argv[1]);
    AvlTree *tree = new AvlTree();
    int v;

    //Insert into the tree
    while(fileIn>>v)
        tree->insert(v);
    tree->levelOrderDump();
    return 0;
}