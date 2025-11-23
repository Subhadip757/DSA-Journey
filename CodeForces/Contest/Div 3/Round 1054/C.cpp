#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        unordered_map<int, int> mp;

        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            mp[arr[i]]++;
        }

        int ans = 0;

        for(auto it : mp){
            if(it.first == k){
                ans = it.second;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}