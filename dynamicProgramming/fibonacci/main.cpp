#include <iostream>

using namespace std;

int dpFib(int n, int dpArr[]){
    if(n <= 1)
        return n;
    dpArr[0] = 0;
    dpArr[1] = 1;
    for(int i = 2; i <= n; i++){
        dpArr[i] = dpArr[i-1] + dpArr[i-2];
    }
    return dpArr[n];
}

int main(){
    int dpArr[7] = {-1, -1, -1, -1, -1, -1, -1};
    cout<<dpFib(6, dpArr)<<endl;
    return 0;
}