#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int minimumCoinSum(vector<int> &arr){
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    cout<<minimumCoinSum(arr);

    return 0;
}