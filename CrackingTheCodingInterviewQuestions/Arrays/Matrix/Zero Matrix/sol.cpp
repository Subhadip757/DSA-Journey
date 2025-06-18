// Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    // In place Change
    void zeroMatrix(vector<vector<int>> &arr){
        int n = arr.size();
        int m = arr[0].size();
        vector<int> rowInd(n, 0);
        vector<int> colInd(m, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] == 0){
                    rowInd[i] = 1;
                    colInd[j] = 1;
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(rowInd[i] == 1 || colInd[j] == 1){
                    arr[i][j] = 0;
                }
            }
        }
    }
};

int main(){
    Solution sol;
    vector<vector<int>> arr = {{1, 2, 3}, {0, 4, 5}, {9, 7, 8}};
    sol.zeroMatrix(arr);

    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[0].size(); j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}