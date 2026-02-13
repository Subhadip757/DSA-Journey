#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;

        int root = sqrt(n);
        if(root * root == n){
            cout<<"0 "<<root<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
    return 0;
}