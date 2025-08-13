#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll modpow(ll x, ll n, ll m) {
    if(n == 0) return 1 % m;
    ll u = modpow(x, n / 2, m);
    u = (u * u) % m;
    if(n % 2 == 1) u = (u * x) % m;
    return u;
}

int main(){
    ll n; cin>>n;
    int m = 1e9 + 7;

    ll ans = modpow(2, n, m);
    cout<<ans % m;
    return 0;
}