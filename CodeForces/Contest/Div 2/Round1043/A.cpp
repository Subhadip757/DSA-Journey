#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin>>t;
    while(t--){
        int n, m;
        string a, b, c;
        cin>>n>>a;
        cin>>m>>b;
        cin>>c;
        
        int itr = 0;

        for(char ch : b){
            if(c[itr] == 'D'){
                a.push_back(ch);
            }
            else{
                a.insert(a.begin(), ch);
            }
            itr++;
        }
        cout<<a<<endl;
    }
    return 0;
}