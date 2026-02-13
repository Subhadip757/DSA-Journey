#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr(3);

    for(int i = 0; i < 3; i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());
    int sum = 0;
    for(int i = 1; i < 3; i++){
        sum += abs(arr[i - 1] - arr[i]); 
    }

    cout<<sum;


    return 0;
}