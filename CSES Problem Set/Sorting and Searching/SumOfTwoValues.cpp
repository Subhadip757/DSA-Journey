#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; ll t;
    cin>>n>>t;

    vector<pair<ll, ll>> arr(n);

    for(int i = 0; i < n; i++){
        cin>>arr[i].first;
        arr[i].second = i;
    }

    int start = 0, end = n - 1;
    sort(arr.begin(), arr.end());

    while(start < end){
        ll elm = arr[start].first + arr[end].first;

        if(elm == t){
            cout << arr[start].second + 1 << " " << arr[end].second + 1 << "\n";
            return 0;
        }
        else if(elm > t){
            end--;
        }
        else{
            start++;
        }
    }

    cout<<"IMPOSSIBLE\n";
    return 0;
}