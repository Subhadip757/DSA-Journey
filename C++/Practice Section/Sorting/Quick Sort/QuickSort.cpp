#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int partition(int s, int e, vector<int> &arr){
    int pivot = arr[s];
    int i = s, j = e;

    while(i < j){
        while(i <= e && arr[i] <= pivot){
            i++;
        }
        while(j >= s && arr[j] > pivot){
            j--;
        }
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[s], arr[j]);
    return j;
}

void quickSort(int s, int e, vector<int> &arr){
    if(s < e){
        int p = partition(s, e, arr);
        quickSort(s, p - 1, arr);
        quickSort(p + 1, e, arr);
    }
}

vector<int> solve(vector<int> &arr){
    quickSort(0, arr.size() - 1, arr);
    return arr;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {19, 10, 12, 5, 8, 2, 1, 9};
    solve(arr);

    for(int x : arr){
        cout<<x<<" ";
    }

    return 0;
}