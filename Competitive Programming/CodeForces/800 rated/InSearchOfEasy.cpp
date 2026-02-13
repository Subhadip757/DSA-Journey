#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    int sum = 0;
    for(int i = 0; i < n; i++){
        int a; cin>>a;
        sum += a;
        if(sum > 0){
            cout<<"HARD";
            return 0;
        }
    }

    cout<<"EASY";
    return 0;
}