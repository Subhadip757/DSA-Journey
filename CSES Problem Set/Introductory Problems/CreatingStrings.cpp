#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin>>s;

    sort(s.begin(), s.end());
    set<string> strs;

    do{
        strs.insert(s);
    }
    while(next_permutation(s.begin(), s.end()));

    cout<<strs.size()<<endl;
    for(auto &it : strs){
        cout<<it<<endl;
    }
    return 0;
}