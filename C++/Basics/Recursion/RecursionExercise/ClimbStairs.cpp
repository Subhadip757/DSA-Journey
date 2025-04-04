#include <iostream>

using namespace std;

int climbStairs(int n){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }
    int ans = climbStairs(n-1) + climbStairs(n-2);
    return ans;
}

int main(){
    int stairs = 3;
    cout<<"Output: "<<climbStairs(stairs)<<endl;
}