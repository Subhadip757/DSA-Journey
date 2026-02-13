#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll maxiSubarraySum(int n, vector<ll> arr){
    ll maxi = arr[0], sum = arr[0];
 
    for(int r = 1; r < n; r++){
        sum = max(arr[r], sum + arr[r]);
        maxi = max(sum, maxi);
    }
 
    return maxi;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin>>n;
 
    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
 
    cout<<maxiSubarraySum(n, arr)<<"\n";
 
    return 0;
}