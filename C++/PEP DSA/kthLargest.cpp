#include<bits/stc++.h>
using namespace std;

int kth(vector<int> &arr, int &k){
    priority_queue<int, vector<int>, greater<int>> p;

    for(int i = 0; i < k; i++){
        p.push(arr[i]);
    }

    for(int i = k; i < arr.size(); i++){
        if(p.top() < arr[i]){
            p.pop();
            p.push(arr[i]);
        }
    }
    return p.top();
}

int main(){

    vector<int> arr = {3, 2, 1, 5, 6, 8, 4};
    int k = 2;

    cout<<endl<<k<<"th Largest element is: "<<kth(arr, k)<<endl<<endl;

}