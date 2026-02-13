#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int c = 1;

    for(int i = 1; i < n; i++){
        if(arr[i - 1] > arr[i]) c++;
    }

    cout<<c<<"\n";
    return 0;
}