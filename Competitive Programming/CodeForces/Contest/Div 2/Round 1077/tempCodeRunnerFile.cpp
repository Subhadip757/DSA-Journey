#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        if(n <= 2){
            cout<<1<<"\n";
            continue;
        }
    
        int count = 0;
        for(int i = 1; i < n; i++){
            if(i == 1){
                if(i < n - 1 && s[i] == '0' && s[i - 1] == '0'){
                    s[i] = '1';
                }
            }
            else{
                if(i < n - 1 && s[i] == '0' && s[i - 1] == '0' && s[i + 1] == '0'){
                    s[i] = '1';
                }
            }
        }
    
        for(char ch : s){
            if(ch == '1') count++;
        }

        cout<<count<<"\n";
    }
    
    return 0;
}