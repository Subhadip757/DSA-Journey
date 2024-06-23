#include <iostream>

using namespace std;

void selectionSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;  
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {  
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main(){
    int arr[] = {64, 25, 12, 22, 11};  // Sample array to sort
    int size = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array

    selectionSort(arr, size);  
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}