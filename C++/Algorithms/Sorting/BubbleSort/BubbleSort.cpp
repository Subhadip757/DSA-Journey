#include <iostream>

using namespace std;

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[5] = {5,3,8,9,1};

    for(int i=1; i<5; i++){
        bool swapped = false;

        for(int j=0; j<5-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false){
            break;
        }
    }

    printArray(arr,5);
}