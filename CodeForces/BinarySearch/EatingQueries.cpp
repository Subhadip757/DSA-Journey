#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;

        vector<int> arr(n);
        int s = 0;

        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }

        sort(arr.rbegin(), arr.rend());

        for(int i = 1; i < n; i++){
            arr[i] += arr[i - 1];
        }
        

        for(int i = 0; i < m; i++){
            int a;
            cin>>a;
            int ans = lower_bound(arr.begin(), arr.end(), a) - arr.begin();

            if(ans == n){
                cout<<-1<<endl;
            }
            else{
                cout<<ans + 1<<endl;
            }
        }
    }
    return 0;
}