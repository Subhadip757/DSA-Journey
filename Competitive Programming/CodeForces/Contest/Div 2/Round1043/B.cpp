#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int countDigits(ll n) {
    if (n == 0) return 1; 
    return (int)log10(n) + 1;
}

int main(){
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;

        int temp = n;
        
        int size = countDigits(n)/2;


    }
    return 0;
}