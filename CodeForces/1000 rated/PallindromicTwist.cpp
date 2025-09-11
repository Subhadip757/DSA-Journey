#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool checkPal(string str, int s, int e, int n){
    while(s <= e){
        if(str[s] != str[e]){
            if(abs(str[s] - str[e]) == 2){
                s++;
                e--;
            }
            else{
                return false;
            }
        }
        else{
            s++;
            e--;
        }
    }
    return true;
}

int main(){
    int t; cin>>t;

    while(t--){
        int n;
        cin>>n;

        string str;
        cin>>str;

        int start = 0;
        int end = n - 1;

        if(checkPal(str, start, end, n)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}