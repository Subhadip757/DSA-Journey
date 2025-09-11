#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(){
    int n; cin>>n;
    string str;
    cin>>str;

    if(n <= 3){
        return 0;
    }

    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(str[j] > str[j + 1]){
                swap(str[j], str[j + 1]);
            }
        }
        count++;
    }
    return count / 3;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}