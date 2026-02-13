#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int l, r;
    cin>>l>>r;

    ll x = l;
    ll y = 2 * l;

    if(y <= r){
        cout<<x<<" "<<y<<endl;
    }
    else{
        cout<<"-1 -1"<<endl;
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}