#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n; cin>>n;
    ll sum = 0;
    for(ll m = 1; m <= n; m++){
        for(int i = 0; i <= m; i++){
            if(m & (1 << i)){
                sum++;
            }
        }
    }

    cout<<sum<<endl;
    return 0;
}