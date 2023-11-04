#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
    char input;
    stack<char> myStack;
    queue<char> myQueue;
    do {
        cin>>noskipws>>input;
        myStack.push(input);
        myQueue.push(input);
    }while(input != '\n');
    while(!myStack.empty()){
        cout<<myStack.top();
        myStack.pop();
    }
    cout<<endl;
    while(!myQueue.empty()){
        cout<<myQueue.front();
        myQueue.pop();
    }
    cout<<endl;
    return 0;
}