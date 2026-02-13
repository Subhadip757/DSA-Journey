#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, x;
vector<int> arr(100100);

int check(int mid){
    if(arr[mid] < arr[0]) return 1;
    return 0;
}

int main(){
    cin>>n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    cin>>x;

    int lo = 0;
    int hi = n - 1;
    int ans = 0;

    while(lo <= hi){
        int mid = lo + (hi - lo)/2;

        if(check(mid) == 1){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }

    cout<<ans<<"\n";
    return 0;
}