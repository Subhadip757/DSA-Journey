#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<pair<string, pair<string, string>>> res;
    for(int i = 0; i < n; i++){
        string s1, s1n1, s1n2;
        cin>>s1>>s1n1>>s1n2;

        res.push_back({s1, {s1n1, s1n2}});
    }

    string str;
    cin>>str;
    int count = 0;

    for(auto it : res){
        if(it.second.first == str || it.second.second == str){
            count++;
        }
    }

    cout<<count<<endl;

    return 0;
}