#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        vector<pair<double, pair<int, int>>> res;
        
        for(int i = 0; i < n; i++){
            double ratio = (double)val[i]/wt[i];
            res.push_back({ratio, {val[i], wt[i]}});
        }
        
        sort(res.rbegin(), res.rend());
        
        double totalValue = 0.0;
        
        for(int i = 0; i < n; i++){
            int currW = res[i].second.second;
            int currV = res[i].second.first;
            
            if(capacity >= currW){
                capacity -= currW;
                totalValue += currV;
            }
            else{
                totalValue += res[i].first * capacity;
                break;
            }
        }
        
        return totalValue;
    }
};

int main()
{
    Solution sol;
    vector<int> val = {60, 100, 120}, wt = {10, 20, 30};
    
    double ans = sol.fractionalKnapsack(val, wt, 50);
    cout<<"Ans: "<<ans<<endl;
}