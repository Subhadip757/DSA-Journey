#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ncr(int n, int r){
    long long res = 1;
    for(int i = 0; i < r; i++){
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

void solve(){
    int n; cin>>n;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
    }
    cout<<ncr(10 - n, 2) * ncr(4, 2)<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}