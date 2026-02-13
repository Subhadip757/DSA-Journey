#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> arr;
        arr.push_back(0);

        for(int i = 1; i <= n; i++){
            int a; cin>>a;
            arr.push_back(a);
        }

        arr.push_back(k);
        n = arr.size();
        
        int maxDis = 0;
        for(int i = 1; i < n; i++){
            if(i == n - 1){
                maxDis = max(maxDis, 2 * (arr[i] -  arr[i - 1]));
            }
            else{
                maxDis = max(maxDis, arr[i] - arr[i - 1]);
            }
        }

        cout<<maxDis<<"\n";
    }
    return 0;
}