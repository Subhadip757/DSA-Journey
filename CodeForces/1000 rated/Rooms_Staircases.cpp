#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin>>n;

    string str;
    cin>>str;

    int ans = n;
    int c = 0;

    for(int i = 0; i < n; i++){
        c++;
        if(str[i] == '1'){
            ans = max(ans, (i + 1) * 2);
            c++;
        }
    }

    reverse(str.begin(), str.end());
    
    c = 0;
    for(int i = 0; i < n; i++){
        c++;
        if(str[i] == '1'){
            ans = max(ans, (i + 1) * 2);
            c++;
        }
    }

    ans = max(ans, c);
    cout<<ans<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}