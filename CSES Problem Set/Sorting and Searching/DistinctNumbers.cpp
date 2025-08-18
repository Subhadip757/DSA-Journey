#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    set<int> st;
    int n; cin>>n;

    for(int i = 0; i < n; i++){
        int a; cin>>a;
        st.insert(a);
    }

    cout<<st.size();

    return 0;
}