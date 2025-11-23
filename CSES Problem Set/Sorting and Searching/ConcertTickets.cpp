#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    multiset<int> st;

    int n, m;
    cin>>n>>m;

    for(int i = 0; i < n; i++){
        int x; cin>>x;
        st.insert(x);
    }

    while(m--){
        int offer; cin>>offer;
        auto it = st.upper_bound(offer);
        if (it == st.begin()) {
            cout << -1 << '\n';
        } else {
            --it;
            cout << *it << '\n';
            st.erase(it);
        }
    }

    return 0;
}