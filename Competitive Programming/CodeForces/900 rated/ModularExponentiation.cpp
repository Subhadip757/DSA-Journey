#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll findPow(int a, int b){
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a;
    }

    ll x = findPow(a, b/2);
    ll ans = 0;
    
    if(b % 2 != 0){
        ans = x * x * a;
    }
    else{
        ans = x * x;
    }
    return ans;
}

int main(){
    ll n, m;
    cin>>n>>m;

    if(n > 30){
        cout<<m<<endl;
    }
    else{
        int ans = findPow(2, n);
        cout<<m % ans<<endl;
    }
    return 0;
}