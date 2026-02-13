#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) cin>>arr[i];

    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());

    int maxPos = 0, minPos = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] == maxVal){
            maxPos = i; break;
        }
    }

    for(int i = n - 1; i >= 0; i--){
        if(arr[i] == minVal){
            minPos = i; break;
        }
    }

    int swaps = maxPos + (n - 1 - minPos);
    if(maxPos > minPos) swaps--;

    cout<<swaps<<"\n";

    return 0;
}