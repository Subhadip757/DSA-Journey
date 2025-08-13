#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n; cin>>n;
    if(n <= 3 && n > 1){
        cout<<"NO SOLUTION";
        return 0;
    }
    for(ll i = 1; i <= n; i++){
        if(i % 2 == 0){
            cout<<i<<" ";
        }
    }

    for(ll i = 1; i <= n; i++){
        if(i % 2 != 0){
            cout<<i<<" ";
        }
    }

    return 0;
}