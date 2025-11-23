#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        int c1 = 0;
        int c2 = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            if(arr[i] == -1){
                c1++;
            }
            else if(arr[i] == 0){
                c2++;
            }
        }

        ans = c2;

        if((c1 & 1) != 0){
            ans += 2;
        }

        cout<<ans<<endl;
    }
    return 0;
}