#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n; cin >> n;

    ll d = 5;
    ll c = 0;

    while(d <= n){
        c += n / d;
        d *= 5;
    }

    cout<<c<<endl;

    return 0;
}