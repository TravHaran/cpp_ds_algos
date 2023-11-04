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
            linkedList->insert(data - '0');
        } else {
            linkedList_char->insert(data);
        }
    }
    linkedList->del(9);
    linkedList->del(1);
    linkedList->del(5);
    linkedList->del(3);
    linkedList->del(2);
    linkedList->del(4);
    linkedList->del(7);
    linkedList->del(8);
    linkedList->print();
    cout<<"LinkedList_Int palindrome check: "<<linkedList->isPalindrome()<<endl;
    linkedList_char->print();
    cout<<"LinkedList_Char palindrome check: "<<linkedList_char->isPalindrome()<<endl;
    return 0;
}