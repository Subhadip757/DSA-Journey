#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    ll elm = arr[n/2];
    ll cost = 0;
    
    for(int x : arr){
        cost += abs(x - elm);
    }

    cout<<cost<<"\n";
    return 0;
}