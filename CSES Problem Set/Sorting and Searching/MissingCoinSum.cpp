#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll minimumCoinSum(vector<int> &arr, int n){
    ll sum = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] > sum + 1){
            return sum + 1;
        }
        sum += arr[i];
    }

    return sum + 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    cout<<minimumCoinSum(arr, n);

    return 0;
}