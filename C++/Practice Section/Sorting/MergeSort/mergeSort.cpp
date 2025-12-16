#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void merge(int s, int mid, int e, vector<int> &arr){
    vector<int> temp;

    int i = s, j = mid + 1;
    while(i <= mid && j <= e){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= e){
        temp.push_back(arr[j]);
        j++;
    }

    for(int ind = 0; ind < temp.size(); ind++){
        arr[s + ind] = temp[ind];
    }
}

void mergeSort(int s, int e, vector<int> &arr){
    if(s < e){
        int mid = s + (e - s)/2;
        mergeSort(s, mid, arr);
        mergeSort(mid + 1, e, arr);
        merge(s, mid, e, arr);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {10, 5, 4, 1, 11, 12, 3, 22};
    mergeSort(0, arr.size() - 1, arr);

    for(int x : arr){
        cout<<x<<" ";
    }

    return 0;
}