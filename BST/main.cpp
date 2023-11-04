#include <iostream>
#include <fstream>
#include "BST.h"

using namespace std;

int main(int argc, char *argv[]){
    if(argc != 2){
        cout<<"Usage:"<<argv[0]<<"name of an input file"<<endl;
        exit(1);
    }
    ifstream filein;
    filein.open(argv[1]);
    BST *tree = new BST();
    int v;

    //Insert into the tree
    while(filein >> v){
        tree->insert(v);
    }

    cout<<"In order dump of tree"<<endl;
    tree->inorderDump();

    cout<<"Level order dump of tree"<<endl;
    tree->levelOrderDump();

    int f;
    cout<<"Enter a value to be found: ";
    cin>>f;
    if(tree->find(f)){
        cout<<f<<" found with recursive find"<<endl;
    }
    cout<<"The tree's size is: ";
    cout<<tree->size()<<endl;

    cout<<"Enter a kth smallest value to be found: ";
    cin>>f;
    cout<<tree->kthSmallest(f)<<endl;

    return 0;

}