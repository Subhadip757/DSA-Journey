#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int k, q;
    cin>>k>>q;

    vector<int> arr(k);

    for(int i = 0; i < k; i++)cin>>arr[i];

    while(q--){
        int n; cin>>n;
        cout<<min(arr[0] - 1, n)<<" ";
    }
    cout<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}