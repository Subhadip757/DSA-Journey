#include <iostream>
using namespace std;

void reverse(int arr[], int size){
    int start = 0;
    int end = size - 1;
    
    while(start <= end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){

    int arr[4] = {2,5,9,4};
    reverse(arr,4);
    printArray(arr,4);
}