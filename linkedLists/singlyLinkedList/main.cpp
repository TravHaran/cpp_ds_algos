#include <iostream>
#include <fstream>
#include "LList.h"
using namespace std;
int main(int argc, char *argv[]){
    if(argc!=2){
        cout<<"Usage"<<argv[0]<<"name of Input File"<<endl;
    }
    LList<int> *linkedList = new LList<int>();
    LList<char> *linkedList_char = new LList<char>();
    ifstream listStream;
    listStream.open(argv[1], ios::in);
    char data;

    while(listStream>>data){
        if(isdigit(data)){
            linkedList->append(data - '0');
        } else {
            linkedList_char->append(data);
        }
    }
    linkedList->print();
    linkedList_char->print();
    return 0;
}