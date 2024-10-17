#include<bits/stdc++.h>
using namespace std;

void subs(int ind, vector<int> out, vector<int> &ans){
    if(ind == ans.size()){
        for(auto x : out){
            cout<<out.size()<<":-->  "<<x<<"    ";
        }
        cout<<endl;
        return;
    }
    
    out.push_back(ans[ind]);
    subs(ind + 1, out, ans);

    out.pop_back();
    subs(ind + 1, out, ans);
}

int main(){
    vector<int> nums = {1, 2, 3};
    vector<int> ans;
    subs(0, ans, nums);
}