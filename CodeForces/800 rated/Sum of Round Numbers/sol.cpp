#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;cin>>n;
    while(n--){
        int a;cin>>a;
        int mod = 1;
        vector<int> ans;

        while(a > 0){
            int dig = a % 10;
            if(dig != 0){
                ans.push_back(dig * mod);
            }
            mod *= 10;
            a /= 10;
        }
        
        reverse(ans.begin(), ans.end());

        cout<<ans.size()<<endl;
        for(int i : ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}