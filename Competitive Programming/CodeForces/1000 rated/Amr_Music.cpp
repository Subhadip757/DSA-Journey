#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k; cin>>n>>k;

    vector<pair<int, int>> pairValues(n);
    vector<int> ans;

    for(int i = 0; i < n; i++){
        cin>>pairValues[i].first;
        pairValues[i].second = i;
    }

    sort(pairValues.begin(), pairValues.end());

    for(int i = 0; i < n; i++){
        if(pairValues[i].first <= k){
            k -= pairValues[i].first;
            ans.push_back(pairValues[i].second + 1);
        }
    }

    cout<<ans.size()<<endl;
    sort(ans.begin(), ans.end());
    for(int it : ans){
        cout<<it<<" ";
    }
}