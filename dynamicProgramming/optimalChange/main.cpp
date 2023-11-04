#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b);
void minCoins(vector<int> coin, int changeNeeded);

int min(int a, int b){
    return a < b ? a : b;
}

void minCoins(vector<int> coins, int changeNeeded){
    vector<int> table(changeNeeded+1, changeNeeded+1);
    table[0] = 0;
    vector<vector<int>> coinsUsed;

    for(int i = 0; i <= changeNeeded; i++){
        vector<int> newVect;
        for(int coin: coins){
            if(i >= coin){
                int smallest = min(table[i], table[i-coin]+1);
                if(smallest != table[i]){
                    newVect = coinsUsed[i - coin];
                    newVect.push_back(coin);
                }
                table[i] = smallest;
            }
        }
        coinsUsed.push_back(newVect);
    }
    cout<<"Min num coins: "<<table[changeNeeded]<<endl;
    cout<<"Coins used: ";
    for(auto &i: coinsUsed[changeNeeded]){
        cout<<i<<" ";
    }
}

int main(){
    vector<int> denoms1{1, 5, 10};
    vector<int> denoms2{1, 8, 9, 14};
    minCoins(denoms2, 17);
    return 0;
}