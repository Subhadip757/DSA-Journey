#include<bits/stdc++.h>
using namespace std;

vector<bool> seive(int range){
    vector<bool> vis(range + 1, true);

    vis[0] = false;
    vis[1] = false;

    for(int i = 2; i * i <= range; i++){
        if(vis[i]){
            for(int j = i * i; j <= range; j += i){
                vis[j] = false;
            }
        }
    }
    return vis;
}
int main()
{
    int n;
    cout<<"Enter range: ";
    cin>>n;
    vector<bool> primes = seive(n);

    for(int i = 0; i < primes.size(); i++){
        if(primes[i]){
            cout<<i<<" is Prime"<<endl;
        }
    }
    return 0;
}