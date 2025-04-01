#include<bits/stc++.h>
using namespace std;

void HeapifyMin(vector<int> &arr, int ind, int n){
    int smallest = ind;
    int left = 2 * ind + 1;
    int right = 2 * ind + 2;

    if(left < n && arr[left] < arr[smallest]){
        smallest = left;
    }
    if(right < n && arr[right] < arr[smallest]){
        smallest = right;
    }

    if(smallest != ind){
        swap(arr[smallest], arr[ind]);
        HeapifyMin(arr, smallest, n);
    }
}

void HeapifyMax(vector<int> &arr, int ind, int n){
    int largest = ind;
    int left = 2 * ind + 1;
    int right = 2 * ind + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != ind){
        swap(arr[largest], arr[ind]);
        HeapifyMax(arr, largest, n);
    }
}

void buildMaxHeap(vector<int> &arr, int n){
    for(int i = n/2 - 1; i >= 0; i--){
        HeapifyMax(arr, i, n);
    }
}

void buildMinHeap(vector<int> &arr, int n){
    for(int i = n/2 - 1; i >= 0; i--){
        HeapifyMin(arr, i, n);
    }
}

void printHeap(vector<int> &arr, int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {10, 3, 8, 9, 5, 13, 18, 14, 11, 70};
    buildMaxHeap(arr, arr.size());
    printHeap(arr, arr.size());

    buildMinHeap(arr, arr.size());
    printHeap(arr, arr.size());
}