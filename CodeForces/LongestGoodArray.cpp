#include<iostream>
#include<vector>
using namespace std;

void goodArray(int left, int right, vector<int> &ans){
    ans.push_back(left);
    int ind = 1;
    while(left + ind < right){
        left += ind;
        ans.push_back(left);
        ind++;
    }
    ans.push_back(right);
}

int main(){
    int left,right;
    cin>>left>>right;
    vector<int> ans;

    goodArray(left, right, ans);

    cout<<ans.size()<<endl;

    // for(int i = 0; i < ans.size(); i++){
    //     cout<<ans[i]<<" ";
    // }

    return 0;
}