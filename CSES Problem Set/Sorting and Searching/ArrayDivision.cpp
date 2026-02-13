#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(vector<ll> &arr, int n, ll mid, int k){
    int c = 0;
    ll total = 0;

    for(int i = 0; i < n; i++){
        if(total >= arr[i]){
            total -= arr[i];
        }
        else{
            c++;
            if(c > k) return 0;
            
            total = mid;
            if(total >= arr[i]){
                total -= arr[i];
            }
            else return 0;
        }
    }

    return 1;
}

ll minimizeTheMaximum(vector<ll> &arr, int n, int k){
    ll end = accumulate(arr.begin(), arr.end(), 0);
    ll start = *max_element(arr.begin(), arr.end());
    ll ans = end;

    while (start <= end) {
        ll mid = start + (end - start)/2;

        if(solve(arr, n, mid, k) == 1){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin>>n>>k;
    
    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    ll ans = minimizeTheMaximum(arr, n, k);
    cout<<ans<<"\n";

    return 0;
}