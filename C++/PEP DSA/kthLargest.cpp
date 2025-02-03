#include<bits/stc++.h>
using namespace std;

int kth(vector<int> &arr, int &k){
    stack<int> st;
    int count = 1;
    st.push(arr[0]);

    while(!st.empty()){
        int top = st.top();
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > top){
                st.push(arr[i]);
            }
        }
    }

    while(count < k){
        st.pop();
        count++;
    }
    return st.top();
}

int main(){

    vector<int> arr = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout<<kth(arr, k);

}