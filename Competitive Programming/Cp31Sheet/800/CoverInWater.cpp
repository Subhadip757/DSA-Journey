#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s;
        cin>>s;

        int c = 0, ans = 0;
        bool continues = false;

        for(int i = 0; i < n; i++){
            if(s[i] == '.') c++;
            if(s[i] == '.' && (i < n - 1 && s[i + 1] == '.') && (i < n - 2 && s[i + 2] == '.')){
                continues = true;
            }
        }
        
        if(continues) cout<<2<<"\n";
        else cout<<c<<"\n";
    }
    return 0;
}