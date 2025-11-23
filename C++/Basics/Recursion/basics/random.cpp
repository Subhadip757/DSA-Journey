#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n){
    if(n == 0) return 1;
    return 1 + solve(n - 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ans = solve(5);
    cout<<ans;
    return 0;
}