#include <iostream>
#include <unordered_map>
#include <deque>
#include <string>
#include <fstream>

using namespace std;

unordered_map<char, string> adjList;
unordered_map<char, int> visited;
deque<char> bfsQueue;
void bfs(char v);

void bfs(char v){
    bfsQueue.push_back(v);
    while(!bfsQueue.empty()){
        char curr = bfsQueue.front();
        bfsQueue.pop_front();
        if(!visited[curr]){
            visited[curr] = 1;
            cout<<curr<<" ";
        }
        for(auto &n: adjList[curr]){
            if(!visited[n])
                bfsQueue.push_back(n);
        }
    }

}

int main(int argc, char *argv[]){
    if(argc!=2){
        cout<<"usage "<<argv[0]<<" <input file>"<<endl;
        exit(-1);
    }
    ifstream instream;
    instream.open(argv[1]);
    string s;
    while(getline(instream, s)){
        adjList[s[0]] = s.substr(2, s.length()-1);
        visited[s[0]] = 0;
    }
    bfs(adjList.begin()->first);
    return 0;
}
