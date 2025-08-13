#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;

        vector<int> a(n), b(n), c(n);

        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        c = a;
        for(int i = 0; i < n; i++){
            cin>>b[i];
        }

        for(int i = n - 1; i >= 0; i--){
            int temp = a[i];
            a.pop_back();
            a.push_back(abs(temp - k));
        }

        for(int i = n - 1; i >= 0; i--){
            int temp = c[i];
            c.pop_back();
            c.push_back(temp + k);
        }

        if(a == b || c == b){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
    return 0;
}