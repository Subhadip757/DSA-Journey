#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

long long XORallWindowSums(){
    long long n, k, x, a, b, c, l = 0;
    cin>>n>>k>>x>>a>>b>>c;

    vector<long long> arr(n);
    arr[0] = x;

    for(long long i = 1; i < n; i++){
        arr[i] = (a * (arr[i - 1]) + b) % c;
    } 

    ll sum = 0;

    for(long long i = 0; i < k; i++){
        sum += arr[i];
    }

    ll ans = sum;

    for(long long i = k; i < n; i++){
        sum -= arr[l++];

        sum += arr[i];
        ans ^= sum;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout<<XORallWindowSums();
    return 0;
}