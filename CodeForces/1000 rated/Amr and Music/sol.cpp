#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k; cin>>n>>k;

    vector<int> arr(n);
    vector<int> ans;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(ans.begin(), ans.end());

    for(int i = 0; i < n; i++){
        if(arr[i] <= k){
            k -= arr[i];
            ans.push_back(i + 1);
        }
    }

    cout<<ans.size()<<endl;
    for(int it : ans){
        cout<<it<<" ";
    }
}