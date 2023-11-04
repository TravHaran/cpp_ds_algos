#include <iostream>
#include <fstream>
#include "unordered_map"
using namespace std;

unordered_map<char, string> adjList;
unordered_map<char, int> visited;
void dfs(char v);

void dfs(char v){
    if(!visited[v]){
        cout<<v<<" ";
        visited[v]=1;
        for(char & i : adjList[v]){
            if(!visited[i])
                dfs(i);
        }
    }
}

int main(int argc, char *argv[]){
    if(argc!=2){
        cout<<"usage: "<<argv[0]<<" <input file>"<<endl;
        exit(-1);
    }
    ifstream instream;
    instream.open(argv[1]);
    string s;
    while(getline(instream, s)){
        // cout<<s<<endl;
        adjList[s[0]] = s.substr(2, s.length()-1);
        visited[s[0]] = 0;
    }
    dfs(adjList.begin()->first);
    return 0;
}