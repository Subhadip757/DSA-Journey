#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end){
    vector<int> temp;
    
    int i = start;
    int j = mid + 1;

    while(i <= mid && j <= end){
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
    while(j <= end){
        temp.push_back(arr[j]);
        j++;
    }
    
    for(int ind = 0; ind < temp.size(); ind++){
        arr[start + ind] = temp[ind];
    }
}

void mergeSort(vector<int> &arr, int start, int end){
    if(start < end){
        int mid = start + (end - start)/2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main(){
    vector<int> arr = {7, 2, 9, 25, 12, 19, 11, 5};
    mergeSort(arr, 0, arr.size() - 1);
    
    for(int n : arr){
        cout<<n<<" ";
    }
    cout<<endl;
}