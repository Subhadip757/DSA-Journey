#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int partition(vector<int> &arr, int s, int e){
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

void quickSort(vector<int> &arr, int s, int e){
    if(s < e){
        int part = partition(arr, s, e);
        quickSort(arr, s, part - 1);
        quickSort(arr, part + 1, e);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {9, 3, 10, 22, 1, 5, 20};
    int n = arr.size();
    quickSort(arr, 0, n - 1);

    for(int it : arr){
        cout<<it<<" ";
    }

    return 0;
}