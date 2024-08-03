#include <bits/stdc++.h>

using namespace std;

int main(){
    /*int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    //precompute
    int hash[13] = {0};
    for(int i=0; i<n; i++){
        hash[arr[i]] += 1;
    }

    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;

        //fetch
        cout<<hash[number]<<endl;
    }*/


    //-------------------------------------------

    string s;
    cin>>s;
    int q; 
    cin>>q;

    int hash[256] = {0};

    for(int i=0; i<s.size(); i++){
        hash[s[i]]++;
    }

    while(q--){
        char ch;
        cin>>ch;
        
        // fetch
        cout<<hash[ch]<<endl;
    }

    return 0;
}