#include <bits/stdc++.h>
using namespace std;

// Function to print all subsequences whose sum equals the target sum
void subs(int ind, vector<int> &ds, int s, int sum, int arr[], int n) {
    if (ind == n) {
        if (s == sum) {
            for (auto it : ds) {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }

    // Pick the current element
    ds.push_back(arr[ind]);
    s += arr[ind];
    subs(ind + 1, ds, s, sum, arr, n);

    // Backtrack: do not pick the current element
    s -= arr[ind];
    ds.pop_back();
    subs(ind + 1, ds, s, sum, arr, n);
}

// Function to find any one subsequence whose sum equals the target sum
bool OneSubs(int ind, vector<int> &ds, int s, int sum, int arr[], int n) {
    if (ind == n) {
        if (s == sum) {
            return true; // Return true if the sum matches
        }
        return false;
    }

    // Pick the current element
    ds.push_back(arr[ind]);
    s += arr[ind];
    if (OneSubs(ind + 1, ds, s, sum, arr, n)) {
        return true; // Return true if a valid subsequence is found
    }

    // Backtrack: do not pick the current element
    s -= arr[ind];
    ds.pop_back();
    if (OneSubs(ind + 1, ds, s, sum, arr, n)) {
        return true; // Return true if a valid subsequence is found in this branch
    }

    return false;
}

int countSubs(int ind, int s, int sum, int arr[], int n){
    if(ind == n){
        if(s == sum){
            return 1;
        }
        return 0;
    }

    s += arr[ind];
    int l = countSubs(ind + 1, s, sum, arr, n);

    s -= arr[ind];
    int r = countSubs(ind + 1, s, sum, arr, n);

    return l + r;
}


int main() {
    int arr[] = {1, 2, 3};
    int n = 3;
    vector<int> ds;

    // Find all subsequences whose sum is 3
    cout << "All subsequences with sum = 3:" << endl;
    subs(0, ds, 0, 3, arr, n);

    // Find any one subsequence whose sum is 3
    ds.clear(); // Clear the vector for reuse

    cout << "Any one subsequence with sum = 3:" << endl;
    if (OneSubs(0, ds, 0, 3, arr, n)) {
        for (auto it : ds) {
            cout << it << " ";
        }
        cout << endl;
    } else {
        cout << "No valid subsequence found" << endl;
    }

    int newArr[] = {1, 2, 1};
    int nn = 3;
    int sum = 2;
    int result = countSubs(0, 0, sum, arr, nn);
    cout<<result;
    
    return 0;
}
