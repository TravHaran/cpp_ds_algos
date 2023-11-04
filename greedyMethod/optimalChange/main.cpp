#include <iostream>
#include <vector>

using namespace std;

vector<int> optimalChange(vector<int> denom, int C){
    //make an empty vector to store our optimal combo of ddenominations
    vector<int> solution;
    //move through our denominations starting at the largest (rightmost)
    for(int i = denom.size()-1; i>=0; i--){
        //keep using the largest coin that doesn't exceed the values of the change needed
        while(C>=denom[i]){
            //subtract that coin value from C
            C = C - denom[i];
            //add the denomination to our solution
            solution.push_back(denom[i]);
        }
    }
}

int main(){
    vector<int> denominations{1, 5, 10, 25, 50};
    for(auto &i : optimalChange(denominations, 56)){
        cout<<i<<" ";
    cout<<endl;
    return 0;
    }
}