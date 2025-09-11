#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, w; cin>>n>>w;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    int l = 0, r = n - 1;
    ll c = 0;

    while(l <= r){
        if(arr[l] + arr[r] <= w){
            l++;
        }
        r--;
        c++;
    }

    cout<<c<<endl;
    return 0;
}