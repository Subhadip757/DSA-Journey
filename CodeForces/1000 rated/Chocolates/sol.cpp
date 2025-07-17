#include<iostream>
#include<vector>
using namespace std;

long long solve(vector<long long> &arr, int n){
    long long ans = arr[n - 1];
    long long value = arr[n - 1] - 1;

    for(int i = n - 2; i >= 0; i--){
        if(value <= 0)break;
        ans += min(value, arr[i]);
        value = min(value, arr[i]) - 1;
    }

    return ans;
}

int main(){
    int n;cin>>n;
    vector<long long> arr;
    
    for(int i = 0; i < n; i++){
        int a;cin>>a;
        arr.push_back(a);
    }

    long long ans = solve(arr, n);
    cout<<ans<<endl;
}