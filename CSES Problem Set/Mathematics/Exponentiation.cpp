#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pow(int a, int b, int m){
    if(b == 0) return 1;
    if(b == 1) return a;

    ll x = pow(a, b/2, m) % m;
    ll ans = 0;

    if(b % 2 != 0){
        ans = (x % m * x % m) % m;
        ans = (ans % m * a % m) % m;
    }
    else{
        ans = (x % m * x % m) % m;
    }

    return ans;
}

void solve(){
    int a, b;
    cin>>a>>b;
    int m = 1e9 + 7;

    cout<<pow(a, b, m)<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}