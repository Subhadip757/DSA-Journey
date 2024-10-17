#include <iostream>
#include <vector>
using namespace std;

//striver approach
void printF(int ind, vector<int> &ds, int arr[], int n){
    if(ind == n){
        for(auto it : ds){
            cout<< it << " ";
        }
        if(ds.size() == 0){
            cout<<"{}";
        }
        cout<<endl;
        return;
    }

    ds.push_back(arr[ind]);
    printF(ind + 1, ds, arr, n);

    ds.pop_back();
    printF(ind + 1, ds, arr, n);
}


//Coder army approach
void subs(int ind, vector<int> &out, int arr[], vector<vector<int>> &ans, int n){
    if(ind == n){
        ans.push_back(out);
        return;
    }

    subs(ind + 1, out, arr, ans, n);

    out.push_back(arr[ind]);
    subs(ind + 1, out, arr, ans, n);

    out.pop_back();
}
int main(){
    int arr[] = {1, 2, 3};
    int n = 3;
    vector<int> a;
    vector<vector<int>> ans;

    printF(0, a, arr, n);

    subs(0, a, arr, ans, n);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}