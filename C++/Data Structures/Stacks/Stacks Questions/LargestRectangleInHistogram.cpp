#include<bits/stdc++.h>
using namespace std;

vector<int> rightSmaller(vector<int> &ht){
    int n = ht.size();
    stack<int> st;
    vector<int> right(n);

    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && ht[st.top()] >= ht[i]){
            st.pop();
        }

        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return right;
}

vector<int> leftSmaller(vector<int> &ht){
    int n = ht.size();
    stack<int> st;
    vector<int> left(n);

    for(int i = 0; i < n; i++){
        while(!st.empty() && ht[st.top()] >= ht[i]){
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return left;
}

int main()
{
    vector<int> arr = {2,1,5,6,2,3};
    vector<int> right = rightSmaller(arr);
    vector<int> left = leftSmaller(arr);

    for(int it : right){
        cout<<it<<" ";
    }

    cout<<endl;

    for(int it : left){
        cout<<it<<" ";
    }

    return 0;
}