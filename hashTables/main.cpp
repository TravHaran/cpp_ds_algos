#include <iostream>
#include <fstream>
#include "HashTable.h"
using namespace std;

int main(int argc, char *argv[]){
    if(argc!=2){
        cout<<"Usage"<<argv[0]<<"name of Input File"<<endl;
    }
    HashTable<int> *hashTable = new HashTable<int>();
    ifstream dataStream;
    dataStream.open(argv[1], ios::in);
    string name;
    string temp;
    int age;
    while(!dataStream.eof()){
        getline(dataStream, name, ':');
        getline(dataStream, temp, '\n');
        age = stoi(temp);
        hashTable->add(name, age);
    }

    cout<<"Patrick's age is: "<<hashTable->search("Jake")<<endl;
}