#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;

        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }

        int c = 0;

        vector<int> arr2 = arr;
        sort(arr.begin(), arr.end());

        if(arr == arr2 || k > 1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}