#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b);
int dpKnapsack(vector<vector<int> > items, int n, int cap, vector<vector<int> > &dp_table);
vector<vector<int> > backtrackItems(vector<vector<int> >items, int n, int cap, vector<vector<int> > &dp_table);

int main(){
    int knapSackCapacity = 6;
    vector<vector<int> > items{{2, 5}, {6, 5}, {2, 9}, {3, 6}, {4, 9}};
    vector<vector<int> > table(items.size()+1, vector<int>(knapSackCapacity+1));
    int result = dpKnapsack(items, items.size(), knapSackCapacity, table);
    vector<vector<int> > results = backtrackItems(items, items.size(), knapSackCapacity, table);
    cout<<"Optimal Value: "<<result<<endl;
    for(auto i : results)
        cout<<"W="<<i[0]<<" V="<<i[1]<<", "<<endl;
    cout<<endl;
}

int dpKnapsack(vector<vector<int> > items, int n, int cap, vector<vector<int> > &dp_table){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= cap; j++){
            if((i == 0) || (j == 0))
                dp_table[i][j] = 0;
            else if(items[i-1][0] <= j)
                dp_table[i][j] = max(items[i-1][1] + dp_table[i-1][(j-items[i-1][0])], dp_table[i-1][j]);
            else
                dp_table[i][j] = dp_table[i-1][j];
        }
    }
    return dp_table[n][cap];
}

vector<vector<int> > backtrackItems(vector<vector<int> >items, int n, int cap, vector<vector<int> > &dp_table){
    vector<vector<int> > usedItems;
    int i = n;
    int j = cap;

    while((i > 0) && (j > 0)){
        if(dp_table[i][j] > dp_table[i-1][j]){
            usedItems.push_back(items[i-1]);
            i--;
            j -=items[i-1][0];
        }
        else 
            i--;
    }
    return usedItems;
}

int max(int a, int b){
    return a > b ? a : b;
}