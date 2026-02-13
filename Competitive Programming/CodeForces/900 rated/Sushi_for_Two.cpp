#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) cin>>arr[i];

    // sort(arr.begin(), arr.end());

    int l = 0;
    int ls = 0;

    int oc = 0, tc = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] == 1) oc++;
        else if(arr[i] == 2) tc++;

        if(oc == tc){
            ls = max(ls, i - l + 1);
        }
        while(tc > oc){
            l++;
            tc--;
        }
    }

    cout<<ls<<"\n";

    return 0;
}