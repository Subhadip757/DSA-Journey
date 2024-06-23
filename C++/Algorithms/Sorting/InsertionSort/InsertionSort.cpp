#include <iostream>

using namespace std;

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[5] = {3,1,2,9,0};

    for(int i = 1;i<5; i++){
        int temp = arr[i];
        int j = i-1;

        for(; j >= 0 && arr[j] > temp; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }

    printArray(arr,5);
}