#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int missingNumber(vector<ll>& nums, int n) {
    int total = n * (n + 1) / 2;
    int sum = 0;
    for (int num : nums) sum += num;
    return total - sum;
}

int main()
{
    ll n; cin>>n;
    vector<ll> hash(n);

    for(int i = 0; i < n - 1; i++){
        int a; cin>>a;
        hash[a] = a;
    }

    cout<<missingNumber(hash, n - 1);

    return 0;
}