#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; cin>>n;
    vector<ll> arr(n);
    ll totalSum = 0;
    ll ans = INT_MAX;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        totalSum += arr[i];
    }

    for(ll m = 0; m < (1 << n); m++){
        ll sum = 0;
        for(int i = 0; i < n; i++){
            if(m & (1 << i)){
                sum += arr[i];
            }
        }
        ll other = totalSum - sum;
        ans = min(ans, abs(sum - other));
    }

    cout<<ans<<endl;
    return 0;
}