#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n; int k;
        cin>>n>>k;
        vector<int> arr(n);

        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }

        if(n == 1){
            cout<<arr[0]<<endl;
            continue;
        }

        cout<<k - 3<<endl;
    }
}