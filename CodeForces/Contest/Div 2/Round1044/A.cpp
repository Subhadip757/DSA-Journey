#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(){
    int n; cin>>n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    unordered_set<int> st;
    for(int it : arr){
        st.insert(it);
    }

    return arr.size() == st.size();
}

int main(){
    int t; cin>>t;
    while(t--){
        if(check()){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}